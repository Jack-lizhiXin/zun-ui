(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.jobs')
      .factory('horizon.dashboard.container.jobs.service', jobsService);
  
    jobsService.$inject = [
      'horizon.app.core.detailRoute',
      'horizon.app.core.openstack-service-api.zun'
    ];
  
    function jobsService(detailRoute, zun) {
      return {
        getJobsPromise: getJobsPromise
      };
  
      function getJobsPromise(params) {
        return zun.getJobs(params).then(modifyResponse);
      }
  
      function modifyResponse(response) {
        return {data: {items: response.data.jobs.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.appID;
        item.uuid = item.id;
        item.trackBy =item.uuid;
        return item;
      }
    }
  })();