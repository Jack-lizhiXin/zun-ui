(function() {
    'use strict';

    angular.module('horizon.dashboard.container.pods.actions',
      [
        'horizon.framework',
        'horizon.dashboard.container'
      ])
      .run(registerPodActions);
  
    registerPodActions.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.dashboard.container.pods.actions.refresh.service',
      'horizon.dashboard.container.pods.resourceType'
    ];
  
    function registerPodActions(
      registry,
      gettext,
      refreshPodService,
      resourceType
    ) {
      var podsResourceType = registry.getResourceType(resourceType);
  
      podsResourceType.itemActions
        .append({
          id: 'refreshPodAction',
          service: refreshPodService,
          template: {
            text: gettext('Refresh')
          }
        });
    }
  
  })();