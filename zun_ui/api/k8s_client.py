# kubernetes client
#
#

from os import  path
import yaml
from kubernetes import client, config, utils

def list_all_pods():
    # load  k8s-config
    config.load_kube_config()

    v1 = client.CoreV1Api()
    result_set = v1.list_pod_for_all_namespaces(watch = False)

    for item_pod in result_set.items:
        print ("%s" % item_pod.metadata.labels)

def create_deployment_from_yaml():
    # load  k8s-config
    config.load_kube_config()
    k8s_client = client.ApiClient()
    utils.create_from_yaml(k8s_client, "XXX.yaml")
    k8s_api = client.ExtensionsV1beta1Api(k8s_client)

    deps = k8s_api.read_namespaced_deployment("XXX.deployment", "default")
    print ("Deployment {0} created".format(deps.metadata.name) )

def create_deployment():
    # load  k8s-config
    config.load_kube_config()

    with open(path.join(path.dirname(__file__), "nginx-deployment.yaml")) as f:

        dep = yaml.safe_load(f)

        k8s_beta = client.ExtensionsV1beta1Api()
        resp = k8s_beta.create_namespaced_deployment(body=dep, namespace="default")
        print("Deployment created. status='%s'" % str(resp.status)) 

def create_deployment_object():

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
        metadata=client.V1ObjectMeta(name=DEPLOYMENT_NAME),
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
        name=DEPLOYMENT_NAME,
        namespace="default",
        body=deployment)
    print("Deployment updated. status='%s'" % str(api_response.status))

def delete_deployment(api_instance):
    # Delete deployment
    api_response = api_instance.delete_namespaced_deployment(
        name=DEPLOYMENT_NAME,
        namespace="default",
        body=client.V1DeleteOptions(
            propagation_policy='Foreground',
            grace_period_seconds=5))
    print("Deployment deleted. status='%s'" % str(api_response.status))

def deployment():
    config.load_kube_config()
    extensions_v1beta1 = client.ExtensionsV1beta1Api()
    # Create a deployment object with client-python API. The deployment we
    # created is same as the `nginx-deployment.yaml` in the /examples folder.

    deployment = create_deployment_object()

    create_deployment(extensions_v1beta1, deployment)

    update_deployment(extensions_v1beta1, deployment)

    delete_deployment(extensions_v1beta1) 

if __name__ == "__main__":
    list_all_pods()