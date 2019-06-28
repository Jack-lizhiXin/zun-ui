import os
import csv
import DB
import commands
import time
import json
import paramiko



# masterIP = '192.168.1.6'
# filepath = '/opt/test.txt'
# containername = 'hadoop-master'
# jar = '/usr/local/hadoop/share/hadoop/mapreduce/hadoop-mapreduce-examples-2.9.2.jar'
# jobtemplate = 'wordcount'
# jobname = 'test'
# inputfile = '/test.txt'
# outputfile = '/wordcount1'
# clustername = 'qh-test'
sourceshell = 'source /opt/stack/devstack/openrc admin admin;'



def writecsv(request, masterIP, appID, containername):
# def writecsv(jobname, jobtemplate, clustername, containername, masterIP, appID, outputfile):
    jobname = request.DATA.get("jobname")
    jobtemplate = request.DATA.get("jobtemplate")
    clustername = request.DATA.get("clustername")
    outputfile = request.DATA.get("outputfilepath")
    with open('/opt/stack/job.csv', 'a+') as f:
        fieldnames = ['jobname', 'jobtemplate', 'clustername', 'containername', 'masterIP', 'appID', 'outputfile']
        write = csv.DictWriter(f, fieldnames=fieldnames)
        reader = csv.DictReader(f)
        if reader.fieldnames != fieldnames:
            write.writeheader()
        write.writerows([{'jobname': jobname, 'jobtemplate': jobtemplate, 'clustername': clustername,
                          'containername': containername, 'masterIP': masterIP, 'appID': appID, 'outputfile': outputfile}])
        f.close()
    return True


def readcsv():
    if os.path.exists('/opt/stack/job.csv') == True:
        with open('/opt/stack/job.csv', 'a+') as f:
            reader = list(csv.DictReader(f))
            return reader
    else:
        return False

def container_submit_job(request, containername):
# def container_submit_job(containername, jar, jobtemplate, inputfile, outputfile):
    # jarname = request.DATA['jar']
    # jar = '/opt/' + jarname
    jar = "/usr/local/hadoop/share/hadoop/mapreduce/hadoop-mapreduce-examples-2.9.2.jar"
    jobtemplate = unicode.encode(request.DATA.get("jobtemplate"))
    inputfile = unicode.encode(request.DATA['inputfile'])
    outputfile = unicode.encode(request.DATA.get("outputfilepath"))
    os.system(sourceshell + 'zun exec' + ' ' + containername + ' ' + 'bash hadoop.sh' + ' ' + jar + ' ' + jobtemplate + ' /'
              + inputfile + ' ' + outputfile)
    str = commands.getstatusoutput(sourceshell + 'zun exec' + ' ' + containername + ' ' + 'cat output.txt')
    str = str[1]
    b = str.find('Submitted application')
    while b == -1:
        time.sleep(1)
        str = commands.getstatusoutput(sourceshell + 'zun exec' + ' ' + containername + ' ' + 'cat output.txt')
        str = str[1]
        b = str.find('Submitted application')
    appID = str[b + 22:b + 52]
    os.system(sourceshell + 'zun exec' + ' ' + containername + ' ' + 'rm -rf output.txt')
    return appID


def sftpput(masterIP, localfile, remotefile):
    p_key = paramiko.RSAKey.from_private_key_file('/root/.ssh/id_rsa')
    transport = paramiko.Transport(masterIP, 22)
    transport.connect(username='root', pkey=p_key)
    sftp = paramiko.SFTPClient.from_transport(transport)
    sftp.put(localfile, remotefile)
    transport.close()


def sftpget(masterIP, remotefile, localfile):
    p_key = paramiko.RSAKey.from_private_key_file('/root/.ssh/id_rsa')
    transport = paramiko.Transport(masterIP, 22)
    transport.connect(username='root', pkey=p_key)
    sftp = paramiko.SFTPClient.from_transport(transport)
    if remotefile[-1] == '/':
        remotefile = remotefile[:-1]
        localfile = localfile + remotefile[remotefile.rfind('/'):]
    else:
        localfile = localfile + remotefile[remotefile.rfind('/'):]
    os.system('mkdir ' + localfile)
    for f in sftp.listdir(remotefile):
        print os.path.join(remotefile + '/'+f)
        sftp.get(os.path.join(remotefile + '/' + f), os.path.join(localfile + '/' + f))
    transport.close()


def upload_file(request, containername, inputfilepath, jarpath):
# def uploadfile(request, masterIP, inputfilepath, jarpath):
    inputfilename = request.DATA['inputfile']
    jarname = request.DATA['jar']
    # sftpput(masterIP, inputfilepath, '/opt/hdfsnfs/'+inputfilename)
    os.system(sourceshell + 'zun cp ' + inputfilepath + ' ' + containername + ':/opt/')
    os.system(sourceshell + 'zun exec ' + containername + ' mv /opt/' + inputfilename + ' /opt/')
    os.system(sourceshell + 'zun exec ' + containername + ' hdfs dfs -put /opt/' + inputfilename+ ' /')
    # sftpput(masterIP, jarpath, '/opt/'+jarname)
    return True


def get_master_details(request):
    clustername = request.DATA.get("clustername")
    return DB.get_master_details_from_clustername(clustername)


def get_status(containername, masterIP, appID):
    yarnInfo = get_yarn_info(containername, masterIP)
    for item in yarnInfo['apps']['app']:
        if appID == item['id']:
            if item['state'] == 'FINISHED':
                return item['finalStatus']
            else:
                return item['state']


def get_yarn_info(containername, masterIP):
    result = commands.getstatusoutput(sourceshell + 'zun exec ' + containername + ' ' + 'curl --compressed -H "Accept:application/json" -X GET "http://' +
                                      masterIP + ':8088/ws/v1/cluster/apps"')
    result = result[1]
    if result[-1] == '}':
        a = result.find('{"apps"')
        if a != -1:
            while result[a:].find('--') != -1:
                result = commands.getstatusoutput(sourceshell +
                    'zun exec ' + containername + ' ' + 'curl --compressed -H "Accept:application/json" -X GET "http://' +
                    masterIP + ':8088/ws/v1/cluster/apps"')
                result = result[1]
                if result[-1] == '}':
                    a = result.find('{"apps"')
            print a
            print result[a:4099]
            result = json.loads(result[a:])
    else:
        a = result.find('{"apps"')
        b = result.rfind('}')
        if a != -1:
            while result[a:b+1].find('--') != -1:
                result = commands.getstatusoutput(sourceshell +
                    'zun exec ' + containername + ' ' + 'curl --compressed -H "Accept:application/json" -X GET "http://' +
                    masterIP + ':8088/ws/v1/cluster/apps"')
                result = result[1]
                if result[-1] == '}':
                    a = result.find('{"apps"')
                    b = result.rfind('}')
            result = json.loads(result[a:b+1])
    return result


def submit_job(request):
    clustername = request.DATA['clustername']
    # masterinfo = DB.get_master_details_from_clustername(clustername)
    # masterIP = masterinfo['ip']
    # containername = masterinfo['name']
    containername = 'hadoop-master'
    masterIP = '192.168.1.6'
    inputfile = os.path.join("/opt/upload/inputfile_upload", request.DATA['inputfile'])
    jar = '/usr/local/hadoop/share/hadoop/mapreduce/hadoop-mapreduce-examples-2.9.2.jar'
    # jar = os.path.join("/opt/upload/jar_upload", request.DATA['jar'])
    upload_file(request, containername,inputfile, jar)
    # upload_file(request, masterIP, inputfile, jar)
    appID = container_submit_job(request, containername)
    writecsv(request, masterIP, appID, containername)