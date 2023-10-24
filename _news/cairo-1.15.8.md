---
title: cairo 1.15.8 development snapshot available
layout: news
date: 2017-08-29
---

Subject: cairo snapshot 1.15.8 now available

A new cairo snapshot 1.15.8 is now available from:

  http://cairographics.org/snapshots/cairo-1.15.8.tar.xz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.15.8.tar.xz.sha1
    07cc2031b74d758299eeee3ec49ecbfbfb85f1c6  cairo-1.15.8.tar.xz

    http://cairographics.org/snapshots/cairo-1.15.8.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.8 tag which points to a commit named:
    112f0fc73b769c2db69f50601bf094892bd6db10

    which can be verified with:
    git verify-tag 1.15.8

    and can be checked out with a command such as:
    git checkout -b build 1.15.8


Features and Enhancements
-------------------------
* Support colored emoji glyphs, stored as PNG images in OpenType fonts.


Bug Fixes
---------

* pdf: Fix internal links pointing to other pages, by pre-calculating page
  heights so that link positions can be calculated more accurately.

* image: Fix crash on negative lengths

* win32: Fix initialization of mutexes for static builds

* pdf: Don't emit /PageLabel dict when no labels defined

* font: Fix color font loading on big-endian systems

* font: Fix color font support infinite-loop with empty glyphs

* Fix off by one check in cairo-image-info.c


Full List of Changes
--------------------
   Adrian Johnson (8):
      Fix off by one check in cairo-image-info.c
      tests: fix bug in pdf-tagged-text that was introduced in 4790a36
      pdf: link tags do not need to be leaf nodes in the document structure
      pdf: Don't emit /PageLabel dict when no labels defined
      pdf: don't write logical structure if it only contains links
      pdf: fix link positions
      pdf: use link attributes instead of dest name for cairo_pdf_surface_add_outline
      pdf: use explicit dest instead of named dest when 'internal' attribute is set

   Alexander Täschner (1):
      win32: Initialize mutexes for static builds for win32

   Behdad Esfahbod (3):
      Fix color font support infinite-loop with empty glyphs
      Fix uninitialized status!
      [ft] Fix color font loading on big-endian systems

   Bryce Harrington (6):
      Bump version for new development tree, 1.15.7
      RELEASING: Note use of branches for stable releases
      RELEASING: Note adding index to cairo-docs.xml for minor releases
      cairo-docs: whitespace cleanup
      image: Disambiguate 0. in doxygen
      1.15.8 release

   Doran Moppert (1):
      image: Check for negative len in fill/blit functions

   Guillermo Rodriguez (2):
      script: Fix misleading indentation warning.
      Remove redundant check.

   Matthias Clasen (6):
      Add support for color glyphs to cairo_scaled_glyph_t
      Support loading color glyphs with freetype
      Expose 'has color glyphs' as a scaled font property
      Implement has_color_glyphs for freetype
      Render color glyphs as source, not as mask
      Simplify things a bit


What is Cairo
-------------
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


Where to get more information about Cairo
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

