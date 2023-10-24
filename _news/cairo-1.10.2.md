---
title: cairo 1.10.2 release available
layout: news
date: 2010-12-25
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, ftp-release@lists.freedesktop.org
Subject:  cairo release 1.10.2 now available

Happy New Year everybody! Here's a belated announcement:

A new cairo release 1.10.2 is now available from:

http://cairographics.org/releases/cairo-1.10.2.tar.gz

    which can be verified with:

http://cairographics.org/releases/cairo-1.10.2.tar.gz.sha1
ccce5ae03f99c505db97c286a0c9a90a926d3c6e  cairo-1.10.2.tar.gz

http://cairographics.org/releases/cairo-1.10.2.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.10.2 tag which points to a commit named:
4938e11ffe11781e4e294092807ebc67f362eac6

    which can be verified with:
git verify-tag 1.10.2

    and can be checked out with a command such as:
git checkout -b build 1.10.2

Release 1.10.2 (2010-12-25 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
The cairo community is pleased to announce the 1.10.2 release of the
cairo graphics library. This is the first update to cairo's stable 1.10
series and contains a large number of bug fixes.

While many people have contributed and have help to test the release,
2 people deserve special recognition for their efforts in tracking down
and fixing bugs, Andrea Canciani and Adrian Johnson. Thanks to their
tremendous efforts, and of all cairo contributors, it is much
appreciated.

We recommend everyone upgrade to cairo 1.10.2 and hope that everyone
will continue to have lots of fun with cairo!

-Chris

Bug fixes
---------

  Fix embedding of grayscale jpegs in PS.
  https://bugs.freedesktop.org/show_bug.cgi?id=31632

  Fix the reported path of extents containing a curve.

  Fix the compositing of unaligned boxes.

  Reset the clipper in PDF upon finish.

  Fix degenerates arcs to become a degenerate line.

  Build support for autoconf 2.67

  Fix painting of transformed patterns in PS

  Fix the EPS bounding box for PS
  https://bugs.freedesktop.org/show_bug.cgi?id=24688

  Fix the missing content for EPS
  https://bugs.freedesktop.org/show_bug.cgi?id=24688

  Fix regression upon changing page size in PS/PDF
  https://bugs.freedesktop.org/show_bug.cgi?id=24691

  Only use ActualText with PDF-1.5 documents

  Fix the bbox for type1 fallbacks.

  Reset the color after ending the context in PDF
  https://bugs.freedesktop.org/show_bug.cgi?id=31140

  Fix the advance of subsetted type1 fonts
  https://bugs.freedesktop.org/show_bug.cgi?id=31062

  Fix handling of EXTEND_NONE gradients for PDF

  Restrict in-place optimisation for a8 image masks with SOURCE

List of all changes between 1.10.0 and 1.10.2
---------------------------------------------

Adrian Johnson (12):
      Fix font metrics in PDF Type 1 fonts
      pdf-operators: fix bug that was causing unnecessary repositioning of text
      PDF: Fix regression in EXTEND_NONE gradients
      Type 1 subset: Fix glyph advance
      PDF: Don't use the currently set color  after a 'Q' operator
      configure.ac.features: s/Meta/Recording/     (cherry picked from commit 8f
      Fix type1-fallback bbox     (cherry picked from commit 74873c82242e9c124b6
      PDF: Restrict ActualText to PDF version >= 1.5
      PS/PDF: Fix regression when changing page size to a larger size
      PS: Fix regression - missing page content in EPS output
      PS: Fix regression - incorrect EPS bounding box
      PDF: Add missing clipper_reset     (cherry picked from commit 2ae2be36d455

Andrea Canciani (14):
      test: do not leak resources
      image: add _cairo_image_reset_static_data
      test: do not leak resources
      image: Use correct size for allocation
      ps: Fix painting
      configure: Correct reporting of tee backend
      Fix degenerate arcs
      test: Add romedalen images copyright information
      xcb: Do not return value in void function
      test: Add rectilinear-grid
      image: Fix compositing of unaligned boxes
      test: Fix ref images
      test: Add bug-extents
      path-bounder: Update current point after curve_to op

Benjamin Otte (1):
      build: Don't build cairo-fdr when the tee surface is off

Carlos Garcia Campos (4):
      doc: Add section for recording surface
      recording: Add section doc comments
      recording: Fix cairo_recording_surface_create() doc comments
      recording: Document CAIRO_HAS_RECORDING_SURFACE macro

Chris Wilson (10):
      version: 1.10.1 open for bugfixing
      configure: Fix typo "(requires both --enable-xcb)"
      cairo: Remove trailing comma from cairo_device_t
      drm: Add missing header file for tarball
      image: Silence a compile warning
      test: Add a8-clear
      image: The a8 in-place span compositing is only valid for SOURCE
      Add a KNOWN_ISSUES file to track WONTFIX(?) bugs
      NEWS: Add entry for 1.10.2
      version: Bump for 1.10.2 release

Erik Zeek (1):
      Fix build on gentoo

Jeff Muizelaar (1):
      Fix degenerate vertical path bounds.

Joerg Sonnenberger (1):
      LD_PRELOAD is supported on DragonFly.

Koji Otani (1):
      PS: fix embedding of grayscale jpegs

Kouhei Sutou (1):
      xml: fix a typo to correct the indentation after <path></path>

Markus Stange (1):
      Fix type of _cairo_memory_stream_destroy parameter

Tim Janik (1):
      cairo: docu fix for cairo_set_source_surface

Tomáš Chvátal (1):
      Fix posix calls in configure.ac test code.
```
