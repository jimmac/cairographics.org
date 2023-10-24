---
title: cairo 1.5.6 snapshot available
layout: news
date: 2008-01-16
---

From: Carl Worth <cworth@cworth.org>
Date: Wed, 16 Jan 2008 11:06:42 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.6 now available

A new cairo snapshot 1.5.6 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.6.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.6.tar.gz.sha1
        101382fc6ad2e702f74acf5486a1fea45affa608  cairo-1.5.6.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.6.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.6 tag which points to a commit named:
        d2a02d4f5ccb1c6dc7f8cca0c322b72f1638d25b

    which can be verified with:
        git verify-tag 1.5.6

    and can be checked out with a command such as:
        git checkout -b build 1.5.6

This is the third snapshot in cairo's unstable 1.5 series. It comes
about 6 weeks after the 1.5.4 snapshot. The only API addition compared
to 1.5.4 is very minor, (a new value CAIRO_STATUS_TEMP_FILE_ERROR).
The remainder of the changes are the usual accumulation of bug fixes
and improvements. See below for details.

We still have a few important fixes we'd like to finish up before we
make a 1.6.0 release. These include some long-standing failures, (like
running cairo with goofy X server visuals, or targeting alpha masks
with non-multiple-of-4-byte strides). Though, interestingly, a lot of
the work for those things will be in pixman not cairo.

But we'll be putting forth a renewed effort to try to get 1.6 ready by
the end of January, (some of us want to be able to relax at LCA). We
also expect that the Mozilla project will soon contribute any patches
that they want to see in cairo 1.6.

Have fun with cairo, everybody!

-Carl

Summary of changes from cairo 1.5.4 to cairo 1.5.6
==================================================
General bug fixes
-----------------
Fix handling of fonts that contain a mixture of outline and bitmapped
glyphs. There was a change in this handling in 1.5.4 that improved
some cases and also regressed other cases. Now, all cases should be
handled quite well.

Fix alignment issues that were causing SIGBUS failures on SPARC.

Fix a regression (which first appeared in 1.5.2) where stroking under
a large scale would sometimes incorrectly replace a miter join with a
bevel join. (Thanks to Keith Packard.)

Fix reporting of zero-sized extents to be {0,0} rather than
{INT_MAX,INT_MIN}. This avoids several integer overflow and
allocations of massive regions in some cases.

Fix failures of gradients with no stops, (quartz, ps, and pdf).

Fix handling of Type 1 fonts on Windows platforms.

Fix handling of Type 1 fonts with no specific family name in the font
itself, (generate a CairoFont-x-y name).

Handle NULL string values in cairo_show_text, cairo_show_glyphs, and
friends.

Many robustness improvements along error-handling paths, (thanks as
always, to Chris "ickle" Wilson).

Various other minor fixes.

Paginated backends (PDF/PostScript/win32-printing)
--------------------------------------------------
Avoid unnecessary rasterization when using a paginated surface as a
source, (such as drawing from one pdf surface to another).

Fix replaying of paginated surface with more than one level of push/pop
group.

cairo-xlib
----------
Fix xlib backend to not consider recent X server release as having a
buggy repeat implementation in the Render extension.

cairo-pdf
---------
Fix PDF output to avoid triggering very slow rendering in PDF viewers,
(avoid starting and stopping the content stream for each pattern
emission).

Support CAIRO_OPERATOR_SOURCE in cases where there is nothing below
the object being drawn.

Fix to avoid seams appearing between multiple fallback regions.

cairo-ps (PostScript)
---------------------
Use correct bounding box in Type 3 fonts.

Fix several bugs in cairo's PostScript output. These include making
the PostScript output more compatible with recent versions of
ghostscript that are more strict about Type 3 fonts, for
example.

Fix for win32 to not attempt to create temporary files in the root
directory, (where the user may not have write permission).

Avoid generating Level 3 PostScript if Level 2 is sufficient. Also,
add code in output documents to alert the user if Level 3 PostScript
is handed to a device that cannot handle PostScript beyond Level
2.

cairo-directfb
--------------
Various performance optimizations.

Fixed support for small surfaces (less than 8x8).

Provide support for environment variables CAIRO_DIRECTFB_NO_ACCEL to
disable acceleration and CAIRO_DIRECTFB_ARGB_FONT to enable ARGB fonts
instead of A8.

cairo-os2
---------
Allow OS/2 APIs instead of C library allocation functions.
