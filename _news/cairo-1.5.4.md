---
title: cairo 1.5.4 snapshot available
layout: news
date: 2007-12-05
---

From: Carl Worth <cworth@cworth.org>
Date: Wed, 05 Dec 2007 02:31:16 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.4 now available

A new cairo snapshot 1.5.4 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.4.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.4.tar.gz.sha1
        74f01fcea59631b077a823afd3a5146f63cb1c59  cairo-1.5.4.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.4.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.4 tag which points to a commit named:
        e0c0275e1764502cfd1d0e93e374b4ed396f0073

    which can be verified with:
        git verify-tag 1.5.4

    and can be checked out with a command such as:
        git checkout -b build 1.5.4

This is the second snapshot in cairo's unstable 1.5 series. It comes
just over 1 month after the 1.5.2 snapshot. There are no API changes
or additions in 1.5.4 compared to 1.5.2, but there are several bug
fixes, and some optimizations. Most of these apply to particular
backends. See below for details.

-Carl

Description of major changes from 1.5.2 to 1.5.4
================================================

General improvements
--------------------
Use less memory for spline approximation calculations.

Change how the tolerance value is interpreted with regard to
fallback-resolution. [XXX: Is this user-visible? If so, how? Will
follow up on the cairo mailing list for more details.]

Fix precision of floating-point values in vector-output backends to
avoid rounding errors with very small numbers.

Xlib improvements
-----------------
Fix bug in glyph rendering with xlib, (due to everything being clipped
out). This was a regression in the 1.5.2 snapshot that was visible in
the GIMP, for example. See:

cairo 1.5.2 causes font problems in GIMP 2.4 status bar and evolution 2.12.1
https://bugs.freedesktop.org/show_bug.cgi?id=13084

[XXX: Are we interpreting "cairo_new_path;cairo_clip" as a request to
clip everything? That wouldn't be consistent with how we treat
cairo_new_path;cairo_fill, for example. Will follow up on cairo
mailing list for more details.]

PostScript improvements
-----------------------
Fix bug leading to invalid PostScript files when rendering
text, (need "0 0 xyshow" instead of "0 xyshow").

Fix many issues with Type 3 fonts, including making the resulting text
extractable.

Quartz improvements
-------------------
Fix font metrics height value for ATSUI, (helps webkit on GTK+ OS X
layout nicely).

Fix gradients.

Fix EXTEND_NONE mode for patterns.

Fix cairo_quartz_surface_create to properly clear the new surface
in cairo_quartz_surface_create.

Fix to correctly handle 0x0 sized surfaces.

Optimize drawing of EXTEND_REPEAT patterns for OS X 10.5.
