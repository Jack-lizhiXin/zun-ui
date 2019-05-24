(function() {
    'use strict';
  
    /**
     * @ngdoc overview
     * @ngname horizon.dashboard.container.deployments.details
     *
     * @description
     * Provides details features for deployment.
     */
    angular.module('horizon.dashboard.container.deployments.details',
                   ['horizon.framework.conf', 'horizon.app.core'])
    .run(registerDetails);
  
    registerDetails.$inject = [
      'horizon.dashboard.container.deployments.basePath',
      'horizon.dashboard.container.deployments.resourceType',
      'horizon.dashboard.container.deployments.service',
      'horizon.framework.conf.resource-type-registry.service'
    ];
  
    function registerDetails(
      basePath,
      resourceType,
      deploymentService,
      registry
    ) {
      registry.getResourceType(resourceType)
        .setLoadFunction(deploymentService.getDeploymentPromise)
        .detailsViews
        .append({
          id: 'deploymentDetailsOverview',
          name: gettext('Overview'),
          template: basePath + 'details/overview.html'
        });
    }
})();
