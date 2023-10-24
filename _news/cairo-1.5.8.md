---
title: cairo 1.5.8 snapshot available
layout: news
date: 2008-01-30
---
```

From: Carl Worth <cworth@cworth.org>
Date: Wed, 30 Jan 2008 05:44:02 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.8 now available

A new cairo snapshot 1.5.8 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.8.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.8.tar.gz.sha1
        8ab70db0eec1db3b730537d9076ddabf7e0ba537  cairo-1.5.8.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.8.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.8 tag which points to a commit named:
        4ccb8cb29546432858e778e1b88cada1327f6f45

    which can be verified with:
        git verify-tag 1.5.8

    and can be checked out with a command such as:
        git checkout -b build 1.5.8

This is the fourth snapshot in cairo's unstable 1.5 series. It comes 2
weeks after the 1.5.6 snapshot. It adds a few new API functions. Most
notably all callers of cairo_image_surface_create_for_data should now
be calling cairo_format_stride_for_width to compute a legal stride
value.

With this snapshot we are getting extrmely close to a final 1.6.0
release. We would appreciate as much testing as possible so that we
can eliminate bugs before that release rather than after. So give this
snapshot a try and let us know how things go for you.

And have fun with cairo!

-Carl

Changes in cairo 1.5.8 since 1.5.6
==================================
New API in cairo 1.5.8
----------------------
We've added a new function that should be called to compute a legal
stride value before allocating data to be used with
cairo_image_surface_create_for_data:

int
cairo_format_stride_for_width (cairo_format_t	format,
       int		width);

We've also added a new cairo_path_extents function that can be used to
compute a bounding box for geometry such as a single line segment,
(contrast with cairo_path_extents and cairo_stroke_extents):

void
cairo_path_extents (cairo_t *cr,
    double *x1, double *y1,
    double *x2, double *y2);

And finally, we've added a function to allow for querying the
XRenderPictFormat of a cairo-xlib surface:

XRenderPictFormat *
cairo_xlib_surface_get_xrender_format (cairo_surface_t *surface);

API changes
-----------
Fix return types of cairo_surface_show_page and
cairo_surface_copy_page. This is an API change to functions that are
new in the 1.5 series, so not an API break compared to any stable
cairo release, (1.0.x, 1.2.x, 1.4.x).

Change the return type of cairo_get_current_point() from void to
cairo_status_t. This allows the caller to receive a
CAIRO_STATUS_NO_CURRENT_POINT value to distinguish the a current point
at the origin from no current point existing.

Performance improvement
-----------------------
Improve performance of clipping by using an optimized code path
internally, (with the ADD operator instead of IN).

General bug fixes
-----------------
Fix various cairo_*_extents functions to initialize the return-value
variables even in the case of a cairo_t in error.

Treat NULL as a legitimate value for cairo_font_options_t*. [XXX: On
discussion afterwards, we decided against this change so we plan to
remove this again before 1.6.0]

Fix rendering with CAIRO_ANTIALIAS_NONE to be more predictable, (that
is, to avoid seams appearing when geometry and imagery share an
identical edge). Portions of this fix are in the pixman library and
will appear in a future release of that library.

Avoid triggering an error for a font size of 0.

Miscellaneous changes
---------------------
Require pixman >= 0.9.6.

There has been a tremendous amount improvement to cairo's
documentation. We're delighted that 100% of the public API has at
least some documentation in the API reference manual. Many thanks to
Behdad Esfahbod and Nis Martensen for leading this effort.

cairo-pdf and cairo-ps
----------------------
Eliminate failure when a Type 1 font is embedded with an explicit
glyph 0.

cairo-pdf
---------
Implement a more correct and more efficient approach for patterns with
an extend mode of CAIRO_EXTEND_REFLECT.

cairo-ps
--------
Fix image masks to properly pack and pad mask bits.

cairo-quartz
------------
Take care to only use DrawTiledImage for integer-aligned images, (and
use slower paths to get the correct result in other cases).

cairo-win32
-----------
Fix for older versions of mingw.

Improve the handling of the clipping with the win32 and win32-printing
surfaces.

Fix rendering of non black/white text.
```
