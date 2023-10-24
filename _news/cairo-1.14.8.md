---
title: cairo 1.14.8 release available
layout: news
date: 2016-12-07
---
```

A new cairo release 1.14.8 is now available from:

  http://cairographics.org/releases/cairo-1.14.8.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.14.8.tar.xz.sha1
    c6f7b99986f93c9df78653c3e6a3b5043f65145e  cairo-1.14.8.tar.xz

    http://cairographics.org/releases/cairo-1.14.8.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.14.8 tag which points to a commit named:
    9b23aa0f9de4b0ccac8640bea43570b13f8f5a0f

    which can be verified with:
    git verify-tag 1.14.8

    and can be checked out with a command such as:
    git checkout -b build 1.14.8


Release 1.14.8	  (2016-12-07  Bryce Harrington <bryce@osg.samsung.com>)
========================================================================
Bugfix release rolling up backported fixes for the past year.

For a complete log of changes since 1.14.6, please see:

    http://cairographics.org/releases/ChangeLog.cairo-1.14.8

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
* Fix "invalidfont" error on some printers when printing PDFs with
  embedded fonts that have glyphs (such as spaces) with
  num_contours == 0.  (Bug #79897)
* Fix deadlock when destruction of a scaled font indirectly triggers
  destruction of a second scaled font, causing the global cache to be
  locked twice.	 (Bug #93891)
* Fix X errors reported to applications when shmdt() is called before
  the Attach request is processed, due to missing xcb and xlib calls.
* Fix random failure in record-paint-alpha-clip-mast test case, caused
  by an incorrect assumption that a deferred clear can be skipped.
  (Bug #84330)
* Fix crash when dealing with an XShmGetImage() failure, caused by a
  double free in _get_image_surface().	(Bug #91967)
* Fix build issue when using non-GNU strings utility.  (Bug #88639)
* Cleanup debugging text sent to stdout instead of log.	 (Bug #95227)


```
