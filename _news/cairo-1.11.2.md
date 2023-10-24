---
title: cairo 1.11.2 snapshot available
layout: news
date: 2011-01-23
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.11.2 now available

A new cairo snapshot 1.11.2 is now available from:

http://cairographics.org/snapshots/cairo-1.11.2.tar.gz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.11.2.tar.gz.sha1
40b9e1066fcd33c2aeecd800764b1aa5a0ac7bde  cairo-1.11.2.tar.gz

http://cairographics.org/snapshots/cairo-1.11.2.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.11.2 tag which points to a commit named:
ac9ee388faf3c8c5df502f6cc7b039f043154954

    which can be verified with:
git verify-tag 1.11.2

    and can be checked out with a command such as:
git checkout -b build 1.11.2

Snapshot 1.11.2 (2011-01-23)
===========================

In this first snapshot along the way to cairo-1.12.0, we are very excited
to announce the introduction of Bezier surface gradients, known as type
6/7 gradients in PS/PDF parlance. This is the culmination of much work by
the dynamic duo: Adrian Johnson and Andrea Canciani. Thanks guys!

Also, I want to warmly welcome Uli Schlachter who recently joined the
Cairo community on a mission. That mission is to make cairo-xcb a
supported backend for 1.12. And for this snapshot he has made great
strides in fixing all the bugs I had left behind. Thanks Uli!

And we have also seen a new contributor, Alexandros Frantzis, who has
begun bringing up cairo-gl for GLESv2 devices. Thanks Alex!

And lastly, I must also thank Adrian and Andrea for the vast numbers of
bugs that they have tackled between them, fixing all those little corner
cases that lie hidden until too late.
-Chris

API additions:

The ability to construct piece-wise Bezier surface gradients:

cairo_pattern_create_mesh

constructs a pattern of type CAIRO_PATTERN_TYPE_MESH using

cairo_pattern_mesh_begin_patch
cairo_pattern_mesh_end_patch
cairo_pattern_mesh_curve_to
cairo_pattern_mesh_line_to
cairo_pattern_mesh_move_to
cairo_pattern_mesh_set_control_point
cairo_pattern_mesh_set_corner_color_rgb
cairo_pattern_mesh_set_corner_color_rgba
cairo_pattern_mesh_get_patch_count
cairo_pattern_mesh_get_path
cairo_pattern_mesh_get_corner_color_rgba
cairo_pattern_mesh_get_control_point

The introduction of a unique ID accessible via the mime data type:
CAIRO_MIME_TYPE_UNIQUE_ID

