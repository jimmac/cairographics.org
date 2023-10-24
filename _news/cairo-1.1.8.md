---
title: cairo 1.1.8 snapshot available
layout: news
date: 2006-06-14
---

From: Carl Worth <cworth@cworth.org>
Date: 14 Jun 2006
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.1.8 now available

A new cairo snapshot 1.1.8 is now available from:

        http://cairographics.org/snapshots/cairo-1.1.8.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.1.8.tar.gz.sha1
        ad660fe7bfede1882f4b81798e3e0ef8fe7ecb9b  cairo-1.1.8.tar.gz

        http://cairographics.org/snapshots/cairo-1.1.8.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.1.8 tag which points to a commit named:
dd859b8736bb4d1bcf3ed78d0bd1f72a7aad9ca9

    which can be verified with:
git verify-tag 1.1.8

    and can be checked out with a command such as:
git checkout -b build 1.1.8

This is the fourth in a series of snapshots working toward the 1.2
release of cairo. At this point, all major features of the 1.2 release
are in place, leaving just a few bug fixes left.

In particular, there will be no additional API changes between this
1.1.8 snapshot and the 1.2 release.

The announcement for 1.1.6 mentioned several API changes being
considered. Only one of these changes was actually implemented
(set_dpi -> fallback_resolution). This change does introduce one
source-level incompatibility with respect to previous 1.1.x snapshots,
so see below for details.

-Carl

What's new in 1.1.8 compared to 1.1.6
=====================================
** API Change **
----------------
According to the plan mentioned in the 1.1.6 notes, one source-level
incompatible change has been implemented. The following three
functions have been removed from cairo's API:

cairo_pdf_surface_set_dpi
cairo_ps_surface_set_dpi
cairo_svg_surface_set_dpi

and in their place the following function has been added:

cairo_surface_set_fallback_resolution

The signature and semantics of the function remains the same, so it is
a simple matter of changing the name of the function when calling
it. As a transition mechanism, this snapshot will (on many systems)
build to include the old symbols so that code previously compiled will
still run. However, all source code using the old names must be
updated before it will compile. And the upcoming 1.2 release is not
anticipated to include the old symbols.

Finally, it should be pointed out that the old symbols never existed
in the supported API of any stable release of cairo. (In the stable
1.0 releases the PDF, PS, and SVG backends were advertised as
experimental and unstable.)

And, as always, cairo continues to maintain source and binary
compatibility between major releases. So applications compiled against
supported backends in a stable release of cairo (1.0.4 say) will
continue to compile and run without modification against new major
releases (1.2.0 say) without modification.

API additions
-------------
The following new functions have been added to cairo's API:

cairo_surface_get_content
cairo_debug_reset_static_data
cairo_image_surface_get_data
cairo_image_surface_get_format
cairo_image_surface_get_stride
cairo_win32_font_face_create_for_hfont

New, backend-specific pkg-config files
--------------------------------------
In addition to the original cairo.pc file, cairo will also now install
a pkg-config files for each configured backend, (for example
cairo-pdf.pc, cairo-svg.pc, cairo-xlib.pc, cairo-win32.pc, etc.) this
also includes optional font backends (such as cairo-ft.pc) and the
optional png functionality (cairo-png.pc).

These new pkg-config files should be very convenient for allowing
cairo-using code to easily check for the existing of optional
functionality in cairo without having to write complex rules to grub
through cairo header files or the compiled library looking for
symbols.

Printing backend (PS, PDF, and SVG)
-----------------------------------
Improving the quality of the "printing" backends has been a priority
of the development between cairo 1.1.6 and cairo 1.1.8.

The big improvement here is in the area of text output. Previously, at
best, text was output as paths without taking advantage of any font
support available in the output file format.

Now, at the minimum text paths will be shared by using type3 fonts
(for PS and PDF---and similarly, defs for SVG). Also, if possible,
type3 and truetype fonts will be embedded in PostScript and PDF
output. There are still some known bugs with this, (for example,
selecting text in a cairo-generated PDF file with an embedded truetype
font does not work). So there will be some more changes in this area
before cairo 1.2, but do try test this feature out as it exists so
far.

Many thanks to Kristian Høgsberg for the truetype and type1 font
embedding.

win32 backend
-------------
Performance improvements by preferring GDI over pixman rendering when possible.
Fixes for text rendering.

xlib backend
------------
Fix potentially big performance bug by making xlib's create_similar
try harder to create a pixmap of a depth matching that of the screen.

Bug fixes
---------
Among various other fixes, the following bugs listed in bugzilla have
been fixed:

    Bug 2488: Patch to fix pixman samping location bug (#2488).
    https://bugs.freedesktop.org/show_bug.cgi?id=2488

    Bug 4196: undef MIN an MAX before defining to avoid duplicate definition
    https://bugs.freedesktop.org/show_bug.cgi?id=4196

    Bug 4723: configure.in: Fix m4 quoting when examining pkg-config version
    https://bugs.freedesktop.org/show_bug.cgi?id=4723

    Bug 4882: Flag Sun's X server has having buggy_repeat.
    https://bugs.freedesktop.org/show_bug.cgi?id=4882

    Bug 5306: test/pdf2png: Add missing include of stdio.h
    https://bugs.freedesktop.org/show_bug.cgi?id=5306

    Bug 7075: Fix make clean to remove cairo.def
    https://bugs.freedesktop.org/show_bug.cgi?id=7075

(Many thanks to Behdad Esfahbod for helping us track down and fix many
of these.)
