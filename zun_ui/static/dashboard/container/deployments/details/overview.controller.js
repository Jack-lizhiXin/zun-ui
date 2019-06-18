(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.deployments')
      .controller('horizon.dashboard.container.deployments.OverviewController', controller);
  
    controller.$inject = [
      '$scope', '$window'
    ];
  
    function controller(
      $scope, $window
    ) {
      var ctrl = this;
      ctrl.webRoot = $window.WEBROOT;
  
      $scope.context.loadPromise.then(onGetDeployment);

      function onGetDeployment(deployment) {
        var detailsData = {};
        detailsData['id'] = deployment.data.id;
        detailsData['deployment_name'] = deployment.data.id_deployment_info[0].metadata.name;
        detailsData['deployment_namespace'] = deployment.data.id_deployment_info[0].metadata.namespace;
        detailsData['cluster_name'] = deployment.data.id_deployment_info[0].metadata['cluster_name'];
        detailsData['deployment_labels'] = deployment.data.id_deployment_info[0].metadata.labels;
        detailsData['replicas'] = deployment.data.id_deployment_info[1].spec.replicas;
        detailsData['available_replicas'] = deployment.data.id_deployment_info[2].status['available_replicas'];
        detailsData['ready_replicas'] = deployment.data.id_deployment_info[2].status['ready_replicas'];
        console.log('details', detailsData);
        ctrl.deployment = detailsData;
      }
    }
  })();