List of all changes between 1.10.0 and 1.11.2
---------------------------------------------
Adrian Johnson (74):
      Fix font metrics in PDF Type 1 fonts
      Add capability for font subsets to put latin glyphs in a separate subset
      pdf-operators: output (abc) style strings when font is latin
      Return latin to glyph mapping in cairo_scaled_font_subset_t
      Add winansi glyph names
      Type 1 subsetting: add support for latin subsets
      Type 1 fallback: add support for latin subsets
      PS: Enable support for latin subsets
      TrueType subsetting: embed a cmap for latin subsets
      PDF: Add support for latin subsets
      pdf-operators: fix bug that was causing unnecessary repositioning of text
      Fix font metrics in PDF Type 1 fonts
      pdf-operators: fix bug that was causing unnecessary repositioning of text
      pdf-operators: word wrap latin text strings
      Don't embed cmap in TrueType fonts embedded in PostScript
      CFF subset: add support for latin subsets
      PS: Allow %%BoundingBox and %%PageBoundingBox to be overriden using DSC comments
      remove unused variable
      Fix bug in subsetting check for winansi characters
      Don't put Type3 glyphs in latin subsets
      Refresh ft-show-glyphs-positioning pdf ref image
      Rewrite pdf-operators word wrapping
      PDF: Fix regression in EXTEND_NONE gradients
      PS: Remove redundant code
      PDF: Remove radial gradient fallback
      PS: Remove radial gradient fallback
      Type 1 subset: Fix glyph advance
      PDF: Fix regression in EXTEND_NONE gradients
      Type 1 subset: Fix glyph advance
      PDF: Don't use the currently set color  after a 'Q' operator
      PDF: Don't use the currently set color  after a 'Q' operator
      PDF: Use correct bfchar size in toUnicode for latin fonts
      CFF Subset: Remove debug code
      configure.ac.features: s/Meta/Recording/
      Fix type1-fallback bbox
      Move glyph names into separate file
      Type 1 glyph names: Do not use an array of pointers for winansi glyph names
      PDF: Fix toUnicode for CID fonts
      PDF: Restrict ActualText to PDF version >= 1.5
      win32: Use a font_face hash table to provide unique font faces
      win32-print: print as unicode where possible
      win32: fix font_face hashing
      PS/PDF: Fix regression when changing page size to a larger size
      PS: Fix regression - missing page content in EPS output
      PS: Fix regression - incorrect EPS bounding box
      Fix regression in fallback-resolution test
      configure.ac.features: s/Meta/Recording/     (cherry picked from commit 8f2f5e5ad4f8e5f18da903865bb2d2afce3a544e)
      Fix type1-fallback bbox     (cherry picked from commit 74873c82242e9c124b69e05d0f8abdf78983d62d)
      PDF: Restrict ActualText to PDF version >= 1.5
      PS/PDF: Fix regression when changing page size to a larger size
      PS: Fix regression - missing page content in EPS output
      PS: Fix regression - incorrect EPS bounding box
      Add unique_id mime type
      Use fallback font for synthetic fonts
      win32: add synthetic font subsetting support
      Document load_truetype_table function and ensure ft-font and Win32-font are compliant
      Check table size in cairo_truetype_get_style()
      Automate error checking for ps-eps test
      Fix xml-surface use of load_truetype_font
      Check is_synthetic() font backend exists before calling it
      PDF: Add missing clipper_reset
      Truetype subset: add missing unicode ranges to cmap
      PDF: Add missing clipper_reset     (cherry picked from commit 2ae2be36d4551906fd4edbc8bf07aaa7fe0c93cf)
      Fix fallback-resolution test
      Boilerplate: Set fallback resolution using force_fallbacks function
      Change fallback resolution test to use resolutions in multiples of 72
      CFF subset: fix subsetting of Euro glyph
      CFF subset: fix bug with euro glyph in fallback fonts
      CFF Subsetting: Subset subroutines
      PDF: Output a stencil mask for cairo_mask() with solid source and A1 mask
      mesh: Add mesh pattern type and enum values
      pdf,ps: Add native mesh pattern support
      pattern: Add public mesh pattern API
      test: Add tests for mesh patterns

Alexandros Frantzis (10):
      gl: Add functions to query GL version and extensions
      gl: Add infrastructure for calling GL functions using a dispatch table
      gl: Embed the GL dispatch table in the cairo-gl context and initialize it.
      gl: Add definitions for the core variant names of used GL constants
      gl: Use the dispatch table for calling ARB/EXT functions
      gl: Use the GL core 2.0 shader implementation for both GL 1.x ARB and GL 2.x
      gl: Remove GL 1.x ARB shader implementation
      gl: Replace GLEW by using the facilities provided by cairo-gl-info
      gl: Remove GLEW from the build system and the source tree
      gl: Fix condition that prevents setting the size of window surfaces

