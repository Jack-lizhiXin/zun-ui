(function() {
    'use strict';
  
    /**
     * @ngdoc overview
     * @ngname horizon.dashboard.container.jobs.actions
     *
     * @description
     * Provides all of the actions for jobs.
     */
    angular.module('horizon.dashboard.container.jobs.actions',
      [
        'horizon.framework',
        'horizon.dashboard.container'
      ])
      .run(registerJobActions);
  
    registerJobActions.$inject = [
      'horizon.framework.conf.resource-type-registry.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.dashboard.container.jobs.actions.refresh.service',
      'horizon.dashboard.container.jobs.resourceType'
    ];
  
    function registerJobActions(
      registry,
      gettext,
      refreshJobService,
      resourceType
    ) {
      var jobsResourceType = registry.getResourceType(resourceType);
  
      // FIXME(shu-mutow): refresh action is dummy. remove it when add other action.
      jobsResourceType.itemActions
        .append({
          id: 'refreshJobAction',
          service: refreshJobService,
          template: {
            text: gettext('Refresh')
          }
        });
    }
  
  })();