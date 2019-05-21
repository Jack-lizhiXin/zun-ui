(function() {
    'use strict';
  
    /**
     * @ngdoc factory
     * @name horizon.dashboard.container.bigdataClusters.actions.create.service
     * @description
     * Service for the create bigdataCluster modal
     */
    angular
      .module('horizon.dashboard.container.bigdataClusters.actions')
      .factory('horizon.dashboard.container.bigdataClusters.actions.create.service', createBigdataClusterService);
  
    createBigdataClusterService.$inject = [
      'horizon.app.core.openstack-service-api.policy',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.bigdataClusters.actions.workflow',
      'horizon.dashboard.container.bigdataClusters.resourceType',
      'horizon.framework.util.actions.action-result.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.framework.util.q.extensions',
      'horizon.framework.widgets.form.ModalFormService',
      'horizon.framework.widgets.toast.service'
    ];
  
    function createBigdataClusterService(
      policy, zun, workflow, resourceType,
      actionResult, gettext, $qExtensions, modal, toast
    ) {
  
      var message = {
        success: gettext('Request to create bigdataCluster %s has been accepted.')
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
        title = gettext('Create BigdataCluster');
        submitText = gettext('Create');
        var config = workflow.init('create', title, submitText);
        return modal.open(config).then(submit);
      }
  
      function allowed() {
        return policy.ifAllowed({ rules: [['bigdataCluster', 'create_bigdataCluster']] });
      }
  
      function submit(context) {
        return zun.createBigdataCluster(context.model, true).then(success, true);
      }
  
      function success(response) {
        console.log('response.data');
        console.log(response.data);
        toast.add('success', interpolate(message.success, [response.data.id]));
        var result = actionResult.getActionResult().created(resourceType, response.data.name);
        return result.result;
      }
    }
  })();