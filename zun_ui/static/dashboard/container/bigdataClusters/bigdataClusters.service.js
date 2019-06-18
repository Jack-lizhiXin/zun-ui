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
        getDetailsPath: getDetailsPath,
        getBigdataClusterPromise: getBigdataClusterPromise,
        getBigdataClustersPromise: getBigdataClustersPromise
      };

      function getDetailsPath(item) {
        return detailRoute + 'OS::Zun::BigdataCluster/' + item.id;
      }

      function getBigdataClusterPromise(identifier) {
        return zun.getBigdataCluster(identifier).then(modifyDetails);
      }

      function modifyDetails(response) {
        return {data: modifyDetailItem(response.data)};
      }

      function getBigdataClustersPromise(params) {
        return zun.getBigdataClusters(params).then(modifyResponse);
      }
  
      function modifyResponse(response) {
        return {data: {items: response.data.hadoop_cluster_deployment_infos.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.id;
        item.trackBy = item.id;
        return item;
      }

      function modifyDetailItem(item) {
        item.id = item.id;
        item.uuid = item.id;
        item.trackBy =item.id;
        return item;
      }
    }
  })();