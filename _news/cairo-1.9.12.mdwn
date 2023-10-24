---
title: cairo 1.9.12 snapshot available
layout: news
date: 2010-07-12
---

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Mon, 12 Jul 2010 12:48:33 +0100
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.9.12 now available

A new cairo snapshot 1.9.12 is now available from:

http://cairographics.org/snapshots/cairo-1.9.12.tar.gz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.9.12.tar.gz.sha1
486a0b6855aa63bcb333f6ac63307ae8647035ba  cairo-1.9.12.tar.gz

http://cairographics.org/snapshots/cairo-1.9.12.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.9.12 tag which points to a commit named:
aa4cd8287f47b4538e765e1b48dcbac19813a8a2

    which can be verified with:
git verify-tag 1.9.12

    and can be checked out with a command such as:
git checkout -b build 1.9.12

Snapshot 1.9.12 (2010-07-12)
============================

  A couple of weeks spent fixing those annoying bugs and cleaning up the build
  system; the list of outstanding tasks to complete for the stable release is
  finally shrinking. The chief bug fixer has been Benjamin Otte who not only
  made sure that the public API is consistent and being tested for its
  consistency, but also ensured that the documentation was up-to-date and
  spent time clarifying cases where even the Cairo developers have come
  unstuck in the past. Many thanks, Benjamin. However, he was not alone,
  as Andrea Canciani continued his fine work in isolating broken corner cases
  and proceeding to fix them, and tidying up the quartz backend. And last, but
  definitely not least, M Joonas Pihlaja tried building Cairo across a
  perverse range of systems and fixed up all the loose bits of code that came
  unravelled. Thanks everybody!

-Chris

API Changes
-----------

  cairo_surface_set_mime_data, cairo_surface_get_mime_data:

    The length parameter is now an unsigned long (as opposed to an unsigned
    int). The parameter is intended to be an equivalent to a size_t without
    requiring POSIX types and be large enough to store the size of the
    largest possible allocation.

  cairo_gl_surface_create_for_texture:

    This a new surface constructor for cairo-gl that explicitly enables
    render-to-texture for foreign, i.e. application, textures.

  cairo_region_xor, cairo_region_xor_rectangle

    A couple of utility routines add to the region handling interface for
    the purpose of replacing existing GdkRegion functionality.

Bugs fixes
----------

  https://bugs.launchpad.net/ubuntu/+source/cairo/+bug/600622

    Inkscape was caught in the act of attempting to modify a finished surface.
    Unfortunately, we had the ordering of our guards and assertions wrong and
    so an ordinary application error was triggering an assert in Cairo. This
    lead Benjamin to add a test case to ensure that the entire public API
    could handle erroneous input and then proceeded to fix a whole slew of
    uncovered bugs.


  https://bugs.freedesktop.org/show_bug.cgi?id=28888

    A regression introduced by the special casing of uploading images to an
    xlib surface in-place which was ignoring the translation applied to the
    image.
