(function() {
    'use strict';
  
    /**
     * @ngDoc factory
     * @name horizon.dashboard.container.bigdataClusters.refresh.service
     * @Description
     * refresh container.
     */
    angular
      .module('horizon.dashboard.container.bigdataClusters.actions')
      .factory('horizon.dashboard.container.bigdataClusters.actions.refresh.service', refreshService);
  
    refreshService.$inject = [
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.bigdataClusters.resourceType',
      'horizon.framework.util.actions.action-result.service',
      'horizon.framework.util.q.extensions'
    ];
  
    function refreshService(
      zun, resourceType, actionResult, $qExtensions
    ) {
  
      var service = {
        initAction: initAction,
        allowed: allowed,
        perform: perform
      };
  
      return service;
  
      //////////////
  
      // include this function in your service
      // if you plan to emit events to the parent controller
      function initAction() {
      }
  
      function allowed() {
        return $qExtensions.booleanAsPromise(true);
      }
  
      function perform(selected) {
        // refresh selected bigdataCluster
        return $qExtensions.booleanAsPromise(true).then(success);
  
        function success() {
          var result = actionResult.getActionResult().updated(resourceType, selected.id);
          return result.result;
        }
      }
    }
  })();
