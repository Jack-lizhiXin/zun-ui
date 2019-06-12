(function() {
    'use strict';
  
    angular
      .module('horizon.dashboard.container.pods', [
        'ngRoute',
        'horizon.dashboard.container.pods.actions'
      ])
      .constant('horizon.dashboard.container.pods.events', events())
      .constant('horizon.dashboard.container.pods.resourceType', 'OS::Zun::Pod')
      .run(run)
      .config(config);
  
    /**
     * @ngdoc constant
     * @name horizon.dashboard.container.pods.events
     * @description A list of events used by Pods
     * @returns {Object} Event constants
     */
    function events() {
      return {
        CREATE_SUCCESS: 'horizon.dashboard.container.pods.CREATE_SUCCESS',
        DELETE_SUCCESS: 'horizon.dashboard.container.pods.DELETE_SUCCESS'
      };
    }
  
    run.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.pods.basePath',
      'horizon.dashboard.container.pods.resourceType',
      'horizon.dashboard.container.pods.service'
    ];
  
    function run(registry, zun, basePath, resourceType, podService) {
      registry.getResourceType(resourceType)
      .setNames(gettext('Pod'), gettext('Pods'))
      // for detail summary view on table row.
      .setSummaryTemplateUrl(basePath + 'drawer.html')
      // for table row items and detail summary view.
      .setProperties(podProperties())
      .setListFunction(podService.getPodsPromise)
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
  
    function podProperties() {
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
      var path = $windowProvider.$get().STATIC_URL + 'dashboard/container/pods/';
      $provide.constant('horizon.dashboard.container.pods.basePath', path);
      $routeProvider.when('/project/container/pods', {
        templateUrl: path + 'panel.html'
      });
    }
  })();