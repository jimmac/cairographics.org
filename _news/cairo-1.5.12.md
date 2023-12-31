---
title: cairo 1.5.12 snapshot available
layout: news
date: 2008-02-28
---
```

From: Carl Worth <cworth@cworth.org>
Date: Thu, 28 Feb 2008 16:15:31 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.12 now available

A new cairo snapshot 1.5.12 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.12.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.12.tar.gz.sha1
        f101957fd0fbd76d9f670de95fc2a726b3d93262  cairo-1.5.12.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.12.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.12 tag which points to a commit named:
        3ec4b9a4fc96572f099d0e9679fec9e5eb97a32e

    which can be verified with:
        git verify-tag 1.5.12

    and can be checked out with a command such as:
        git checkout -b build 1.5.12

This is the sixth snapshot in cairo's unstable 1.6 series. It comes
1 week after the 1.5.10 snapshot. This snapshot includes the
long-awaited change from 16.16 to 24.8 fixed-point values, (see below
for why you should care and some caveats).  It also includes several
backend-specific bug fixes.

As always, we appreciate whatever testing can be done. The change to
24.8 coordinates is a fairly big change, (we found and fixed several
significant bugs after first making this change), so careful testing
will be particularly desired here.

The change to 24.8 coordinated was one of only very few requirements
on the short list of things to get done before 1.6. What remains is:

* Characterizing and working around an X server crash
  triggered by the extend-reflect test.

* Adding support for more X server visuals (including
          pseudocolor).

* Whatever needs to be done in pixman, (including lifting
          16-bit limits as discussed below).

So that's looking like cairo 1.6 is very close, (and will come sooner
with your help!). You're all getting 24 free hours tomorrow, perhaps
you'll want to spend some improving cairo?

Have fun with cairo everybody!

-Carl

24.8 fixed-point format
-----------------------
Cairo has always converted path coordinates to a fixed-point
representation very early in its processing. Historically, this has
been a 32-bit representation with 16 bits of integer for the
device-pixel grid and 16 bits of sub-pixel positioning. The choice of
16 bits for the integer coordinate space was based on the 16-bit limit
for X Window drawables.

This 16-bit limit has proven problematic for many applications. It's
an especially vexing problem when targeting non-X backends that don't
have any 16-bit restriction. But even when targeting cairo-xlib, it's
often desirable to draw a large shape, (say a background rectangle),
that extends beyond the surface bounds and expect it to fill the
surface completely, (rather than overflowing and triggering random
behavior).

Meanwhile, nobody has ever really needed 16 bits of sub-pixel
precision.

With this snapshot, the fixed-point system is still in place and is
still using a 32-bit representation, (future versions of cairo might
move entirely to floating-point when targeting PDF output for
example). But the representation now provides 24 bits of pixel
addressing and only 8 bits of sub-pixel positioning. This should give
a much less stifling space to many applications.

However, the underlying pixman library still has 16-bit limitations in
many places, (it has its roots in the X server as well). Until those
are also fixed, applications targeting cairo image surfaces, or
hitting software fallbacks when targeting other surfaces will still
encounter problems with device-space values needing more than 16
integer bits.

generic fixes
-------------
Add a few tests to the test suite to increase coverage.

Cleanup a few error-handling paths, (propagate error correctly).

cairo-ft
--------
Fix handling of font sizes smaller than 1 device pixel.

cairo-pdf
---------
Fix to properly save/restore clip when analyzing meta-surface
patterns, (fixing a couple of test-suite failures).

Implement native support for CAIRO_OPERATOR_SOURCE when the source
pattern is opaque.

Emit rectangles as PDF rectangles ("re" operator) rather than as
general paths.

cairo-ps
--------
Fix to work properly with the 16.16->24.8 change.

cairo-svg
---------
Fix CAIRO_EXTEND_REFLECT by using an image fallback, (there's no
direct SVG support for reflected patterns).

Fix the use of alpha-only masks, (such as CAIRO_FORMAT_A8).

cairo-quartz
------------
Add new API for efficiently using image data as a source:

cairo_surface_t *
cairo_quartz_image_surface_create (cairo_surface_t *image_surface);

cairo_surface_t *
cairo_quartz_image_surface_get_image (cairo_surface_t *surface);

For full documentation, see:

http://cairographics.org/manual/cairo-Quartz-Surfaces.html#cairo-quartz-image-surface-create

Several fixes for cairo_mask().

cairo-atsui
-----------
Change default from from Monaco to Helvetica to be more consistent
with other font backends.
```
