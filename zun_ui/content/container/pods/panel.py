from django.utils.translation import ugettext_lazy as _
import horizon


class Pods(horizon.Panel):
    name = _("Pods")
    slug = "container.pods"