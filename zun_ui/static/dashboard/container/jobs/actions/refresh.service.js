(function() {
    'use strict';
  
    /**
     * @ngDoc factory
     * @name horizon.dashboard.container.jobs.refresh.service
     * @Description
     * refresh container.
     */
    angular
      .module('horizon.dashboard.container.jobs.actions')
      .factory('horizon.dashboard.container.jobs.actions.refresh.service', refreshService);
  
    refreshService.$inject = [
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.jobs.resourceType',
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
        // refresh selected job
        return $qExtensions.booleanAsPromise(true).then(success);
  
        function success() {
          var result = actionResult.getActionResult().updated(resourceType, selected.id);
          return result.result;
        }
      }
    }
  })();