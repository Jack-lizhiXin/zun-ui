(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.bigdataClusters.actions')
      .factory('horizon.dashboard.container.bigdataClusters.actions.workflow2', workflow2);
  
    workflow2.$inject = [
      'horizon.dashboard.container.bigdataClusters.basePath',
      'horizon.framework.util.i18n.gettext'
    ];
  
    function workflow2(basePath, gettext) {
      var workflow2 = {
        init: init
      };
  
      function init(actionType, title, submitText) {
        var schema, form, model;
  
        // schema
        schema = {
            type: "object",
            properties: {
              // info
              name: {
                title: gettext("Name"),
                type: "string"
              },
              namespace: {
                title: gettext("Namespace"),
                type: "string"
              },
              pods_number: {
                title: gettext("Pods number"),
                type: "string"
              }
            }
        };
  
        // form
        form = [
            {
                type: "tabs",
                tabs: [
                  {
                    title: gettext("Info"),
                    //help: basePath + "containers/actions/workflow/info.help.html",
                    type: "section",
                    htmlClass: "row",
                    items: [
                      {
                        type: "section",
                        htmlClass: "col-xs-12",
                        items: [
                          {
                            key: "name",
                            placeholder: gettext("Name of the bigdataCluster to create.")
                          },
                          {
                            key: "namespace",
                            placeholder: gettext("Namespace of the bigdataCluster."),
                          }
                        ]
                      },
                      {
                        type: "section",
                        htmlClass: "col-xs-12",
                        items: [
                          {
                            key: "pods_number",
                            placeholder: gettext("Pods number of the bigdataCluster."),
                          }
                        ]
                      }
                    ]
                  }
                ]
              }
        ];
        


        model = {
            name: "",
            namespace: "",
            pods_number: "",
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
      return workflow2;
    }
  })();