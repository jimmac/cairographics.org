---
title: cairo 1.5.10 snapshot available
layout: news
date: 2008-02-20
---

From: Carl Worth <cworth@cworth.org>
Date: Wed, 20 Feb 2008 10:22:17 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.10 now available

A new cairo snapshot 1.5.10 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.10.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.10.tar.gz.sha1
        8c97a24f3297bade49508d833cf9218f42e88b8c  cairo-1.5.10.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.10.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.10 tag which points to a commit named:
        0f2ecb5ec65ff13c3aafbe57600c1906f3fe7978

    which can be verified with:
        git verify-tag 1.5.10

    and can be checked out with a command such as:
        git checkout -b build 1.5.10

This is the fifth snapshot in cairo's unstable 1.5 series. It comes 3
weeks after the 1.5.8 snapshot. This snapshot adds one new API
function, (cairo_has_current_point), and the usual mix of
improvements, (more efficient PostScript/PDF output, optimized
stroking), and fixes (more robust error-handling, etc.).

With this snapshot we're getting *really* close to cairo 1.6. The
number of test-suite failures is rapidly approaching zero and the
list of things still needing to be done is getting very short.

I am a bit disappointed to not have the change from 16.16 fixed point
to 24.8 fixed point in this snapshot. We did a ton of work to make
this possible, (including fixing the infinite loop bug it was exposing
earlier), and I even had the change in place just before releasing the
snapshot. But at the last moment we noticed that the change caused
some regressions in PS/PDF/SVG rendering, (pattern offsets are wrong
at least), so we pulled it out. But look for another snapshot soon
with that change. And see details below on what *did* make it in.

Do have fun with this. And try your best to break it. We're especially
interested in learning of any regressions in quality or performance of
1.5.10 compared to any 1.4.x release of cairo.

Enjoy,

-Carl

What's new in cairo 1.5.10 compared to cairo 1.5.8
==================================================
New API
-------
Add a new function to query if there is a current point:

cairo_bool_t
cairo_has_current_point (cairo_t *cr);

There is no current point immediately after cairo_create(), nor after
cairo_new_path() or cairo_new_sub_path(). There is a current point
after any of the path-creation functions, (cairo_move_to,
cairo_line_to, cairo_curve_to, etc.).

With this new function, we also revert the change of the return type
of cairo_get_current_point from cairo 1.5.8, (it's now a void function
again).

Optimizations
-------------
Optimize stroking code to avoid repeated calculation of redundant
values, (particularly significant for very large, offscreen paths).

General fixes
-------------
Patch a few more potential buffer overruns, (due to integer
overflow).

Many fixes and improvements to cairo's error-handling, (ensure that
correct error values are returned, clean up memory leaks on
error-handling paths, etc.).

Fix a potential infinite loop when stroking a spline with a pen that
has been transformed to a line segment.

Remove treating NULL as a synonym for a valid cairo_font_options_t*
with default values, (a change that had been introduced as of cairo
1.5.8).

Remove the altered handling of tolerance and fallback-resolution that
had been introduced as of cairo 1.5.4.

cairo-xlib
----------
Pass the original Drawable, (as opposed to the root window), to
XCreatePixmap when creating a similar surface. This gives the X server
more information so that it can be clever and efficient.

cairo-pdf
---------
Fix the rendering of repeating and reflecting patterns.

Ensure miter limit is always >= 1, (smaller limits are not meaningful,
but they can cause some PDF viewers to fail to display pages).

Generate more efficient output when the same path is used for both
fill and stroke.

cairo-ps
--------
Start sharing much of the cairo-pdf code rather than implementing very
similar code in cairo-ps.

Implement native support for repeating and reflecting linear
gradients.

Implement reflected surface patterns.

Ensure miter limit is always >= 1, (smaller limits are not meaningful,
but they can cause some PostScript viewers to crash).

Generate PostScript that will perform more efficiently and use less
memory on printers, (use currentfile instead of a giant string array
for image data, and avoid using PostScript patterns for paint() and
fill() when possible).

cairo-svg
---------
Avoid unnecessary rasterization when copying a "similar" surface to
another svg surface, (allow the SOURCE operator to be implemented with
all-vector operations if there are no underlying objects).

cairo-atsui
-----------
Eliminate infinite loop when attempting to render an empty string.
