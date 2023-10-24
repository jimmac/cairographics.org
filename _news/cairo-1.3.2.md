---
title: cairo 1.3.2 snapshot available
layout: news
date: 2006-11-15
---

From: Carl Worth <cworth@cworth.org>
Date: 15 Nov 2006
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo snapshot 1.3.2 now available

A new cairo snapshot 1.3.2 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.2.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.2.tar.gz.sha1
        2d380e89dc4d1c5be1460884e953b01f42fd5c1a  cairo-1.3.2.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.2.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.2 tag which points to a commit named:
        804e20b55d049a26fe4d96bb6d79890c65e43ab5

    which can be verified with:
        git verify-tag 1.3.2

    and can be checked out with a command such as:
        git checkout -b build 1.3.2

This snapshot is a chance to play with some of the recent performance
improvements that have been made to cairo (see below). But we're
really just getting started and there should be a lot more performance
improvements coming soon.

I hope that this snapshot is just the beginning of a steady stream of
ever-improving cairo snapshots. Ideally, we would see a new cairo
snapshot every week or two, and each faster than the one
before. Please help us make that happen!

We do have several performance problems identified and patches in
progress for several issues that still aren't in this snapshot, so
there's definitely some more exciting stuff to come, (more about that
in my follow ups to the cairo list). But please test this snapshot out
and let us know if it helps performance for your applications or not.

Have fun with cairo, everybody!

-Carl

Snapshot 1.3.2 (2006-11-14 Carl Worth <cworth@cworth.org>)
==========================================================
This is the first development snapshot since the 1.2 stable series
branched off shortly after the 1.2.4 release in August 2006.

This snapshot includes all the bug fixes from the 1.2.6 release,
(since they originated here on the 1.3 branch first and were
cherry-picked over to 1.2). But more importantly, it contains some new
API in preparation for a future 1.4 release, and most importantly, it
contains several performance improvements.

The bug fixes will not be reviewed here, as most of them are already
described in the 1.2.6 release notes. But details for the new API and
some performance improvements are included here.

As with all snapshots, this is experimental code, and the new API
added here is still experimental and is not guaranteed to appear
unchanged in any future release of cairo.

API additions
-------------
Several new API additions are available in this release. There is a
common theme among all the additions in that they allow cairo to
advertise information about its state that it was refusing to
volunteer earlier. So this isn't groundbreaking new functionality, but
it is essential for easily achieving several tasks.

The new functions can be divided into three categories:

        Getting information about the current clip region
        -------------------------------------------------
        cairo_clip_extents
        cairo_copy_clip_rectangles
        cairo_rectangle_list_destroy

        Getting information about the current dash setting
        --------------------------------------------------
        cairo_get_dash_count
        cairo_get_dash

        Getting information from a pattern
        ----------------------------------
        cairo_pattern_get_rgba
        cairo_pattern_get_surface
        cairo_pattern_get_color_stop_rgba
        cairo_pattern_get_color_stop_count
        cairo_pattern_get_linear_points
        cairo_pattern_get_radial_circles

In each of these areas, we have new API for providing a list of
uniform values from cairo. The closest thing we had to this before was
cairo_copy_path, (which is rather unique in providing a list of
non-uniform data).

The copy_clip_rectangles/rectangle_list_destroy functions follow a
style similar to that of cairo_copy_path. Meanwhile, the dash and
pattern color stop functions introduce a new style in which there is a
single call to return the number of elements available (get_dash_count
and get_color_stop_count) and then a function to be called once to get
each element (get_dash and get_color_stop_rgba).

I'm interested in hearing feedback from users of these new API
functions, particularly from people writing language bindings. One
open question is whether the clip "getter" functionality should adopt
a style similar to that of the new dash and color_stop interfaces.

API deprecation
---------------
The CAIRO_FORMAT_RGB16_565 enum value has been deprecated. It never
worked as a format value for cairo_image_surface_create, and it wasn't
necessary for supporting 16-bit 565 X server visuals.

XCB backend changes
-------------------
The XCB backend has been updated to track the latest XCB API (which
recently had a 1.0 release).

