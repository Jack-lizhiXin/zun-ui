(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.deployments.actions')
      .factory('horizon.dashboard.container.deployments.actions.create.service', createDeploymentService);
  
    createDeploymentService.$inject = [
      'horizon.app.core.openstack-service-api.policy',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.deployments.actions.workflow',
      'horizon.dashboard.container.deployments.resourceType',
      'horizon.framework.util.actions.action-result.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.framework.util.q.extensions',
      'horizon.framework.widgets.form.ModalFormService',
      'horizon.framework.widgets.toast.service'
    ];
  
    function createDeploymentService(
      policy, zun, workflow, resourceType,
      actionResult, gettext, $qExtensions, modal, toast
    ) {
  
      var message = {
        success: gettext('Request to create deployment %s has been accepted.')
      };
  
      var service = {
        initAction: initAction,
        perform: perform,
        allowed: allowed
      };
  
      return service;
  
      //////////////
  
      function initAction() {
      }
  
      function perform() {
        var title, submitText;
        title = gettext('Create Deployment');
        submitText = gettext('Create');
        var config = workflow.init('create', title, submitText);
        return modal.open(config).then(submit);
      }
  
      function allowed() {
        return policy.ifAllowed({ rules: [['deployment', 'create_deployment']] });
      }
  
      function submit(context) {
        return zun.createDeployment(context.model, true).then(success, true);
      }
  
      function success(response) {
        toast.add('success', interpolate(message.success, [response.data.id]));
        var result = actionResult.getActionResult().created(resourceType, response.data.name);
        return result.result;
      }
    }
  })();