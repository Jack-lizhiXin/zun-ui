(function() {
    'use strict';
  
    /**
     * @ngdoc overview
     * @ngname horizon.dashboard.container.bigdataClusters.actions
     *
     * @description
     * Provides all of the actions for bigdataClusters.
     */
    angular.module('horizon.dashboard.container.bigdataClusters.actions',
      [
        'horizon.framework',
        'horizon.dashboard.container'
      ])
      .run(registerBigdataClusterActions);
  
    registerBigdataClusterActions.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.dashboard.container.bigdataClusters.actions.refresh.service',
      'horizon.dashboard.container.bigdataClusters.resourceType'
    ];
  
    function registerBigdataClusterActions(
      registry,
      gettext,
      refreshBigdataClusterService,
      resourceType
    ) {
      var bigdataClustersResourceType = registry.getResourceType(resourceType);
  
      // FIXME(shu-mutow): refresh action is dummy. remove it when add other action.
      bigdataClustersResourceType.itemActions
        .append({
          id: 'refreshBigdataClusterAction',
          service: refreshBigdataClusterService,
          template: {
            text: gettext('Refresh')
          }
        });
    }
  
  })();