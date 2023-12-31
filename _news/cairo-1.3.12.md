---
title: cairo 1.3.12 snapshot available
layout: news
date: 2007-01-20
---
```

From: Carl Worth <cworth@cworth.org>
Date: 20 Jan 2007
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.3.12 now available

A new cairo snapshot 1.3.12 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.12.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.12.tar.gz.sha1
        d84b48e06b2499e894f81c42361650ab5e00b974  cairo-1.3.12.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.12.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.12 tag which points to a commit named:
        c34a1a75fdb886b7a69875fb92d30c6dfd9d39cb

    which can be verified with:
        git verify-tag 1.3.12

    and can be checked out with a command such as:
        git checkout -b build 1.3.12

The relentless march toward the cairo 1.4 release continues, (even if
slightly late out of the starting blocks in 2007). This is the sixth
development snapshot in the 1.3 series. It comes 4 weeks after the
1.3.10 snapshot.

What's new in cairo 1.3.12
==========================
Performance
-----------
As usual, this snapshot has some fun performance improvements to show
off:

image-rgba long-lines-uncropped-100  470.08 -> 4.95: 94.91x speedup
███████████████████████████████████████████████
image-rgb  long-lines-uncropped-100  461.60 -> 4.96: 93.02x speedup
██████████████████████████████████████████████

This 100x improvement, (and yes, that's 100x, not 100%), in the image
backend occurs when drawing large shapes where only a fraction of the
shape actually appears in the final result, (the rest being outside
the bounds of the destination surface). Many applications should see
speedups here, and the actual amount of speedup depends on the ratio
of non-visible to visible portions of geometry.

[Note: There remains a similar performance bug when drawing mostly
non-visible objects with the xlib backend. This is due to a similar
bug in the X server itself, but we hope a future cairo snapshot will
workaround that bug to get a similar speedup with the xlib backend.]

image-rgba       unaligned_clip-100    0.09 -> 0.06:  1.67x speedup
▍
image-rgb        unaligned_clip-100    0.09 -> 0.06:  1.66x speedup
▍

This speedup is due to further MMX optimization by Soeren Sandmann for
a case commonly hit when rendering PDF files, (and thanks to Jeff
Muizelaar for writing code to extract the test case for us).

There's another MMX optimization in this snapshot (without a fancy
speedup chart) by Dan Williams which improves compositing performance
specifically for the OLPC machine.

Thanks to Adrian Johnson, cairo's PDF output is now much more
efficient in the way it encodes text output. By reducing redundant
information and adding compression to text output streams, Adrian
achieved a ~25x improvement in the efficiency of encoding text in PDF
files, (was ~45 bytes per glyph and is now ~1.6 bytes per glyph).

Bug fixes
---------
In addition to those performance improvements, this snapshot includes
several bug fixes:

 * A huge number of bug fixes for cairo-atsui text rendering, (for mac
   OS X). These bugs affect font selection, glyph positioning, glyph
   rendering, etc. One noteworthy bug fixes is that
   cairo_select_font_face will no longer arbitrarily select bold nor
   italic when not requested, (at least not when using a standard CSS2
   font family name such as "serif", "sans-serif", "monospace", etc.).
   All these fixes are thanks to Brian Ewins who continues to do a
   great job as the new cairo-atsui maintainer.

 * Fix PDF output so that images that are scaled down no longer
   mysteriously repeat (Carl Worth).

 * Fix segfault on Mac OS X dues to attempt to measure extents of a
   zero-length string (Behdad Esfahbod).

 * Fix text extents to not include the size of initial/trailing
   non-inked characters (Behdad Esfahbod).

API tweaks
----------
Three functions have had API changes to improve consistency. Note that
the API functions being changed here are all functions that were
introduced as new functions during these 1.3.x snapshots. As always,
there will not be any API changes to functions included in a major
release (1.2.x, 1.4.x, etc.) of cairo.

The changes are as follows:

 * Rename of cairo_copy_clip_rectangles to cairo_copy_clip_rectangle_list.

 * Change cairo_get_dash_count to return an int rather than accepting a
   pointer to an int for the return value.

 * Change cairo_get_dash to have a void return type rather than
   returning cairo_status_t.

It's possible there will be one more round of changes to these
functions, (and perhaps cairo_get_color_stop as well), as we seek to
establish a unifying convention for returning lists of values.
```
