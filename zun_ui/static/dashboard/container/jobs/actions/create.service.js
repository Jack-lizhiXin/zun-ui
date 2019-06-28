(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.jobs.actions')
      .factory('horizon.dashboard.container.jobs.actions.create.service', createJobService);
  
    createJobService.$inject = [
      'horizon.app.core.openstack-service-api.policy',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.jobs.actions.workflow',
      'horizon.dashboard.container.jobs.resourceType',
      'horizon.framework.util.actions.action-result.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.framework.util.q.extensions',
      'horizon.framework.widgets.form.ModalFormService',
      'horizon.framework.widgets.toast.service'
    ];
  
    function createJobService(
      policy, zun, workflow, resourceType,
      actionResult, gettext, $qExtensions, modal, toast
    ) {
  
      var message = {
        success: gettext('Request to create job %s has been accepted.')
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
        title = gettext('Create Job');
        submitText = gettext('Create');
        var config = workflow.init('create', title, submitText);
        return modal.open(config).then(submit);
      }
  
      function allowed() {
        return policy.ifAllowed({ rules: [['job', 'create_job']] });
      }
  
      function submit(context) {
        var inputfile = document.querySelectorAll('input[type=file]')[0].files[0];
        var jar = document.querySelectorAll('input[type=file]')[1].files[0];
        context.model.inputfile = inputfile;
        context.model.jar = jar;
        return zun.createJob(context.model, true).then(success, true);
      }
  
      function success(response) {
        toast.add('success', interpolate(message.success, [response.data.id]));
        var result = actionResult.getActionResult().created(resourceType, response.data.name);
        return result.result;
      }
    }
  })();