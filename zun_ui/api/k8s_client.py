# kubernetes client
# YSP

from os import path
import yaml
from kubernetes import client, config, utils, watch
import json
from os import system
from zun_ui.api import cfy
from kubernetes.client.rest import ApiException
from pprint import pprint

def load_k8s_config():
    # load  k8s-config
    config.load_kube_config("//.kube/config")

def list_all_pods():

    load_k8s_config()
    v1 = client.CoreV1Api()
    result_set = v1.list_pod_for_all_namespaces(watch = False)

    pods_infos = []
    for item in result_set.items:
        # print item, "\n\n\n"
        pod_info = {}
        pod_info['pods_name'] = item.metadata.name
        pod_info['pods_namespace'] = item.metadata.namespace
        pod_info['pods_labels'] = item.metadata.labels
        pod_info['id'] = item.metadata.uid
        pods_infos.append(pod_info)
    # print json.dumps(pods_infos)
    pods_infos_to_dict = {}
    pods_infos_to_dict['pods_info'] = pods_infos
    return json.dumps(pods_infos_to_dict)

def create_deployment_from_yaml(json_file):

    load_k8s_config()
    k8s_client = client.ApiClient()
    # print "k8s_client:", json_file
    cfy.create_from_yaml_single_item(k8s_client, json_file)

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

    load_k8s_config()
    # create an instance of the API class
    api_response = client.AppsV1Api()
    try:
        deployment_result_set = api_response.list_deployment_for_all_namespaces()
        print deployment_result_set
        deployment_info = []
        for item in deployment_result_set.items:
            deployment_item = {}
            deployment_item['uuid'] = item.metadata.uid
            deployment_item['deployment_name'] = item.metadata.name
            deployment_item['deployment_namespace'] = item.metadata.namespace
            deployment_item['deployment_labels'] = item.metadata.labels
            deployment_info.append(deployment_item)

        deployment_info_to_dict = {}
        deployment_info_to_dict['deployments_info'] = deployment_info
        print json.dumps(deployment_info_to_dict)
    except:
        print "exception !!!"
    return json.dumps(deployment_info_to_dict)


def get_deployment_info_from_id(id):

    load_k8s_config()
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

"""
def get_deployment_info_from_id2():

    id = '29cd87b8-7c6e-11e9-be4f-44a8423d9a40'
    load_k8s_config()
    # create an instance API class
    api_instance = client.AppsV1Api()
    str_id = str(id)
    try:
        deployment_result_set = api_instance.list_deployment_for_all_namespaces()
        id_to_deployment_info = {}
        id_to_deployment_info['id'] = id
        id_deployment_info = {}

        for item in deployment_result_set.items:
            if item.metadata.uid == str_id:
                metadata = item.metadata.to_dict()
                for metadata_key, metadata_value in metadata.items():
                    try:
                        json.dumps(metadata_value)
                    except TypeError:
                        key = metadata_key
                        value = metadata_value
                        del metadata[key]
                        metadata[key] = str(value)
                spec = item.spec.to_dict()
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

                status = item.status.to_dict()
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

        id_deployment_info['metadata'] = metadata
        id_deployment_info['spec'] = spec
        id_deployment_info['status'] = status
        id_to_deployment_info['id_deployment_info'] = id_deployment_info
        print json.dumps(id_to_deployment_info)

    except:
        print "exceptions !!!"
        import traceback
        traceback.print_exc()

    return json.dumps(id_to_deployment_info)
"""

def delete_deployment_from_id(id):

    # load k8s config-file
    load_k8s_config()
    # create an instance of API class

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
    # print delete_name
    # print delete_namespace

    # if can get deployment-name and deployment-namespace info from front-end, just exec followed code
    try:
        api_response = api_instance.delete_namespaced_deployment(delete_name, delete_namespace)
        pprint(api_response)
    except ApiException as e:
        print("Exception when calling AppsV1Api->delete_namespaced_deployment: %s\n" % e)

