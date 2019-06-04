#
# kubernetes client
#

from os import  path
import yaml
from kubernetes import client, config, utils, watch
import json
from os import system
import getpass
import uuid
from zun_ui.api import cfy
from kubernetes.client.rest import ApiException
from pprint import pprint


def list_all_pods():

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
    if len(result_set.items)>0:
        pods_info = pods_info[:-1]
    pods_info = pods_info + "]}"
    return pods_info


def create_deployment_from_yaml(json_file):
# def create_deployment_from_yaml():
    # load  k8s-config
    config.load_kube_config("//.kube/config")
    # XXXyaml = get_file()
    k8s_client = client.ApiClient()
    # print "k8s_client:", json_file
    cfy.create_from_yaml_single_item(k8s_client, json_file)

    # deployment_test.yaml
    # utils.create_from_yaml(k8s_client, "deployment_test.yaml")
    # k8s_client = client.ApiClient()

    # k8s_api = client.ExtensionsV1beta1Api(k8s_client)
    # extensions/v1beta1 
    # deps = k8s_api.read_namespaced_deployment("XXX.deployment", "default")
    # print ("Deployment {0} created".format(deps.metadata.name) )

# just a test
def create():
    config.load_kube_config("//.kube/config")
    api_instance = client.AppsV1Api()
    namespace = 'namespace_example'
    body = client.V1Deployment()
    try:
        api_response = api_instance.create_namespaced_deployment(namespace, body)
    except ApiException as e:
        print("Exception when calling AppsV1Api->create_namespaced_deployment: %s\n" % e)

def list_all_deployment():

    config.load_kube_config("//.kube/config")

    # create an instance of the API class
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
        deployment_info = deployment_info + "\"uuid\":" + json.dumps(item_deployment.metadata.uid)+","

        # print item_deployment.metadata.cluster_name
        deployment_info = deployment_info + "\"deployment_name\":" + json.dumps(item_deployment.metadata.name) + ","

        # print item_deployment.metadata.namespace
        deployment_info = deployment_info + "\"deployment_namespace\":" + json.dumps(item_deployment.metadata.namespace) + ","

        # print item_deployment.metadata.labels
        deployment_info = deployment_info + "\"deployment_labels\":" + json.dumps(item_deployment.metadata.labels) + "},"
    if len(deployment_result_set.items)>0:
        deployment_info = deployment_info[:-1]
    deployment_info = deployment_info + "]}"
    return deployment_info

def get_deployment_info_from_id(id):

    config.load_kube_config("//.kube/config")
    api_instance = client.AppsV1Api()
    deployment_result_set = api_instance.list_deployment_for_all_namespaces()
    id_to_deployment_info = "{ \"id\":" + json.dumps(id) + ","
    id_to_deployment_info = id_to_deployment_info + "\"id_deployment_info\": ["
    str_id = str(id)

    for item_deployment in deployment_result_set.items:

        if item_deployment.metadata.uid == str_id:

            metadata = item_deployment.metadata.to_dict()
            for metadata_key, metadata_value in metadata.items():
                try:
                    json.dumps(metadata_value)
                except TypeError:
                    key = metadata_key
                    value = metadata_value
                    del metadata[key]
                    metadata[key] = str(value)

            id_to_deployment_info = id_to_deployment_info + "{ \"metadata\": " + json.dumps(metadata) + "},"

            spec = item_deployment.spec.to_dict()
            for spec_key, spec_value in spec.items():
                if spec_key == 'template':
                    del spec[spec_key]
                    continue
                try:
                    json.dumps(spec_value)
                except TypeError:
                    key = spec_key
                    value = spec_value
                    del spec[key]
                    spec[key] = str(value)

            id_to_deployment_info = id_to_deployment_info + "{ \"spec\": " + json.dumps(spec) + "},"

            status = item_deployment.status.to_dict()
            for status_key, status_value in status.items():
                if status_key == 'conditions':
                    del status[status_key]
                    continue
                try:
                    json.dumps(status_value)
                except TypeError:
                    print "ok"
                    key = status_key
                    value = status_value
                    del status[key]
                    status[key] = str(value)

            id_to_deployment_info = id_to_deployment_info + " { \"status\": " + json.dumps(status) + "}]}"
            break

    return id_to_deployment_info

def delete_deployment_from_id(id):
    # load k8s config-file
    print id
    config.load_kube_config("//.kube/config")
    # create an instance of API class
    api_instance = client.AppsV1Api()
    # api_response = api_instance.delete_namespaced_deployment()

    # if only can get id info from front-end, so need to search deployment list and get id to (name, namespace)
    api_instance = client.AppsV1Api()
    deployment_result_set = api_instance.list_deployment_for_all_namespaces()
    str_id = str(id)

    for item_deployment in deployment_result_set.items:

        if item_deployment.metadata.uid == str_id:
            delete_name = item_deployment.metadata.name
            delete_namespace = item_deployment.metadata.namespace
            break
    # print test
    print delete_name
    print delete_namespace

    # if can get deployment-name and deployment-namespace info from front-end, just exec followed code
    try:
        api_response = api_instance.delete_namespaced_deployment(delete_name, delete_namespace)
        pprint(api_response)
    except ApiException as e:
        print("Exception when calling AppsV1Api->delete_namespaced_deployment: %s\n" % e)

def watch_k8s():

    config.load_kube_config("//.kube/config")
    v1 = client.CoreV1Api()
    count = 10
    w = watch.Watch()
    for event in w.stream(v1.list_namespace, _request_timeout=60):
        print ("Event: %s %s" % (event['type'], event['object'].metadata.name))
        count-=-1
        if not count:
            w.stop()
    print "ended."

def list_all_pods_with_theirIPs():

    config.load_kube_config("//.kube/config")

    v1 = client.CoreV1Api()
    print "listing pods with their IPs:"
    ret = v1.list_pod_for_all_namespaces(watch=False)
    for item in ret.items:
        print("%s\t%s\t%s" % (item.status.pod_ip, item.metadata.namespace, item.metadata.name) ) 

# def test():


if __name__ == "__main__":
    test()