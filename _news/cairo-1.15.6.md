---
title: cairo 1.15.6 release available
layout: news
date: 2017-06-13
---
```

Subject: cairo snapshot 1.15.6 now available

A new cairo snapshot 1.15.6 is now available from:

  http://cairographics.org/snapshots/cairo-1.15.6.tar.xz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.15.6.tar.xz.sha1
    1a1724ecd012efeeaa43adee7094223227b61d90  cairo-1.15.6.tar.xz

    http://cairographics.org/snapshots/cairo-1.15.6.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.6 tag which points to a commit named:
    c31721ab27c65941dd9e0c29662d7ebb5caa2a01

    which can be verified with:
    git verify-tag 1.15.6

    and can be checked out with a command such as:
    git checkout -b build 1.15.6

This new snapshot incorporates changes over the past half-year since the
1.15.4 snapshot, including all the fixes from the 1.14 release series.

The PDF code continues to be enhanced, and we're restored MacOSX 10.4
support.  Font-related fixes and improved error handling for X round out
the release.

For a complete log of changes, please see

    http://cairographics.org/releases/ChangeLog.cairo-1.15.6


Features and Enhancements
-------------------------
* Detect if variable fonts have	synthesized bold/italic	or non-default
  variants, and	     use a fallback font where needed.

* Restore MacOSX 10.4 support.	    Cairo had dropped 10.4 support when
  moving to the CoreText API.  Now we automatically detect which API to
  use via dynamic linking, so can resume supporting this older version
  of MacOSX.


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
* Fix error reporting in the xcb backend if fallback fails.  Instead of
  returning NULL when the X11 server can't do some operation, return a
  surface in an error state.

* Call XSync in the xlib backend before setting the error handler to
  ignore errors for certain requests, to make sure all pending errors
  are handled first.

* Fix text-glyph-range for quartz-font.	 Use 0xFFFF instead of 0 for
  invalid index	       tracking.

* Fix handling of Supplementary Multilingual Plane (SMP) Unicode
  characters in quartz-font.

* Fix various issues in the drm backend	including updating API usage and
  general code cleanup.

* Clarify documentation	regarding device scale inheritance and the units
  used in cairo_surface_create_similar_image.
  Bug #99094.


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
Adrian Johnson (3):
      pdf: don't return uninitialized status
      pdf-operators: fix bug in line wrapping
      subsetting: support variable fonts

Andrea Canciani (5):
      quartz: Restore 10.4-specific font code
      test: Add a test for characters in the SMP
      unicode: Extract the UCS4 to UTF-16 conversion to a separate function
      quartz-font: Correct handling of SMP Unicode characters
      quartz-font: Fix text-glyph-range

Bryce Harrington (6):
      Bump version for new development tree, 1.15.5
      RELEASING: Fix tabbing
      gl: Fix comment syntax
      drm: Add/reorder headers as required by check-preprocessor-syntax.sh
      1.15.6 release

Chris Wilson (1):
      stroker: Check for scaling overflow in computing half line widths

Debarshi Ray (2):
      doc: Fix the units used by cairo_surface_create_similar_image
      doc: Clarify when the device scale is inherited and when it isn't

Enrico Weigelt, metux IT consult (4):
      drm: fixed missing includes
      drm: dropped obsolete/unused intel_bo_get_image()
      drm: use typedefs and defines from drm headers instead of redundant own definitions
      drm: fixed calls to _cairo_surface_init()

Kouhei Sutou (2):
      pdf: Remove duplicated item
      pdf: Fix wrong cairo_pdf_outline_flags_t item prefix

Uli Schlachter (4):
      xlib: Remove unused variable
      xlib: Call XSync() before ignoring errors
      Revert "stroker: Check for scaling overflow in computing half line widths"
      xcb: Fix error reporting if fallback fails

```
