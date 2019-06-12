import MySQLdb
import json

def create_connect_tomysql_DB():
    db = MySQLdb.connect("10.10.87.62", "root", "fudan_Nisl2019@", "hadoop", charset='utf8')
    return db

def read_hadoop_info_from():
    db = create_connect_tomysql_DB()
    conn = db.cursor()
    name = "hadoop-cluster"
    namespace = "default"

    try:
        select_hadoop_info_sql = "SELECT * FROM hadoop_cluster WHERE cluster_name = '" + name + "' AND namespace = '" + \
                                 namespace + "'"
        conn.execute(select_hadoop_info_sql)
        results_set = conn.fetchall()
        metadata = {}
        for row in results_set:
            metadata['cluster_name'] = row[0]
            metadata['namespace'] = row[7]
            metadata['create_time'] = row[3]
            metadata['number_of_nodes '] = row[1]
            metadata['available_number'] = row[2]
            metadata['cluster_status'] = row[6]
            metadata['master_node_id'] = row[4]
            metadata['slave_node_id'] = row[5]
            break
        # print json.dumps(metadata)

    except:
        print "select hadoop_cluster info from database exception !!!"

    print metadata

    master_node_id = metadata['master_node_id']
    select_master_node_info_sql = "SELECT * FROM hadoop_nodes WHERE container_id  = '" + master_node_id + "'"
    conn.execute(select_master_node_info_sql)
    results_set2 = conn.fetchall()
    hadoop_master_node = {}
    for row in results_set2:
        hadoop_master_node['container_id '] = row[3]
        hadoop_master_node['name'] = row[1]
        hadoop_master_node['namespace'] = row[0]
        hadoop_master_node['ip'] = row[4]
        hadoop_master_node['status'] = row[5]
        break
    # print json.dumps(hadoop_master_node)

    slave_node_id = metadata['slave_node_id']
    slave_node_id_str = str(slave_node_id)
    slave_node_ids = slave_node_id_str.split('@-@')
    # print slave_node_ids
    lens = len(slave_node_ids)
    ids = ""
    for i in range(0, lens):
        ids = ids + '\'' + slave_node_ids[i] + '\''
        if i<lens-1:
            ids = ids + ','

    select_slave_node_info_sql = "SELECT * FROM hadoop_nodes WHERE container_id in ("
    select_slave_node_info_sql += ids
    select_slave_node_info_sql += ')'
    conn.execute(select_slave_node_info_sql)
    results_set3 = conn.fetchall()

    hadoop_slave_node = []
    for row in results_set3:
        # print row
        hadoop_slave_node_item = {}
        hadoop_slave_node_item['container_id'] = row[3]
        hadoop_slave_node_item['name'] = row[1]
        hadoop_slave_node_item['namespace'] = row[0]
        hadoop_slave_node_item['ip'] = row[4]
        hadoop_slave_node_item['status'] = row[5]
        hadoop_slave_node.append(hadoop_slave_node_item)

    # print json.dumps(hadoop_slave_node)
    hadoop_cluster_info = {}
    hadoop_cluster_info['metadata'] = metadata
    hadoop_cluster_info['hadoop_master_node'] = hadoop_master_node
    hadoop_cluster_info['hadoop_slave_node'] = hadoop_slave_node
    hadoop_cluster_info_to_dict = {}
    hadoop_cluster_info_to_dict['hadoop_cluster_info'] = hadoop_cluster_info
    print json.dumps(hadoop_cluster_info_to_dict)

    db.close()
    return

if __name__ == '__main__':
    read_hadoop_info_from()