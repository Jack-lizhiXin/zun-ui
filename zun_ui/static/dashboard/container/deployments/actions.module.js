(function() {
    'use strict';
  
    /**
     * @ngdoc overview
     * @ngname horizon.dashboard.container.deployments.actions
     *
     * @description
     * Provides all of the actions for deployments.
     */
    angular.module('horizon.dashboard.container.deployments.actions',
      [
        'horizon.framework',
        'horizon.dashboard.container'
      ])
      .run(registerDeploymentActions);
  
    registerDeploymentActions.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.dashboard.container.deployments.actions.refresh.service',
      'horizon.dashboard.container.deployments.resourceType'
    ];
  
    function registerDeploymentActions(
      registry,
      gettext,
      refreshDeploymentService,
      resourceType
    ) {
      var deploymentsResourceType = registry.getResourceType(resourceType);
  
      // FIXME(shu-mutow): refresh action is dummy. remove it when add other action.
      deploymentsResourceType.itemActions
        .append({
          id: 'refreshDeploymentAction',
          service: refreshDeploymentService,
          template: {
            text: gettext('Refresh')
          }
        });
    }
  
})();