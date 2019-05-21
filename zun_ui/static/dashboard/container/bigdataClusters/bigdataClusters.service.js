(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.bigdataClusters')
      .factory('horizon.dashboard.container.bigdataClusters.service', bigdataClustersService);
  
    bigdataClustersService.$inject = [
      'horizon.app.core.detailRoute',
      'horizon.app.core.openstack-service-api.zun'
    ];
  
    function bigdataClustersService(detailRoute, zun) {
      return {
        getBigdataClustersPromise: getBigdataClustersPromise
      };

      function getBigdataClustersPromise(params) {
        return zun.getBigdataClusters(params).then(modifyResponse);
      }
  
      function modifyResponse(response) {
        console.log(response.data);
        return {data: {items: response.data.pods_info.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.id;
        item.trackBy = item.id;
        // item.trackBy = item.trackBy.concat(item.updated_at);
        return item;
      }
    }
  })();