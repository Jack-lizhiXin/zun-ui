from django.conf.urls import url
from django.utils.translation import ugettext_lazy as _
from horizon.browsers import views

title = _("Deployments")
urlpatterns = [
    url('', views.AngularIndexView.as_view(title=title), name='index'),
]