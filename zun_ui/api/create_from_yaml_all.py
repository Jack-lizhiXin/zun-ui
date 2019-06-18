from os import path
import yaml
from kubernetes import client, config

def create_from_yaml(k8s_client, yaml_file, verbose=False, **kwargs):

    with open(path.abspath(yaml_file)) as f:

        yml_document_all = yaml.safe_load_all(f)

        api_exceptions = []

        for yml_document in yml_document_all:
            print yml_document

            if "List" in yml_document["kind"]:
                print ""
