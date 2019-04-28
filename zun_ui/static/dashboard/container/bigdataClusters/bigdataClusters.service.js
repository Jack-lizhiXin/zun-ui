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
        return {data: {items: response.data.items.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.uuid;
        item.trackBy = item.uuid;
        item.trackBy = item.trackBy.concat(item.updated_at);
        return item;
      }
    }
  })();