(function() {
    'use strict';
  
    angular
      .module('horizon.dashboard.container.bigdataClusters.actions')
      .factory('horizon.dashboard.container.bigdataClusters.actions.delete.service', deleteService);
  
    deleteService.$inject = [
      '$location',
      '$q',
      '$rootScope',
      'horizon.app.core.openstack-service-api.zun',
      'horizon.app.core.openstack-service-api.policy',
      'horizon.framework.util.actions.action-result.service',
      'horizon.framework.util.i18n.gettext',
      'horizon.framework.util.q.extensions',
      'horizon.framework.widgets.modal.deleteModalService',
      'horizon.framework.widgets.table.events',
      'horizon.framework.widgets.toast.service',
      'horizon.dashboard.container.bigdataClusters.resourceType',
      'horizon.dashboard.container.bigdataClusters.events'
    ];
  
    function deleteService(
      $location, $q, $rootScope, zun, policy, actionResult, gettext, $qExtensions, deleteModal,
      tableEvents, toast, resourceType, events
    ) {
      var scope;
      var context = {
        labels: null,
        deleteEntity: deleteEntity,
        successEvent: events.DELETE_SUCCESS
      };
      var service = {
        initAction: initAction,
        allowed: allowed,
        perform: perform
      };
      var notAllowedMessage = gettext("You are not allowed to delete bigdataClusters: %s");
  
      return service;
  
      //////////////
  
      function initAction() {
      }
  
      function allowed() {
        // only row actions pass in bigdataCluster
        // otherwise, assume it is a batch action
        return $qExtensions.booleanAsPromise(true);
      }
  
      // delete selected resource objects
      function perform(selected, newScope) {
        scope = newScope;
        selected = angular.isArray(selected) ? selected : [selected];
        context.labels = labelize(selected.length);
        return $qExtensions.allSettled(selected.map(checkPermission)).then(afterCheck);
      }
  
      function labelize(count) {
        return {
          title: ngettext('Confirm Delete BigdataCluster',
                          'Confirm Delete BigdataClusters', count),
          /* eslint-disable max-len */
          message: ngettext('You have selected "%s". Please confirm your selection. Deleted bigdataCluster is not recoverable.',
                            'You have selected "%s". Please confirm your selection. Deleted bigdataClusters are not recoverable.', count),
          /* eslint-enable max-len */
          submit: ngettext('Delete BigdataCluster',
                           'Delete BigdataClusters', count),
          success: ngettext('Deleted BigdataCluster: %s.',
                            'Deleted BigdataClusters: %s.', count),
          error: ngettext('Unable to delete BigdataCluster: %s.',
                          'Unable to delete BigdataClusters: %s.', count)
        };
      }
  
      // for batch delete
      function checkPermission(selected) {
        return {promise: allowed(selected), context: selected};
      }
  
      // for batch delete
      function afterCheck(result) {
        var outcome = $q.reject();  // Reject the promise by default
        if (result.fail.length > 0) {
          toast.add('error', getMessage(notAllowedMessage, result.fail));
          outcome = $q.reject(result.fail);
        }
        if (result.pass.length > 0) {
          outcome = deleteModal.open(scope, result.pass.map(getEntity), context).then(createResult);
        }
        return outcome;
      }
  
      function createResult(deleteModalResult) {
        // To make the result of this action generically useful, reformat the return
        // from the deleteModal into a standard form
        var result = actionResult.getActionResult();
        deleteModalResult.pass.forEach(function markDeleted(item) {
          result.updated(resourceType, getEntity(item).uuid);
        });
        deleteModalResult.fail.forEach(function markFailed(item) {
          result.failed(resourceType, getEntity(item).uuid);
        });
        var indexPath = '/project/container/bigdataClusters';
        var currentPath = $location.path();
        if (result.result.failed.length === 0 && result.result.updated.length > 0 &&
            currentPath !== indexPath) {
          $location.path(indexPath);
        } else {
          $rootScope.$broadcast(tableEvents.CLEAR_SELECTIONS);
          return result.result;
        }
      }
  
      function getMessage(message, entities) {
        return interpolate(message, [entities.map(getName).join(", ")]);
      }
  
      function getName(result) {
        return getEntity(result).name;
      }
  
      // for batch delete
      function getEntity(result) {
        return result.context;
      }
  
      // call delete REST API
      function deleteEntity(uuid) {
        return zun.deleteBigdataCluster(uuid, true);
      }
    }
  })();