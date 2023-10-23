---
layout: default
---
<picture class="pixels full">
    <source srcset="../assets/cairo-news-dark.png" media="(prefers-color-scheme: dark)">
    <img src="../assets/cairo-news.png">
</picture>

{% assign sorted_news = site.news | sort: 'date' | reverse %}
<ul class="news">
{% for item in sorted_news %}
  <li><span class="title"><a href="{{ item.url }}">{{ item.title }}</a></span>
    <span class="date">{{ item.date | date: "%Y-%m-%d" }}</span>
  </li>
{%endfor%}
</ul>
