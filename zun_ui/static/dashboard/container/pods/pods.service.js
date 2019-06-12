(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.pods')
      .factory('horizon.dashboard.container.pods.service', podsService);
  
    podsService.$inject = [
      'horizon.app.core.detailRoute',
      'horizon.app.core.openstack-service-api.zun'
    ];
  
    /*
     * @ngdoc factory
     * @name horizon.dashboard.container.pods.service
     *
     * @description
     * This service provides functions that are used through
     * the pods of container features.
     */
    function podsService(detailRoute, zun) {
      return {
        getPodsPromise: getPodsPromise
      };
  
      /*
       * @ngdoc function
       * @name getPodsPromise
       * @description
       * Given filter/query parameters, returns a promise for the matching
       * pods.  This is used in displaying lists of pods.
       */
      function getPodsPromise(params) {
        return zun.getPods(params).then(modifyResponse);
      }
  
      function modifyResponse(response) {
        return {data: {items: response.data.pods_info.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.id;
        item.trackBy = item.id;
        return item;
      }
    }
  })();