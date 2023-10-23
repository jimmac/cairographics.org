---
layout: default
---
<picture class="pixels full">
    <source srcset="../assets/cairo-news-dark.png" media="(prefers-color-scheme: dark)">
    <img src="../assets/cairo-news.png">
</picture>

{% assign sorted_news = site.news | sort: 'date' | reverse %}
{% for item in sorted_news %}
  - <span class="date">{{ item.date | date: "%Y-%m-%d" }}</span> -- <span class="title">[{{ item.title }}]({{ item.url }})</span>
{% endfor %}{:.news}
