from django.utils.translation import ugettext_lazy as _
import horizon


class BigdataClusters(horizon.Panel):
    name = _("BigdataClusters")
    slug = "container.bigdataClusters"