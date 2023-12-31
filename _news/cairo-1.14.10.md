---
title: cairo 1.14.10 release available
layout: news
date: 2017-06-15
---
```

Subject: cairo release 1.14.10 now available

A new cairo release 1.14.10 is now available from:

  http://cairographics.org/releases/cairo-1.14.10.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.14.10.tar.xz.sha1
    28c59d85d6b790c21b8b59ece73a6a1dda28d69a  cairo-1.14.10.tar.xz

    http://cairographics.org/releases/cairo-1.14.10.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.14.10 tag which points to a commit named:
    05b63e807bb5f86f600283df1c3ca554778d90fa

    which can be verified with:
    git verify-tag 1.14.10

    and can be checked out with a command such as:
    git checkout -b build 1.14.10


Features and Enhancements
-------------------------
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
* Clarify documentation regarding device scale inheritance and the units
  used in cairo_surface_create_similar_image.  Bug #99094.

* Fix error reporting in the xcb backend if fallback fails.  Instead of
  returning NULL when the X11 server can't do some operation, return a
  surface in an error state.

* Call XSync in the xlib backend before setting the error handler to
  ignore errors for certain requests, to make sure all pending errors
  are handled first.

* For opentype fonts, always use gid to lookup glyph.

* If glyph 0 used for rendering, remap to different index.

* Set font size to em size when retrieving unhinted metrics.

* Flush ASCII85Decode file after use with Postscript files.

* pdf: Don't fail subsetting if unable to convert utf8 to utf16.

* For truetype, reverse cmap search should end when 0xffff- 0xffff range
  reached.

* Fix bug in line wrapping with the PDF operators.

* Fix an off by one check in cairo-image-info.c.


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


Changelog
---------
Adrian Johnson (8):
      cff: opentype fonts always use gid to lookup glyph
      scaled-font-subsets: if glyph 0 used for rendering, remap to different index
      ft: set font size to em size when retrieving unhinted metrics
      ps: flush ASCII85Decode file after use
      pdf: Don't fail subsetting if unable to convert utf8 to utf16
      truetype: reverse cmap search should end when 0xffff- 0xffff range reached
      pdf-operators: fix bug in line wrapping
      Fix off by one check in cairo-image-info.c

Bryce Harrington (4):
      Start 1.14.9 development
      RELEASING: Sync doc from trunk
      Release 1.14.10
      Start 1.14.11 development

Debarshi Ray (2):
      doc: Clarify when the device scale is inherited and when it isn't
      doc: Fix the units used by cairo_surface_create_similar_image

Uli Schlachter (2):
      xcb: Fix error reporting if fallback fails
      xlib: Call XSync() before ignoring errors

```