Andrea Canciani (179):
      test: do not leak resources
      image: add _cairo_image_reset_static_data
      test: do not leak resources
      xcb: Do not return value in void function
      quartz: Remove unused argument from _cairo_surface_to_cgimage
      quartz: Assert upon invalid enum values
      quartz: Check for valid patterns
      quartz: Don't typecast surfaces
      quartz: Fix function call coding style
      quartz: Mark failures as unlikely
      quartz: Whitespace cleanup
      quartz: Beautify code
      quartz: Use NOTHING_TO_DO instead of SUCCESS where appropriate
      quartz: Simplify cairo_quartz_surface_create_for_cg_context
      quartz: Remove useless code
      quartz: Improve handling of surface creation failure
      quartz: Improve _cg function types
      quartz: Handle failures in _cairo_quartz_setup_fallback_source
      test: Make tests run in natural order
      test: Add a new test result html page
      test: Remove old html infrastructure
      test: Update ref images for radial tests
      quartz: Remove linear gradient fallback
      quartz: Make radial gradients follow PDF specification
      quartz: Remove unused code
      Add _cairo_rectangle_union
      quartz: Improve gradient consistency
      quartz: Fix EXTEND_PAD gradients
      quartz: Improve gradient quality
      quartz: Remove DO_NOTHING and DO_UNSUPPORTED actions
      quartz: Set operator when setting up source
      quartz: Unify DO_SOLID and DO_PATTERN
      quartz: Unify DO_SHADING, DO_IMAGE and DO_TILED_IMAGE
      quartz: Move drawing state out of surface
      quartz: Cleanup gradient setup functions
      quartz: Remove unused imageSurface field
      test: Add romedalen images copyright information
      test: Fix get-path-extents
      path: Replace _cairo_path_fixed_is_equal with _cairo_path_fixed_equal
      path: Do not access flags directly
      path: Improve hashing
      path: Make path equality independent of flags
      path: Rename _cairo_path_last_op to _cairo_path_fixed_last_op
      path: Add utility functions
      path: Simplify close_path
      path: Cleanup _cairo_path_fixed_line_to
      box: Add box header
      box: Add _cairo_box_add_curve_to
      path: Move _cairo_path_fixed_add at the end of line_to and curve_to
      path: Drop degenerate line_to in _cairo_path_fixed_curve_to
      path: New path construction logic
      path: Add stroke_is_rectilinear flag
      path: Rename fill optimization flags
      path: Log flags
      path: Cleanup _cairo_path_fixed_transform
      path: Cleanup _cairo_path_fixed_iter_at_end
      path: Make _cairo_path_fixed_last_op assert on empty path
      path: Cleanup close_path
      path: Recompute flags in _cairo_path_fixed_translate
      path: Transform current_point and last_move_to in _cairo_path_fixed_scale_and_offset
      path: Recompute flags in _cairo_path_fixed_scale_and_offset
      path: Fix _cairo_path_fixed_transform
      path: Replace _cairo_path_fixed_extents_add with _cairo_box_add_point
      Fix degenerate arcs
      path: Tighten curve_to extents
      path-bounder: Simplify code
      path: Tighten transformed extents
      drm: Do not access path flags directly
      path: Solve co-dependency problem
      cff: Fixes for 'make check'
      script: Fix compilation
      quartz-font: Add truetype font table tags accessor
      quartz-font: Do not leak CFDataRef's
      image: Use correct size for allocation
      image: Use correct size for allocation
      configure: Correct reporting of tee backend
      quartz-font: Implement new load_truetype_table semantics
      ps: Fix painting
      ps: Fix painting
      array: Remove snapshot support
      array: Add read-only accessor
      array: Cleanup types
      configure: Correct reporting of tee backend
      Fix degenerate arcs
      test: Add romedalen images copyright information
      xcb: Do not return value in void function
      array: Silence warnings
      pdf: Silence compiler warnings
      array: Fix comment
      test: Add rectilinear-grid
      image: Fix compositing of unaligned boxes
      image: Fix _pixel_to_solid
      test: Fix ref images
      test: Add rectilinear-grid
      image: Fix compositing of unaligned boxes
      test: Fix ref images
      test: Handle crashed tests
      arc: Avoid infinite loop
      arc: Clamp to 65536 full circles
      test: Add arc-looping-dash
      test: Add arc-infinite-loop
      surface: Remove _cairo_surface_fill_rectangle
      pdf: Use composite rectangles in fill_stroke
      surface: Remove _cairo_surface_*_extents
      path: Cleanup unused current_point
      path: Always interpret in forward direction
      path: Remove support for inverse direction interpretation
      fill: Simplify path to polygon conversion
      polygon: Merge _cairo_polygon_init and _cairo_polygon_limit
      test: Update reference images list
      pdf: Use switch instead of multiple if's
      ps: Use switch instead of multiple if's
      pattern: Specialise signatures of pattern specific functions
      pattern: Improve extents computation of radial gradients.
      ps, pdf, pattern: Implement _cairo_pattern_alpha_range to analyse patterns.
      ps: Avoid unneeded fallbacks for gradients with opaque stops.
      pattern: Compute a covering parameter range of a gradient for a box.
      pattern: Use pattern parameter range when analysing all gradients.
      pattern: Add a function to interpolate gradient objects.
      quartz: Unify gradient construction and fix radial gradients.
      pdf: Unify gradient emitters and support all extend modes.
      ps: Unify gradient emitters and support all extend modes.
      ps,pdf: Deal with empty domain gradients.
      test: Update ref images
      path: Silence warnings
      test: Add bug-extents
      path-bounder: Update current point after curve_to op
      test: Add bug-extents
      gl: Fix #include's to pass 'make check'
      quartz: Clean up dynamically loaded functions
      quartz: Don't dynamically load unused functions
      quartz: Use native PDF blend modes
      Keep makefiles in alphabetical order
      gstate: Disallow incomplete mesh gradient sources
      Add mesh gradient rasterizer
      script: Add support for mesh patterns
      test: Extend pattern-get-type and pattern-getters for mesh patterns
      doc: Add documentation for the mesh API
      pattern: Remove unused 'opaque' variable
      pattern: Use cairo_color_stop_t when hashing gradient stops
      pattern: Make functions not used elsewhere static
      test: New radial-gradient tests
      matrix: Cairo matrix to pixman transform/offset conversion
      test: Make huge-* test gradients not within pixed_fixed_t range
      pattern: Factor out pattern rescaling
      test: Huge means more than MAX_INT
      pattern: Use double precision for gradient extreme objects
      matrix: Fix warnings about documentation by 'make check'
      pattern: Remove unused _cairo_pattern_size function
      xcb: Correct handling of index 0 glyphs
      xcb: Stricter glyph validation
      xcb: Handle a wider range of glyph positions
      xlib: Handle a wider range of glyph positions
      doc: Add links to flush() and mark_dirty() in direct access functions
      test: Add white-in-noop
      test: Add missing ref image to REFERENCE_IMAGES
      Fix optimization of white IN dest compositing
      xcb: Add a short comment to the Picture cache
      mesh: Do not declare min and max functions
      gl: Ensure that gl surface resizes are properly applied
      gl: Update radial gradient implementation
      gl: Don't ignore offset for gradient sources
      pdf,ps,quartz: Use correct tolerance for gradient domain computation
      Add a results.tar.gz target to the test Makefile
      test: Fix operator-alpha-alpha
      test: Update quartz ref images
      quartz: Use standard stack allocation size
      quartz: Make huge domain handling more stable
      quartz: Do not use opaque patterns as masks
      quartz: Cleanup extents computation
      quartz: Use CGLayer to implement unbounded operators
      quartz: Avoid using private APIs
      quartz: Respect pattern filter settings
      test: Workaround pixman limits in large-source-roi
      Bump pixman requirements to 0.20.2 for radial gradients
      clip: Improve _cairo_clip_contains_*
      test: Add group-state
      gstate: Set an error status when restoring a push_group
      gstate: Remove unused code

