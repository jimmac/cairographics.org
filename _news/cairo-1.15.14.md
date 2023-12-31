---
title: new cairo snapshot 1.15.14 is available
date: 2018-09-19
layout: news
---
```
A new cairo snapshot 1.15.14 is now available from:

http://cairographics.org/snapshots/cairo-1.15.14.tar.xz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.15.14.tar.xz.sha1
62ebffbaf4cc81c412f0ad3f87dc20499f85d046  cairo-1.15.14.tar.xz

http://cairographics.org/snapshots/cairo-1.15.14.tar.xz.sha1.asc
(signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.14 tag which points to a commit named:
d9aaea0c1e1484c632e1a6735c6ecc961c4b032b

    which can be verified with:
git verify-tag 1.15.14

    and can be checked out with a command such as:
git checkout -b build 1.15.14

Release 1.15.14    (2018-09-19 Bryce Harrington <bryce@bryceharrington.org>)
============================================================================
We're nearly ready to finalize the 1.16.0 release, so this snapshot
can be considered a beta for 1.16.

The most notable change this release is a performance optimization for
windows, discussed below.  Other than that, much of the development
focus was on final polish and stability as we prepare for 1.16.

Some attention went into getting the testsuite passing at least for the
image backend.  The Cairo testsuite depends on external software like
Pixman, and changes in the rendering behavior of these dependencies
change test behavior, leading to false positives.

Results from the Coverity static testing tool were also reviewed.  Most
of the issues flagged were false positives, but there were several
legitimate problems found and fixed.

For a complete log of changes, please see

    http://cairographics.org/releases/ChangeLog.cairo-1.15.12

Features and Enhancements
-------------------------
* Add more FreeeType font color conversions to support COLR/CPAL
* Update test reference images against current pixman

API Changes
-----------
None

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
Vasily Galkin introduced a Win32 performance optimization for
CAIRO_OPERATOR_SOURCE when copying data from a backbuffer to an argb32
surface corresponding to a Win32 DC.  With this, argb32 drawing should
perform as fast as typical dibsection-buffered GDI drawing.  See the
Cairo mailing list for April 2018 for data and discussion of the
performance improvements.


Bug Fixes
---------
* Fix crash when rendering Microsoft's Segoe UI Emoji Regular font.
* Fix build breakage with glesv3 enabled due to non-existant glesv3.pc.
* Fix memory leaks found by Coverity
* Fix incorrect null ptr handling found by Coverity
* Fix test compilation when font-config is disabled
* Use _cairo_malloc instead of malloc (Bug #101547) (CVE-2017-9814)
* Fix assertion failure in the freetype backend (Bug #105746)


Full changes since 1.15.12:
===========================

Adrian Johnson (1):
      Use _cairo_malloc instead of malloc

Alexandre Bique (1):
      Fix test compilation when font-config is disabled

Behdad Esfahbod (1):
      [ft] Implement some more color conversion routines

Bryce Harrington (24):
      Drop stray patch from prior commit
      gl: Whitespace cleanup
      win32: Copyedit recent comments
      test: Use C comment syntax, not C++
      Bump version for new development tree, 1.15.13
      script-surface: Check for invalid ids (CID #1159557, 1159558)
      bo: Check null return from _cairo_malloc_ab() (CID #1159556)
      snapshot: Don't use extra after it's been freed (CID #220086)
      bo: Free event_y in case of error to prevent memory leak (CID ##1160682)
      pdf: Fix potential null ptr deref when creating smask groups (CID #1159559)
      type1-subset: Fix incorrect null ptr check from find_token() (CID #1160662)
      polygon-intersection: Clarify ptr checks for right edges (CID #1160730)
      gl: For glesv3 detection, use glesv2.pc + header check
      scaled-font: Fix glyph and cluster count checks (CID #983386)
      Convert 3 headers to UTF8
      build: Sp. fix
      doc: Add missing symbols to sections for recently added APIs
      Fix sp. sheering
      gstate: Minor grammar copyedit
      Normalize more test reference images with minor text rendering differences
      Normalize one more test image with minor gradient differences
      doc: Drop tmpl support
      1.15.14 release
      Bump version for 1.15.15

Federico Mena Quintero (5):
      cairo-analysis-surface: Quell invalid uninitialized variable warning
      test/extended-blend.c: Remove obsolete comments about buggy librsvg
      Normalize extended-blend-mask.{argb32,rgb24}.ref.png
      Normalize test images with minor gradient differences
      Normalize test reference images with minor text rendering differences

Uli Schlachter (1):
      Fix assertion failure in the freetype backend

Vasily Galkin (3):
      win32: Introduce new flag to mark surfaces that support solid brush drawing
      win32: CAIRO_WIN32_SURFACE_CAN_RGB_BRUSH and other argb32 flags set+check
      win32: Allow GDI operations for argb32 surfaces (allowed by surface flags)

```
