#
# kubernetes client
#

from os import  path
import yaml
from kubernetes import client, config, utils
import json
from os import system
import getpass
import uuid
from zun_ui.api import cfy

from pprint import pprint


def list_all_pods():

    # user_name = getpass.getuser()
    # print(user_name)
    # print ("---")
    # config_file = open('//.kube/config', 'r')
    # print (config_file.read())

    # load  k8s-config
    config.load_kube_config("//.kube/config")

    v1 = client.CoreV1Api()
    result_set = v1.list_pod_for_all_namespaces(watch = False)

    # format to a json file
    pods_info = "{\"pods_info\":["
    for item_pod in result_set.items:
        pods_info = pods_info + "{"
        pods_info = pods_info + "\"pods_name\":" + json.dumps(item_pod.metadata.name) + ","
        pods_info = pods_info + "\"pods_namespace\":" + json.dumps(item_pod.metadata.namespace) + ","
        pods_info = pods_info + "\"pods_labels\":" + json.dumps(item_pod.metadata.labels) + ","
        id = str(uuid.uuid4())
        # print id
        pods_info = pods_info + "\"id\":" + json.dumps(id) + "},"

        # print ("%s\n" % item_pod.metadata.name)
        # print ("%s\n" % item_pod.metadata.labels)
        # print ("%s" % item_pod.metadata.namespace)

    pods_info = pods_info[:-1]
    pods_info = pods_info + "]}"
    return pods_info


def create_deployment_from_yaml(json_file):
# def create_deployment_from_yaml():
    # load  k8s-config
    config.load_kube_config("//.kube/config")
    # XXXyaml = get_file()
    k8s_client = client.ApiClient()
    # utils.create_from_yaml(k8s_client, yaml_file)
    # cfy.create_from_yaml(k8s_client, "/root/yaml-file/deployment_test.yaml")
    print "k8s_client:", json_file
    cfy.create_from_yaml_single_item(k8s_client, json_file)

    # utils.create_from_yaml(k8s_client, "/root/yaml-file/vh/virtualhadoop1.yaml")
    # utils.create_from_yaml(k8s_client, "/root/yaml-file/vh/virtualhadoop2.yaml")

    # deployment_test.yaml
    # utils.create_from_yaml(k8s_client, "deployment_test.yaml")
    # k8s_client = client.ApiClient()

    # k8s_api = client.ExtensionsV1beta1Api(k8s_client)
    # extensions/v1beta1 
    # deps = k8s_api.read_namespaced_deployment("XXX.deployment", "default")
    # print ("Deployment {0} created".format(deps.metadata.name) )

def list_all_deployment():

    config.load_kube_config("//.kube/config")

    # create an instance of the API class
    # api_instance = kubernetes.client.AppsV1Api(kubernetes.client.ApiClient(configuration))
    api_response = client.AppsV1Api()
    deployment_result_set = api_response.list_deployment_for_all_namespaces()

    # pprint(deployment_result_set)
    # format to a json file
    deployment_info = "{\"deployments_info\":["

    for item_deployment in deployment_result_set.items:
        # print item_deployment.kind
        # print item_deployment.metadata.cluster_name
        deployment_info = deployment_info + "{"
        # print item_deployment.metadata.uid
        deployment_info = deployment_info + "\"deployment_uuid\":" + json.dumps(item_deployment.metadata.uid)+","

        # print item_deployment.metadata.cluster_name
        deployment_info = deployment_info + "\"deployment_name\":" + json.dumps(item_deployment.metadata.name) + ","

        # print item_deployment.metadata.namespace
        deployment_info = deployment_info + "\"deployment_namespace\":" + json.dumps(item_deployment.metadata.namespace) + ","

        # print item_deployment.metadata.labels
        deployment_info = deployment_info + "\"deployment_labels\":" + json.dumps(item_deployment.metadata.labels) + "},"

    deployment_info = deployment_info[:-1]
    deployment_info = deployment_info + "]}"

    return deployment_info

def delete_deployment_from_k8s():
    # load k8s config-file
    config.load_kube_config("//.kube/config")
    # create an instance of API class
    api_instance = client.AppsV1Api()
    api_response = api_instance.delete_namespaced_deployment()


if __name__ == "__main__":
    # list_all_pods()
    # create_deployment_from_yaml()
    list_all_deployment()