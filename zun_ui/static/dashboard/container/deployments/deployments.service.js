(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.deployments')
      .factory('horizon.dashboard.container.deployments.service', deploymentsService);
  
    deploymentsService.$inject = [
      'horizon.app.core.detailRoute',
      'horizon.app.core.openstack-service-api.zun'
    ];
  
    /*
     * @ngdoc factory
     * @name horizon.dashboard.container.deployments.service
     *
     * @description
     * This service provides functions that are used through
     * the deployments of container features.
     */
    function deploymentsService(detailRoute, zun) {
      return {
        getDetailsPath: getDetailsPath,
        getDeploymentPromise: getDeploymentPromise,
        getDeploymentsPromise: getDeploymentsPromise
      };
  
      function getDetailsPath(item) {
        return detailRoute + 'OS::Zun::Deployment/' + item.id;
      }

      function getDeploymentPromise(identifier) {
        return zun.getDeployment(identifier).then(modifyDetails);
      }
  
      function modifyDetails(response) {
        return {data: modifyItem(response.data)};
      }

      /*
       * @ngdoc function
       * @name getDeploymentsPromise
       * @description
       * Given filter/query parameters, returns a promise for the matching
       * deployments.  This is used in displaying lists of deployments.
       */
      function getDeploymentsPromise(params) {
        return zun.getDeployments(params).then(modifyResponse);
      }
  
      function modifyResponse(response) {
        console.log(response.data);
        return {data: {items: response.data.deployments_info.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.uuid;
        item.trackBy = item.uuid;
        return item;
      }
    }
})();