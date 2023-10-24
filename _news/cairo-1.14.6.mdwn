---
title: cairo 1.14.6 release available
layout: news
date: 2015-12-09
---

A new cairo release 1.14.6 is now available from:

  http://cairographics.org/releases/cairo-1.14.6.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.14.6.tar.xz.sha1
    0a59324e6cbe031b5b898ff8b9e2ffceb9d114f5  cairo-1.14.6.tar.xz

    http://cairographics.org/releases/cairo-1.14.6.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.14.6 tag which points to a commit named:
    9d3191da6fae7dfd914c3516d6ba369c9ba1a576

    which can be verified with:
    git verify-tag 1.14.6

    and can be checked out with a command such as:
    git checkout -b build 1.14.6


Release 1.14.6    (2015-12-09  Bryce Harrington <bryce@osg.samsung.com>)
========================================================================
Simple bugfix release to fix one Windows issue.

For a complete log of changes since 1.14.4, please see:

    http://cairographics.org/releases/ChangeLog.cairo-1.14.6

-Bryce

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
* Fix failure on Windows due to reference of the function
  cairo_win32_surface_create_with_format(), which isn't included in the
  1.14.4 release. (Bug #92771)



------------------------------------------------------------------------
Bryce Harrington (4):
      Bump version for new stable tree, 1.14.5
      Revert "win32: Add a win32 boilerplate that uses a real window"
      Release 1.14.6
      Start 1.14.7 development.
