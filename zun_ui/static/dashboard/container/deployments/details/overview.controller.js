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
        ctrl.deployment = deployment.data;
      }
    }
  })();
