---
title: cairo 1.14.2 release available
layout: news
date: 2015-03-10
---
```

 Date:  Tue Mar 10 19:41:20 PDT 2015
 From: Bryce Harrington <bryce@osg.samsung.com>
 Subject: [cairo] cairo release 1.14.2 now available

A new cairo release 1.14.2 is now available from:

  http://cairographics.org/releases/cairo-1.14.2.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.14.2.tar.xz.sha1
    c8da68aa66ca0855b5d0ff552766d3e8679e1d24  cairo-1.14.2.tar.xz

    http://cairographics.org/releases/cairo-1.14.2.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.14.2 tag which points to a commit named:
    93422b3cb5e0ef8104b8194c8873124ce2f5ea2d

    which can be verified with:
    git verify-tag 1.14.2

    and can be checked out with a command such as:
    git checkout -b build 1.14.2


Release 1.14.2 (2014-03-09 Bryce Harrington <bryce@osg.samsung.com>)
====================================================================
This release provides collected bug fixes, along with one feature
enhancement for the xcb backend, and a small performance improvement for
fonts.

The running theme of the bug fixes is platform-specific issues, both
build and run-time.  Platforms with fixes include Sparc, AIX, Windows
(mingw), and Windows (MSVC8).  Memory leaks, valgrind issues, and PDF
issues round out our list.

It's come to light that changes in cairo 1.14 resulted in breakage on
MacOS X 10.4.  We've not yet determined whether to fix up the support,
or excise the 10.4-specific code and support only OS X 10.5 or newer.
Meantime, we'll only advertise cairo as working on OS X 10.5.

Features
--------
 * Improve xcb's handling of per-screen subpixel ordering.  If no
   Xft.rgba property is specified, default to the screen's subpixel
   order.

API Changes
-----------
None

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
 * Improve performance of cpu_to_be32 and be32_to_cpu, making truetype
   subsetting of large fonts run about 15% faster.

Bug Fixes
---------
 * Fix unaligned access on sparc with the compact font format (CFF).
   Unlike truetype, all data in CFF is not aligned.
   (Debian bug #712836)
 * Fix unaligned access on sparc with tor-scan-converter's memory pool.
 * Fix crash when loading a PDF with a transformed image.
   (fdo bug #85151)
 * Fix regression on mingw for bigendian test due to removal of file
   extension for executables.
   (fdo bug #85120)
 * Fix handling of backslash in PDF interpreter
   (fdo bug #85662)
 * Fix crash in xlib and xcb renderers when swapping a 0-sized glyph
 * Fix bug with RTL text in PDF operators
   (fdo bug #86461)
 * Fix compilation 'cairo-path-stroke-traps.c' with MSVC8
   (fdo bug #84908)
 * Fix crash in _fill_xrgb32_lerp_opaque_spans when a span length is
   negative.
 * Fix valgrind error by releasing pattern created by
   cairo_pattern_create_rgb().
 * Fix valgrind errors when running cairo-test-suite.
 * Fix memory leak in recording surface replays
   (fdo bug #87898)
 * Fix destruction of fonts in api-special-cases test.
   (fdo bug #87567)
 * Fix duplicated surface push on similar-image, preventing trivial GTK3
   program traces from being replayable, with an error message about
   invalid values for the size of the input.
   (fdo bug #73580)
 * Fix crash when win32 surface's image size does not cover the entire
   surface.
   (fdo bug #53121)
 * Fix crash due to obsolete CGFontGetGlyphPath call
   (fdo bug #84324)
 * Fix several build issues on AIX
   (fdo bugs #89338, #89340, #89356, #89354)
 * Fix various documentation warnings and errors


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


Contributors
============
Adam Jackson (2):
      xlib: Don't crash when swapping a 0-sized glyph
      xcb: Don't crash when swapping a 0-sized glyph

Adrian Johnson (7):
      Update mime type documentation.
      CFF: Fix unaligned access
      pdf: fix compiler warning
      build: fix regression on mingw
      pdf-operators: only wrap text strings for PS output
      Improve performance of cpu_to_be32 and be32_to_cpu
      pdf-operators: fix bug with RTL text

Andrea Canciani (6):
      test: Release owned pattern
      test: Free test list
      font: Actually perform destruction of fonts
      quartz: Remove call to obsolete CGFontGetGlyphPath
      Update KNOWN_ISSUES documentation
      Update README with new minimum MacOSX requirements

Bryce Harrington (21):
      Start 1.14.1 development
      RELEASING:  Update tags push command
      Add execution bit for make-cairo-test-constructors.sh
      Revert "Add execution bit for make-cairo-test-constructors.sh"
      RELEASING: Be explicit as to which tag is pushed
      Drop the target-specific huge-radial.pdf.*.ref.png images
      test: Use ARRAY_LENGTH macro
      Refactor ARRAY_LENGTH macro definitions in test code
      image: Fix crash in _fill_xrgb32_lerp_opaque_spans
      gitignore: logs, manuals
      doc: Drop extraneous para's
      git-ignore: Add build's test-driver
      Revert "xlib: Remove queued event from _XReadEvents"
      csi-trace:  Add --version and --help args to utility
      HACKING: Add link to git tutorial and wordsmith a bit
      NEWS: Update for changes through Nov 2014
      NEWS: Finish filling in changes
      On MacOSX, the sed utility errors out when parsing non-UTF8 files
      NEWS: Note about the OS X support
      KNOWN_ISSUES:  Restore known issues file as a stub
      version: bump for cairo-1.14.2 release

Chris Wilson (1):
      xlib: Bump reference count for recording surface replays

Emanuele Aina (1):
      cairo-trace: Fix duplicated surface push on similar-image

Hans Breuer (1):
      win32: Fix compilation of 'cairo-path-stroke-traps.c' with MSVC8

Henry (Yu) Song (1):
      xlib: Remove queued event from _XReadEvents

Massimo Valentini (2):
      tor-scan-converter: can't do_fullrow when intersection in row + 0.5subrow
      win32:  Fix crash from win32 surface's image size too small

Michael Haubenwallner (8):
      fix conflicting types for 'sync' on AIX, bug#89338
      skip MAP_NORESERVE when unsupported
      define _GETDELIM for getline() on AIX
      test: fix include order for AIX, bug#89354
      perf/micro: fix include order for AIX, bug#89354
      perf: fix include order for AIX, bug#89354
      headers: fix include order for AIX, bug#89354
      headers: fix include order for AIX, bug#89354

Ravi Nanjundappa (2):
      Fix warnings from check-doc-syntax.sh
      Fix one more warning from check-doc-syntax.sh

Uli Schlachter (3):
      tor-scan-converter: Correctly align 64bit types
      xcb: Query the display's subpixel order via RENDER
      xlib-xcb: Don't be lazy and use the real xcb_screen_t

--
Bryce Harrington
Senior Open Source Developer  -  bryce@osg.samsung.com
Open Source Group             -  Samsung Research America



```
