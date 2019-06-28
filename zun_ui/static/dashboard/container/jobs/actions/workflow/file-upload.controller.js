(function() {
    'use strict';

    angular
      .module('horizon.dashboard.container.jobs.actions')
      .controller('horizon.dashboard.container.jobs.actions.workflow.fileUploadController', fileUploadController);
  
    fileUploadController.$inject = [
      '$scope'
    ];

  
    function fileUploadController($scope) {
      var ctrl = this;
      ctrl.template = "";
      ctrl.onTemplateChange = onTemplateChange;
           
      // var file1 = document.querySelector('#file1');
      // file1.addEventListener('change', function () {
      //   var fileObj = file1.files[0];
      //   console.log('fileobj', fileObj)
      //   var formData = new FormData();
      //   formData.append('file', fileObj);
      //   $.ajax({
      //       url: "/dashboard/project/container/jobs/upload",
      //       type: "post",
      //       dataType: "json",
      //       data: formData,
      //       async: false,
      //       cache: false,
      //       contentType: false,
      //       processData: false,
      //       // headers:{ "X-CSRFtoken": $.cookie("csrftoken")},
      //       success: function (json_data) {
      //           alert("success!");
      //       },
      //   });
      // })
  
      function onTemplateChange(template) {
        $scope.model.template = template;
      }
    }
})();