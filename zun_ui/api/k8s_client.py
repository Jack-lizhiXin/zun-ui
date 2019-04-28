# kubernetes client
#
#

from kubernetes import client, config

def list_all_pods():
    # load  k8s-config
    config.load_kube_config()

    v1 = client.CoreV1Api()
    result_set = v1.list_pod_for_all_namespaces(watch = False)

    for item_pod in result_set.items:
        print ("%s" % item_pod.metadata.labels)



if __name__ == "__main__":
    list_all_pods()