Behdad Esfahbod (2):
      Fix typo
      Add note re gtk-doc.make

Benjamin Otte (4):
      build: Don't build cairo-fdr when the tee surface is off
      build: Don't build cairo-fdr when the tee surface is off
      xlib: Add more _cairo_error() calls
      xcb: Add more _cairo_error() calls

Carlos Garcia Campos (4):
      doc: Add section for recording surface
      recording: Add section doc comments
      recording: Fix cairo_recording_surface_create() doc comments
      recording: Document CAIRO_HAS_RECORDING_SURFACE macro

Chris Wilson (31):
      version: 1.10.1 open for bugfixing
      configure: Fix typo "(requires both --enable-xcb)"
      cairo: Remove trailing comma from cairo_device_t
      drm: Add missing header file for tarball
      version: 1.11.1
      image: Silence a compile warning
      test: Add a8-clear
      image: The a8 in-place span compositing is only valid for SOURCE
      Merge branch '1.10'
      xcb: Correct a minor typo prevent an assert from firing
      xcb: Fix reduction of clipping for bounded glyphs.
      xcb,image: Fix a missing clip fini
      xcb: Pass clip to composite_glyphs_via_mask
      perf: Only print description once per backend
      configure: Remove noisy -Wlogical-op
      drm/intel: Drop the bo cache.
      pdf: Silence compiler for an impossible case
      wgl: Use CreateWindowA with an ASCII string
      scaled-font: assert that we hold the scaled-font mutex when looking up glyphs
      test/arc-infinite-loop: Random return value fun.
      gl: Enable PLT symbol hiding for dispatch entries
      Add a KNOWN_ISSUES file to track WONTFIX(?) bugs
      NEWS: Add entry for 1.10.2
      version: Bump for 1.10.2 release
      version: Post release version bump
      xcb: Apply a clip region for compositing many-pixel-aligned-boxes
      xcb: Prefer RenderFillRectangles to perform the deferred clear
      Makefile: add missing cairo-box-private.h
      Merge branch '1.10' into tmp
      NEWS: 1.11.2 snapshot
      version: Bump for 1.11.2 snapshot

