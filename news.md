---
layout: default
---

{% for item in site.news %}
  - <span class="date">{{ item.date }}</span> -- [{{item.title}}]({{ item.url }})
{% endfor %}{:.news}
