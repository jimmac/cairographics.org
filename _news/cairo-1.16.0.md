---
date: 2018-10-19
layout: news
title: cairo release 1.16.0 is now available
---
```
A new cairo release 1.16.0 is now available from:

        https://cairographics.org/releases/cairo-1.16.0.tar.xz

    which can be verified with:

        https://cairographics.org/releases/cairo-1.16.0.tar.xz.sha1
        00e81842ae5e81bb0343108884eb5205be0eac14  cairo-1.16.0.tar.xz

        https://cairographics.org/releases/cairo-1.16.0.tar.xz.sha1.asc
        (signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.16.0 tag which points to a commit named:
        3ad43122b21a3299dd729dc8462d6b8f7f01142d

    which can be verified with:
        git verify-tag 1.16.0

    and can be checked out with a command such as:
        git checkout -b build 1.16.0

Release 1.16.0 (2018-10-19 Bryce Harrington <bryce@bryceharrington.org>)
========================================================================
This new stable release incorporates a number of improvements made in
the four years since 1.14.0.

Of particular note is a wealth of work by Adrian Johnson to enhance PDF
functionality, including restoring support for MacOSX 10.4, metadata,
hyperlinks, and more.

Much attention also went into fonts, including new colored emoji glyph
support, variable fonts, and fixes for various font idiosyncrasies.

Other noteworthy changes include GLESv3 support for the cairo_gl
backend, tracking of SVG units in generated SVG documents, and cleanups
for numerous test failures and related issues in the PDF and Postscript
backends.

For a complete log of changes, please see

    https://cairographics.org/releases/ChangeLog.cairo-1.16.0


Features and Enhancements
-------------------------
* Add support for OpenGL ES 3.0 to the gl backend.
* The PDF backend has gained support for a range of widely used
  features, including thumbnails, page labels, metadata, document
  outlines, structured text, hyperlinks, and tags.  Tags permit adding
  logical info such as headings, tables, figures, etc. that facilitates
  indexing, accessibility, text reflow, searching, and extraction of the
  tagged items to other software.  For details on this new PDF
  functionality, see:
    https://lists.cairographics.org/archives/cairo/2016-June/027427.html
* Variable font support.  Variable fonts are single font files with
  various typography characteristics, such as weight or slant, that users
  of the font can adjust between two points.  Effectively this enables a
  single font to behave as multiple fonts.
* Restore MacOSX 10.4 support.  Cairo had dropped 10.4 support when
  moving to the CoreText API.  Now we automatically detect which API to
  use via dynamic linking, so can resume supporting this older version
  of MacOSX.
* Support colored emoji glyphs, stored as PNG images in OpenType fonts.
* Skia backend is removed
* Use Reusable streams for forms in Level 3 Postscript.
* Add CAIRO_MIME_TYPE_EPS mime type for embedding EPS files.
* Add CCITT_FAX mime type for PDF and PS surfaces
* svg: add a new function to specify the SVG document unit
  (Bug #90166)
* Use UTF-8 filenames on Windows


API Changes
-----------
Several new APIs were added.  No existing APIs were altered.

New PDF functionality:

  * cairo_pdf_surface_add_outline
  * cairo_pdf_surface_set_metadata
  * cairo_pdf_surface_set_page_label
  * cairo_pdf_surface_set_thumbnail_size
  * cairo_tag_begin
  * cairo_tag_end
  * CAIRO_STATUS_TAG_ERROR

New error status items for problems relating to PDF tagging:

  * CAIRO_STATUS_WIN32_GDI_ERROR
  * CAIRO_STATUS_FREETYPE_ERROR
  * CAIRO_STATUS_PNG_ERROR

    New error status items for handling of GDI, libfreetype, and libpng
    errors, respectively.


Setting up Win32 surfaces for HDC with alpha channels:

  * cairo_win32_surface_create_with_format

    New API for added PDF functionality (see above), and new error
    status item for problems relating to PDF tagging.

Variable fonts:

  * cairo_font_options_get_variations
  * cairo_font_options_set_variations

Tracking units in SVG documents:

  * cairo_svg_surface_set_document_unit
  * cairo_svg_surface_get_document_unit



Dependency Changes
------------------
None


Performance Optimizations
-------------------------
None


Notable Bug Fixes
-----------------
* Fix thin lines that don't show up when printing in Inkscape due to
  overly aggressive culling.
  (Bug #77298)
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
* Fix a data race in freed_pool discovered by Firefox's cairo usage.
  The patch adads atomic int load and store functions, with relaxed
  memory ordering.  (Bug #90318)
* Handle SOURCE and CLEAR operators when painting color glyphs.
  (Bug #102661)
* Fix falling back to system font with PDFs using certain embedded
  fonts, due to truncated font names.
  (Bug #103249)
* Prevent curved strokes in small ctms from being culled from vector
  surfaces
  (Bug #103071)
* Fix assertion hit with PDFs using Type 4 fonts rendered with user
  fonts, due to error when destroying glyph page.
  (Bug #103335)
* Prevent invalid ptr access for > 4GB images.
  (Bug #98165)
* pdf: Fix internal links pointing to other pages, by pre-calculating
  page heights so that link positions can be calculated more accurately.
* Fix error reporting in the xcb backend if fallback fails.  Instead of
  returning NULL when the X11 server can't do some operation, return a
  surface in an error state.
* Clarify documentation regarding device scale inheritance and the units
  used in cairo_surface_create_similar_image.
  (Bug #99094)
* Call XSync in the xlib backend before setting the error handler to
  ignore errors for certain requests, to make sure all pending errors
  are handled first.
* Fix regression with text containing space character on Win32.
  (Bug: https://gitlab.freedesktop.org/cairo/cairo/issues/339)


------------------------------------------------------------------------
List of changes in this release:

Adam Jackson (2):
      xlib: Don't crash when swapping a 0-sized glyph
      xcb: Don't crash when swapping a 0-sized glyph

Adrian Johnson (129):
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
      scaled-font: don't store pointer in hash value
      Add CAIRO_STATUS_PNG_ERROR for errors returned by libpng
      Adding missing error status to utils
      Add CAIRO_STATUS_FREETYPE_ERROR for errors returned by libfreetype
      Add CAIRO_STATUS_WIN32_GDI_ERROR for GDI errors
      pdf2png: fix deprecated warning
      svg2png: fix deprecated warning
      test: add record-neg-extents
      Add recording-ink-extents test
      Fix test failures when recording surface extents has negative x,y
      pdf: change from pdf coordinates to cairo coordinates
      Fix PDF record-neg-extents test failure
      test: replay record surface with negative extents for each extend mode
      image: fix record-replay-extend test failures
      pdf: fix record-replay-extend test failures
      ps: change from ps coordinates to cairo coordinates
      Fix PS record-neg-extents test failure
      Update ref images
      image: only cache analyzed transparency/color for snapshot surfaces
      win32-print: fix unbounded surface assertion
      win32: gcc 5.4 build fix
      recording: Remove unused function
      pdf: remove unused variable
      add test text-unhinted-metrics
      ft: set font size to em size when retrieving unhinted metrics
      test: refresh text-rotate ref images
      truetype: Don't write glyph if num_contours == 0
      ps: flush ASCII85Decode file after use
      ps/pdf: remove debug and commented out code
      pattern: don't round extents to 0 on vector surfaces
      pdf: Don't fail subsetting if unable to convert utf8 to utf16
      truetype: reverse cmap search should end when 0xffff- 0xffff range reached
      pattern: revert an unintentional change added in 190678f
      pdf: fix combined image/smask
      Add tag functions to cairo_t and cairo_surface_t
      Add tag functions to recording surface and surface-wrapper
      Support tag operations in analysis and paginated surface
      pdf: structured text and hyperlink support
      pdf: add document outline API
      pdf: metadata API
      pdf: page label API
      pdf: thumbnail API
      add test for PDF document interchange features such as tagged text and links
      fix make check
      fix compiler warnings
      strndup is not avuilable with MSVC
      pdf: don't return uninitialized status
      pdf-operators: fix bug in line wrapping
      subsetting: support variable fonts
      Fix off by one check in cairo-image-info.c
      tests: fix bug in pdf-tagged-text that was introduced in 4790a36
      pdf: link tags do not need to be leaf nodes in the document structure
      pdf: Don't emit /PageLabel dict when no labels defined
      pdf: don't write logical structure if it only contains links
      pdf: fix link positions
      pdf: use link attributes instead of dest name for cairo_pdf_surface_add_outline
      pdf: use explicit dest instead of named dest when 'internal' attribute is set
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
      Use _cairo_malloc instead of malloc

Alban Browaeys (1):
      pattern: allow for a floating one pixel rounded difference.

Aleksander Morgado (1):
      build: fix minor typo in autogen.sh

Alexander Täschner (1):
      win32: Initialize mutexes for static builds for win32

Alexandre Bique (1):
      Fix test compilation when font-config is disabled

Andrea Canciani (18):
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
      quartz: Restore 10.4-specific font code
      test: Add a test for characters in the SMP
      unicode: Extract the UCS4 to UTF-16 conversion to a separate function
      quartz-font: Correct handling of SMP Unicode characters
      quartz-font: Fix text-glyph-range

Antonio Ospite (2):
      svg: add a new function to specify the SVG document unit
      svg: fix compilation with MSVC which doesn't support C99 initializers

Arpit Jain (3):
      xlib: Fix deferencing of uninitialised 'display'
      test/bitmap-font: Fix use of pointer after freed pointer
      gl: Fix incorrect size of expression

Ashim (1):
      Fix out of bound access in struct pattern->type

Behdad Esfahbod (23):
      [ft] Return CAIRO_STATUS_FILE_NOT_FOUND if font file can't be opened
      Oops, fixup previous commit
      Remove debug printf; ouch!
      Bug 29319 - Modules are built as versioned shared objects
      Fix color font support infinite-loop with empty glyphs
      Fix uninitialized status!
      [ft] Fix color font loading on big-endian systems
      Fix undefined-behavior with integer math
      Handle SOURCE and CLEAR operators when painting color glyphs
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
      [ft] Implement some more color conversion routines

Bryce Harrington (149):
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
      On MacOSX, the sed utility errors out when parsing non-UTF8 files. Because of this, the generated cairo-test-constructor only contained a few tests and the test suite was thus incomplete.
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
      If more than one trap is passed in then it's guaranteed that the returned traps will have their left edge to the left of their right edge, but if only one trap is passed in then the function always returns without doing anything.  This results in incorrect rendering of SVG paths with more than one subpath.
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
      RELEASING: Fix documentation of proper ChangeLog path
      cairo-misc: Whitespace cleanup
      Fix grammar in cairo_*_reference() function documentation.
      pattern: Fix incorrect grammar in cairo_pattern_get_type.
      build: Don't rely on non-POSIX 'strings -' behavior
      gl: Treat GLES v2 as a separate flavor from GLES v3
      gl: Fix one more CAIRO_GL_FLAVOR_ES3 enum
      NEWS: Fix a couple typos
      1.15.4 release
      Bump version for new development tree, 1.15.5
      RELEASING: Fix tabbing
      gl: Fix comment syntax
      drm: Add/reorder headers as required by check-preprocessor-syntax.sh
      1.15.6 release
      Bump version for new development tree, 1.15.7
      RELEASING: Note use of branches for stable releases
      RELEASING: Note adding index to cairo-docs.xml for minor releases
      cairo-docs: whitespace cleanup
      image: Disambiguate 0. in doxygen
      1.15.8 release
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
      Drop stray patch from prior commit
      gl: Whitespace cleanup
      win32: Copyedit recent comments
      test: Use C comment syntax, not C++
      Bump version for new development tree, 1.15.13
      script-surface: Check for invalid ids (CID #1159557, 1159558)
      bo: Check null return from _cairo_malloc_ab() (CID #1159556)
      snapshot: Don't use extra after it's been freed (CID #220086)
      bo: Free event_y in case of error to prevent memory leak (CID ##1160682)
      pdf: Fix potential null ptr deref when creating smask groups (CID #1159559)
      type1-subset: Fix incorrect null ptr check from find_token() (CID #1160662)
      polygon-intersection: Clarify ptr checks for right edges (CID #1160730)
      gl: For glesv3 detection, use glesv2.pc + header check
      scaled-font: Fix glyph and cluster count checks (CID #983386)
      Convert 3 headers to UTF8
      build: Sp. fix
      doc: Add missing symbols to sections for recently added APIs
      Fix sp. sheering
      gstate: Minor grammar copyedit
      Normalize more test reference images with minor text rendering differences
      Normalize one more test image with minor gradient differences
      doc: Drop tmpl support
      1.15.14 release
      Bump version for 1.15.15
      RELEASING: Clarify how to add the news item
      Revert "Correctly decode Adobe CMYK JPEGs in PDF export"
      Drop skia backend
      win32: Fix regression with text containing space character
      test: Free resources in pdf2png
      1.16.0 release
      Bump version for 1.17.1

Carlos Garcia Campos (1):
      scaled-font: Fix assert when destroying glyph page

Chris Wilson (4):
      xlib: Bump reference count for recording surface replays
      Revert "xlib: Fix deferencing of uninitialised 'display'"
      xlib: Avoid using uninitialised variable on impossible error path
      stroker: Check for scaling overflow in computing half line widths

Debarshi Ray (2):
      doc: Fix the units used by cairo_surface_create_similar_image
      doc: Clarify when the device scale is inherited and when it isn't

Doran Moppert (1):
      image: Check for negative len in fill/blit functions

Ed Schouten (2):
      Prevent observer surfaces from writing to stdout
      Write debugging information to the debugging file

Emanuele Aina (1):
      cairo-trace: Fix duplicated surface push on similar-image

Enrico Weigelt, metux IT consult (14):
      core: updated .gitignore
      core: reintroduce bot-scan-converter functions
      core: dropped unnecessary local variable in _cairo_composite_rectangles_intersect()
      core: some in-code documentation
      drm: fix importing of libdrm
      core: fix compiler warnings
      core: helper inline for rect->box conversion
      core: dropped actually unused parameter of _cairo_boxes_to_array()
      core: fixed code duplication
      qt: replaced calls to _cairo_clip_init_copy() by _cairo_clip_copy()
      drm: fixed missing includes
      drm: dropped obsolete/unused intel_bo_get_image()
      drm: use typedefs and defines from drm headers instead of redundant own definitions
      drm: fixed calls to _cairo_surface_init()

Eric Hoffman (1):
      win32: Fix multi-monitor virtual desktop with negative monitor coords

Federico Mena Quintero (7):
      Add .gitlab-ci.yml to run the tests automatically
      bfo#105084 - Initialize memory properly in _cairo_ft_font_face_create_for_pattern()
      cairo-analysis-surface: Quell invalid uninitialized variable warning
      test/extended-blend.c: Remove obsolete comments about buggy librsvg
      Normalize extended-blend-mask.{argb32,rgb24}.ref.png
      Normalize test images with minor gradient differences
      Normalize test reference images with minor text rendering differences

Fredrik Fornwall (1):
      Fix cairo_get_locale_decimal_point() on Android

Guillaume Ayoub (1):
      Use surface_transform in replay_and_create_regions

Guillermo Rodriguez (2):
      script: Fix misleading indentation warning.
      Remove redundant check.

Hans Breuer (1):
      win32: Fix compilation of 'cairo-path-stroke-traps.c' with MSVC8

Hans Petter Jansson (1):
      scaled-font: Fix deadlock when recursing in _cairo_scaled_font_reset_cache()

Henry (Yu) Song (1):
      xlib: Remove queued event from _XReadEvents

John Lindgren (1):
      Avoid indiscriminate use of VALGRIND_MAKE_MEM_NOACCESS.

Julien Isorce (1):
      build: Show all disabled features in cairo-features.h

Koop Mast (1):
      cairo-gl: Fix compiler warning if CAIRO_HAS_*_FUNCTIONS is not defined.

Kouhei Sutou (2):
      pdf: Remove duplicated item
      pdf: Fix wrong cairo_pdf_outline_flags_t item prefix

Marc-André Lureau (1):
      xlib: fix mixing xcb & xlib calls

Massimo (1):
      bfo#91271 - Fix access of uninitialized memory

Massimo Valentini (6):
      tor-scan-converter: can't do_fullrow when intersection in row + 0.5subrow
      win32:  Fix crash from win32 surface's image size too small
      polygon-intersection: Do not discard intersection exactly at top edge
      polygon-intersection: Include approximation in intersection points
      polygon-intersection: Try not to invoke undefined behaviour
      polygon-intersection: Delete misleading comments and dead-code

Matthias Clasen (27):
      Add support for color glyphs to cairo_scaled_glyph_t
      Support loading color glyphs with freetype
      Expose 'has color glyphs' as a scaled font property
      Implement has_color_glyphs for freetype
      Render color glyphs as source, not as mask
      Simplify things a bit
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

Michael Haubenwallner (8):
      fix conflicting types for 'sync' on AIX, bug#89338
      skip MAP_NORESERVE when unsupported
      define _GETDELIM for getline() on AIX
      test: fix include order for AIX, bug#89354
      perf/micro: fix include order for AIX, bug#89354
      perf: fix include order for AIX, bug#89354
      headers: fix include order for AIX, bug#89354
      headers: fix include order for AIX, bug#89354

Mikhail Fludkov (2):
      Surround initialisations with atomic critical section
      Fix code generation when using GCC legacy atomic operations

Nathan Froyd (1):
      Support new-style __atomic_* primitives

Olivier Blin (1):
      Pull -lz for the script backend

Patrick Fritzsch (1):
      win32: check if GetTextMetrics failed

Paul Menzel (3):
      Use HTTPS URLs for cairographics.org domains
      Use HTTPS URLs for freedesktop.org domains
      Use HTTPS URLs for gnome.org domains

Peter TB Brett (1):
      Correctly decode Adobe CMYK JPEGs in PDF export

Ravi Nanjundappa (2):
      Fix warnings from check-doc-syntax.sh
      Fix one more warning from check-doc-syntax.sh

Rodrigo Rivas Costa (1):
      win32-print: fix transparent images have black background

Sahil Vij (1):
      gl: Fix bug in _cairo_gl_pattern_texture_setup()

Tom Schoonjans (1):
      Use UTF-8 filenames on Windows

Uli Schlachter (21):
      tor-scan-converter: Correctly align 64bit types
      xcb: Query the display's subpixel order via RENDER
      xlib-xcb: Don't be lazy and use the real xcb_screen_t
      XCB: Don't attach uploaded surfaces as snapshots
      xcb: Fix _put_shm_image_boxes if no SHM available
      xcb: Fix _put_image_boxes() if no SHM is available
      Fix cairo-xlib-xcb compilation
      xlib: Fix double free in _get_image_surface()
      cairo-xcb: Remove a wrong optimisation
      xlib: Remove unused variable
      xlib: Call XSync() before ignoring errors
      Revert "stroker: Check for scaling overflow in computing half line widths"
      xcb: Fix error reporting if fallback fails
      Revert "fix warning: variable X might be clobbered by 'longjmp'"
      Add test for error handling with broken PNG streams
      Fix warning: '*' in boolean context
      fix warning: variable X might be clobbered by 'longjmp'
      Fix a 'memory leak' in the image compositor
      Skip font-variations test for missing fonts
      pthread-same-source: Refresh reference images
      Fix assertion failure in the freetype backend

Unknown (1):
      Cairo trivial typos

Vasily Galkin (3):
      win32: Introduce new flag to mark surfaces that support solid brush drawing
      win32: CAIRO_WIN32_SURFACE_CAN_RGB_BRUSH and other argb32 flags set+check
      win32: Allow GDI operations for argb32 surfaces (allowed by surface flags)

Wan-Teh Chang (1):
      Fix data race in freed_pool

Zan Dobersek (1):
      Manually transpose the matrix in _cairo_gl_shader_bind_matrix()

darxus@chaosreigns.com (2):
      Remove closed poppler bugs from test/README
      Add example to run specific tests by name to the test/README

suzuki toshiya (1):
      csi-trace does not show help

Руслан Ижбулатов (2):
      win32: Add cairo API to set up a Win32 surface for an HDC with an alpha channel.
      win32: Add a win32 boilerplate that uses a real window

江頭幸路 (1):
      Avoid appending an empty slot to an user data array when user_data is NULL.

--
Bryce Harrington              -  bryce@bryceharrington.org
Senior Open Source Developer  -  bryce@osg.samsung.com
Open Source Group             -  Samsung Research America
```
