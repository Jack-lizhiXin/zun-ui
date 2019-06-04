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
        detailsData.id = deployment.data.id;
        detailsData.metadata = deployment.data.id_deployment_info[0].metadata;
        detailsData.spec = deployment.data.id_deployment_info[1].spec;
        detailsData.status = deployment.data.id_deployment_info[2].status;
        console.log('detaildata', detailsData);
        ctrl.deployment = detailsData;
      }
    }
  })();
