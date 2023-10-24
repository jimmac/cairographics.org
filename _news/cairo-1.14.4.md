---
title: cairo 1.14.4 release available
layout: news
date: 2015-10-28
---
```

A new cairo release 1.14.4 is now available from:

  http://cairographics.org/releases/cairo-1.14.4.tar.xz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.14.4.tar.xz.sha1
    5b44471e7c328f96de6830baf8ea65030de797f9  cairo-1.14.4.tar.xz

    http://cairographics.org/releases/cairo-1.14.4.tar.xz.sha1.asc
    (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.14.4 tag which points to a commit named:
    0317ee7f61f1f4d154f7cb7e56d2b1080c2c644a

    which can be verified with:
    git verify-tag 1.14.4

    and can be checked out with a command such as:
    git checkout -b build 1.14.4


Release 1.14.4    (2015-10-28  Bryce Harrington <bryce@osg.samsung.com>)
========================================================================
Just in time for Halloween we see another bug-fix release for Cairo.
This brings a few dozen straightforward bug fixes with no API changes.

In addition, this includes a typical assortment of fixes to tests,
cleanup of warnings and memory leaks, correction of misspellings,
updates to documentation, etc.

For a complete log of changes since 1.14.2, please see:

    http://cairographics.org/releases/ChangeLog.cairo-1.14.4


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
* Avoid appending empty slots to user data arrays.  Fixes a memory
  consumption regression since commit 9341c254a.

* Return a better error (file-not-found) when setting up pango on
  devices where the font files don't have read permissions.

* Fix regression in the font size of canvas text in Inkscape when
  compiled with the Quartz backend.  (Bug #84324)

* Fix _cairo_gl_shader_bind_matrix() to maintain compatibility with
  OpenGL ES 2.0.  Manually transpose the matrix.

* Fix incorrect font descriptor conversion when the font matrix yy is
  negative. (Bug #90538)

* Fix crash when using a complex path for clip and stroke due to
  discarding the intersection exactly at the top edge.
  (Bug #74779)

* Fix cairo_get_locale_decimal_point() on Android

* Fix compilation problem on AIX due to conflicting usage of symbol
  'jmpbuf'.  (Bug #89339)

* Fix broken rendering with XCB due to snapshotting of uploaded part of
  surfaces.  (Bug #67505)

* Fix loss of alpha when copying a mask for a cairo recording surface,
  resulting in a double copy.  (Bugs #73038, #73901)

* Fix incorrect recording of certain paths with script surfaces.
  (Bug #91054)

* Fix typo in definition of MAYBE_WARN in configure script.
  (Bug #89750)

* Fix use of filename variable after it's been freed.
  (Bug #91206)

* Fix out of bounds access when printing pattern.
  (Bug #91266)

* Fix incorrect size calculation in glyph cache unlocking for Cairo GL
  compositor.
  (Bug #91321)

* Fix memory leak in _cairo_gl_pattern_texture_setup()
  (Bug #91537)

* Fix transparent images in win32-print.
  (Bug #91835)

* Fix _put_shm_image_boxes and _put_image_boxes when no SHM available
  with XCB.


------------------------------------------------------------------------
Adam Jackson (2):
      xlib: Don't crash when swapping a 0-sized glyph
      xcb: Don't crash when swapping a 0-sized glyph

Adrian Johnson (9):
      Update mime type documentation.
      CFF: Fix unaligned access
      pdf: fix compiler warning
      build: fix regression on mingw
      pdf-operators: only wrap text strings for PS output
      Improve performance of cpu_to_be32 and be32_to_cpu
      pdf-operators: fix bug with RTL text
      doc: add index of new symbols in 1.14
      cff: ensure glyph widths are positive when font matrix yy is negative

Alban Browaeys (1):
      pattern: allow for a floating one pixel rounded difference.

Andrea Canciani (9):
      test: Release owned pattern
      test: Free test list
      font: Actually perform destruction of fonts
      quartz: Remove call to obsolete CGFontGetGlyphPath
      Update KNOWN_ISSUES documentation
      Update README with new minimum MacOSX requirements
      Harden make-cairo-test-constructors.sh
      test: Fix coverage-intersecting-triangles reference
      test: Correct bug number in clip-complex-bug61592

Arpit Jain (2):
      test/bitmap-font: Fix use of pointer after freed pointer
      gl: Fix incorrect size of expression

Ashim (1):
      Fix out of bound access in struct pattern->type

Behdad Esfahbod (1):
      [ft] Return CAIRO_STATUS_FILE_NOT_FOUND if font file can't be opened

Bryce Harrington (44):
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
      On MacOSX, the sed utility errors out when parsing non-UTF8 files
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
      configure: Fix typo for missing line continuation character
      test: Free the memory, not the pointer to the memory
      boilerplate: Fix list termination for glXChooseVisual
      Ensure null-terminated result from strncpy()
      Revert "pattern: allow for a floating one pixel rounded difference."
      Revert "win32: Add cairo API to set up a Win32 surface for an HDC with an alpha channel."
      NEWS: Update for 1.14.4 release
      1.14.4 release

Chris Wilson (1):
      xlib: Bump reference count for recording surface replays

Emanuele Aina (1):
      cairo-trace: Fix duplicated surface push on similar-image

Fredrik Fornwall (1):
      Fix cairo_get_locale_decimal_point() on Android

Hans Breuer (1):
      win32: Fix compilation of 'cairo-path-stroke-traps.c' with MSVC8

Henry (Yu) Song (1):
      xlib: Remove queued event from _XReadEvents

Julien Isorce (1):
      build: Show all disabled features in cairo-features.h

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

Ravi Nanjundappa (2):
      Fix warnings from check-doc-syntax.sh
      Fix one more warning from check-doc-syntax.sh

Rodrigo Rivas Costa (1):
      win32-print: fix transparent images have black background

Sahil Vij (1):
      gl: Fix bug in _cairo_gl_pattern_texture_setup()

Uli Schlachter (6):
      tor-scan-converter: Correctly align 64bit types
      XCB: Don't attach uploaded surfaces as snapshots
      xcb: Query the display's subpixel order via RENDER
      xlib-xcb: Don't be lazy and use the real xcb_screen_t
      xcb: Fix _put_shm_image_boxes if no SHM available
      xcb: Fix _put_image_boxes() if no SHM is available

Zan Dobersek (1):
      Manually transpose the matrix in _cairo_gl_shader_bind_matrix()

Руслан Ижбулатов (2):
      win32: Add cairo API to set up a Win32 surface for an HDC with an alpha channel.
      win32: Add a win32 boilerplate that uses a real window

江頭幸路 (1):
      Avoid appending an empty slot to an user data array when user_data is NULL.
--
cairo mailing list
cairo@cairographics.org
http://lists.cairographics.org/mailman/listinfo/cairo
```
