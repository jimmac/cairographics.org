---
title: cairo 1.15.10 release available
layout: news
date: 2017-12-14
---
```
Subject: cairo snapshot 1.15.10 now available

A new cairo snapshot 1.15.10 is now available from:

  http://cairographics.org/snapshots/cairo-1.15.10.tar.xz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.15.10.tar.xz.sha1
    de180498ac563249b93ee5e17ba9aa26f90644b3  cairo-1.15.10.tar.xz

    http://cairographics.org/snapshots/cairo-1.15.10.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.10 tag which points to a commit named:
    95c464d5feaae58b6cc0990434ce2498cc315dc6

    which can be verified with:
    git verify-tag 1.15.10

    and can be checked out with a command such as:
    git checkout -b build 1.15.10

Release 1.15.10    (2017-12-07 Bryce Harrington <bryce@osg.samsung.com>)
========================================================================
This release adds GLESv3 support to the cairo_gl backend, adds
tracking of SVG units in generated svg documents, and cleans up numerous
test failures and related issues in the PDF and Postscript backends.

For a complete log of changes, please see

    http://cairographics.org/releases/ChangeLog.cairo-1.15.10

Features and Enhancements
-------------------------
* Add support for OpenGL ES 3.0 to the gl backend.
* Use Reusable streams for forms in Level 3 Postscript.
* Add CAIRO_MIME_TYPE_EPS mime type for embedding EPS files.
* Add CCITT_FAX mime type for PDF and PS surfaces
* svg: add a new function to specify the SVG document unit
  (Bug #90166)
* Use UTF-8 filenames on Windows

API Changes
-----------
* cairo_svg_surface_set_document_unit() and
  cairo_svg_surface_get_document_unit()

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
None

Bug Fixes
---------
* Fix regression in gles version detection
* Fix undefined-behavior with integer math.
* Handle SOURCE and CLEAR operators when painting color glyphs.
  (Bug #102661)
* Convert images to rgba or a8 formats when uploading with GLESv2
* Use _WIN32 instead of windows.h to check for windows build.
* Fix sigabrt printing documents with fonts lacking the mandatory .nodef
  glyph.
  (Bug #102922)
* Prevent curved strokes in small ctms from being culled from vector
  surfaces
  (Bug #103071)
* Fix painting an unbounded recording surface with the SVG backend.
* Fix falling back to system font with PDFs using certain embedded
  fonts, due to truncated font names.
  (Bug #103249)
* Fix handling of truetype fonts with excessively long font names
  (Bug #103249)
* Fix race conditions with cairo_mask_compositor_t
  (Bug #103037)
* Fix build error with util/font-view
* Fix assertion hit with PDFs using Type 4 fonts rendered with user
  fonts, due to error when destroying glyph page.
  (Bug #103335)
* Set default creation date for PDFs
* Prevent invalid ptr access for > 4GB images.
  (Bug #98165)
* Prevent self-copy infinite loop in Postscript surface.
* Fix padded image crash in Postscript surface.
* Fix annotation bugs in PDFs and related memory leaks
* Fix test failures and other assorted issues in ps and pdf code.
* Fix code generation when using GCC legacy atomic operations
  (Bug #103559)
* Fix various compilation warnings and errors.
* Fix various distcheck errors with private symbols, doxygen formatting,
  etc.

See below for a complete log of changes since 1.15.8, or see:

    http://cairographics.org/releases/ChangeLog.cairo-1.15.10



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



Changes since 1.15.8
--------------------

Adrian Johnson (47):
      RELEASING: use correct branch name
      Remove unused variable
      build: use _WIN32 instead of windows.h to check for windows build
      replace _BSD_SOURCE with _DEFAULT_SOURCE
      factor out ascii to double code in cff-subset into _cairo_strtod
      truetype: reserve space in subset arrays for .notdef
      truetype: clarify glyph count variables
      Prevent curved strokes in small ctms from being culled from vector surfaces
      svg: fix painting an unbounded recording surface
      output-stream: allow %s strings larger than 512 chars
      truetype: limit font name to 127 chars
      svg: use hash table instead of user_data to track emitted surfaces
      svg: source surface hash table does not need to hold the source
      svg2png: remove unused headers
      ft: prevent unused var warning when freetype < 2.8
      fix unused function warnings
      svg: recording_surface is needed even if not emitted
      fix warning: variable X might be clobbered by 'longjmp'
      fix warning: inlining failed in call to '_csi_stack_push'
      util/font-view: fix build error
      Add CCITT_FAX mime type for PDF and PS surfaces
      Allow mime image to be different size to cairo image
      pdf: set ca/CA instead of using an smask when the mask has constant alpha
      pdf: set default create date
      pdf: remove old comment
      image: prevent invalid ptr access for > 4GB images
      Add mime-unique-id test
      pdf: fix mime-unique-id bounded recording test
      pdf: fix mime-unique-id unbounded recording test
      pdf: fix mime-unique-id jpeg attached to recording test
      ps: emit base85 strings instead of strings of base85
      ps: remove unused prolog
      ps: use << >> for dictionaries instead of dict begin end
      ps: don't acquire image or snapshot in acquire_source_image_from_pattern
      ps: use forms for surfaces with UNIQUE_ID mime type
      ps: use Reusable streams for forms in Level 3
      ps: add CAIRO_MIME_TYPE_EPS mime type for embedding EPS files
      test: use CAIRO_MIME_TYPE_UNIQUE_ID with record-text-transform
      ps: prevent self-copy infinite loop
      ps: fix padded image crash
      ps: fix extend-*-similar failures
      test: update some stale ref images
      pdf: fix document structure for non tagged structures
      ps: fix compile with old versions of MSVC
      pdf: fix some annotation bugs
      Prevent -Wundef warnings in when cairo-ft.h is used without fontconfig
      ps: fix compile warning

Aleksander Morgado (1):
      build: fix minor typo in autogen.sh

Antonio Ospite (2):
      svg: add a new function to specify the SVG document unit
      svg: fix compilation with MSVC which doesn't support C99 initializers

Behdad Esfahbod (2):
      Fix undefined-behavior with integer math
      Handle SOURCE and CLEAR operators when painting color glyphs

Bryce Harrington (15):
      Bump version for new development tree, 1.15.9
      glesv2: Fix regression in gles version detection
      gl: Convert images to rgba or a8 formats when uploading with GLESv2
      gl: Make _cairo_gl_ensure_framebuffer a private shared routine
      gl: Add support for OpenGL ES 3.0
      Factor out the ISFINITE() macro
      configure: Check for typeof
      Un-doxygen disabled cairo_set_opacity
      image: Fix include for use of ptrdiff
      win32: Fix since field version number
      Fix various doxygen warnings found by check-doc-syntax.sh
      Fix distcheck errors on use of #ifdef
      pattern: Mark a private routine as cairo_private.
      1.15.10 release
      Bump version for new development tree, 1.15.9

Carlos Garcia Campos (1):
      scaled-font: Fix assert when destroying glyph page

Mikhail Fludkov (2):
      Surround initialisations with atomic critical section
      Fix code generation when using GCC legacy atomic operations

Tom Schoonjans (1):
      Use UTF-8 filenames on Windows

```
