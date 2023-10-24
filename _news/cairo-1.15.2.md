---
title: cairo 1.15.2 release available
layout: news
date: 2015-12-10
---

A new cairo snapshot 1.15.2 is now available from:

  http://cairographics.org/snapshots/cairo-1.15.2.tar.xz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.15.2.tar.xz.sha1
    1948129ea5047332d79141a9de10558b9705583e  cairo-1.15.2.tar.xz

    http://cairographics.org/snapshots/cairo-1.15.2.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.15.2 tag which points to a commit named:
    db8a7f1697c49ae4942d2aa49eed52dd73dd9c7a

    which can be verified with:
    git verify-tag 1.15.2

    and can be checked out with a command such as:
    git checkout -b build 1.15.2

Release 1.15.2     (2015-12-10 Bryce Harrington <bryce@osg.samsung.com>)
========================================================================
This release is largely a rollup to include a variety of fixes that
didn't make the cut for the stable 1.14.2 and 1.14.4 releases, as well
as all the fixes from those releases.  Notably this includes a highly
requested new API for Win32 surfaces.

For a complete log of changes since the last release, please see:

    http://cairographics.org/releases/ChangeLog.cairo-1.15.2

Features
--------
None

API Changes
-----------

  cairo_win32_surface_create_with_format

    Added a cairo API to set up Win32 surfaces for HDC with alpha
    channels.

Dependency Changes
------------------
None

Performance Optimizations
-------------------------
None

Bug Fixes
---------
* All the bug fixes from 1.14.2, 1.14.4, and 14.6

* Fix xcb/xlib compilation and calls.  Make image boxes behave when SHM
  is not available.

* Fix various issues with printing and transparent images on Win32.