New quartz backend
------------------
Vladimir Vukicevic has written a new "native quartz" backend which
will eventually replace the current "image-surface wrapping" quartz
backend. For now, both backends are available, (the old one is
"quartz" and the new one is "nquartz"). But it is anticipated that the
new backend will replace the old one and take on the "quartz" name
before this backend is marked as supported in a release of cairo.

New OS/2 backend
----------------
Doodle and Peter Weilbacher have contributed a new, experimental
backend for using cairo on OS/2 systems.

Performance improvements
------------------------
Here are some highlights from cairo's performance suite showing
improvements from cairo 1.2.6 to cairo 1.3.2. The command used to
generate this data is:

        ./cairo-perf-diff 1.2.6 HEAD

available in the perf/ directory of a recent checkout of cairo's
source, (the cairo-perf-diff script does require a git checkout and
will not work from a tar file---though ./cairo-perf can still be used
to generate a single report there and ./cairo-perf-diff-files can be
used to compare two reports).

Results are described below both for an x86 laptop (with an old Radeon
video card, recent X.org build, XAA, free software drivers), as well
as for a Nokia 770. First the x86 results with comments on each, (all
times are reported in milliseconds).

Copying subsets of an image surface to an xlib surface (much faster)
--------------------------------------------------------------------
 xlib-rgba              subimage_copy-512   10.50 ->   : 53.97x speedup
█████████████████████████████████████████████████████

Thanks to Christopher (Monty) Montgomery for this big performance
improvement. Any application which has a large image surface and is
copying small pieces of it at a time to an xlib surface, (imagine an
application that loads a single image containing all the "sprites" for
that application), will benefit from this fix. The larger the ratio of
the image surface to the portion being copied, the larger the benefit.

Floating-point conversion (3x faster)
-------------------------------------
 xlib-rgba  pattern_create_radial-16    27.75 ->   3.93 :  2.94x speedup
██
image-rgb   pattern_create_radial-16    26.06 ->   3.74 :  2.90x speedup
█▉

Thanks to Daniel Amelang, (and others who had contributed the idea
earlier), for this nice improvement in the speed of converting
floating-point values to fixed-point.

Text rendering (1.3 - 2x faster)
------------------------------
 xlib-rgba text_image_rgba_source-256  319.73 ->  62.40 :  2.13x speedup
█▏
image-rgb    text_solid_rgba_over-64     2.85 ->   0.88 :  1.35x speedup
▍
I don't think we've ever set out to improve text performance
specifically, but we did it a bit anyway. I believe the extra
improvement in the xlib backend is due to Monty's image copying fix
above, and the rest is due to the floating-point conversion speedup.

Thin stroke improvements (1.5x faster)
---------------------------------------------
image-rgb               world_map-800  1641.09 -> 414.77 :  1.65x speedup
▋
 xlib-rgba              world_map-800  1939.66 -> 529.94 :  1.52x speedup
▌

The most modest stuff to announce in this release is the 50%
improvement I made in the world_map case. This is in improvement that
should help basically anything that is doing strokes with many
straight line segments, (and the thinner the better, since that makes
tessellation dominate rasterization). The fixes here are to use a
custom quadrilateral tessellator rather than the generic tessellator
for straight line segments and the miter joins.

Performance results from the Nokia 770
--------------------------------------
 xlib-rgba          subimage_copy-512     55.88 ->     2.04 : 27.34x speedup
██████████████████████████▍
 xlib-rgb     text_image_rgb_over-256   1487.58 ->   294.43 :  5.05x speedup
████
image-rgb   pattern_create_radial-16     187.13 ->    91.86 :  2.04x speedup
█
 xlib-rgba              world_map-800  21261.41 -> 15628.02 :  1.36x speedup
▍

Here we see that the subimage_copy improvement was only about half as
large as the corresponding improvement on my laptop, (27x faster
compared to 54x) and the floating-point conversion fix also was quite
as significant, (2x compared to 3x). Oddly the improvement to text
rendering performance was more than twice as good (5x compared to
2x). I don't know what the reason for that is, but I don't think it's
anything anybody should complain about.
