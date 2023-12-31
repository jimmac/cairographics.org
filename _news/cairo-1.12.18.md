---
title: cairo 1.12.18 snapshot available
layout: news
date: 2014-11-07
---
```

From: Bryce Harrington <bryce@osg.samsung.com>
To: cairo-announce@cairographics.org
Date: Fri, 07 Nov 2014 01:04:19 -0800

A new cairo release 1.12.18 is now available from:

  http://cairographics.org/releases/cairo-1.12.18.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.12.18.tar.xz.sha1
    a76940b58da9c83b8934264617135326c0918f9d  cairo-1.12.18.tar.xz

    http://cairographics.org/releases/cairo-1.12.18.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.18 tag which points to a commit named:
    c5bba093dec4fc7addddb1a16b6a17e3a4c29555

    which can be verified with:
    git verify-tag 1.12.18

    and can be checked out with a command such as:
    git checkout -b build 1.12.18


Release 1.12.18 (2014-11-06 Bryce Harrington <bryce@osg.samsung.com>)
=====================================================================
By popular demand, here is an update of the 1.12 series.  This provides
an array of important bug fix patches cherrypicked from the 1.14
series.  Also included is the distcheck warnings cleanup work.

Note that glib 2.14 is now required for g_once_init_enter(), etc. in
cairo-gobject.


Bug Fixes
---------

    Don't embed CMYK JPEG images since SVG viewers don't have support

    Fix regression in the embedding of mime-data in PDF

    Fix hardcoding of awk; search $PATH instead

    Fix stroke-clipped for dashed strokes, etc.

    Fix rectangle stroke with non-rectilinear pens in PDF

    Fix imagemask with pattern source on certain PS printers

    Fix font names in generated PDF when they have white space or
    delimiter characters.

    Fix crash in pixman_image_composite32()

    Fix issue with modification of all-clipped cairo_clip_t, causing a
    write to read-only memory.

    Fix segfault in firefox when scrolling certain pages.

    Fix potential double free.

    Fix check for image surface for inplace upload.

    Fix crash in sweep_line_delete on video playback by prefiltering
    zero-area boxes when converting traps, given a traps tesselator like
    cairo-xlib.

    Fix cache_frozen assertions on Win32.

    Fix image scale when GDI scale  is not identity on windows.

    Fix build with --enable-pdf=no

    Fix build for Qt backend

    Fix typo in _cairo_int128_negate and _cairo_int128_not
    implementations, which could be a problem on systems without a
    uint128 type.

    Use setpagedevice to set page size

    Add font DSC comments

    Remove LTO support.

    Various improvements to code documentation, tons of warnings and
    distcheck cleanup and fixes, and repairs to a slew of tests.


Complete list of changes from 1.12.16 to 1.12.18
------------------------------------------------

Adrian Johnson (12):
      svg: Don't embed CMYK Jpeg images
      pdf: fix embedding of mime data that has been broken since 0a10982f
      ps: fix embedding of mime data
      pdf: fix rectangle stroke with non rectilinear pen
      ps: remove duplicate /Interpolate from image dictionary
      ps: fix imagemask with pattern source failure on some printers
      ps: use setpagedevice to set page size
      ps: cairo_set_page_size does not need to be in eps output
      ps: add font DSC comments
      type1: strip space from end of font name
      win32 printing: fix image scale when GDI scale is not identity
      type1-subset: don't rename glyphs used by seac operator

Bryce Harrington (20):
      image: Fix bad HTML generation in code docs for cairo-format-stride-for-width
      Fix segfault in firefox when scrolling on certain pages
      configure.ac: Add a --disable-lto configure option
      README:  Update required dependencies
      cairo-wideint:  Fix typo in two cairo_uint128 functions
      configure.ac: Fix broken build for Qt backend
      configure.ac: Quell warnings about AM_PROG_AR when using automake 1.12
      doc: Drop a couple quartz routines which distcheck claims don't exist
      mesh: Avoid theoretical infinite loops
      xml: constify source objects for emit routines
      test: Quell warning for deprecated g_type_init()
      test: Quell warning for inclusion of old rsvg header files
      perf: Guarantee path width is non-negative
      cairo-script: Compare status with CSI enums
      cairo-script: Error if asked to decompress with missing compression lib
      test:  Handle error in fgets call in ps-eps test
      test:  Replace deprecated rsvg_init() in any2ppm test
      gl: Handle PIXMAN_a8r8g8b8_sRGB format in switch
      doc: Add missing sections and symbols for public docs
      Bump release to 1.12.18

Chris Wilson (4):
      Post-release version bump
      clip: Do not modify the special all-clipped cairo_clip_t
      traps,xcb: Prefilter zero-area boxes when converting traps
      traps,xcb: Set the box count after filtering

Koji Egashira (1):
      image: Add NULL checks for return value of _pixman_image_for_color()

Marek Kasik (1):
      font: Generate PDFs with correct font names

Ravi Nanjundappa (2):
      test : build fix when --enable-pdf=no
      src : Fix warn_unused_result warnings from gcc

Rodrigo Rivas Costa (1):
      win32 print: fix cache_frozen assertions

Ryan Lortie (1):
      cairo-version: fix docs build

Sylvestre Ledru (1):
      Remove some potential double free

Uli Schlachter (8):
      cairo-gobject: Require at least glib 2.14
      check-doc-syntax: Don't hardcode path to awk
      fill_reduces_to_source(): Handle failure of color_to_pixel()
      clip: Fix handling of special all-clipped cairo_clip_t
      mask compositor: Set a check_composite method
      Remove LTO support
      xcb: Correctly check for image surface for inplace upload
      Fix warnings from check-doc-syntax.sh

egag (1):
      Fixes stroke-clipped, i.c. of a dashed stroke


What is cairo
=============
Cairo is a 2D graphics library with support for multiple output
devices. Currently supported output targets include the X Window
System (via both Xlib and XCB), quartz, win32, and image buffers,
as well as PDF, PostScript, and SVG file output. Experimental backends
include OpenGL, BeOS, OS/2, and DirectFB.

Cairo is designed to produce consistent output on all output media
while taking advantage of display hardware acceleration when available
(for example, through the X Render Extension).

The cairo API provides operations similar to the drawing operators of
PostScript and PDF. Operations in cairo include stroking and filling
cubic Bézier splines, transforming and compositing translucent images,
and antialiased text rendering. All drawing operations can be
transformed by any affine transformation (scale, rotation, shear,
etc.).

Cairo has been designed to let you draw anything you want in a modern
2D graphical user interface.  At the same time, the cairo API has been
designed to be as fun and easy to learn as possible. If you're not
having fun while programming with cairo, then we have failed
somewhere---let us know and we'll try to fix it next time around.

Cairo is free software and is available to be redistributed and/or
modified under the terms of either the GNU Lesser General Public
License (LGPL) version 2.1 or the Mozilla Public License (MPL) version
1.1.

Where to get more information about cairo
=========================================
The primary source of information about cairo is:

http://cairographics.org/

The latest versions of cairo can always be found at:

http://cairographics.org/download

Documentation on using cairo and frequently-asked questions:

http://cairographics.org/documentation
http://cairographics.org/FAQ

Mailing lists for contacting cairo users and developers:

http://cairographics.org/lists

Roadmap and unscheduled things to do, (please feel free to help out):

http://cairographics.org/roadmap
http://cairographics.org/todo

--
Bryce Harrington
Senior Open Source Developer  -  bryce@osg.samsung.com
Open Source Group             -  Samsung Research America
```
