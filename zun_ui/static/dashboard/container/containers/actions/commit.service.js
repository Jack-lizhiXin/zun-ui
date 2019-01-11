/**
 * Licensed under the Apache License, Version 2.0 (the "License"); you may
 * not use self file except in compliance with the License. You may obtain
 * a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
 * License for the specific language governing permissions and limitations
 * under the License.
 */

(function() {
  'use strict';

  /**
   * @ngDoc factory
   * @name horizon.dashboard.container.containers.commit.service
   * @Description
   * commit container.
   */
  angular
    .module('horizon.dashboard.container.containers')
    .factory('horizon.dashboard.container.containers.commit.service', commitService);

  commitService.$inject = [
    '$q',
    'horizon.app.core.openstack-service-api.zun',
    'horizon.dashboard.container.containers.adminActions',
    'horizon.dashboard.container.containers.basePath',
    'horizon.dashboard.container.containers.resourceType',
    'horizon.dashboard.container.containers.validStates',
    'horizon.framework.util.actions.action-result.service',
    'horizon.framework.util.i18n.gettext',
    'horizon.framework.util.q.extensions',
    'horizon.framework.widgets.form.ModalFormService',
    'horizon.framework.widgets.toast.service'
  ];

  function commitService(
    $q, zun, adminActions, basePath, resourceType, validStates,
    actionResult, gettext, $qExtensions, modal, toast
  ) {

    // model
    var model = {
      id: "",
      name: "",
      image_driver: "Glance",
      reponame: ""
    };

    // schema
    var schema = {
      type: "object",
      properties: {
        reponame: {
          title: gettext("Name"),
          type: "string"
        }
      }
    };

    // form
    var form = [
      {
        type: 'section',
        htmlClass: 'row',
        items: [
          {
            type: 'section',
            htmlClass: 'col-sm-12',
            items: [
              {
                "key": "reponame",
                "placeholder": gettext("The repository name of the image.")
              }
            ]
          }
        ]
      }
    ];

    var message = {
      success: gettext('Container %s was successfully commited.')
    };

    var service = {
      initAction: initAction,
      allowed: allowed,
      perform: perform
    };

    return service;

    //////////////

    // include this function in your service
    // if you plan to emit events to the parent controller
    function initAction() {
    }

    function allowed(container) {
      var adminAction = true;
      if (zun.isAdmin()) {
        adminAction = adminActions.indexOf("commit") >= 0;
      }
      return $q.all([
        $qExtensions.booleanAsPromise(adminAction),
        $qExtensions.booleanAsPromise(
          validStates.commit.indexOf(container.status) >= 0
        )
      ]);
    }

    function perform(selected) {
      model.id = selected.id;
      model.name = selected.name;
      // modal config
      var config = {
        "title": gettext('Commit Container'),
        "submitText": gettext('Commit'),
        "schema": schema,
        "form": form,
        "model": model
      };
      return modal.open(config).then(submit);

      function submit(context) {
        var id = context.model.id;
        var name = context.model.name;
        var reponame = context.model.reponame;
        delete context.model.id;
        delete context.model.name;
        delete context.model.reponame;
        return zun.commitContainer(id, reponame).then(function() {
          toast.add('success', interpolate(message.success, [name]));
          var result = actionResult.getActionResult().updated(resourceType, id);
          return result.result;
        });
      }
    }
  }
})();
