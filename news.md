---
layout: default
---

{% for item in site.news | sort: 'date' | reverse %}
  - <span class="date">{{ item.date }}</span> -- [{{item.title}}]({{ item.url }})
{% endfor %}{:.news}