Eric Anholt (1):
      gl: Avoid using gl_FragCoord for linear gradients.

Erik Zeek (2):
      Fix build on gentoo
      Fix build on gentoo

Jeff Muizelaar (2):
      Fix degenerate vertical path bounds.
      Sync get-path-extents test with the one on 1.10.

Joerg Sonnenberger (2):
      LD_PRELOAD is supported on DragonFly.
      LD_PRELOAD is supported on DragonFly.

Koji Otani (2):
      PS: fix embedding of grayscale jpegs
      PS: fix embedding of grayscale jpegs

Kouhei Sutou (1):
      xml: fix a typo to correct the indentation after <path></path>

Maarten Bosmans (2):
      doc: Add a remark about toy status of the PNG API
      doc: Fix some broken references and gtk-doc warnings

Markus Stange (2):
      Fix type of _cairo_memory_stream_destroy parameter
      Fix type of _cairo_memory_stream_destroy parameter

Mats Palmgren (1):
      win32: Improve error logging

Robert O'Callahan (1):
      tee: Do not apply two times the master device transform

Tim Janik (1):
      cairo: docu fix for cairo_set_source_surface

Tomá\u0161 Chvátal (1):
      Fix posix calls in configure.ac test code.

Uli Schlachter (40):
      XCB: Fix some weird code
      xcb: Fix CAIRO_OPERATOR_IN
      xcb: Fix compiler warning about unused result
      xcb: Correctly clear the composite surface
      _cairo_xcb_surface_ensure_picture: Check fallback
      _cairo_xcb_surface_picture: Check for fallback
      xcb: Correctly handle ARGB visuals
      Add myself to AUTHORS
      XCB: Remove an incorrect clipping optimizations
      XCB: Move the assert from 5a0f8f7320c916c
      XCB: Fix for all unbounded operators
      XCB: Use consistent rounding modes for a1 rasterisation.
      font options: Add private round_glpyh_positions field
      Actually implement round_glpyh_positions
      raster backends: Set round_glpyh_positions to ON
      Other backends: Set round_glyph_positions to OFF
      xcb: Do not access flags directly
      xcb: Fix transformation matrix setting
      XCB: Check screen size in boilerplate
      _cairo_round: Fix documentation
      Make both versions of _cairo_lround consistent again
      test/README: Change suggested screen size
      xcb: Handle deferred_clear in _copy_to_picture
      Avoid some unneeded 'is_clear = FALSE'
      xcb: Work around wrong extent computation in the X server
      xcb: Remove a wrong optimization
      XCB: Stop taking the xcb socket
      Verify that surfaces leak no snapshots
      Detach snapshots after flushing in cairo_surface_finish()
      Remove an unused field from cairo_xcb_shm_info_t
      Switch the order of two functions in the C file
      XCB: Make sure SHM memory isn't reused too early
      xcb: Handle events in boilerplate
      xcb: Add a define for some magic number
      xcb: Only print the first error and ignore subsequent ones
      xcb: Check harder for X11 errors in boilerplate
      xcb: Check the check for errors in boilerplate
      xcb: Fix premature pixmap free in boilerplate cleanup
      Add a test case for a bug in the xcb backend
      xcb: Don't finish snapshots when they are detached
```
