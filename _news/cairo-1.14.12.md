---
title: cairo 1.14.12 stable release available
layout: news
date: 2017-12-14
---
```

Subject: Cairo 1.14.12 released

A new cairo release 1.14.12 is now available from:

  http://cairographics.org/releases/cairo-1.14.12.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.14.12.tar.xz.sha1
    490025a0ba0622a853010f49fb6343f29fb70b9b  cairo-1.14.12.tar.xz

    http://cairographics.org/releases/cairo-1.14.12.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.14.12 tag which points to a commit named:
    7cf32a065e7c3d8721ae5f4eccf6695152fe14b7

    which can be verified with:
    git verify-tag 1.14.12

    and can be checked out with a command such as:
    git checkout -b build 1.14.12

Features
--------
None

API Changes
-----------
None

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
None

Bug Fixes
---------
* Fix assertion hit with PDFs using Type 4 fonts rendered with user
  fonts, due to error when destroying glyph page.
  (Bug #103335)
* Fix build error with util/font-view
* Fix handling of truetype fonts with excessively long font names
  (Bug #103249)
* Fix falling back to system font with PDFs using certain embedded
  fonts, due to truncated font names.
  (Bug #103249)
* Fix sigabrt printing documents with fonts lacking the mandatory .nodef
  glyph.
  (Bug #102922)
* Fix undefined-behavior with integer math.
* Fix various warnings and typos

See below for a complete log of changes since 1.14.10, or see:

    http://cairographics.org/releases/ChangeLog.cairo-1.14.12



What is cairo
-------------
Cairo is a 2D graphics library with support for multiple output
devices. Currently supported output targets include the X Window
System (via both Xlib and XCB), quartz, win32, and image buffers,
as well as PDF, PostScript, and SVG file output. Experimental backends
include OpenGL, BeOS, OS/2, and DirectFB.

Cairo is free software and is available to be redistributed and/or
modified under the terms of either the GNU Lesser General Public
License (LGPL) version 2.1 or the Mozilla Public License (MPL) version
1.1.


Where to get more information about cairo
-----------------------------------------
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



Changes since 1.14.10
---------------------

Adrian Johnson (8):
      fix warning: inlining failed in call to '_csi_stack_push'
      util/font-view: fix build error
      fix warning: variable X might be clobbered by 'longjmp'
      truetype: limit font name to 127 chars
      output-stream: allow %s strings larger than 512 chars
      truetype: reserve space in subset arrays for .notdef
      replace _BSD_SOURCE with _DEFAULT_SOURCE
      build: use _WIN32 instead of windows.h to check for windows build

Aleksander Morgado (1):
      build: fix minor typo in autogen.sh

Behdad Esfahbod (1):
      Fix undefined-behavior with integer math

Bryce Harrington (3):
      Start 1.14.11 development
      Release 1.14.12
      Start 1.14.13 development

Carlos Garcia Campos (1):
      scaled-font: Fix assert when destroying glyph page
```
