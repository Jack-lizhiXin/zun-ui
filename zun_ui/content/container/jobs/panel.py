from django.utils.translation import ugettext_lazy as _
import horizon


class Jobs(horizon.Panel):
    name = _("Jobs")
    slug = "container.jobs"