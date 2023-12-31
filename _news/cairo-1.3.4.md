---
title: cairo 1.3.4 snapshot available
layout: news
date: 2006-11-22
---
```

From: Carl Worth <cworth@cworth.org>
Date: 22 Nov 2006
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo snapshot 1.3.4 now available

A new cairo snapshot 1.3.4 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.4.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.4.tar.gz.sha1
        0c412d56c01ea5fcbcfeafdfc6f23b3772a9711e  cairo-1.3.4.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.4.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.4 tag which points to a commit named:
        143c56cb12ee5d0b0fbc5e4039dd4fc88764254d

    which can be verified with:
        git verify-tag 1.3.4

    and can be checked out with a command such as:
        git checkout -b build 1.3.4

What's new since 1.3.2?
=======================
This is the second development snapshot in the 1.3 series. It comes
one week after the 1.3.2 snapshot.

This snapshot has a couple of significant performance improvements,
and also adds new support for producing multi-page SVG output, (when
targeting SVG 1.2)---thanks to Emmanuel Pacaud. The details of the
performance improvements are as follows:

1. The long-awaited "new tessellator".

   The credit for this being an improvement goes to Joonas Pihlaja. He
   took my really slow code and really put it through its paces to get
   the dramatic performance improvement seen below (up to 38x faster
   on realistic cases, and more than 10x faster for the zrusin_another
   test).

   His own writeup of the work he did is quite thorough, but more than
   can be quoted here. Please see his post for the interesting details:

   http://lists.freedesktop.org/archives/cairo/2006-November/008483.html

   (Though note that this snapshot also includes some additional,
   significant improvements that were only sketched out in that
   email---see "Generating fewer trapezoids").

2. More floating-point improvements

   Daniel Amelang continues to work the magic he began in the 1.3.2
   snapshot. This time he short-circuits floating-point
   transformations by identity matrices and applies the earlier
   floating-to-fixed-point technique to the problem of rounding.

   The improvements here will primarily benefit text performance, and
   will benefit platforms without hardware floating-point more than
   those that have it, (some text tests show 20% improvement on an x86
   machine and closer to 80% improvement on arm).

The performance chart comparing 1.3.2 to 1.3.4 really speaks for
itself, (this is on an x86 laptop). This is quite a lot of progress
for one week:

 xlib-rgb    stroke_similar_rgba_over-256   74.99 1.45% ->   2.03 68.38%: 36.86x speedup
███████████████████████████████████▉
 xlib-rgb  stroke_similar_rgba_source-256   78.23 1.43% ->   3.30 67.05%: 23.71x speedup
██████████████████████▊
 xlib-rgba             tessellate-256-100  820.42 0.15% ->  35.06 2.84%: 23.40x speedup
██████████████████████▍
image-rgba             tessellate-256-100  819.55 0.32% ->  35.04 3.56%: 23.39x speedup
██████████████████████▍
 xlib-rgb      stroke_image_rgba_over-256   78.10 1.43% ->   4.33 65.56%: 18.04x speedup
█████████████████
 xlib-rgb    stroke_image_rgba_source-256   80.11 1.63% ->   5.75 63.99%: 13.94x speedup
█████████████
 xlib-rgba  zrusin_another_tessellate-415   89.22 0.35% ->   8.38 5.23%: 10.65x speedup
█████████▋
image-rgba  zrusin_another_tessellate-415   87.38 0.89% ->   8.37 5.22%: 10.44x speedup
█████████▍
image-rgba        zrusin_another_fill-415  117.67 1.34% ->  12.88 2.77%:  9.14x speedup
████████▏
 xlib-rgba        zrusin_another_fill-415  140.52 1.57% ->  15.79 2.88%:  8.90x speedup
███████▉
image-rgba              tessellate-64-100    9.68 3.42% ->   1.42 0.60%:  6.82x speedup
█████▉
 xlib-rgba              tessellate-64-100    9.78 4.35% ->   1.45 0.83%:  6.72x speedup
█████▊
 xlib-rgb     stroke_linear_rgba_over-256   46.01 2.44% ->   7.74 54.51%:  5.94x speedup
█████
 xlib-rgb   stroke_linear_rgba_source-256   48.09 2.15% ->   9.14 53.00%:  5.26x speedup
████▎
 xlib-rgb     stroke_radial_rgba_over-256   50.96 2.34% ->  12.46 47.99%:  4.09x speedup
███▏
 xlib-rgb   stroke_radial_rgba_source-256   53.06 1.57% ->  13.96 46.57%:  3.80x speedup
██▊
image-rgba  paint_similar_rgba_source-256    0.12 1.57% ->   0.08 9.92%:  1.42x speedup
▍
image-rgba    paint_image_rgba_source-256    0.12 2.49% ->   0.08 10.70%:  1.41x speedup
▍
image-rgba                  world_map-800  356.28 0.46% -> 275.72 1.15%:  1.29x speedup
▎
 xlib-rgba                  world_map-800  456.81 0.39% -> 357.95 1.39%:  1.28x speedup
▎
image-rgb               tessellate-16-100    0.09 0.57% ->   0.07 3.43%:  1.23x speedup
▎
image-rgba              tessellate-16-100    0.09 0.06% ->   0.07 2.46%:  1.23x speedup
▎
image-rgba        text_solid_rgb_over-256    5.39 4.01% ->   4.47 0.70%:  1.21x speedup
▎
image-rgba       text_solid_rgba_over-256    5.37 0.82% ->   4.45 0.75%:  1.21x speedup
▎
image-rgba        text_image_rgb_over-64     0.78 0.10% ->   0.65 0.74%:  1.20x speedup
▎
image-rgba       text_image_rgba_over-64     0.78 0.29% ->   0.65 0.68%:  1.19x speedup
▎
image-rgb         text_solid_rgb_over-64     0.76 2.45% ->   0.63 0.81%:  1.19x speedup
▎
image-rgba       text_solid_rgba_over-64     0.76 0.33% ->   0.64 0.66%:  1.19x speedup
▎
image-rgba     text_similar_rgba_over-256    5.99 4.72% ->   5.04 1.09%:  1.19x speedup
▎

We should point out that there is some potential for slowdown in this
snapshot. The following are the worst slowdowns reported by the cairo
performance suite when comparing 1.3.2 to 1.3.4:

image-rgba              subimage_copy-256    0.01 0.87% ->   0.01 3.61%:  1.45x slowdown
▌
 xlib-rgb        paint_solid_rgb_over-256    0.31 10.23% ->   0.38 0.33%:  1.26x slowdown
▎
image-rgba           box-outline-fill-100    0.01 0.30% ->   0.01 2.52%:  1.21x slowdown
▎
image-rgba        fill_solid_rgb_over-64     0.20 1.22% ->   0.22 1.59%:  1.12x slowdown
▏
image-rgb       fill_similar_rgb_over-64     0.21 1.04% ->   0.24 1.06%:  1.11x slowdown
▏
image-rgba        fill_image_rgb_over-64     0.21 1.19% ->   0.24 0.72%:  1.11x slowdown
▏
image-rgba      fill_similar_rgb_over-64     0.21 0.18% ->   0.24 0.30%:  1.11x slowdown
▏
image-rgb        fill_solid_rgba_over-64     0.22 1.66% ->   0.24 1.15%:  1.11x slowdown
▏
image-rgb         fill_image_rgb_over-64     0.21 0.14% ->   0.24 0.80%:  1.11x slowdown
▏
image-rgba       fill_image_rgba_over-64     0.22 1.34% ->   0.25 0.20%:  1.11x slowdown
▏
image-rgba       fill_solid_rgba_over-64     0.22 1.48% ->   0.24 0.95%:  1.11x slowdown
▏
image-rgb      fill_similar_rgba_over-64     0.22 1.13% ->   0.25 1.25%:  1.10x slowdown
▏

The 45% slowdown for subimage_copy is an extreme case. It's unlikely
to hit many applications unless they often use cairo_rectangle;
cairo_fill to copy a single pixel at a time. In any case, it shows a
worst-case impact of the overhead of the new tessellator. The other
slowdowns (~ 10%) are probably more realistic, and still very
concerning.

We will work to ensure that performance regressions like these are not
present from one major release of cairo to the next, (for example,
from 1.2 to 1.4).

But we're putting this 1.3.4 snapshot out there now, even with this
potential slowdown so that people can experiment with it. If you've
got complex geometry, we hope you will see some benefit from the new
tessellator. If you've got primarily simple geometry, we hope things
won't slowdown too much, but please let us know what slowdown you see,
if any, so we can calibrate our performance suite against real-world
impacts.
```
