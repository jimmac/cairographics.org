---
title: cairo 1.1.2 snapshot available
layout: news
date: 2006-04-25
---

From: Carl Worth <cworth@cworth.org>
Date: 25 Apr 2006
To: cairo@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.1.2 now available for testing

A new cairo snapshot 1.1.2 is now available from:

        http://cairographics.org/snapshots/cairo-1.1.2.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.1.2.tar.gz.sha1
        7551757bd758428242718638d690ac5d4edd7b28  cairo-1.1.2.tar.gz

        http://cairographics.org/snapshots/cairo-1.1.2.tar.gz.sha1.asc
        (signed by Carl Worth)

This is the first in a series of snapshots working toward the upcoming
1.2 release of cairo. (Subsequent snapshots will use successive even
numbers for the third digit, 1.1.4, 1.1.6, etc.) This snapshot is
backwards-compatible with the 1.0 series---it makes a few API
additions but does not remove any API. See a few paragraphs below
for details on what's new in 1.1.2.

What is cairo
=============
Cairo is a 2D graphics library with support for multiple output
devices. Currently supported output targets include the X Window
System, win32, and image buffers. Experimental backends include OpenGL
(through glitz), Quartz, XCB, PostScript and PDF file output.

Cairo is designed to produce consistent output on all output media
while taking advantage of display hardware acceleration when available
(for example, through the X Render Extension).

The cairo API provides operations similar to the drawing operators of
PostScript and PDF. Operations in cairo including stroking and filling
cubic Bézier splines, transforming and compositing translucent images,
and antialiased text rendering. All drawing operations can be
transformed by any affine transformation (scale, rotation, shear,
etc.).

Cairo has been designed to let you draw anything you want in a modern
2D graphical user interface.  At the same time, the cairo API has been
designed to be as fun and easy to learn as possible. If you're not
having fun while programming with cairo, then we have failed
somewhere---let us know and we'll try to fix it next time around.

Cairo is free software and is available to be redistributed and/or
modified under the terms of either the GNU Lesser General Public
License (LGPL) version 2.1 or the Mozilla Public License (MPL)
version 1.1.

Where to get more information about cairo
=========================================
The primary source of information about cairo is:

        http://cairographics.org/

The latest releases of cairo can be found at:

        http://cairographics.org/releases

Snapshots of in-development versions of cairo:

        http://cairographics.org/snapshots

The programming manual for using cairo:

        http://cairographics.org/manual

Mailing lists for contacting cairo users and developers:

        http://cairographics.org/lists

Answers to some frequently asked questions about cairo:

        http://cairographics.org/FAQ

What's new in 1.1.2 compared to the 1.0 series
==============================================

PostScript and PDF backends are no longer "experimental"
--------------------------------------------------------
The major theme of the 1.2 release is improved PostScript and PDF
backends for cairo. Unlike the 1.0 series, in the 1.2 series these
backends will not be marked as experimental and will be enabled by
default. We encourage people to test this snapshot and the PS/PDF
backends in particular as much as possible.

The PostScript and PDF output is not yet ideal.

 * One major problem with the PostScript output is that image
   fallbacks are used more often than strictly necessary, and the
   image fallbacks are at a lower resolution than desired, (the
   cairo_ps_surface_set_dpi call is ignored).

  * The major drawback of the current PDF backend implementation is
    its text support. Every glyph is represented by a filled path in
    the PDF file. The causes file sizes to be much larger and
    rendering to be much slower than desired.

It is anticipated that both of these shortcomings will see some
improvements before the final 1.2 release.

In spite of those shortcomings, we hope that the PS and PDF backends
will yield faithful results for pretty much any cairo operations you
can throw at them. Please let us know if you are getting obviously
"different" results from the PS/PDF backends than from the image or
xlib backends.

Other new experimental backends
-------------------------------
This snapshot includes three new backends that did not exist in the
1.0 series:

        * beos backend

        * directfb backend

        * svg backend

These are all currently marked "experimental" and are disabled by
default. But the SVG backend in particular has seen a lot of recent
development and is very close to passing the entire cairo test
suite. It is possible that this backend will become a fully supported
backend by the time of the cairo 1.2 release.

Public API additions
--------------------
There have been a few new API functions added to cairo, including:

New get_type functions for querying sub-types of object:

        cairo_surface_get_type
        cairo_pattern_get_type
        cairo_font_face_get_type
        cairo_scaled_font_get_type

More convenience in working with cairo_scaled_font_t with new getter
functions:

        cairo_scaled_font_get_font_face
        cairo_scaled_font_get_font_matrix
        cairo_scaled_font_get_ctm
        cairo_scaled_font_get_font_options

As well as a convenience function for setting a scaled font into a
cairo context:

        cairo_set_scaled_font

and a function to allow text extents to be queried directly from a
scaled font, (without requiring a cairo_surface_t or a cairo_t):

        cairo_scaled_font_text_extents

These new scaled font functions were motivated by the needs of the
pango library.

Finally, a new path-construction function was added which clears the
current point in preparation for a new sub path. This makes cairo_arc
easier to use in some situations:

        cairo_new_sub_path

Before the 1.2 release is final we do still plan a few more API
additions specifically motivated by the needs of Mozilla/Firefox.

Optimizations and bug fixes
---------------------------
Shortly after the 1.0 maintenance series branched off the mainline
there was a major rework of the cairo font internals. This should
provide some good performance benefits, but it's also another area
people should look at closely for potential regressions.

There has not yet been any widespread, systematic optimization of
cairo, but various performance improvements have been made, (and some
of them are fairly significant). So if some things seem faster than
1.0 then things are good. If there are any performance regressions
compared to 1.0 then there is a real problem and we would like to hear
about that.

There has been a huge number of bug fixes---too many to mention in
detail, (but I've attached the giant log below). Again, things should
be better, and never worse compared to 1.0. Please let us know if your
testing shows otherwise.

-Carl
