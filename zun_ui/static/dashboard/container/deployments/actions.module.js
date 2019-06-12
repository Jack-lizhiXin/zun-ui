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
      'horizon.dashboard.container.deployments.actions.create.service',
      'horizon.dashboard.container.deployments.actions.create2.service',
      'horizon.dashboard.container.deployments.actions.delete.service',
      'horizon.dashboard.container.deployments.resourceType'
    ];
  
    function registerDeploymentActions(
      registry,
      gettext,
      createDeploymentService,
      createDeploymentService2,
      deleteDeploymentService,
      resourceType
    ) {
      var deploymentsResourceType = registry.getResourceType(resourceType);

      deploymentsResourceType.globalActions
        .append({
          id: 'createDeploymentAction',
          service: createDeploymentService,
          template: {
            text: gettext('Create By Yaml')
          }
        });

        //  workflow2: create by property

        // .append({
        //   id: 'createDeploymentAction2',
        //   service: createDeploymentService2,
        //   template: {
        //     text: gettext('Create By Property')
        //   }
        // })
  
      deploymentsResourceType.itemActions
        .append({
          id: 'deleteDeploymentAction',
          service: deleteDeploymentService,
          template: {
            type: 'delete',
            text: gettext('Delete')
          }
        });
    }
})();