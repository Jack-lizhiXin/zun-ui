(function() {
    'use strict';

    angular.module('horizon.dashboard.container.bigdataClusters.details',
                   ['horizon.framework.conf', 'horizon.app.core'])
    .run(registerDetails);
  
    registerDetails.$inject = [
      'horizon.dashboard.container.bigdataClusters.basePath',
      'horizon.dashboard.container.bigdataClusters.resourceType',
      'horizon.dashboard.container.bigdataClusters.service',
      'horizon.framework.conf.resource-type-registry.service'
    ];
  
    function registerDetails(
      basePath,
      resourceType,
      bigdataClusterService,
      registry
    ) {
      registry.getResourceType(resourceType)
        .setLoadFunction(bigdataClusterService.getBigdataClusterPromise)
        .detailsViews
        .append({
          id: 'bigdataClusterDetailsOverview',
          name: gettext('Overview'),
          template: basePath + 'details/overview.html'
        });
    }
  })();