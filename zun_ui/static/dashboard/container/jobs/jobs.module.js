(function() {
    'use strict';
  
    /**
     * @ngdoc overview
     * @name horizon.dashboard.container.jobs
     * @ngModule
     * @description
     * Provides all the services and widgets require to display the jobs
     * panel
     */
    angular
      .module('horizon.dashboard.container.jobs', [
        'ngRoute',
        'horizon.dashboard.container.jobs.actions'
      ])
      .constant('horizon.dashboard.container.jobs.events', events())
      .constant('horizon.dashboard.container.jobs.resourceType', 'OS::Zun::Job')
      .run(run)
      .config(config);
  
    /**
     * @ngdoc constant
     * @name horizon.dashboard.container.jobs.events
     * @description A list of events used by Jobs
     * @returns {Object} Event constants
     */
    function events() {
      return {
        CREATE_SUCCESS: 'horizon.dashboard.container.jobs.CREATE_SUCCESS',
        DELETE_SUCCESS: 'horizon.dashboard.container.jobs.DELETE_SUCCESS'
      };
    }
  
    run.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.jobs.basePath',
      'horizon.dashboard.container.jobs.resourceType',
      'horizon.dashboard.container.jobs.service'
    ];
  
    function run(registry, zun, basePath, resourceType, jobService) {
      registry.getResourceType(resourceType)
      .setNames(gettext('Job'), gettext('Jobs'))
      // for detail summary view on table row.
      .setSummaryTemplateUrl(basePath + 'drawer.html')
      // for table row items and detail summary view.
      .setProperties(jobProperties())
      .setListFunction(jobService.getJobsPromise)
      .tableColumns
      .append({
        id: 'name',
        priority: 1,
        sortDefault: true
      })
      .append({
        id: 'id',
        priority: 2
      })
      .append({
        id: 'status',
        priority: 1
      })
      .append({
        id: 'time',
        priority: 3
      });
      // for magic-search
      registry.getResourceType(resourceType).filterFacets
      .append({
        'label': gettext('ID'),
        'name': 'id',
        'singleton': true
      })
      .append({
        'label': gettext('Name'),
        'name': 'meta_name',
        'singleton': true
      })
      .append({
        'label': gettext('Status'),
        'name': 'status',
        'singleton': true
      });
    }
  
    function jobProperties() {
      return {
        'id': {label: gettext('ID'), filters: ['noValue'] },
        'name': { label: gettext('Name'), filters: ['noName'] },
        'status': { label: gettext('Status'), filters: ['noValue'] },
        'time': { label: gettext('Time'), filters: ['noValue'] }
      };
    }
  
    config.$inject = [
      '$provide',
      '$windowProvider',
      '$routeProvider'
    ];
  
    /**
     * @name config
     * @param {Object} $provide
     * @param {Object} $windowProvider
     * @param {Object} $routeProvider
     * @description Routes used by this module.
     * @returns {undefined} Returns nothing
     */
    function config($provide, $windowProvider, $routeProvider) {
      var path = $windowProvider.$get().STATIC_URL + 'dashboard/container/jobs/';
      $provide.constant('horizon.dashboard.container.jobs.basePath', path);
      $routeProvider.when('/project/container/jobs', {
        templateUrl: path + 'panel.html'
      });
    }
  })();