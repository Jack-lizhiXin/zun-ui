(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.bigdataClusters')
      .controller('horizon.dashboard.container.bigdataClusters.OverviewController', controller);
  
    controller.$inject = [
      '$scope', '$window'
    ];
  
    function controller(
      $scope, $window
    ) {
      var ctrl = this;
      ctrl.webRoot = $window.WEBROOT;
  
      $scope.context.loadPromise.then(onGetBigdataCluster);
  
      function onGetBigdataCluster(bigdataCluster) {
        var bigdataClusterInfo = {};
        var metadata = bigdataCluster.data['hadoop_cluster_info'].metadata;
        var nodeInfo = [];
        var masterNodeInfo = bigdataCluster.data['hadoop_cluster_info']['hadoop_master_node'];
        masterNodeInfo.type = 'master node';
        var slaveNodeInfo = bigdataCluster.data['hadoop_cluster_info']['hadoop_slave_node'];
        for (let i in slaveNodeInfo) slaveNodeInfo[i].type = 'slave node';
        nodeInfo.push(masterNodeInfo);
        nodeInfo = nodeInfo.concat(slaveNodeInfo);
        for (let key in metadata) {
          if (key === 'create_time') {
            bigdataClusterInfo[key] = metadata[key].slice(0, 19);
          }
          else if (key === 'slave_node_id') {
            bigdataClusterInfo[key] = metadata[key].split('@-@');
          }
          else {
            bigdataClusterInfo[key] = metadata[key];
          } 
        }
        bigdataClusterInfo.nodeInfo = nodeInfo;
        ctrl.bigdataCluster = bigdataClusterInfo;
      }
    }
  })();