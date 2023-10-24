---
title: cairo 1.1.6 snapshot available
layout: news
date: 2006-05-04
---
```

From: Carl Worth <cworth@cworth.org>
Date: 4 May 2006
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo snapshot 1.1.6 now available

A new cairo snapshot 1.1.6 is now available from:

        http://cairographics.org/snapshots/cairo-1.1.6.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.1.6.tar.gz.sha1
        6c2c5dc688edca44f8087b6ffe8bfc1b7b1c3ba1  cairo-1.1.6.tar.gz

        http://cairographics.org/snapshots/cairo-1.1.6.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.1.6 tag which points to a commit named:
        7ba3b75efd56113411ed141a86675099ae82d5d5

    which can be verified with:
        git verify-tag 1.1.6

    and can be checked out with a command such as:
        git checkout -b build 1.1.6

Snapshot 1.1.6 (2006-05-04 Carl Worth <cworth@cworth.org>)
==========================================================
This is the third in a series of snapshots working toward the imminent
1.2 release of cairo. For a list of items still needing work on the
cairo 1.2 roadmap, please see:

        http://cairographics.org/ROADMAP

As can be seen in that list, there are no longer any API additions
left on the roadmap. Instead, there is a feature (PDF type 3 fonts) a
performance optimization (X server gradients) and a list of bug
fixes. This gives us a fair amount of freedom to cut the 1.2 release
at almost any point by deciding to defer remaining bug fixes to
subsequent maintenance releases such as 1.2.2 and 1.2.4.

Before we will do that, we must first be wiling to commit to all the
new API additions. As a heads-up, there are a couple of potential API
changes being considered. (Note that these are changes to new API
introduced during 1.1 so these will not introduce API
incompatibilities compared to the stable 1.0 series). The changes
being considered are:

  cairo_get_group_target: may acquire x and y offset return
        parameters. May also be eliminated in favor of
        cairo_get_target assuming its role

  cairo_pdf_surface_set_dpi:
  cairo_ps_surface_set_dpi:
  cairo_svg_surface_set_dpi: These functions may be removed in favor
        of a new cairo_surface_set_fallback_resolution

Additionally there is the possibility of a slight change in the
semantics of cairo_set_line_width. We believe the current behavior of the sequence:

        cairo_set_line_width; ... change CTM ...; cairo_stroke;

is buggy. It is currently behaving the same as:

        ... change CTM ...; cairo_set_line_width; cairo_stroke;

We are considering fixing this bug before 1.2 with the hope that
nobody is already relying on the buggy behavior described here. Do
shout if you suspect you might be in that position.

This snapshot is backwards-compatible with the 1.0 series---it makes a
few API additions but does not remove any API. See a few paragraphs
below for details on what's new in 1.1.6.

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

What's new in 1.1.6 compared to 1.1.4
=====================================
API additions
-------------
The long-awaited group-rendering support is now available with the
following function calls:

        cairo_push_group
        cairo_push_group_with_content
        cairo_pop_group
        cairo_pop_group_to_source
        cairo_get_group_target

This API provides a much more convenient mechanism for doing rendering
to an intermediate surface without the need to manually create a
temporary cairo_surface_t and a temporary cairo_t and clean them up
afterwards.

Add the following missing get function to complement
cairo_surface_set_device_offset:

        cairo_surface_get_device_offset

PDF backend (API addition)
--------------------------
The PDF backend now provides for per-page size changes, (similar to
what the PostScript backend got in the 1.1.4 snapshot). The new API
is:

        cairo_pdf_surface_set_size

Xlib backend (API additions)
----------------------------
The following functions have been added to allow the extraction of
Xlib surface:

        cairo_xlib_surface_get_display
        cairo_xlib_surface_get_drawable
        cairo_xlib_surface_get_screen
        cairo_xlib_surface_get_visual
        cairo_xlib_surface_get_depth

XCB backend (experimental)
--------------------------
Update backend so that it now compiles with the recent XCB 0.9 release.

Bug fixes and memory leak cleanup
---------------------------------
Various little things, nothing too significant though.
```
