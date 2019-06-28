from django.conf.urls import url
from django.utils.translation import ugettext_lazy as _
from horizon.browsers import views
from django.views.decorators.csrf import csrf_exempt

title = _("Jobs")
urlpatterns = [
    url('', views.AngularIndexView.as_view(title=title), name='index')
]