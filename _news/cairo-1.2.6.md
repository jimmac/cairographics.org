---
title: cairo 1.2.6 release available
layout: news
date: 2006-11-02
---
```

From:   Behdad Esfahbod <besfahbo@redhat.com>
Date:   2 Nov 2006
To:     cairo-announce@cairographics.org
Cc:     gnome-announce-list@gnome.org
Subject:        cairo release 1.2.6 now available

A new cairo release 1.2.6 is now available from:

        http://cairographics.org/releases/cairo-1.2.6.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.2.6.tar.gz.sha1
        b86b4017a9abd565ef11c72b7faee9082a04118f  cairo-1.2.6.tar.gz

        http://cairographics.org/releases/cairo-1.2.6.tar.gz.sha1.asc
        (signed by Behdad Esfahbod)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.2.6 tag which points to a commit named:
        8878bbc549a01868853ff6270b986e57c6474d88

    which can be verified with:
        git verify-tag 1.2.6

    and can be checked out with a command such as:
        git checkout -b build 1.2.6


This is the third bug fix release in the 1.2 series, coming less than
two months after the 1.2.4 release made on August 18.

The 1.2.4 release turned out to be a pretty solid one, except for a crasher
bug when forwarding an X connection where the client and the server have
varying byte orders, eg. from a PPC to an i686.  Other than that, various
other small bugs have been fixed.

Various improvements have been made in the testing infrastructure to prevent
false positives, and to make sure the generated cairo shared object behaves as
expected in terms of exported symbols and relocations.

There were a total of 89 changes since 1.2.4.  The following list the most
important ones:

Common fixes
------------
- Avoid unsigned loop control variable to eliminate infinite,
  memory-scribbling loop. (#7593)
- Fix cairo_image_surface_create to report INVALID_FORMAT errors.
  Previously the detected error was being lost and a nil surface was
  returned that erroneously reported CAIRO_STATUS_NO_MEMORY.
- Change _cairo_color_compute_shorts to not rely on any particular
  floating-point epsilon value. (#7497)
- Fix infinite-join test case (bug #8379)
- Pass correct surface to create_similar in _cairo_clip_init_deep_copy().

PS/PDF fixes
------------
- Fix Type 1 embedding in PDF.
- Correct the value of /LastChar in the PDF Type 1 font dictionary.
- Improve error checking in TrueType subsetting.
- Compute right index when looking up left side bearing. (bug #8180)
- Correct an unsigned to signed conversion problem in truetype subsetting
  bbox.
- Type1 subsetting: Don't put .notdef in Encoding when there are 256 glyphs.
- Add cairo version to PS header / PDF document info dictionary.
- Set CTM before path construction.

Win32 fixes
-----------
- Get correct unhinted outlines on win32. (bug 7603)
- Make cairo as a win32 static library possible.
- Use CAIRO_FORMAT_RGB24 for BITSPIXEL==32 surfaces too.

Build system fixes
------------------
- Define WINVER if it's not defined. (bug 6456)
- Fix the AMD64 final link by removing SLIM from pixman.
- Misc win32 compilation fixes.
- Add Sun Pro C definition of pixman_private.
- Use pixman_private consistently as prefix not suffix.
- Added three tests check-plt.sh, check-def.sh, and check-header.sh that check
  that the shared object, the .def file, and the public headers agree about
  the exported symbols.
- Require pkg-config 0.19. (#8686)


And like every time, have fun with cairo!

behdad


What is cairo
=============
Cairo is a 2D graphics library with support for multiple output
devices. Currently supported output targets include the X Window
System, win32, and image buffers, as well as PDF, PostScript, and SVG
file output. Experimental backends include OpenGL (through glitz),
Quartz, XCB, BeOS, and DirectFB.

Cairo is designed to produce consistent output on all output media
while taking advantage of display hardware acceleration when available
(for example, through the X Render Extension).

The cairo API provides operations similar to the drawing operators of
PostScript and PDF. Operations in cairo including stroking and filling
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
=========================================
The primary source of information about cairo is:

        http://cairographics.org/

The latest releases of cairo can be found at:

        http://cairographics.org/releases

Snapshots of in-development versions of cairo:

        http://cairographics.org/snapshots

The programming manual for using cairo:

        http://cairographics.org/manual

Mailing lists for contacting cairo users and developers:

        http://cairographics.org/lists

Answers to some frequently asked questions about cairo:

        http://cairographics.org/FAQ


Detailed list of changes since 1.2.4
====================================

Adrian Johnson:
      Get correct unhinted outlines on win32.
      Fix Type 1 embedding in PDF
      Correct the value of /LastChar in the PDF Type 1 font dictionary.
      Improve error checking in TrueType subsetting
      Correct an unsigned to signed conversion problem in truetype subsetting bbox
      Type1 subsetting: Don't put .notdef in Encoding when there are 256 glyphs
      PS: Add cairo version to PS header
      PDF: Add cairo version to document info dictionary

Alfred Peng:
      Add Sun Pro C definition of pixman_private
      Use pixman_private consistently as prefix not suffix

Behdad Esfahbod:
      [Makefile.am] Remove unnecessary parantheses that were causing trouble with old bash
      [ROADMAP] Add glyph cache inspection to 1.4 roadmap
      [TODO] Add cairo_get_scaled_font
      [ROADMAP] Remove 1.2.4 stuff out of the way
      [test] bufferdiff: take abs of the pixel diffs.  Oops!
      [image] Print out cairo version in the unsupported-format message
      Bug #7593: Avoid unsigned loop control variable to eliminate infinite, memory-scribbling loop.
      [xlib] Bug 7593: rewrite loop to be more readable, and fix warnings
      [PNG] Mark status volatile to fix gcc warning
      [test] Add 128 to any diff component such that differences are visible
      [test] Use $(srcdir) to find valgrind supressions
      [test] Use FcFreeTypeQuery
      [configure] Invalidate cached warning flags if list of flags changes
      Add scripts to sanity check the shared object for exported and PLT symbols
      [x86-64] check-plt.sh: match on JU?MP_SLO as on x86-64 "SLOT" is truncated
      check-headers.sh:  Add a test for cairo_public decorators in public headers
      cairo-pdf.h: Add missing cairo_public decorators
      cairo-directfb.h: Add missing cairo_public decorators
      check-def.sh: Only allow _cairo_.*_test_.* symbols, not all _cairo.* ones
      [configure] Print out whether SVG and PDF surfaces can be tested
      [check-headers.sh] Don't use '\>' regexp syntax
      [Makefile.am] Pass srcdir down to the tests
      [slim] hide cairo_glitz_surface_create() (#8551)
      [configure.in] Require pkg-config 0.19. (#8686)
      [PDF] Set CTM before path construction
      [slim] hide cairo_pattern_status() #8551
      [win32] Remove _cairo_win32_surface_show_glyphs()
      Add notes for the 1.2.6 release.
      Makefile.am: Remove boilerplate out of DIST_SUBDIRS
      [doc] Update templates prior to release
      Released cairo-1.2.6.

Carl Worth:
      Increment version to 1.2.5 after making the 1.2.4 release
      Add -Wextra (as well as -Wno-missing-field-initializers -Wno-unused-parameter)
      Put static first to avoid compiler warning.
      Eliminate conditions checking for unsigned or enum values less than 0.
      test: Add link to test log file in HTML output
      Require librsvg >= 2.14.0 to test SVG backend
      bug 8104: Eliminate unused variables. Replicate assert statement to identify branch of interest.
      pixman: Add pixman_private decorations to hide pixman symbols from public interface
      Add many missing slim_hidden calls to bypass PLT entries for local use of public functions
      slim_hidden_proto: Move smeicolon from definition to use for consistency and legibility
      RELEASING: Add note on checking for local symbol PLT entries.
      Make _cairo_output_stream_destroy return the stream's status as a last gasp.
      Use new return value from _cairo_output_stream_destroy
      test/bitmap-font: Fix arguments to FcFreeTypeQuery to avoid warnings.
      Fix typo in error message (enhacement -> enhancement)
      Add missing pixman_private to _FbOnes when a function.
      Fix cairo_copy_path and cairo_copy_path_flat to propagate errors.
      Rename test from stale path-data name to copy-path
      Fix typo in documentation of cairo_in_fill (thanks to Jonathan Watt) and clarify a bit.
      Fix Makefile bug preventing 'make doc' from succeeding
      Rename docs-publish target to doc-publish in order to be consistent with the doc target.
      Fix dependency of 'make doc' so that necessary header files are built first.
      Fix cairo_image_surface_create to report INVALID_FORMAT errors.
      Add new _cairo_pattern_create_for_status so that patterns properly propagate errors.
      Fix typo that was resulting in device glyph_extents of INT16_MAX in some cases.
      Bug #7497: Change _cairo_color_compute_shorts to not rely on any particular floating-point epsilon value.
      Add test case from bug #8379 demonstrating infinite loop during round join
      Add assert statement so the infinite-join test simply exits rather than looping infinitely.
      test/infinite-join: Modify to draw something visible, and make the output a more reasonable size.
      Fix infinite-join test case (bug #8379)
      Add neglected reference images for infinite-join test
      test: Update reference images due to previous change to _cairo_color_compute_shorts
      test: Remove custom read/write-png code in favor of using cairo surfaces
      test: Ignore single-bit errors for SVG backend.
      Move target tolerance to cairo_test_target structure (should let single-pixel SVG errors pass)
      Make xlib and xcb backends tolerant of single-bit errors in the test suite output.

Christian Biesinger:
      [beos] Fix build error
      fix comment: pixman_private needs to be before the type of a variable
      Add missing ) in comment

Jamey Sharp:
      [slim] hide cairo_version_string()

Kristian Høgsberg:
      Compute right index when looking up left side bearing.

Miklós Erdélyi:
      Pass correct surface to create_similar in _cairo_clip_init_deep_copy()

Nicholas Miell:
      Fix the AMD64 final link by removing SLIM from pixman
      Make the SLIM macros robust in the face of macro-renamed symbols

Robert O'Callahan:
      Remove redundant call to _cairo_surface_get_extents

Tor Lillqvist:
      [win32] Use CAIRO_FORMAT_RGB24 for BITSPIXEL==32 surfaces too

Vladimir Vukicevic:
      [win32] Make cairo as a win32 static library possible
      [win32] Misc win32 compilation fixes
      Correctly acquire/release mutex in _cairo_scaled_font_map_destroy

Yevgen Muntyan:
      Define WINVER if it's not defined. (bug 6456)
```
