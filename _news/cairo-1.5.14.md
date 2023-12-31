---
title: cairo 1.5.14 snapshot available
layout: news
date: 2008-03-20
---
```

From: Carl Worth <cworth@cworth.org>
Date: Thu, 20 Mar 2008 17:08:01 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.14 now available

A new cairo snapshot 1.5.14 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.14.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.14.tar.gz.sha1
        af40870b3ec62bbdeaecdf3ea4cce23919fedc42  cairo-1.5.14.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.14.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.14 tag which points to a commit named:
        f4d4d7b3d0bd62af6ffd50ba9cd8df0b9a12be71

    which can be verified with:
        git verify-tag 1.5.14

    and can be checked out with a command such as:
        git checkout -b build 1.5.14

This is the seventh snapshot in cairo's unstable 1.5 series. It comes
3 weeks after the 1.5.12 snapshot. This snapshot includes support for
arbitrary X server visuals, (including PseudoColor), which was the
final remaining cairo-specific item on the cairo 1.6 roadmap. It also
includes a huge number of improvements to the cairo-quartz backend. So
this is effectively a cairo 1.6 release candidate. We expect very few
changes from now until 1.6 and only for specific bug fixes. See below
for more about what's new in cairo 1.5.14.

We do appreciate any testing and feedback you can provide. In
particular, if you know of a bug in cairo 1.5.14 that you'd like to
see fixed before 1.6.0 and that bug isn't exercised by the cairo test
suite, then please make loud noises on the cairo mailing list so that
we know about it.

Have fun with cairo!

-Carl

Changes from cairo 1.5.12 to 1.5.14
===================================

API Change
----------
Rename ATSUI font backend to Quartz font backend. This affects the
following usage:

--enable-atsui		-> --enable-quartz-font
CAIRO_HAS_ATSUI_FONT 	-> CAIRO_HAS_QUARTZ_FONT
CAIRO_FONT_TYPE_ATSUI	-> CAIRO_FONT_TYPE_QUARTZ

cairo_atsui_font_face_create_for_atsu_font_id ->
cairo_quartz_font_font_create_for_atsu_font_id

This API change is justified by the cairo-quartz backend still be
marked as "experimental" rather than "supported", (though this is one
step toward making the change to "supported" before 1.6). Cairo will
still provide ABI compatibility with the old symbol name, however.

paginated (all of ps, pdf, svg, and win32-printing)
---------------------------------------------------
Optimize by not analyzing an image surface for transparency more than
once, (previously all images were analyzed twice).

cairo-ps and cairo-pdf
----------------------
Avoiding emitting a matrix into the stroke output when unnecessary,
(making output size more efficient).

Reduce rounding error of path shapes by factoring large scale factors
out of the path matrix, (ensuring that a fixed-number of printed
digits for path coordinates contains as much information as possible).

Reduce excess digits for text position coordinates. This makes the
output file size much smaller without making the result any less
correct.

cairo-ps
--------
Eliminate bug causing extraneous text repetition on Linux PostScript
output in some cases.

See: Mozilla Bug 419917 – Printed page contents are reflected
inside bordered tables (Linux-only)

https://bugzilla.mozilla.org/show_bug.cgi?id=419917

Optimize output when EXTEND_PAD is used.

cairo-pdf
---------
Fix to not use fill-stroke operator with transparent fill, (else PDF
output doesn't match the cairo-defined correct result). See:

https://bugs.launchpad.net/inkscape/+bug/202096

cairo-svg
---------
Fix stroke of path with a non-solid-color source pattern:

http://bugs.freedesktop.org/show_bug.cgi?id=14556

cairo-quartz
------------
Fix text rendering with gradient or image source pattern.

Handling antialiasing correctly for cairo_stroke(), cairo_clip(), and
cairo_show_text()/cairo_show_glyphs().

Correctly handle gradients with non-identity transformations:

Fixes http://bugs.freedesktop.org/show_bug.cgi?id=14248

Add native implementation of REPEAT and REFLECT extend modes for
gradients.

Fix implementation for the "unbounded" operators, (CAIRO_OPERATOR_OUT,
_IN, _DEST_IN, and _DEST_ATOP).

Correctly handle endiannees in multi-architecture compiles on Mac OS
X.

Avoid behavior which would cause Core Graphics to print warnings to
the console in some cases.

cairo-win32
-----------
Fix handling of miter limit.

cairo-win32-printing
--------------------
Fix to not use a 1bpp temporary surface in some cases while printing,
(so grayscale data is preserved rather than just becoming black and
white).

cairo-xlib
----------
Add support for rendering to arbitrary TrueColor X server
visuals. This fixes at least the following bugs:

cairo doesn't support 8-bit truecolor visuals
https://bugs.freedesktop.org/show_bug.cgi?id=7735

cairo doesn't support 655 xlib format
https://bugs.freedesktop.org/show_bug.cgi?id=9719

Add support for rendering to 8-bit PseudoColor X server visuals. This
fixes the following bug:

Cairo doesn't support 8-bit pseudocolor visuals
https://bugs.freedesktop.org/show_bug.cgi?id=4945

Unresolved issues (must be fixed before cairo 1.6)
--------------------------------------------------
XXX: Need to decide if cairo_image_surface_create_for_data should be
documented and tested as supporting an image with a negative
stride. Also need to decide the correct return value for
cairo_format_stride_for_width in case of any error.
```