def watch_k8s():

    load_k8s_config()
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

    load_k8s_config()
    v1 = client.CoreV1Api()
    print "listing pods with their IPs:"
    ret = v1.list_pod_for_all_namespaces(watch=False)
    for item in ret.items:
        print("%s\t%s\t%s" % (item.status.pod_ip, item.metadata.namespace, item.metadata.name) )

def list_all_hadoop_cluster_info():

    load_k8s_config()
    api_instance = client.AppsV1Api()

    try:
        hadoop_cluster_deployment_infos = []
        deployment_result_set = api_instance.list_deployment_for_all_namespaces()
        for item in deployment_result_set.items:
            # print item
            containers = item.spec.template.spec.containers
            # print containers
            info = containers[0].to_dict()
            if info['env'] != None:
                ans = info['env']
                info2 = ans[0]
                if info2['name'] != None and info2['name'] == 'HADOOP':
                    # this is a hadoop deployment
                    # print item
                    hadoop_cluster_deployment_info = {}
                    hadoop_cluster_deployment_info['id'] = item.metadata.uid
                    hadoop_cluster_deployment_info['name'] = item.metadata.name
                    hadoop_cluster_deployment_info['namespace'] = item.metadata.namespace
                    hadoop_cluster_deployment_info['replicas'] = item.spec.replicas
                    hadoop_cluster_deployment_info['labels'] = item.metadata.labels
                    # print hadoop_cluster_deployment_info
                    hadoop_cluster_deployment_infos.append(hadoop_cluster_deployment_info)

    except:
        print "exceptions !!!"
    hadoop_cluster_deployment_infos_to_dict = {}
    hadoop_cluster_deployment_infos_to_dict["hadoop_cluster_deployment_infos"] = hadoop_cluster_deployment_infos
    # print json.dumps(hadoop_cluster_deployment_infos_to_dict)
    return json.dumps(hadoop_cluster_deployment_infos_to_dict)
"""
class create_deployment_by_property(deployment_name):

    DEPLOYMENT_NAME = "nginx-deployment" 

    def create_deployment_object(self):
        # Configureate Pod template container
        container = client.V1Container(
            name="nginx",
            image="nginx:1.7.9",
            ports=[client.V1ContainerPort(container_port=80)])
        # Create and configurate a spec section
        template = client.V1PodTemplateSpec(
            metadata=client.V1ObjectMeta(labels={"app": "nginx"}),
            spec=client.V1PodSpec(containers=[container]))
        # Create the specification of deployment
        spec = client.ExtensionsV1beta1DeploymentSpec(
            replicas=3,
            template=template)
        # Instantiate the deployment object
        deployment = client.ExtensionsV1beta1Deployment(
            api_version="extensions/v1beta1",
            kind="Deployment",
            metadata=client.V1ObjectMeta(name=create_deployment_by_property.DEPLOYMENT_NAME),
            spec=spec)

        return deployment

    def create_deployment(api_instance, deployment):
        # Create deployement
        api_response = api_instance.create_namespaced_deployment(
            body=deployment,
            namespace="default")
        print("Deployment created. status='%s'" % str(api_response.status))

    def update_deployment(api_instance, deployment):
        # Update container image
        deployment.spec.template.spec.containers[0].image = "nginx:1.9.1"
        # Update the deployment
        api_response = api_instance.patch_namespaced_deployment(
            name=create_deployment_by_property.DEPLOYMENT_NAME,
            namespace="default",
            body=deployment)
        print("Deployment updated. status='%s'" % str(api_response.status))

    def delete_deployment(api_instance):
        # Delete deployment
        api_response = api_instance.delete_namespaced_deployment(
            name=create_deployment_by_property.DEPLOYMENT_NAME,
            namespace="default",
            body=client.V1DeleteOptions(
                propagation_policy='Foreground',
                grace_period_seconds=5))
        print("Deployment deleted. status='%s'" % str(api_response.status)) 
"""

if __name__ == "__main__":
    list_all_deployment()