from django.utils.translation import ugettext_lazy as _
import horizon


class Deployments(horizon.Panel):
    name = _("Deployments")
    slug = "container.deployments"