* Fix thin lines that don't show up when printing in Inkscape due to
  overly aggressive culling.
  (Bug #77298)

* Fix broken printing via pdf when glyph 0 is used for rendering,
  resulting in missing spaces and letters.
  (Bug #89082)

* Fix crash for certain glyphs in opentype fonts.
  (Bug #91902)

* Fix incorrect rendering of SVG paths with more than one subpath.  If
  more than one trap is passed in then it's guaranteed that the returned
  traps will have their left edge to the left of their right edge, but
  if only one trap is passed in then the function always returns without
  doing anything.
  (Bug #90984)

* Improve rendering with Quarts to better match pixman's blending and
  filtering behavior.

------------------------------------------------------------------------
Adam Jackson (2):
      xlib: Don't crash when swapping a 0-sized glyph
      xcb: Don't crash when swapping a 0-sized glyph

Adrian Johnson (24):
      Update mime type documentation.
      CFF: Fix unaligned access
      pdf: fix compiler warning
      build: fix regression on mingw
      pdf-operators: only wrap text strings for PS output
      Improve performance of cpu_to_be32 and be32_to_cpu
      pdf-operators: fix bug with RTL text
      doc: add index of new symbols in 1.14
      cff: ensure glyph widths are positive when font matrix yy is negative
      cff: opentype fonts always use gid to lookup glyph
      scaled-font-subsets: if glyph 0 used for rendering, remap to different index
      ps: merge emit_recording surface and emit_recording_subsurface into one function
      ps: fix raster source patterns
      ps: fix subsurface recordings
      pdf: fix subsurface recordings
      win32-print: Fix the page extents
      win32-print: fix warnings
      win32-print: support raster_source patterns
      Don't cull very thin lines on vector surfaces
      Add test case for thin lines
      Fix some surfaces missed in b1192bea
      Compile fix
      win32-print: support subsurface recording patterns
      Compile fix

Alban Browaeys (1):
      pattern: allow for a floating one pixel rounded difference.

Andrea Canciani (13):
      test: Release owned pattern
      test: Free test list
      font: Actually perform destruction of fonts
      quartz: Remove call to obsolete CGFontGetGlyphPath
      Update KNOWN_ISSUES documentation
      Update README with new minimum MacOSX requirements
      Harden make-cairo-test-constructors.sh
      test: Fix coverage-intersecting-triangles reference
      test: Correct bug number in clip-complex-bug61592
      test: Always use DejaVu Sans as default font
      test: Update quartz reference images
      quartz: Align filtering quality with image backend
      quartz: be more strict about the behavior of blend operators

Arpit Jain (3):
      xlib: Fix deferencing of uninitialised 'display'
      test/bitmap-font: Fix use of pointer after freed pointer
      gl: Fix incorrect size of expression

Ashim (1):
      Fix out of bound access in struct pattern->type

Behdad Esfahbod (3):
      [ft] Return CAIRO_STATUS_FILE_NOT_FOUND if font file can't be opened
      Oops, fixup previous commit
      Remove debug printf; ouch!

Bryce Harrington (69):
      Start 1.14.1 development
      RELEASING:  Update tags push command
      Add execution bit for make-cairo-test-constructors.sh
      Revert "Add execution bit for make-cairo-test-constructors.sh"
      RELEASING: Be explicit as to which tag is pushed
      Drop the target-specific huge-radial.pdf.*.ref.png images
      test: Use ARRAY_LENGTH macro
      Refactor ARRAY_LENGTH macro definitions in test code
      image: Fix crash in _fill_xrgb32_lerp_opaque_spans
      gitignore: logs, manuals
      doc: Drop extraneous para's
      git-ignore: Add build's test-driver
      Revert "xlib: Remove queued event from _XReadEvents"
      csi-trace:  Add --version and --help args to utility
      HACKING: Add link to git tutorial and wordsmith a bit
      NEWS: Update for changes through Nov 2014
      NEWS: Finish filling in changes
      On MacOSX, the sed utility errors out when parsing non-UTF8     files. Because of this, the generated cairo-test-constructor only     contained a few tests and the test suite was thus incomplete.
      NEWS: Note about the OS X support
      KNOWN_ISSUES:  Restore known issues file as a stub
      version: bump for cairo-1.14.2 release
      RELEASING:  Update contacts
      Start 1.14.3 development
      surface: Clarify flush documentation
      NEWS: Sp. fix
      Fix spellings descibed, indicies, stange
      Fix broken canvas text font size in Inkscape
      cairo-script: Improve buffer length check
      cairo-script: Always include config.h first thing
      cairo-script: Add missing copyright and boilerplate
      cairo-script: Cleanup boilerplate header for consistency
      cairo-script: Prefer cairo from local tree
      cairo-script: Rename struct member to avoid name collision on AIX
      cairo-script: Fix sp. "directoriy"
      cairo-recording-surface: Fix loss of alpha when clipping
      cairo-script: Return a cairo_status_t error, not FALSE
      RELEASING: Add requirement to upload ChangeLogs
      configure: Fix typo for missing line continuation character
      cairo-gl: Still check the value of the macros
      truetype: Drop redundant check of truetype struct
      Revert "pattern: allow for a floating one pixel rounded difference."
      Revert "cairo-gl: Fix compiler warning if CAIRO_HAS_*_FUNCTIONS is not defined."
      If more than one trap is passed in then it's guaranteed that the     returned traps will have their left edge to the left of their right     edge, but if only one trap is passed in then the function always returns     without doing anything.  This results in incorrect rendering of SVG     paths with more than one subpath.
      svg2png: Only call deprecated g_type_init() for old glib versions.
      test: Free the memory, not the pointer to the memory
      boilerplate: Fix list termination for glXChooseVisual
      NEWS: Fix date on release
      NEWS: Begin filling out news entry for upcoming 1.14.4.
      gitignore:  Ignore .trs (test results)
      test: Add script to summarize the test results from a run
      test: Add script to display the difference between two result sets
      Ensure null-terminated result from strncpy()
      build: Use memory barriers for ARM
      NEWS: Whitespace cleanup
      NEWS: Update to cover changes to date
      1.14.4 release
      WIP news and release
      NEWS: Update for 1.14.4 release
      RELEASING: Note how to upload the changelog
      RELEASING: Doc what's required to properly undo a publish
      Bump version for new development tree, 1.15.1
      RELEASING: Doc handling devel versions for micro vs minor releases
      test: Fix use after frees
      RELEASING: Whitespace cleanup.  Fix inconsistent tabbing.
      RELEASING: Fix misspelling in last commit
      RELEASING: Make X.Y.Z versions less ambiguous
      RELEASING: Drop inclusion of boilerplate in news messages
      RELEASING: Clarify snapshot numbering rules
      1.15.2 release

Chris Wilson (3):
      xlib: Bump reference count for recording surface replays
      Revert "xlib: Fix deferencing of uninitialised 'display'"
      xlib: Avoid using uninitialised variable on impossible error path

Emanuele Aina (1):
      cairo-trace: Fix duplicated surface push on similar-image

Fredrik Fornwall (1):
      Fix cairo_get_locale_decimal_point() on Android

Hans Breuer (1):
      win32: Fix compilation of 'cairo-path-stroke-traps.c' with MSVC8

Henry (Yu) Song (1):
      xlib: Remove queued event from _XReadEvents

John Lindgren (1):
      Avoid indiscriminate use of VALGRIND_MAKE_MEM_NOACCESS.

Julien Isorce (1):
      build: Show all disabled features in cairo-features.h

Koop Mast (1):
      cairo-gl: Fix compiler warning if CAIRO_HAS_*_FUNCTIONS is not defined.

Marc-André Lureau (1):
      xlib: fix mixing xcb & xlib calls

Massimo Valentini (6):
      tor-scan-converter: can't do_fullrow when intersection in row + 0.5subrow
      win32:  Fix crash from win32 surface's image size too small
      polygon-intersection: Do not discard intersection exactly at top edge
      polygon-intersection: Include approximation in intersection points
      polygon-intersection: Try not to invoke undefined behaviour
      polygon-intersection: Delete misleading comments and dead-code

Michael Haubenwallner (8):
      fix conflicting types for 'sync' on AIX, bug#89338
      skip MAP_NORESERVE when unsupported
      define _GETDELIM for getline() on AIX
      test: fix include order for AIX, bug#89354
      perf/micro: fix include order for AIX, bug#89354
      perf: fix include order for AIX, bug#89354
      headers: fix include order for AIX, bug#89354
      headers: fix include order for AIX, bug#89354

Nathan Froyd (1):
      Support new-style __atomic_* primitives

Patrick Fritzsch (1):
      win32: check if GetTextMetrics failed

Ravi Nanjundappa (2):
      Fix warnings from check-doc-syntax.sh
      Fix one more warning from check-doc-syntax.sh

Rodrigo Rivas Costa (1):
      win32-print: fix transparent images have black background

Sahil Vij (1):
      gl: Fix bug in _cairo_gl_pattern_texture_setup()

Uli Schlachter (7):
      tor-scan-converter: Correctly align 64bit types
      xcb: Query the display's subpixel order via RENDER
      xlib-xcb: Don't be lazy and use the real xcb_screen_t
      XCB: Don't attach uploaded surfaces as snapshots
      xcb: Fix _put_shm_image_boxes if no SHM available
      xcb: Fix _put_image_boxes() if no SHM is available
      Fix cairo-xlib-xcb compilation

Zan Dobersek (1):
      Manually transpose the matrix in _cairo_gl_shader_bind_matrix()

Руслан Ижбулатов (2):
      win32: Add cairo API to set up a Win32 surface for an HDC with an alpha channel.
      win32: Add a win32 boilerplate that uses a real window

江頭幸路 (1):
      Avoid appending an empty slot to an user data array when user_data is NULL.
