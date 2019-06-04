(function() {
    'use strict';
  
    /**
     * @ngdoc overview
     * @name horizon.dashboard.container.deployments
     * @ngModule
     * @description
     * Provides all the services and widgets require to display the deployments
     * panel
     */
    angular
      .module('horizon.dashboard.container.deployments', [
        'ngRoute',
        'horizon.dashboard.container.deployments.actions',
        'horizon.dashboard.container.deployments.details'
      ])
      .constant('horizon.dashboard.container.deployments.events', events())
      .constant('horizon.dashboard.container.deployments.resourceType', 'OS::Zun::Deployment')
      .run(run)
      .config(config);
  
    /**
     * @ngdoc constant
     * @name horizon.dashboard.container.deployments.events
     * @description A list of events used by Deployments
     * @returns {Object} Event constants
     */
    function events() {
      return {
        CREATE_SUCCESS: 'horizon.dashboard.container.deployments.CREATE_SUCCESS',
        DELETE_SUCCESS: 'horizon.dashboard.container.deployments.DELETE_SUCCESS'
      };
    }
  
    run.$inject = [
      '$filter',
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.deployments.basePath',
      'horizon.dashboard.container.deployments.resourceType',
      'horizon.dashboard.container.deployments.service'
    ];
  
    function run($filter, registry, zun, basePath, resourceType, deploymentService) {
      registry.getResourceType(resourceType)
      .setNames(gettext('Deployment'), gettext('Deployments'))
      // for detail summary view on table row.
      .setSummaryTemplateUrl(basePath + 'drawer.html')
      // for table row items and detail summary view.
      .setProperties(deploymentProperties())
      .setListFunction(deploymentService.getDeploymentsPromise)
      .tableColumns
      .append({
        id: 'deployment_name',
        priority: 1,
        sortDefault: true,
        urlFunction: deploymentService.getDetailsPath
      })
      .append({
        id: 'id',
        priority: 1
      })
      .append({
        id: 'deployment_namespace',
        priority: 1
      })
      .append({
        id: 'deployment_labels',
        priority: 1
      });
      // for magic-search
      registry.getResourceType(resourceType).filterFacets
      .append({
        'label': gettext('Namespace'),
        'name': 'deployment_namespace',
        'singleton': true
      })
      .append({
        'label': gettext('Name'),
        'name': 'deployment_name',
        'singleton': true
      })
      .append({
        'label': gettext('ID'),
        'name': 'id',
        'singleton': true
      })
      .append({
        'label': gettext('Labels'),
        'name': 'deployment_labels',
        'singleton': true
      });
    }
  
    function deploymentProperties() {
      return {
        'deployment_labels': {label: gettext('Labels'), filters: ['noValue', 'json'] },
        'deployment_name': { label: gettext('Name'), filters: ['noName'] },
        'id': { label: gettext('ID'), filters: ['noValue'] },
        'deployment_namespace': { label: gettext('Namespace'), filters: ['noValue'] },
        'metadata': {label: gettext('Metadata'), filters: ['noValue', 'json']}
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
      var path = $windowProvider.$get().STATIC_URL + 'dashboard/container/deployments/';
      $provide.constant('horizon.dashboard.container.deployments.basePath', path);
      $routeProvider.when('/project/container/deployments', {
        templateUrl: path + 'panel.html'
      });
    }
})();