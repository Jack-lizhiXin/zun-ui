from zun_ui.api import k8s_client
from os import path
import yaml
from kubernetes import client, config


# DEPLOYMENT_NAME = "hadoop-deployment"

def create_deployment_object(dname, dnamespace, dreplicas):
    # Configureate Pod template container
    print "flag *** ", type(dreplicas)
    container = client.V1Container(
        name="hadoop",
        image="hadoop2",
        # image_pull_policy="IfNotPresent ",
        # env=[{"name": "HADOOP", "value": "6"}],
        env=[client.V1EnvVar(name="HADOOP", value=str(dreplicas) )],
        resources={"limits":{"cpu":"2", "memory":"4Gi"}})
        # ports=[client.V1ContainerPort(container_port=80)])

    # Create and configurate a spec section
    template = client.V1PodTemplateSpec(
        metadata=client.V1ObjectMeta(labels={"app": "hadoop-test-ysp"}),
        spec=client.V1PodSpec(containers=[container], node_name="virtual-kubelet62"))

    # Create the specification of deployment
    spec = client.ExtensionsV1beta1DeploymentSpec(
        replicas=dreplicas,
        template=template)

    # Instantiate the deployment object
    deployment = client.ExtensionsV1beta1Deployment(
        api_version="extensions/v1beta1",
        kind="Deployment",
        metadata=client.V1ObjectMeta(name=dname, namespace=dnamespace),
        spec=spec
    )
    return deployment


def create_deployment(api_instance, deployment):
    # Create deployement
    api_response = api_instance.create_namespaced_deployment(
        body=deployment,
        namespace="default")
    print("Deployment created. status='%s'" % str(api_response.status))

"""
def update_deployment(api_instance, deployment):
    # Update container image
    deployment.spec.template.spec.containers[0].image = "nginx:1.9.1"
    # Update the deployment
    api_response = api_instance.patch_namespaced_deployment(
        name=DEPLOYMENT_NAME,
        namespace="default",
        body=deployment)
    print("Deployment updated. status='%s'" % str(api_response.status))
"""

def update_deployment(update_property):
    # update replicas
    k8s_client.load_k8s_config()
    api_instance = client.ExtensionsV1beta1Api()

    deployments = api_instance.list_deployment_for_all_namespaces()
    id = update_property['id']
    for item in deployments.items:
        if item.metadata.uid == str(id):
            name = item.metadata.name
            namespace = item.metadata.namespace
            deployment = item
            break;
    # update this deployment
    # print deployment
    deployment.spec.replicas = update_property['pods']
    api_response = api_instance.patch_namespaced_deployment(
        name=name,
        namespace=namespace,
        body=deployment)
    print("Deployment updated. status='%s'" % str(api_response.status))
    return

"""
 def delete_deployment(api_instance):
    # Delete deployment
    api_response = api_instance.delete_namespaced_deployment(
        name=DEPLOYMENT_NAME,
        namespace="default",
        body=client.V1DeleteOptions(
            propagation_policy='Foreground',
            grace_period_seconds=5))
    print("Deployment deleted. status='%s'" % str(api_response.status))
"""

def main(create_property):
    # Configs can be set in Configuration class directly or using helper
    # utility. If no argument provided, the config will be loaded from default location.
    k8s_client.load_k8s_config()
    extensions_v1beta1 = client.ExtensionsV1beta1Api()

    dnm = create_property['name']
    dnp = create_property['namespace']
    dpods = create_property['pods']
    deployment = create_deployment_object(dnm, dnp, dpods)
    create_deployment(extensions_v1beta1, deployment)

    return

if __name__ == "__main__":
    update_deployment()
