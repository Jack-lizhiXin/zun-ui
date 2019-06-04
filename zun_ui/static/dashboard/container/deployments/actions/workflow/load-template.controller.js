(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.deployments.actions')
      .controller('horizon.dashboard.container.deployments.actions.workflow.loadTemplateController',
        loadTemplateController);
  
    loadTemplateController.$inject = [
      '$scope'
    ];
  
    function loadTemplateController($scope) {
      var ctrl = this;
      ctrl.title = $scope.schema.properties.template.title;
      ctrl.template = "";
      ctrl.onTemplateChange = onTemplateChange;
  
      function onTemplateChange(template) {
        $scope.model.template = template;
      }
    }
  })();