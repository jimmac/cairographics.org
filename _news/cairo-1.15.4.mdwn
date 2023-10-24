---
title: cairo 1.15.4 release available
layout: news
date: 2016-12-08
---

Subject: cairo snapshot 1.15.4 now available

A new cairo snapshot 1.15.4 is now available from:

  http://cairographics.org/snapshots/cairo-1.15.4.tar.xz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.15.4.tar.xz.sha1
    4e5d28697ac5a750a071edcf4a99e8af8d7c04b2  cairo-1.15.4.tar.xz

    http://cairographics.org/snapshots/cairo-1.15.4.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.4 tag which points to a commit named:
    9fe6683cb105354e86ea649ba7a13052c7edc757

    which can be verified with:
    git verify-tag 1.15.4

    and can be checked out with a command such as:
    git checkout -b build 1.15.4

This new snapshot incorporates changes over the past year since the
1.15.2 snapshot, including all the fixes from the 1.14 release series.

Of particular note in this snapshot is a wealth of work by Adrian
Johnson to enhance PDF support, as well as numerous bug fixes provided
by him and other contributors.

For a complete log of changes since the last release, please see:

    http://cairographics.org/releases/ChangeLog.cairo-1.15.4

Features
--------
* The PDF backend has gained support for a range of widely used
  features, including thumbnails, page labels, metadata, document
  outlines, structured text, hyperlinks, and tags.  Tags permit adding
  logical info such as headings, tables, figures, etc. that facilitates
  indexing, accessibility, text reflow, searching, and extraction of the
  tagged items to other software.  For details on this new PDF
  functionality, see:

    https://lists.cairographics.org/archives/cairo/2016-June/027427.html


API Changes
-----------

  cairo_win32_surface_create_with_format

    Added a cairo API to set up Win32 surfaces for HDC with alpha
    channels.

  cairo_pdf_surface_add_outline
  cairo_pdf_surface_set_metadata
  cairo_pdf_surface_set_page_label
  cairo_pdf_surface_set_thumbnail_size
  cairo_tag_begin
  cairo_tag_end
  CAIRO_STATUS_TAG_ERROR

    New API for added PDF functionality (see above), and new error
    status item for problems relating to PDF tagging.

  CAIRO_STATUS_WIN32_GDI_ERROR
  CAIRO_STATUS_FREETYPE_ERROR
  CAIRO_STATUS_PNG_ERROR

    New error status items for handling of GDI, libfreetype, and libpng
    errors, respectively.

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
None

Bug Fixes
---------
* Bug fixes from 1.15.2 (see the 1.15.2 NEWS for details)

* Fix playback of recording surfaces into PDF surfaces, where objects
  with negative coordinates were not getting drawn.  To address this,
  the coordinate systems for PDF and PS have been changed to match
  cairo's coordinate system.  This allows recording surfaces to be
  emitted in cairo coordinates, and results in the same origin being
  used for all operations when using the recording surface XObject.
  Test cases for PDF and PS have also been updated accordingly.
  (Bug #89232)

* Fix "invalidfont" error on some printers when printing PDFs with
  embedded fonts that have glyphs (such as spaces) with
  num_contours == 0.  (Bug #79897)

* Fix missing glyphs such as thin dashes, which get scaled to 0 in
  userspace and thus have their drawing operations culled.  (Bug #94615)

* Fix other oddities caused by variously idiosyncratic fonts.

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

* Fix invalid execution of ASCII85 data by the PS interpreter that the
  image operator didn't use, by flushing the extraneous data after
  drawing the image.  (Bug #84811)

* Fix decoding of Adobe Photoshop's inverted CMYK JPEG files in PDF
  export.

* Fix unbounded surface assertion in win32-print code.

* Fix a data race in freed_pool discovered by Firefox's cairo usage.
  The patch adads atomic int load and store functions, with relaxed
  memory ordering.  (Bug #90318)

* Cleanup debugging text sent to stdout instead of log.	 (Bug #95227)

* Fix build issue when using non-GNU strings utility.  (Bug #88639)

* Fix build of cairo modules as regular modules, not as versioned shared
  libaries.  (Bug #29319)

* Fix build on win32 using gcc 5.4.

* Fix build of script backend to require zlib.

* Update test suite reference images using Debian Jessie 64-bit and
  poppler current as of June, 2016.

* Various improvements to documentation and tests, compiler warning
  fixes, and an assortment of code refactoring and cleanup.
