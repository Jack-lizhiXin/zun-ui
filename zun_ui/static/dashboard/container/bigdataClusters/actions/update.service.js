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
      .factory('horizon.dashboard.container.bigdataClusters.actions.update.service', updateBigdataClusterService);
  
    updateBigdataClusterService.$inject = [
      'horizon.app.core.openstack-service-api.policy',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.dashboard.container.bigdataClusters.actions.workflow2',
      'horizon.dashboard.container.bigdataClusters.resourceType',
      'horizon.framework.util.actions.action-result.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.framework.util.q.extensions',
      'horizon.framework.widgets.form.ModalFormService',
      'horizon.framework.widgets.toast.service'
    ];
  
    function updateBigdataClusterService(
      policy, zun, workflow2, resourceType,
      actionResult, gettext, $qExtensions, modal, toast
    ) {
  
      var message = {
        success: gettext('BigdataCluster %s was successfully updated.')
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
  
      function perform(selected) {
        var title, submitText;
        title = gettext('Update');
        submitText = gettext('Update');
        var config = workflow2.init('update', title, submitText);
        config.model.id = selected.id;

        // load current data
        zun.getDeployment(selected.id).then(onLoad);
        function onLoad(response) {
            var deploymentInfo = response.data['id_deployment_info'];
            config.model.name = deploymentInfo[0].metadata.name ? deploymentInfo[0].metadata.name : "";
            config.model.namespace = deploymentInfo[0].metadata.namespace ? deploymentInfo[0].metadata.namespace : "";
            config.model['pods_number'] = deploymentInfo[2].status.replicas ? deploymentInfo[2].status.replicas : "";
            config.model.id = response.data.id;
            console.log(config.model);
          }
        return modal.open(config).then(submit);
      }
  
      function allowed() {
        return policy.ifAllowed({ rules: [['bigdataCluster', 'edit_bigdataCluster']] });
      }
  
      function submit(context) {
        var id = context.model.id;
        return zun.updateBigdataCluster(id, context.model).then(success);
      }
  
      function success(response) {
        console.log('res', response.data);
        response.data.id = response.data.id;
        toast.add('success', interpolate(message.success, [response.data.name]));
        var result = actionResult.getActionResult().created(resourceType, response.data.name);
        return result.result;
      }
    }
  })();