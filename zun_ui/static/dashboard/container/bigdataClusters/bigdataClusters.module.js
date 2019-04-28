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
        id: 'meta_name',
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
        id: 'cpu',
        priority: 3
      })
      .append({
        id: 'memory',
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
  
    function bigdataClusterProperties() {
      return {
        'addresses': {label: gettext('Addresses'), filters: ['noValue', 'json'] },
        'cluster_versionid': {label: gettext('Cluster Version ID'), filters: ['noValue'] },
        'containers': {label: gettext('Containers'), filters: ['noValue', 'json'] },
        'container_uuids': {label: gettext('Container UUIDs'), filters: ['noValue', 'json'] },
        'cpu': {label: gettext('CPU'), filters: ['noValue'] },
        'created_at': { label: gettext('Created'), filters: ['simpleDate'] },
        'id': {label: gettext('ID'), filters: ['noValue'] },
        'links': {label: gettext('Links'), filters: ['noValue', 'json'] },
        'memory': { label: gettext('Memory'), filters: ['noValue'] },
        'meta_labels': {label: gettext('Labels'), filters: ['noValue', 'json'] },
        'meta_name': { label: gettext('Name'), filters: ['noName'] },
        'project_id': { label: gettext('Project ID'), filters: ['noValue'] },
        'restart_policy': { label: gettext('Restart Policy'), filters: ['noValue'] },
        'status': { label: gettext('Status'), filters: ['noValue'] },
        'status_reason': { label: gettext('Status Reason'), filters: ['noValue'] },
        'updated_at': { label: gettext('Updated'), filters: ['simpleDate'] },
        'user_id': { label: gettext('User ID'), filters: ['noValue'] },
        'volumes_info': {label: gettext('Volumes Info'), filters: ['noValue', 'json'] }
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