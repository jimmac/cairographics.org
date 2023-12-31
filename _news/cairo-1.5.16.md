---
title: cairo 1.5.16 snapshot available
layout: news
date: 2008-04-01
---
```

From: Carl Worth <cworth@cworth.org>
Date: Tue, 01 Apr 2008 16:25:32 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.16 now available

A new cairo snapshot 1.5.16 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.16.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.16.tar.gz.sha1
        46e08f540f0abf18dea4b889c82455c556c50f2e  cairo-1.5.16.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.16.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.16 tag which points to a commit named:
        5366c8f483dc7bd40b5d0a184c9b16826007c032

    which can be verified with:
        git verify-tag 1.5.16

    and can be checked out with a command such as:
        git checkout -b build 1.5.16

This is the eighth snapshot in cairo's unstable 1.5 series. It comes
less than two weeks after the 1.5.14 snapshot and it really is a
legitimate snapshot, (in spite of sharing this date with that of many
bogus announcements). The major change in this snapshot is that the
cairo-quartz backend is now officially "supported", including new API
to construct a font face from a CGFontRef . Also several bug fixes
have been fixed in many backends. See below for details.

This is definitely a "release candidate" snapshot for cairo 1.6.0. At
this point all significant items from the cairo 1.6.0 roadmap are
already in this snapshot. See:

http://cairographics.org/roadmap

At this point, the only change we are planning to make before cairo
1.6 is to change the setting of the infamous buggy_repeat flag,
(depending on what we learn from characterizing which X server/driver
versions exhibit bugs). We don't anticipate any other changes unless
people identify bugs. So please let us know if you find anything. We
plan to release cairo 1.6 by the end of this week.

Have fun with cairo!

-Carl

What's new in cairo 1.5.16 compared to cairo 1.5.14
===================================================
general
-------
Cairo now depends on pixman 0.10.0 which was recently released. The
latest pixman release can always be found alongside cairo releases at:

   http://cairographics.org/releases

Increase the precision of color stops for gradients. This fixes a
regression in gradient rendering that had been present since the
1.5.12 snapshot.

paginated (all of ps, pdf, svg, and win32-printing)
---------------------------------------------------
Fix assertion failure when some drawing elements are outside the page
boundaries, (this bug was noticed when using Inkscape to print a
drawing with landscape orientation to a portrait-oriented piece of
paper).

cairo-ps
--------
Fix of bug causing incorrect glyph positioning.

Fix handling of CAIRO_OPERATOR_SOURCE.

cairo-pdf
---------
More reduction of unnecessary digits of precision in PDF output.

Fix handling of CAIRO_OPERATOR_SOURCE.

cairo-svg
---------
Fix bug in usage of libpng that was preventing cairo_mask from working
with the svg backend.

Fix transformation of source pattern for cairo_stroke().

cairo-win32-printing
--------------------
Fix fallback resolution, (thanks again to inkscape users/developers
for helping us find this one).

cairo-quartz
------------
Mark the cairo-quartz backend as "supported" rather than
"experimental". This means the following:

    * The backend will now be built by default (if possible).

    * We are committing that the backend-specific API (as published in
      cairo-quartz.h) are stable and will be supported in all future
      cairo 1.x releases.

    * We are committing that the output quality of this backend
      compares favorably with other cairo backends, (and that quality
      is ensured by good results from the cairo test suite).

    * We recommend that distributions build and distribute this
      backend when possible.

Note that the cairo_quartz_image API (in cairo-quartz-image.h) is
still experimental, will not build by default, (pass
--enable-quartz-image to configure to build it), and may see API
changes before it is marked as "supported" in a future release.

Put the CAIRO_FONT_TYPE_ATSUI name back into
cairo-deprecated.h. Without this, the cairo 1.5.14 snapshot broke all
builds for applications using the C++ cairomm bindings (and perhaps
others) which have the CAIRO_FONT_TYPE_ATSUI name in their header
files. This breakage happened even for applications not using
cairo-quartz at all.

    Note: Even though the CAIRO_FONT_TYPE_ATSUI name is provided to
    avoid this build breakage, we still recommend that bindings and
    applications move to the new, and more accurate,
    CAIRO_FONT_TYPE_QUARTZ name.

Replace the implementation of cairo-quartz-font to use CGFont instead
of ATSUI. The CGFont API is a better fit than ATSUI, and this new
implementation is also more correct than the old one as well.

This also adds the following new API call:

cairo_public cairo_font_face_t *
cairo_quartz_font_face_create_for_cgfont (CGFontRef font);

The previous cairo_quartz_font_face_create_for_atsu_font_id function
continues to exist and is part of the supported API going
forward. (However, the old name of that same function, which was
cairo_atsui_font_face_create_for_atsu_font_id is officially
deprecated. Any source code using the old name should be updated to
use the new name.)

Fix transformation of source pattern for cairo_stroke().

cairo-win32
-----------
Avoid crash in create_similar is cairo_win32_surface_create fails.
```
