(function() {
    'use strict';
  
    angular
      .module('horizon.dashboard.container.bigdataClusters', [
        'ngRoute',
        'horizon.dashboard.container.bigdataClusters.actions'
      ])
      .constant('horizon.dashboard.container.bigdataClusters.events', events())
      .constant('horizon.dashboard.container.bigdataClusters.resourceType', 'OS::Zun::BigdataCluster')
      .run(run)
      .config(config);
  
    /**
     * @ngdoc constant
     * @name horizon.dashboard.container.bigdataClusters.events
     * @description A list of events used by BigdataClusters
     * @returns {Object} Event constants
     */
    function events() {
      return {
        CREATE_SUCCESS: 'horizon.dashboard.container.bigdataClusters.CREATE_SUCCESS',
        DELETE_SUCCESS: 'horizon.dashboard.container.bigdataClusters.DELETE_SUCCESS'
      };
    }
  
    run.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.bigdataClusters.basePath',
      'horizon.dashboard.container.bigdataClusters.resourceType',
      'horizon.dashboard.container.bigdataClusters.service'
    ];
  
    function run(registry, zun, basePath, resourceType, bigdataClusterService) {
      registry.getResourceType(resourceType)
      .setNames(gettext('BigdataCluster'), gettext('BigdataClusters'))
      // for detail summary view on table row.
      .setSummaryTemplateUrl(basePath + 'drawer.html')
      // for table row items and detail summary view.
      .setProperties(bigdataClusterProperties())
      .setListFunction(bigdataClusterService.getBigdataClustersPromise)
      .tableColumns
      .append({
        id: 'pods_name',
        priority: 1,
        sortDefault: true
      })
      .append({
        id: 'pods_namespace',
        priority: 1
      })
      .append({
        id: 'pods_labels',
        priority: 1
      });
      // for magic-search
      registry.getResourceType(resourceType).filterFacets
      .append({
        'label': gettext('Namespace'),
        'name': 'pods_namespace',
        'singleton': true
      })
      .append({
        'label': gettext('Name'),
        'name': 'pods_name',
        'singleton': true
      })
      .append({
        'label': gettext('Labels'),
        'name': 'pods_labels',
        'singleton': true
      });
    }
  
    function bigdataClusterProperties() {
      return {
        'pods_labels': {label: gettext('Labels'), filters: ['noValue', 'json'] },
        'pods_name': { label: gettext('Name'), filters: ['noName'] },
        'pods_namespace': { label: gettext('Namespace'), filters: ['noValue'] }
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
      var path = $windowProvider.$get().STATIC_URL + 'dashboard/container/bigdataClusters/';
      $provide.constant('horizon.dashboard.container.bigdataClusters.basePath', path);
      $routeProvider.when('/project/container/bigdataClusters', {
        templateUrl: path + 'panel.html'
      });
    }
  })();