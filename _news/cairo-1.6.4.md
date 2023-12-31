---
title: cairo 1.6.4 release available
layout: news
date: 2008-04-11
---
```

From: Carl Worth <cworth@cworth.org>
Date: Fri, 11 Apr 2008 15:08:04 -0700
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo release 1.6.4 now available

The cairo community is wildly embarrassed to announce the 1.6.4
release of the cairo graphics library. This release reverts the xlib
locking change introduced in 1.6.2, (and the application crashes that
it caused).  The community would be glad to sack its current release
manager and is accepting applications for someone who could do the job
with more discipline.

We do hope you'll have fun with cairo, and we also hope that the
recent spike in traffic on the cairo-announce mailing list is now
officially over.

-Carl

Release 1.6.4 (2008-04-11 Carl Worth <cworth@cworth.org>)
=========================================================
A new cairo release 1.6.4 is now available from:

        http://cairographics.org/releases/cairo-1.6.4.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.6.4.tar.gz.sha1
        9d990fe39a125ceb07221623c237cd7015855d5c  cairo-1.6.4.tar.gz

        http://cairographics.org/releases/cairo-1.6.4.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.6.4 tag which points to a commit named:
        08a804806355d99d7968976d6afb98bbc0f2613d

    which can be verified with:
        git verify-tag 1.6.4

    and can be checked out with a command such as:
        git checkout -b build 1.6.4

Revert 'add missing locking in cairo-xlib'
------------------------------------------
This change was introduced in cairo 1.6.2, but also introduced a bug
which causes many cairo-xlib applications to crash, (with a
segmentation fault inside of XSetClipMask). Instead of attempting
another fix for the broken fix, the change in 1.6.2 has been
reverted. The original bug which the change was addressing has been
present since at least cairo 1.4, so it is not expected that leaving
this bug unfixed will cause any new problems for applications moving
from cairo 1.4 to cairo 1.6.

At this point, the code of cairo 1.6.4 differs from cairo 1.6.0 only
in the fix for the PostScript-printer crashes.

Tweak build to avoid linking with g++
-------------------------------------
Cairo 1.6.4 avoids a quirk in automake that was causing the cairo
library to be linked with g++ and linked against libstdc++ even when
only C source files were compiled for the library.

Cairo 1.6.4 still includes all the good things from cairo 1.6.0, so
that announcement is repeated here:

The cairo community is quite pleased to announce the 1.6.0 release of
the cairo graphics library. This is a major update to cairo, with new
features and enhanced functionality which maintains compatibility for
applications written using cairo 1.4, 1.2, or 1.0. We recommend that
anybody using a previous version of cairo upgrade to cairo 1.6.4.

The most significant new features in this release are dramatically
improved PDF and PostScript[*] output, support for arbitrary X server
visuals (including PseudoColor), a new Quartz backend, and a new
"win32 printing" backend. See below for more details on these and
other new features.

Have fun with cairo!

-Carl

Summary of changes from cairo 1.4 to 1.6.0
==========================================
[Note: For people following along, there have been no code changes at
all from the cairo 1.5.20 snapshot to cairo 1.6.0]

New dependency on external pixman library (Thanks, Søren!)
----------------------------------------------------------
As of cairo 1.6, cairo now depends on the pixman library, for which
the latest release can be obtained alongside cairo:

http://cairographics.org/releases/pixman-0.10.0.tar.gz

This library provides all software rendering for cairo, (the
implementation of the image backend as well as any image fallbacks
required for other backends). This is the same code that was
previously included as part of cairo itself, but is now an external
library so that it can be shared by both cairo and by the X server,
(which is where the code originated).

Improved PDF, PostScript, and SVG output (Thanks, Adrian!)
----------------------------------------------------------
Users of the cairo-pdf, cairo-ps, and cairo-svg should see a dramatic
improvement from cairo 1.2/1.4 to 1.6. With this release there are now
almost no operations that will result in unnecessary rasterization in
the PDF and PostScript. Rasterized "image fallbacks" are restricted
only to minimal portions of the document where something is being
drawn with cairo that is beyond the native capabilities of the
document, (this is rare for PDF or SVG, but occurs when blending
translucent objects for PostScript).

This means that the final output will be of higher quality, and will
also be much smaller, and therefore will print more quickly. The
machinery for doing analysis and minimal fallbacks also benefits the
win32-printing surface described below.

In addition to doing less rasterization, the PostScript and PDF output
also has several other improvements to make the output more efficient
and more compatible with specifications.

[*] Note: Just before this release, a bug has been reported that the
PostScript output from cairo can crash some printers, (so far the
following models have been reported as problematic Xerox Workcentre
7228 or 7328 and Dell 5100cn). We will implement a workaround as soon
as we can learn exactly what in cairo's output these printers object
to, (and we could use help from users that have access to misbehaving
printers). This bug is being tracked here:

Printing some PDFs from evince is crashing our Xerox printer
http://bugs.freedesktop.org/show_bug.cgi?id=15348

New support for arbitrary X server visuals (Thanks, Keith and Behdad!)
----------------------------------------------------------------------
As of cairo 1.6, cairo should now work with an arbitrary TrueColor or
8-bit PseudoColor X server visual. Previous versions of cairo did not
support these X servers and refused to draw anything. We're pleased to
announce that this limitation has been lifted and people stuck with
ancient display systems need no longer be stuck with ancient software
just because of cairo.

New, supported Quartz backend for Mac OS X (Thanks, Brian and Vladimir!)
------------------------------------------------------------------------
As of cairo 1.6, the cairo-quartz backend is now marked as "supported"
rather than "experimental" as in previous cairo releases. Its API now
has guarantees of API stability into future cairo releases, and its
output quality is comparable to other backends. There have been
significant improvements to cairo-quartz since 1.4. It now uses many
fewer image fallbacks, (meaning better performance), and has greatly
improved text rendering.

New, "win32 printing" backend (Thanks, Adrian and Vladimir!)
------------------------------------------------------------
A new win32-printing surface has been added with an interface very
similar to the original win32 surface, (both accept an HDC
parameter). But this new surface should only be called with a printing
DC, and will result in all drawing commands being stored into a
meta-surface and emitted after each page is complete. This allows
cairo to analyze the contents, (as it does with PDF, PostScript, and
SVG backends), and to do minimal image-based fallbacks as
necessary. The analysis keeps things as efficient as possible, while
the presence of fallbacks, (when necessary), ensure the consistent,
high-quality output expected from cairo.

Robustness fixes (Thanks, Chris!)
---------------------------------
There has been a tremendous number of improvements to cairo's
robustness. Areas that have been improved include:

* Proper reporting of errors

* Responding correctly to invalid input

* Avoiding integer overflows

* Avoiding memory leaks on error-recovery paths

* Making reference counting thread safe

* Exhaustive testing of memory allocation points

Other fixes (Thanks, everybody!)
--------------------------------
Cairo's internal fixed-point representation has been changed from
16.16 to 24.8. This has a direct impact on applications as it allows
much larger objects to be drawn before internal limits in cairo make
the drawing not work.

The `CAIRO_EXTEND_PAD` mode is now fully supported by surface
patterns. This mode allows applications to use `cairo_rectangle` and
`cairo_fill` to draw scaled images with high-quality bilinear filtering
for the internal of the image, but without any objectionably blurry
edges, (as would happen with the default `EXTEND_NONE` and cairo_paint).

Rendering with `CAIRO_ANTIALIAS_NONE` has been fixed to be more
predictable, (previously image rendering and geometry rendering would
be slightly misaligned with respect to each other).

The reference manual at http://cairographics.org/manual now documents
100% of the functions and types in cairo's public API.

API additions
-------------
Several small features have been added to cairo with new API functions:

`cairo_format_stride_for_width`

    Must be called to compute a properly aligned stride value before
    calling `cairo_image_surface_create_for_data`.

`cairo_has_current_point`

    Allows querying if there is a current point defined for the
    current path.

`cairo_path_extents`

    Allows querying for path extents, (independent of any fill or
    stroke parameters).

`cairo_surface_copy_page`
`cairo_surface_show_page`

    Allow beginning a new document page without requiring a cairo_t
    object.

`cairo_ps_surface_restrict_to_level`
`cairo_ps_get_levels`
`cairo_ps_level_to_string`
`cairo_ps_surface_set_eps`

    Allow controlling the Post PostScript level, (2 or 3), to
    target, as well as to generate Encapsulated PostScript (EPS).

`cairo_quartz_font_face_create_for_cgfont`

    Create a quartz-specific `cairo_font_face_t` from a CGFontRef.

`cairo_win32_font_face_create_for_logfontw_hfont`

    Create a win32-specific `cairo_font_face_t` from a LOGFONTW and an
    HFONT together.

Thanks, Everyone!
-----------------
I've accounted for 32 distinct people with attributed code added to
cairo between 1.4.14 and 1.6.0, (their names are below). That's an
impressive number, but there are certainly dozens more that
contributed with testing, suggestions, clarifying questions, and
encouragement. I'm grateful for the friendships that have developed as
we have worked on cairo together. Thanks to everyone for making this
all so much fun!

Adrian Johnson, Alp Toker, Antoine Azar, Behdad Esfahbod,
Benjamin Otte, Bernardo Innocenti, Bertram Felgenhauer,
Boying Lu, Brian Ewins, Carl Worth, Chris Heath, Chris Wilson,
Claudio Ciccani, Emmanuel Pacaud, Jeff Muizelaar, Jeremy Huddleston,
Jim Meyering, Jinghua Luo, Jody Goldberg, Jonathan Gramain,
Keith Packard, Ken Herron, Kouhei Sutou, Kristian Høgsberg,
Larry Ewing, Martin Ejdestig, Nis Martensen, Peter Weilbacher,
Richard Hult, Shailendra Jain, Søren Sandmann Pedersen,
Vladimir Vukicevic
```
