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
  <li><a href="{{ item.url | prepend: site.baseurl }}"><span class="title">{{ item.title }}</span>
    <span class="date">{{ item.date | date: "%Y-%m-%d" }}</span></a>
  </li>
{%endfor%}
</ul>
