(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.jobs.actions')
      .factory('horizon.dashboard.container.jobs.actions.workflow', workflow);
  
    workflow.$inject = [
      'horizon.dashboard.container.jobs.basePath',
      'horizon.framework.util.i18n.gettext'
    ];
  
    function workflow(basePath, gettext) {
      var workflow = {
        init: init
      };
  
      function init(actionType, title, submitText) {
        var schema, form, model;
        var outputfilepaths = [
          {value: "/wordcount", name: gettext("/wordcount")},
          {value: "/terasort", name: gettext("/terasort")}
        ]
        var jobtemplates = [
          {value: "wordcount", name: gettext("wordcount")},
          {value: "terasort", name: gettext("terasort")}
        ];
        // schema
        schema = {
            type: "object",
            properties: {
              // info
              jobname: {
                title: gettext("Job name"),
                type: "string"
              },
              clustername: {
                title: gettext("Cluster name"),
                type: "string"
              },
              jobtemplate: {
                title: gettext("Job Template"),
                type: "string"
              },
              inputfile: {
                title: gettext("Input File"),
                type: "string"
              },
              outputfilepath: {
                title: gettext("Output File Path"),
                type: "string"
              },
              jar: {
                title: gettext("Jar"),
                type: "string"
              },
              template: {
                title: gettext('Template'),
                type: 'string'
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
                            key: "jobname",
                            placeholder: gettext("Name of the job to create.")
                          },
                          {
                            key: "clustername",
                            placeholder: gettext("Name of the Cluster.")
                          }
                        ]
                      },
                      {
                        type: "section",
                        htmlClass: "col-xs-12",
                        items: [
                          {
                            key: "jobtemplate",
                            type: "select",
                            titleMap: jobtemplates
                          }
                        ]
                      },
                      {
                        type: 'section',
                        htmlClass: 'col-sm-12',
                        items: [
                          {
                            key: "outputfilepath",
                            type: "select",
                            titleMap: outputfilepaths
                          }
                        ]
                      },
                      {
                        type: 'section',
                        htmlClass: 'col-sm-12',
                        items: [
                          {
                            type: 'template',
                            templateUrl: basePath + 'actions/workflow/file-upload.html',
                          }
                        ]
                      }
                    ]
                  }
                ]
            }
        ];

        model = {
            jobname: "",
            clustername: "",
            jobtemplate: "wordcount",
            outputfilepath: "/wordcount",
            template: ""
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