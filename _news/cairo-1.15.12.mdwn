---
title: cairo 1.15.12 release available
layout: news
date: 2018-04-11
---

Subject: cairo snapshot 1.15.12 now available

A new cairo snapshot 1.15.12 is now available from:

  http://cairographics.org/snapshots/cairo-1.15.12.tar.xz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.15.12.tar.xz.sha1
    4e64c6a48789edb4c60bc3fa95bd3992cc388b88  cairo-1.15.12.tar.xz

    http://cairographics.org/snapshots/cairo-1.15.12.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.12 tag which points to a commit named:
    7149686456ec3c481fa1d3dbe76a0dab1e42b519

    which can be verified with:
    git verify-tag 1.15.12

    and can be checked out with a command such as:
    git checkout -b build 1.15.12


Release 1.15.12    (2018-04-04 Bryce Harrington <bryce@osg.samsung.com>)
========================================================================
The main focus for this release is the addition of Variable Font
support.  Variable fonts are single font files with various typography
characteristics, such as weight or slant, that users of the font can
adjust between two points.  Effectively this enables a single font to
behave as multiple fonts.

The Skia backend is disabled in this release, due to severe bitrot, and
will be removed in future releases.  Contact the cairo team if you have
a need of this backend.

For a complete log of changes, please see

    http://cairographics.org/releases/ChangeLog.cairo-1.15.12

Features and Enhancements
-------------------------
* Variable font support
* Skia backend is disabled

API Changes
-----------
* cairo_font_options_get_variations() and
  cairo_font_options_set_variations() are added.

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
None

Bug Fixes
---------
* Fix errors in csi-trace --help and --version options
* Fix a 'memory leak' in the image compositor, with
  pixman_glyph_cache_t.
* Fix access of uninitialized memory found by valgrind
  (Bug #91271)
* Fix improper initialization of memory in
  _cairo_ft_font_face_create_for_pattern()
  (Bug #105084)
* Fix multi-monitor virtual desktop with negative coords on Win32
  (Bug #100793)
* Fix issues occuring with older FreeType versions.


What is cairo
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



Changes since 1.15.10
---------------------

Adrian Johnson (1):
      ps: fix compile warning

Antonio Ospite (1):
      svg: fix compilation with MSVC which doesn't support C99 initializers

Behdad Esfahbod (13):
      [variations] Towards fixing test
      [variations] Fix test
      [variations] Merge variations in cairo-ft font option merging
      [varfonts] Use blend, not design, coordinates to check for non-base variation
      [varfonts] Correctly (re)set variations of named instances
      [ft] Use variations from ft_options, not scaled-font
      [ft] When merging font options, order variations correctly
      [ft] Fix warnings
      [ft] Remember variations set on FT_Face and apply them
      Merge branch 'font-variations'
      Use FT_Done_MM_Var() if available
      Fix compile with older FreeType without FT_Get_Var_Design_Coordinates
      Fixup on previous commit

Bryce Harrington (18):
      1.15.10 release
      1.15.10 release
      Bump version for new development tree, 1.15.9
      svg: Label for cairo_svg_unit_t doxygen was incorrect
      makefile: Fix sorting of source files
      test: Fix compile with older FreeType without FT_Get_Var_Design_Coordinates
      RELEASING: Refine devel version and tagging
      Fix two type casting warnings in get_C_locale()
      font: Check return value from _cairo_ft_unscaled_font_lock_face
      xml: Typo in comment
      win32: Whitespace cleanup
      win32: Fix a few typos in comments
      compiler-private: Define what PLT stands for
      cairo-version: Fix version references in docs
      Disable skia from configure
      configure: Conditionalize color font feature for older freetype2
      1.15.12 release
      Bump version for new development tree, 1.15.13

Eric Hoffman (1):
      win32: Fix multi-monitor virtual desktop with negative monitor coords

Federico Mena Quintero (2):
      Add .gitlab-ci.yml to run the tests automatically
      bfo#105084 - Initialize memory properly in _cairo_ft_font_face_create_for_pattern()

Massimo (1):
      bfo#91271 - Fix access of uninitialized memory

Matthias Clasen (21):
      Fix a logic error in color glyph compositing
      Make _intern_string_hash safe for ""
      Make _intern_string_hash non-static
      Add font variations to font options
      Load font variations from fontconfig too
      Use strtod_l when available
      Apply font variations when loading fonts
      Add a test for font variations
      Work around a freetype bug
      Make the font-variations test pass
      Apply font variation options consistently
      Always save the origin face index
      Trivial: code movement
      Apply font variations when loading glyphs
      fixup: remove a hack
      fixup
      Shortcut FT_Set_Var_Design_Coordinates
      Fix a memory leak
      Don't leak patterns when compositing color glyphs
      Add a _cairo_font_options_fini function
      Don't leak memory in font options

Uli Schlachter (7):
      Revert "fix warning: variable X might be clobbered by 'longjmp'"
      Add test for error handling with broken PNG streams
      Fix warning: '*' in boolean context
      fix warning: variable X might be clobbered by 'longjmp'
      Fix a 'memory leak' in the image compositor
      Skip font-variations test for missing fonts
      pthread-same-source: Refresh reference images

Unknown (1):
      Cairo trivial typos

suzuki toshiya (1):
      csi-trace does not show help
