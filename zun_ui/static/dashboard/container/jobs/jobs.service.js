(function() {
    "use strict";
  
    angular
      .module('horizon.dashboard.container.jobs')
      .factory('horizon.dashboard.container.jobs.service', jobsService);
  
    jobsService.$inject = [
      'horizon.app.core.detailRoute',
      'horizon.app.core.openstack-service-api.zun'
    ];
  
    /*
     * @ngdoc factory
     * @name horizon.dashboard.container.jobs.service
     *
     * @description
     * This service provides functions that are used through
     * the jobs of container features.
     */
    function jobsService(detailRoute, zun) {
      return {
        getJobsPromise: getJobsPromise
      };
  
      /*
       * @ngdoc function
       * @name getJobsPromise
       * @description
       * Given filter/query parameters, returns a promise for the matching
       * jobs.  This is used in displaying lists of jobs.
       */
      function getJobsPromise(params) {
        return zun.getJobs(params).then(modifyResponse);
      }
  
      function modifyResponse(response) {
        return {data: {items: response.data.items.map(modifyItem)}};
      }
  
      function modifyItem(item) {
        item.id = item.uuid;
        item.uuid = item.uuid;
        item.trackBy =item.uuid;
        return item;
      }
    }
  })();