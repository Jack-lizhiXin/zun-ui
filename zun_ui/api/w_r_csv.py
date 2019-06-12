import csv

from os import path

def write_csv(csv_file_path):
    # try to write a csv-file at local file system
    try:
        # create a csv-file at local file system
        with open(csv_file_path, 'wb') as f:
            csv_write = csv.writer(f)
            csv_head_info = ["id", "name"]
            csv_write.writerow(csv_head_info)
    except:
        print "create csv-file exception!"
    return

def write_csv(csv_file_path, ):

    try:
        with open(csv_file_path, 'a+') as f:
            csv_write = csv.writer(f)

    except:
        print ""

def read_csv():
    return

if __name__ == "__main__":
    write_csv('/opt/test.csv')