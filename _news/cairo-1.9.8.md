---
title: cairo 1.9.8 snapshot available
layout: news
date: 2010-06-12
---
From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Sun, 13 Jun 2010 12:26:33 +0100
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.9.8 now available

A new cairo snapshot 1.9.8 is now available from:

http://cairographics.org/snapshots/cairo-1.9.8.tar.gz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.9.8.tar.gz.sha1
25f1a445ac0e2b33355ab9bc046b4ee7639554a1  cairo-1.9.8.tar.gz

http://cairographics.org/snapshots/cairo-1.9.8.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.9.8 tag which points to a commit named:
3a20b10cd0d94406fbd5fe3bb3d4820a95364537

    which can be verified with:
git verify-tag 1.9.8

    and can be checked out with a command such as:
git checkout -b build 1.9.8

One major API change since the last snapshot, and a whole slew of bugs
fixed and inconsistencies eliminated. Far too many bugs fixed to
individually identify. We need to thank Benjamin Otte for his fantastic
work on the cairo-gl backend making it faster and more robust, Andrea
Canciani for finding so many bugs and developing test cases for them, as
well fixing them. And last but not least we must all thank Adrian Johnson for
continuing to eliminate bugs and improving the PostScript and PDF backends.

This snapshot represents almost 4 months of bug fixing, bringing Cairo to
a point where we consider it almost ready to be a candidate for release.
There are a few known bugs left to be fixed, being tracked in
https://bugs.freedesktop.org/show_bug.cgi?id=24384, so please give Cairo a
whirl and report any regressions. The plan is to release a new snapshot
every other week leading to a 1.10 release with a target date of
2010-08-16.

-Chris

API additions
-------------
  CAIRO_FORMAT_RGB16_565

    16 bit devices still remain popular, and so with great demand,
    CAIRO_FORMAT_RGB16_565 has been restored enabling applications to create
    and use 16 bit images as sources and render targets.

  cairo_surface_create_for_rectangle()

    It is common practice to cut an image up into many smaller pieces and use
    each of those as a source - a technique called texture atlasing.
    cairo_surface_create_for_rectangle() extends Cairo to directly support use
    these subregions of another cairo_surface_t both as a source and as a render
    target.

  cairo_region_create()
  cairo_region_create_rectangle()
  cairo_region_create_rectangles()
  cairo_region_copy()
  cairo_region_reference()
  cairo_region_destroy()
  cairo_region_equal()
  cairo_region_status()
  cairo_region_get_extents()
  cairo_region_num_rectangles()
  cairo_region_get_rectangle()
  cairo_region_is_empty()
  cairo_region_contains_rectangle()
  cairo_region_contains_point()
  cairo_region_translate()
  cairo_region_subtract()
  cairo_region_subtract_rectangle()
  cairo_region_intersect()
  cairo_region_intersect_rectangle()
  cairo_region_union()
  cairo_region_union_rectangle()

    The Cairo region API was actually added a couple of snapshots ago, but we
    forgot to mention it at the time. A simple API for the handling of
    rectangular pixel-aligned regions by Soeren Sandmann.


Backend-specific improvements
-----------------------------
cairo-gl

  Benjamin Otte made more than 300 commits in which he refactored the cairo-gl
  backend, reducing a lot of code duplication and enabled him to begin working
  on improving performance by reducing state changes and associated overhead.

cairo-xlib

  Access to the underlying connection to the Display is now thread-safe
  enabling cairo-xlib to be used in a multi-threaded application without fear
  of random corruption. Thanks Benjamin Otte!

  cairo-xlib will now attempt to use PolyModeImprecise when compositing
  trapezoids (i.e. a fill or a stroke operation with a non-trivial path) which
  should allow hardware drivers more scope for accelerating the operation at
  the cost of potentially incurring minute rendering errors. The mode can be
  forced back to PolyModePrecise by setting the antialias parameter to
  CAIRO_ANTIALIAS_SUBPIXEL.

cairo-svg

  A notable improvement was contributed by Alexander Shulgin to enable SVG to
  reference external image through the use an extended MIME data type.
