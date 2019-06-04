(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.deployments.actions')
      .factory('horizon.dashboard.container.deployments.actions.workflow', workflow);
  
    workflow.$inject = [
      'horizon.dashboard.container.deployments.basePath',
      'horizon.framework.util.i18n.gettext'
    ];
  
    function workflow(basePath, gettext) {
      var workflow = {
        init: init
      };
  
      function init(actionType, title, submitText) {
        var schema, form, model;
  
        // schema
        schema = {
          type: 'object',
          properties: {
            template: {
              title: gettext('Template'),
              type: 'string'
            }
          }
        };
  
        // form
        form = [
          {
            type: 'section',
            htmlClass: 'row',
            items: [
              {
                type: 'section',
                htmlClass: 'col-sm-12',
                items: [
                  {
                    type: 'template',
                    templateUrl: basePath + 'actions/workflow/load-template.html',
                  }
                ]
              }
            ]
          }
        ]; // form
  
        model = {
          template: ''
        };
  
        var config = {
          title: title,
          submitText: submitText,
          schema: schema,
          form: form,
          model: model
        };
        return config;
      }
      return workflow;
    }
  })();