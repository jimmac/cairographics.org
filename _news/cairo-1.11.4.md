---
title: cairo 1.11.4 snapshot available
layout: news
date: 2012-03-12
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.11.4 now available

A new cairo snapshot 1.11.4 is now available from:

http://cairographics.org/snapshots/cairo-1.11.4.tar.gz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.11.4.tar.gz.sha1
ac4c37de8827ec1c4092509b9eec72106173d350  cairo-1.11.4.tar.gz

http://cairographics.org/snapshots/cairo-1.11.4.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.11.4 tag which points to a commit named:
a8dbc68056af9f32b6ebc6c1a0191e9ca7ec2e7d

    which can be verified with:
git verify-tag 1.11.4

    and can be checked out with a command such as:
git checkout -b build 1.11.4

Snapshot 1.11.4 (2012-13-12)
============================
The cairo community is pleased to finally announce the long aniticpated
release candidate for 1.12, 1.11.4, of the cairo graphics library. This
is the first major update to cairo in over a year and brings a large
number of new features; undoubtably a few bugs as well.

While many people have contributed and have helped to test the release,
providing feedback on 1.10 and suggesting improvements, this release
is the result of a few persevering souls who deserve recognition for their
outstanding contributions: Andrea Canciani (all round bug fixing,
performance tuning and master of the gradients), Adrian Johnson (PDF
supremo) and Uli Schlachter (who stepped forward as maintainer for the
XCB backend).

Major additions since 1.11.2:

 * cairo_surface_map_to_image API for pixel level access to any surface

 * New antialias hints to control the trade-off between speed and
 * quality

 * A callback pattern, cairo_pattern_create_raster_source, for lazy
   decoding of image data.

 * cairo_surface_observer_t, a new type of surface to gather performance
   statistics

 * XCB as a supported backend

 * A rewritten compositor pipeline for performance improvements for, but not
   limited to, the xlib and image backends.
   From ION and PineView through to SandyBridge, every machine I have shows
   across the board performance improvement on the cairo-traces:

   i5-2520m	gnome-system-monitor:	5.97x speedup
   pnv		gnome-system-monitor:	4.86x speedup
   i5-2520m	firefox-asteroids:	4.66x speedup
   pnv		firefox-asteroids:	4.43x speedup
   image	firefox-canvas:		3.82x speedup
   i5-2520m	firefox-canvas-alpha:	3.49x speedup
   image	firefox-asteroids:	2.87x speedup
   pnv		firefox-talos-svg:	2.83x speedup
   ion		grads-heat-map:		2.75x speedup
   pnv		firefox-canvas-alpha:	2.66x speedup
   image	gnome-system-monitor:	2.66x speedup
   image	swfdec-giant-steps:	2.46x speedup
   image	firefox-canvas-alpha:	2.14x speedup
   i5-2520m	firefox-talos-svg:	2.03x speedup
   image	grads-heat-map:		2.02x speedup
   ion		gnome-system-monitor:	2.00x speedup
   pnv		firefox-particles:	1.99x speedup
   i5-2520m	grads-heat-map:		1.96x speedup
   pnv		firefox-canvas:		1.92x speedup
   ion		firefox-particles:	1.80x speedup
   image	poppler-reseau:		1.77x speedup
   pnv		xfce4-terminal-a1:	1.72x speedup
   image	firefox-talos-svg:	1.65x speedup
   pnv		grads-heat-map:		1.63x speedup
   i5-2520m	firefox-canvas:		1.63x speedup
   pnv		swfdec-youtube:		1.62x speedup
   image	ocitysmap:		1.59x speedup
   i5-2520m	firefox-fishbowl:	1.56x speedup
   i5-2520m	poppler-reseau:		1.50x speedup
   i5-2520m	evolution:		1.50x speedup
   i5-2520m	midori-zoomed:		1.43x speedup
   pnv		firefox-planet-gnome:	1.42x speedup
   i5-2520m	firefox-talos-gfx:	1.41x speedup
   i5-2520m	gvim:			1.41x speedup
   pnv		ocitysmap:		1.37x speedup
   image	poppler:		1.31x speedup
   ion		firefox-canvas-alpha:	1.35x speedup
   ion          firefox-talos-svg:	1.34x speedup
   i5-2520m	ocitysmap:		1.32x speedup
   pnv		poppler-reseau:		1.31x speedup
   i5-2520m	firefox-planet-gnome:	1.31x speedup
   pnv		firefox-fishbowl:	1.30x speedup
   pnv		evolution:		1.28x speedup
   image	gvim:			1.27x speedup
   i5-2520m	swfdec-youtube:		1.25x speedup
   pnv		gnome-terminal-vim:	1.27x speedup
   pnv		gvim:			1.25x speedup
   image	firefox-planet-gnome:	1.25x speedup
   image	swfdec-youtube:		1.25x speedup
   ...

And a plethora of minor improvements everywhere!
-Chris

List of all changes since 1.11.2
================================

Adrian Johnson (90):
      Type1-subset: Fallback if font contains more than one /Encoding
      cff: Fix heap corruption
      PS: Use tight bounding box
      png: fix type1 encoding bugs
      cff-subset: Fix /guillemotright SID encoding
      type1-subset: Remove FT dependency part 1
      type1-subset: Remove FT dependency part 2
      type1-subset: Remove FT dependency part 3
      type1-subset: Remove FT dependency part 4
      type1-subset: Remove FT dependency part 5
      type1-subset: Remove FT dependency part 6
      Add win32 font backend functions for Type 1 subsetting
      Remove HAS_FT_FONT from cairo-scaled-font-subsets-private.h
      win32: Fix build breakage
      ps: Don't return CAIRO_INT_STATUS_NOTHING_TO_DO for empty glyphs
      analysis: CAIRO_INT_STATUS_NOTHING_TO_DO should not cause fallback
      Add support for subsetting bare CFF fonts
      type1-subset: Subset the subroutines
      Check glyph_index range in _index_to_glyph_name
      ps: remove unnecessary flush
      pdf: check if images are grayscale or monochrome and encode as such
      image: fix bug in analyze_color
      ps: check if images are grayscale or monochrome and encode as such
      image: check if A8 image is bilevel when analyzing transparency
      pdf: check if smask is bilevel and encode as such
      ps: use show_text_glyphs
      subsets: use show_text_glyphs supplied utf8 to determine latin character
      ps: use deflate compression for ps level 3
      pdf: change end of line in pdf output from \r\n to \n
      cff-subset: fallback when parsing the charstrings in bare cff fonts fails
      cff-subset: don't easily give up parsing a charstring if we already have the width
      cff-subset: fix decoding of real numbers
      font-subsets: fix wrong string length
      ps/pdf: use a new clipper object when emitting a recording surface
      pdf: use a new clipper object in recording_subsurface
      pdf: use ink extents for smask bbox
      pdf: use ink extents for pattern bbox
      pdf: use ink extents in content stream XObjects
      pdf: each row of 1-bit image data needs to begin on a byte boundary
      ps: each row of 1-bit image data needs to begin on a byte boundary
      pdf: use _emit_smask() instead of _emit_imagemask to emit stencil mask
      ps: support stencil masks
      ps/pdf: fix the polarity of stencil masks
      pdf: use interpolate in image smask
      cff: strip subset tag when reading font name
      pdf: latin text must use character codes in the toUnicode CMap, not glyph indices
      ps: use reusable stream for mesh pattern data
      ps: improve formatting of fallback image comment
      pdf: add status check
      ft: fix warning
      scaled-subsets: ensure different glyphs with same utf8 mapping are not merged together
      ps: turn off debug
      Refresh some pdf/ps ref images
      subsetting: Support unicode fontnames
      analysis mask: unwrap recording surface snapshot
      test: add mask-alpha ps ref
      test: refresh some pdf/ps refs
      test: refresh some pdf/ps refs
      pdf: ensure ink extents is not larger than bounded extents
      test: refresh pdf mask ref images
      subsets: latin char map needs to belong to the font, not the subset
      test: Add stroke-pattern
      test: make text-pattern draw with both opaque and translucent patterns
      cff: in CID fonts the CID is the glyph index
      cff: fallback if seac style endchar is found
      truetype-subset: remove unused variable
      type1-subset: remove unused variables
      pdf: don't use patterns with padded images
      ps: avoid padding images if the padding is not required to fill the extents
      pdf: allow embedding of cmyk jpeg images
      ps: allow embedding of cmyk jpeg images
      pdf: avoid using pdf patterns to paint/fill opaque linear/radial gradients
      pdf: avoid using pdf patterns to paint/fill translucent linear/radial gradients
      ps: simplify the EPS save and restore
      doc: fix typos
      test: add fallback
      pdf: support RASTER_SOURCE patterns
      test: add push/pop group to fallback test
      ps: handle different x/y fallback resolution in Fallback Image comment
      api: add cairo_surface_supports_mime_type
      ps: support RASTER_SOURCE patterns
      ps: avoid using ps patterns to paint/fill gradients
      ps: add missing 'Q' to end of page
      ps: ensure shading domain is [ 0 1 ]
      ps: fix extend-pad-border test failure
      type1-subset: some fonts have "noaccess put" instead of NP in the Subrs
      type1-subset: ensure additional glyphs required by seac operator are parsed
      win32: fix compilation on cygwin
      test: add test to check that pdf transparency groups are non-isolated
      pdf: ensure all transparency groups are isolated

Alexandros Frantzis (32):
      gl: Fail if GL implementation doesn't support shaders
      gl: Remove unnecessary checks for NULL shader implementation
      gl: Remove fixed-function related code paths
      gl: Add entry for UniformMatrix4fv in the gl dispatch table
      gl: Add function to bind a 4x4 float matrix shader uniform
      gl: Replace ftransform() with manual coordinate calculation in shaders
      gl: Use a custom shader uniform for the ModelViewProjection matrix
      gl: Add gl dispatch entries for functions related to vertex attributes
      gl: Replace built-in vertex attributes with custom attributes
      egl: Ensure that the dummy pbuffer surface is compatible with the supplied context
      boilerplate/egl: Ensure that we are using an RGBA32 egl config
      gl: Correctly extract GL version from OpenGL ES version strings
      gl: Store the GL flavor (Desktop or ES) in the device struct
      gl: Add GLES2 support to dispatch table initialization
      gl: Pass more information to the shader emitter functions
      gl: Add functions to get the filter and extend of gl operands.
      gl: Provide a shader implementation of GL_CLAMP_TO_BORDER for GLES2
      gl: Store gradients in 2D textures of height 1 instead of 1D textures
      Extract function to query endianness from xlib/xcb and make it common
      gl: Require the GL_EXT_texture_format_BGRA8888 extension for GLES2
      gl: Use conventional texture upload for GLES2
      gl: Add support for creating image surfaces for GLES2
      gl: Add GLES2 support for drawing image surfaces on gl surfaces
      gl: Remove unnecessary call to glDisableClientState()
      gl: Use GL_MAX_TEXTURE_IMAGE_UNITS to query the maximum texture units
      gl: Require the GL_OES_texture_npot extension for GLES2
      gl: Add GLESv2 backend to build system
      gl: Fix build issues for GLES2
      boilerplate/egl: Add GLES2 support
      gl: Define the float precision in the fragment shader for GLES2
      gl: Fall back to dlsym() if *GetProcAddress() fails
      gl: Add fallback path for GLES2 implementations not supporting GL_OES_mapbuffer

Andrea Canciani (189):
      Fix regressions from 1.10 merge
      xcb: Fix compositing of pixel-aligned rectangles
      mesh: Rename cairo_pattern_mesh_* functions to cairo_mesh_pattern_*
      test: Fix clip-device-offset
      test: Fix surface-pattern-scale-down-extend
      test: Fix REFERENCE_IMAGES
      xlib: Fix compilation when gradient functions are not available
      image: Fix surface acquisition if PIXMAN_HAS_ATOMIC_OPS
      test: Fix missing REFERENCE_IMAGES
      test: Silence gcc
      test: Silence gcc warning
      test: Silence gcc warnings
      test: Cleanup macros
      test: Use ARRAY_LENGTH() macro
      test: Add show-glyphs-advance
      quartz: Fix y glyph advance
      xcb,xlib: Fix 1-stop gradients
      xcb,xlib: Fallback upon generic radial gradients
      test: Add stroke-open-box
      path: Fix _cairo_path_fixed_is_rectangle()
      script: Fix stroking of 3 sided boxes
      Make cairo_set_font_size() a wrapper of cairo_set_font_matrix()
      quartz-font: Remove unused variables
      Improve cairo_rectangle_list_t error handling
      trace: Always emit a function name for write-to-png-stream
      image: Silence missing enum value warning
      image: Silence gcc warning
      Do not warn when ignoring the return value of _cairo_rectangle_intersect()
      Remove unused function declarations
      Do not use fmax()
      Revert "Add an implementation of fmax for use with MSVC"
      Improve headers-standalone target
      Fix warning by check-doc-syntax
      Fix visibility issues found by make check
      Remove if's from Makefile.sources
      boilerplate: Add generation of constructors on win32
      test: Update generation of constructors on win32
      test: Fix compilation on win32
      test: Use POSIX-compatible unlink
      path-stroke: Avoid mixing cap and join values
      toy-font-face: Do not assume hash != 0
      xlib: Fix build of xlib-xcb
      build: Don't build cairo-sphinx when the tee surface is off
      xlib-xcb: Implement cairo_xlib_device_debug_{g,s}et_precision
      script: Return status when flushing device
      toy-font: Do not open-code cairo_font_face_reference ()
      boilerplate: Silence MSVC warnings
      Avoid deprecated functions on win32
      win32-font: Do not return font in error status
      win32-font: Implement destroy function
      win32-font: Improve static data reset function
      build: Improve generation of cairo-features.h on win32
      build: Improve dependencies in win32 Makefiles
      build: Use common rules for making pdiff
      build: Clean up environment variables and flags for the win32 build
      build: Silence autoconf warnings
      Hide private symbols on MacOSX
      error: Do not define _cairo_error twice
      test: Cleanup build on Win32
      script-interpreter: Build on win32
      perf: Ensure M_SQRT2 is defined
      perf: Fix build on win32
      test: Improve check-ref-missing
      test: Fix typo
      clip: Fix boxes extents computation in intersect_with_boxes
      test: Make parsing of log files more solid
      test: Ignore \r when parsing test log files
      test: Add extended-blend-solid tests
      win32: Fallback upon PDF blend operators
      test: Merge text-antialias-*
      test: Fix check-ref-missing
      Do not open-code freed-pool
      Remove conditional compilation of freed-pools
      Clean up context_pool upon static data reset
      Make error contexts static
      pattern: Implement _rgb functions as wrappers over _rgba functions
      color: Remove unused functions
      gstate: Remove useless code
      device: Add CAIRO_STATUS_DEVICE_FINISHED
      device: Define the CAIRO_DEVICE_TYPE_INVALID device type
      device: Fix documentation of device types
      build: Fix automake error
      build: Fix compilation
      xcb,xlib: Cleanup GC cache handling
      Use new pixman formats
      quartz: Silence const cast warnings
      Fix surface backend structures
      win32: Fix compilation
      win32: Constify
      surface: Check image parameter in cairo_surface_unmap_image()
      win32: Fix typos in documentation
      test: Update image references
      test: Improve horizontal-clip
      polygon: Simplify code for edge clipping
      polygon: Fix generic case of edge clipping
      script: Initialize recording extents
      directfb: Unbreak compilation
      Silence gcc warnings
      Silence Clang static analyzer reports
      cff-subset: Do not use garbage values
      quartz: Silence some clang warnings
      device: Flush on a finished device is a no-op
      pattern: Complete the list of possible pattern errors
      build: Respect CFLAGS and LIBS env settings
      default-context: Do not allow restoring pushed gstates
      clip: Fix copy of clip rectangles list
      Fix make check
      Update FSF address
      Tighten error validation
      surface: Set errors through _cairo_surface_set_status()
      pattern: Do not provide type field in cairo_pattern_union_t
      font-face: Cleanup backend-specific destruction code
      Remove useless checks for NULL before freeing
      hash: Improve double hashing
      hash: Compare hash values before calling keys_equal
      scaled-font: Remove _cairo_ft_scaled_font_get_unscaled_font()
      scaled-font: Make unscaled font utility functions static
      perf: Add hash table benchmark
      hash: Improve handling of dead entries
      hash: Code cleanup
      clipper: Fix crashes
      perf: Silence gcc warning
      quartz: Fix compilation
      win32: Fix compilation
      time: Add cairo_time_t type
      Introduce the cairo-missing library
      perf: Reuse cairo-time
      perf: Drop cairo_perf_ticks_t in favor of cairo_time_t
      perf: Get rid of cairo_perf_ticks_per_second()
      perf: Fix readme
      script: Fix make check
      surface: Fix make check
      win32: Fix linking
      perf: Fix win32 build
      observer: Fix build on suncc
      cairo-missing: Fix and cleanup ssize_t type definition
      malloc: Fix build on suncc
      wideint: Fix build on suncc
      cairo-missing: Fix build
      quartz: Fix build
      Make cairo-missing a static library
      quartz-font: Fix scaled font backend hooks
      quartz: Fix the 32-bits build on MacOSX 10.7
      rectangle: Fix warning
      stroke: Fix typos
      quartz-image: Fix build
      vg: Fix build
      cogl: Fix 'make check'
      default-context: Fix 'make check'
      xml: Fix backend structure
      Silence some 'unused var' warnings
      cairo-script: Don't ask for inlining of a cold-path function
      boilerplate: Provide close callback after opening any2ppm output
      Sort option flags
      Improve the documentation of the flags
      test: Re-enable pass-through
      test: Remove dead code
      test: Remove unused thread field
      boilerplate: Remove unused thread id parameter
      test: Reuse cairo_test_logv()
      Use xstrdup instead of xmalloc when possible
      Remove useless checks for NULL before freeing
      boilerplate: Fix svg extension
      test: Use cairo_test_list_t for the main test list
      test: Do not open files in non-existing dirs
      xcb: Fix typo
      subsurface: Fix 'make check'
      test: Use fork() on MacOS X
      test: Add negative-stride-image
      test: Add stride-12-image
      quartz: Fix building with QUARTZ_DEBUG
      quartz: Make glyph antialiasing consistent with quartz-font
      quartz: Do not export private functions
      raster-source: Do not return value in void function
      pattern: Infinite color-only sources are always opaque
      rectangle: Implement _cairo_rectangle_contains_rectangle()
      observer: Return status when printing the observed data
      observer: Silence gcc warning
      win32: Fix Makefile.win32 build
      device: Minor documentation fixes
      build: Add 'clean' target to Makefile.win32 build system
      test: Compile any2ppm on Windows
      test: Fix any2ppm on MSVC
      test: Create output directory even on Win32
      build: Make 'all' the default target in the base Makefile.win32 build
      path-fixed: Silence gcc warnings
      stroke-style: Silence gcc warning
      perf: Don't use a boolean value as integer
      boilerplate: Use any2ppm from ANY2PPM env variable

Behdad Esfahbod (4):
      Don't err on non-invertible font matrix
      Bug 34011 - headers-standalone target is incorrect for some non-gcc compilers
      Don't cache _CAIRO_ENABLE results
      [ft] Minor

Benjamin Franzke (1):
      egl: Fix eglMakeCurrent for egl surfaces

Benjamin Otte (22):
      AUTHORS: Use correct email for me
      tests: Add line-width-tolerance
      tests: Fix gcc complaint
      test: Add line-width-overlap
      xcb: Don't operate on a status variable that is never set
      Assert that an error is valid when set
      surface: Don't be nice to people setting internal error codes
      device: Don't be nice to people setting internal error codes
      region: Don't be nice to people setting internal error code
      surface: Allow NOTHING_TO_DO as a valid error for now
      test: Add missing format to any2ppm to silence gcc
      surface: Actually return a value from _cairo_surface_set_error()
      arc: Handle radius == 0 the same no matter the arc direction
      Revert accidental checkin in last commit
      Declare variables first so gcc shuts up
      test: Add a test for 0-radius negative arcs
      test: Fix gcc complaints about old style definitions
      test: Fix copy/paste error
      arc: Remove erroneous return statement
      test: Fix gcc signedness warning
      build: Use $GREP -e instead of plain grep -e
      image: Don't crash on weird pixman formats

Carlos Garcia Campos (1):
      xlib: Check pixman format before trying to create an image surface for it

Chris Wilson (533):
      version: Post-snapshot bump
      xcb: Only use clip rectangles for more than 1 pixel-aligned box
      image: Limit span rendering to bounded extents
      test: Attempt to capture out-of-bounds spans compositing bug
      surface: Don't pass INT_UNSUPPORTED to _cairo_surface_set_error
      configure: Test for funlockfile
      xcb: Compile fix when using xcb-drm
      trace: Fix hint_style/hint_metrics typo
      image: Fix pixman format to RGB30 conversion
      Silence the compiler for another couple of RGB30 switches
      cairo-trace: Fix an obscure bug recording the fishtank
      xlib,xcb: Force strict adherence to the Render specification when testing
      boilerplate/xcb: Fix silly cut'n'paste errors in previous commit
      test: Add unaligned-box
      perf/micro: Add wave
      perf
      gl: Mark the use-once vertex buffers as DYNAMIC
      boilerplate: Introduce create_similar hook
      cairo-trace: Fix use of buf outside of scope
      cairo-perf-diff-files: Don't print size/content for trace results
      test: Add a Makefile.refs generator
      xlib: Create an exact match for the image surface if possible using Xrender
      png: Fix support of depth-30 images
      test: Test a1 clipping semantics
      ft-font: If the pattern is already resolved, use it immediately
      scaled-font: Key the cache on the orignal font_face
      Excise DRM-Xr
      Excise xcb-drm
      scaled-font: Fix assertions for original font-face vs font-face
      image: Only discard the outer boxes
      tests: Add clip-complex-shape
      tests: Add paint-clip-fill
      Implement cairo_backend_t
      pattern: Add observer hooks
      xcb: Remove more bits of drm integration
      test: Always compile cairo-test-suite
      test: Add random-clips to stress test clipping
      gl: Compile fix, missing include cairo-pattern-private.h
      tests,perf: Add a hatchings clip-test
      test,perf: Another hatching!
      ps: Add HAS_FT_FONT guards for type1
      clip: Rudimentary support for clip-polygon extraction
      win32: Fixup clip-mask fallback after API changes
      clip-boxes: Intersection with 0 boxes means clip-all
      xcb: Take advantage of clip-boxes
      xcb: squash initial ChangePicture request for precision
      xcb: Reduce one pass for masking, now just 2 passes required!
      Fix proxying of ->context_create()
      gstate: Handle NULL clip for in_clip()
      xcb: Always send a clip region along with clipped glyphs
      test: Expand partial-clip-text
      test: Extend recording-surface-pattern to include a SOURCE operator test
      test: Add a paint-with-alpha variant to test clip-boxes fast path
      image: Fix partial clipping of text
      image: replay the recording surface directly onto the target
      image: Apply mask-opacity to clip boxes
      tests: Missing ref images for new recording-surface test
      tests: Another missing ref, this time clip-disjoint-hatching
      region: Directly handle single rectangle creation in create_rectangles()
      trace: Create a new opcode for recording surface
      surface-wrapper: Fix use of uninitialised variable
      clip: Embed a single box to avoid a common allocation
      freed-pool: Enlarge the freed cache
      scaled-font: Single glyph extent computations are worryingly frequent
      composite: Perform a quick is-clipped for glyphs
      recording: Only look for a fill-stroke operation if the target supports one
      test: Exercise replaying basic painting paths
      test: Add clip-intersect
      image: Fix clip-intersect
      xcb: set the right members of cairo_color_t for generating the opacity mask
      recording: Move the glyph allocation into the wrapper after checking clip status
      wrapper: Factor out the common clip handling
      wrapper: Use the stack for small glyph allocations
      wrapper: show-text-glyphs can now operate on constant array of glyphs
      wrapper: Correct translation of clip for wrapper extents
      clip: Skip processing of rectangle-intersection if it wholly subsumes the clip
      clip: Short-cut the common condition of intersecting with a single box
      recording: Combine the clip to the recording + target surface extents
      xcb: Make composite_opacity_boxes slightly less silly
      record: Store the untransformed operation extents along with the command
      record: Check the operation against the target device extents.
      wrapper: target to recording needs the inverse transform
      rectangle: speed up the is-intersecting test.
      API: map-to-image and create-similar-image
      composite: Pass unbounded extents to initialisation
      wrapper: translate the clip by the device transform
      polygon: Don't skip clipped horizontal edges
      polygon: Fix clipping of edges outside of their range
      test: Add horizontal clip test
      record: Use a bbtree to reduce is-visible checking overheads
      record: And remember to offset the index of unbounded playback
      record: We can only skip the clear so long as we know the destination is clear
      record: Recording surfaces need an explicit clear
      record: Assume recording surface targets are clear
      clip: Fix cairo_clip_equal()
      clipper: Detect a incremental change in the general clip-path
      record: Only reduce fill+stroke if the clip doesn't change between the commands
      fallback: Prevent recursion when combining with the clip
      xcb: Short-circuit multiplying the alpha mask by 1.0
      clip: Fix clip-equal to handle one or the other being NULL/all-clipped
      clipper: Also need to guard against the incoming clip being NULL
      pdf: Remove redundant clip regions
      pdf: Don't remove the current clip if redundant
      ps: Apply the clip reduction techniques from pdf
      gl: Rectangular fast path
      gl: Rectilinear fast path
      xcb: Convert the box back to integer coordinates for uploading the image
      trace: Emit the content type for image surfaces
      image: extend support of direct replay for paginated surfaces
      image: Free clip_surface after use
      paginated: Remove an impossible test
      test: Exercise extend modes with recording patterns
      spans: fast-path common case of a single box.
      tor: Use longjmp to throw an error whilst generating spans
      image: Reduce compositing bounded boxes with a clip-mask to a polygon
      clip: Mark __cairo_clip_all as private and do not export
      tor: Sort the initial edge correctly
      image: the boxes are already pixel-aligned so skip the extra rounding step
      test: Extend PDF blend tests to include an opacity mask
      tor: Suppress repeated spans
      perf: Add a few more variations to dragon to exercise unaligned lines/spans
      bo-rectangular: perform an incremental sort
      perf: Save/restore gstate across runs
      test: Add an test case to exercise overlapping caps between dash segments
      test: Add a second ring to overlapping-dash-caps
      bo-rectangular: handle in==out specifically for the single box case
      perf: Add stroke/fill variants to world-map
      test: Add world-map from the perf-suite
      test: Add a couple of tests to exercise stroking of short tail segments
      clipper: Don't emit an empty clip-path for no clip boxes
      test: Add join-star, another stroker exercise
      test: Add an loopy I-bar stroker test
      test: Add joins-retrace
      util: Add show-polygons
      test: Add a1-sample
      test: Add unclosed-strokes
      perf: Add many-strokes
      perf: add the usual special cases to many-strokes
      tor: First perform a bucket sort before merge the sub-edges from the polygon
      tor: Inline reverse insertion sort for handling intersections
      build: Add a missing cairo-backend-private.h
      perf: Add many-fills
      fill: A horizontal/vertical line is also a degenerate fill box
      bo-rectangular: Eliminate allocation for pqueue
      bo-rectangular: Use a mergesort to speedup insertion
      bo-rectangular: Correctly mergesort a doubly-linked list
      tor: trivial changes
      tor: Fix mergesort to handle doubly-linked list
      perf: add many-curves
      perf: add curve
      tor: update is-vertical along with min-height
      fixed: Allow the implicit close of the last fill path to complete a fill-box
      trace: Pop the surface after write-to-png
      script: Include an operator to replay a recording surface to a file
      script: Compile fix
      recording: do not reduce required clips
      test: Add record-extend
      util/show-polygon: Show end-points
      util/show-traps: Cache the rendering of the traps+edges
      script: Remove reference to image-surface-private
      default-context: Tidy push-group
      tor: Micro-optimise
      bo: Perform an initial bucket sort on the start events
      xlib: Set the clip_region for glyphs
      test/line-width: Add a non-antialiased variant
      perf/micro: Test wide vs hairline strokes
      perf/micro: diagonal lines
      bo-rect: Micro-optimisation
      image: move surface definition to new header for subclassing
      skia: Update to use cairo_backend_t interface
      Fix pollution from skia commit
      surface-wrapper: Initialise clip to NULL
      bo-rect: One step too far...
      boilerplate: improve fidelity of surface extraction
      recording-surface: Don't store the transient error when returning the path
      surface: propagate internal statuses
      pdf: Propagate NOTHING_TO_DO
      surface: Don't modify operator
      recording: replay_all is meant to mean REPLAY && ALL!
      pdf: Compute fill-stroke extents first before trying to use it to set the clip
      pdf: composite-rectangles now require freeing after use
      Only reduce the clip if it is not in active use for the operation
      test/line-width: Refactor and tidy
      test: Add a couple of variants to line-width-overlap
      stroke: Rely on the tessellator to remove self-intersections
      Add missing 'cairo-image-surface-private.h'
      test/xlib-expose-event: Be kinder to recording surfaces
      script: Emit sequences of boxes to as 'rectangle' for clarity
      snapshot: Defer acquisition
      script: Support unbounded native recording surfaces
      recording: remove the duplicate 'content' field
      recording: break self-copy loop
      subsurface: call the high-level cairo_surface_flush
      subsurface+recording: handle recursion
      image: peek through a snapshot to the recording surface behind
      paginated: unwrap subsurfaces during context creation
      analysis: prevent recursion whilst analysing recording patterns
      ps: unwrap recording surface snapshots
      snapshot: Assert that we do not generate a snapshot clone
      paginated: Use the backend->snapshot
      wrapper: Use the backend->snapshot function
      pdf: If the recording surface is unbounded, limit the pattern to the ink extents
      script: leave the tail of the RGB24 data unmolested
      script: take advantage of the polymorphism of the interpreter
      script: Missed break for creating unbounded recording surfaces.
      xlib: Mark surfaces as finished when the Display is finished/destroyed/closed.
      xlib: Move the Display pointer nullify into destroy from finish
      record: Offset the clip by the replay transformation as well
      surface: Rearrange nothing_to_do? to catch OVER + clear source
      script: Hook image caching into the snapshot mechanism
      gstate: Copy clusters for an untransformed unbounded surface
      Introduce cairo_surface_observer_t for performance analysis
      script: enable by default
      tee: compile fix for migration of _cairo_is_recording_surface()
      xml: Include 'cairo-image-surface-private.h'
      Introduce cairo_mime_surface_t
      check: make check-headers happy
      recording: Defend against bad user-input
      stroke: move normal stroker to new file
      stroke: Convert the outlines into contour and then into a polygon
      observer: report number of solid patterns first
      observer: print operator frequencies
      observer: print stroke caps/joins frequencies
      snapshot: restore the order of detach vs callback
      observer: print path antialias modes
      obverser: only print out the active patterns
      observer: only print out the non-zero path types
      observer: only print out the non-zero clip types
      observer: further classify general clips
      observer: put a comma between array items when printing
      obsever: include the operation timings
      perf: Cleanup target after each run
      observer: record all operations and their timings
      xlib: Fix typo in snapshotting.
      recording: optionally disable optimise away clears
      observer: copy glyphs around call into backend
      observer: bypass surface mid-layer and call into recording surface directly
      test: Add checkerboard
      test: Add big-little-box
      test: Add record-mesh
      test: Extend record-extend to exercise similar surface sources
      test: Extend rotate-image-surface-paint
      test: Add shape-general-concave
      observer: correct classification of aligned paths
      observe: Provide the sum of the elapsed time of the individual operations
      test: Add clip-mixed-antialias
      test: Add big-little-triangle
      test: Add big-empty-box
      test: Add big-empty-triangle
      perf: Print a summary of each operation for a trace (using '-s')
      api: Extend cairo_antialias_t to include performace/quality hints
      observer: Add missing return codes
      perf/Makefile.am: Add missing '\' line continuation
      Introduce a new compositor architecture
      test-surfaces: compilation fixes
      perf/micro: Add measurement of setting the pixel directly using pixman
      test: Update ref images
      mono-scan-converter: Decrement height as we skip straight edges
      perf/stats: Avoid overflow when summing time-squared
      traps: Send unaligned boxes as trapezoids
      traps: Skip compositing an empty bounded regions
      image: Adapt to updated pixman lerp operators
      test: Add the PS tiger
      perf/micro: Add the PS tiger as a measure for the antialias hints
      mono: Amalgamate adjacent spans
      skia: fix compilation
      image: fix compilation of spans with LERP
      test: Fix ref images for a1-clip-*
      test: Add ref image for random-clip
      perf: Add an a1-pixel variant
      test: Use the trapezoid reference image for random-clip
      test: Complete set of baseline reference images
      ps: Set transparency for stencil_masks
      test: Move all the reference images to their own directory
      test: Write the individual test logs to output/
      ps: Fix return value for mask_supported and ps2
      ps: Check earlier for a supported mask
      test: Mark some more raster-only tests
      composite: Reduce an unaligned clip
      script: Tag the similar surface rather than snapshot
      test: Fix reference image for unbounded operator
      build: Add missing cairo-surface-backend-private.h to sources
      build: Another missing private.h
      check: Make the newly added privates pass make check
      image: Invert recording matrix before replay
      test: refresh clip-operator ref.png
      test: Record the failure of recent freetype libraries for type1 vertical layout
      test: Update refernece dir for create-from-png-stream
      test: Update couple of refs for the improved mono rasteriser
      test: Use the test-traps as the reference images for xlib/xcb
      test: Replace xlib reference images with the traps references
      fdr,tee: Reorder master/slave invocation to capture death-upon-signals
      test: Hack cairo-test-trace to write at trace for all contexts
      test: Add bug-bo-ricotz
      bentley-ottman: End subsumed colinear traps
      test: Update reference images for test-base
      base: Make sure we have fuzzy clip boxes!
      path: Skip calls to zero-length memcpy
      test: Add a1-fill
      test: Refresh reference images for spans/traps
      image: Use A8 for creating a mask from a recording surface
      image: Use the recording surface content for the recording source
      wrapper: intersect with target extents
      image: intersect the source extents with the replay extents for EXTEND_NONE
      test: Record the current status of radial-outer-focus as xfail
      composite-rectangle: Add a helper to refine source extents
      pdf: Use the helper functions to update the composite rectangles
      os2: Blindly update os2 to the new fallback compositor
      test: Make cairo_test_suite depend upon the any2ppm exectuable on all platforms
      traps: use the customised _cairo_clip_get_surface
      xcb: track fallback damage
      wrapper: transform the clip into device space
      image: clip the replay to the sample extents in device space
      image: don't offset by device transform for replay onto source surface
      test/trace: Hack to dump out per-context images and traces
      test/create-from-png: Update to point to new reference/ images
      test: refresh text-pattern reference
      test: Exercise scaling from an atlas through a subsurface
      test: Redefine success for miter-precision
      spans: Fix empty polygon unbounded fixup
      test: Refresh tighten-bounds reference image
      test: Refresh rotated-clip reference
      test: Mark the record-select-font-face as XFAIL
      boilerplate: Skip testing of null surfaces
      win32: Compile, but broken
      script: compile without
      polygon-intersect: Remove surplus edge direction
      test/random-clips: Paint clip to highlight the issues
      test: Refresh reference images
      trace: Emit an stack operation to create a pattern from an undefined surface
      test: Add line-width-large-overlap
      stroke: Use the tessellator to resolve overlapping strokes
      image: Enable use of LERP_SRC for masked source composition
      fill: Fix unantialiased rectilinear-fill-to-boxes
      test: Add clip-rectilinear
      gl: Declare coverage input for fragment shaders.
      gl: Basic fixes to get cairo-gl running again
      gl: Need to increment reference count when copying operands
      botor: Remove a couple of inlines to cleanup -Winline
      perf
      debug-traps
      gl: Include use-coverage in shader hash
      gl: Spans start after the mask, not coincident!
      gl: Remove unused alpha argument from operand_emit
      xcb: Re-enable glyph rendering
      observer: Fix typo and handle the condition of no script device
      mono: Silence valgrind by placing a sentinel value in the sorted buckets
      spans: Propagate internal status when retrieving the clip surface
      test: Add clip-polygons
      surface-clipper: Fix path leak due to typo
      clip: Free the freed clip pool on reset
      clip: Replace the original clip when transforming
      recording-surface: Free the contents of the command array when clearing
      recording-surface: Optimize away anything below an opaque fill
      spans: Refresh polygon limits after trimming the composite extents
      gstate: Prevent leak of old clip when creating a group with translation
      recording-surface: Initialize optimize-clears before use in snapshotting
      ft: Add missing break to enable BGR subpixel rendering
      gl/msaa: Markup the new symbols as private for PLT hiding
      xlib: Reduce the composite traps operator for when the dest is clear
      xlib-xp
      Merge branch 'master' of git://cairographics.org/git/cairo
      Merge branch 'master' of git://cairographics.org/git/cairo
      gl: Initialize spans on the context
      Revert "xcb: Fix xcb-huge-image-shm"
      xcb: Handle SHM exhaustion gracefully
      perf: Compile fix, add the index to cairo_perf_report_load()
      polygon-intersection: Finish any edges upon intersection
      image: Only unwrap a subsurface if the sample is fully contained
      subsurface: Simplify acquire_source_image
      image: Remove dubious "optimisations" for acquired source images
      subsurface: And remove the dead code for releasing complex source
      xlib: ADD only reduces to SOURCE for alpha-only targets
      xlib: Handle subsurfaces correctly
      subsurface: Support caching for cloned subsurfaces
      surface: Bump reference count around finish
      xlib: Cache the subsurface Picture
      xlib: Eliminate redundant copies of subsurfaces
      gl: Update glyphs to use cairo_gl_source_t
      gl: Correctly offset sub-image uploads
      gl: Fallback for complex subsurfaces
      gl: Avoid cleaning up an uninitialised composite upon UNSUPPORTED
      gl: Embed a operand into the surface for pass-through
      gl: Prevent the traps compositor from exploding
      Convert cairo_mime_surface_t to cairo_raster_source_pattern_t
      script: Prefer polymorphorism for mesh path construction
      trace: Remove the warning about the unstable format
      gl: Temporarily clone a subsurface as required
      gl: And enable subsurface caching of the clones
      subsurface: Replace any existing snapshot
      gl: Even repeating subsurfaces need to be cloned
      xcb: Silence a compiler warning for mixing status and internal status enums
      doc: Add similar-image, map-to-image, unmap-image
      doc: Add sections for cairo-script
      script: Add documentation
      doc: Add new antialias symbols
      doc: add CAIRO_DEVICE_TYPE_COGL
      doc: Drop the gtk-doc markup from _cairo_radial_pattern_focus_is_inside
      gl: Make the backend struct static
      gl: Check against user-provided invalid sizes
      gl: Propagate surface texture to embedded operand
      gl: Use the embedded operand to allow passing sources around
      gl: Embed the operand rather than a pattern into the glyph cache
      gl: Decouple glyphs on shutdown from the scaled font caches
      gl: Substitute the white source for the default pattern
      gl: Propagate clip region
      gl: Set the device offset on map-to-image
      fallback: fix the offset for painting
      gl: Unbreak the glyph cache
      gl: Re-enable the CLEAR optimisation
      polygon: Assert that we add edges that are wholly contained by the clip
      polygon: Tweak the y-coordinates of the edge so that it is inside the clip
      test: reference ref images after tweaking polygon clipping
      test: Exercise copy/filling unsorted rectangles
      gl: Defer stencil allocation until use
      gl: Prevent leak of the white source used with glyph masks
      doc: Add documentation for cairo_raster_source_pattern
      gl: Decouple the glyph upon eviction
      gl: Track surface references through operands
      gl: Set the destination for swap buffers, required by EGL at least
      gl: Disable the msaa compositor by default (for release testing)
      perf/chart: Tweak labels on right not to fall off the edge
      perf/chart: Show values next to the column if too small to fit inside
      perf/chart: Make the columns transculent so that the label behind is visible
      test: Add arc-direction
      xlib: Do not upload inplace if the image does not match the surface format
      xcb: Add dimension guards to create-similar-image
      subsurface: Add guards for creating similar surface
      xlib: Fix typo in 5045155de6, lack of closing ';'
      xlib: Improve choice of bits-per-pixel for depth
      xlib: Set IncludeInferiors when using CopyArea
      xlib: Set IncludeInferiors when acquiring the source image
      xlib: Only reduce a readback of an uninitialised source for pixmaps
      gl: Just flush the context upon operand destroy
      Replace the ad-hoc surface unwrappers with a function pointer
      test: Referesh traps (xlib) reference images for font updates
      directfb: Discard long broken code and return to basics
      polygon: Extend intersection edges to cover entire range
      tor: Restore the 256x15 sampling of the original rasteriser
      clip: Check whether an extents only clip contains the box
      clip: Apply the partial boxes for clip_combine_with_surface
      spans: Pass unbounded operations to the spans compositors
      traps: composite_boxes() is not a mask constructor
      polygon-intersection: The edge direction is immaterial
      gl: Transfer ownership of trapezoid mask to operand
      analysis: replace open-coded _cairo_box_add_box()
      quartz: Add missing source hook
      Add preliminary damage tracking
      win32: Move to separate directoy
      win32: Rebase on the new compositor infrastructure
      win32: Fix lifetime tracking of create_similar_image()
      win32: Cast the surface to an image-surface to find its parent (compile fix)
      test: Refresh reference images for antialiasing fix
      image: Add the get-font-options callback again.
      test/README: Update sha1sums for fonts used
      test: Update base reference images for new reference font
      test: Update traps for changes in reference font
      boilerplate/xlib: The xlib-fallback should be visually identical to image
      test/xlib: Remove stale reference images
      xlib: Replace obsolete disable-xrender with shiny new device debug interface
      test: Add a set of reference images for the mask-based compositor
      boilerplate/xlib: Exercise the mask based compositor for xrender version 0.0
      xlib: Hook up copy_boxes for the mask compositor
      mask-compositor: Acquire the target surface when creating the composite mask
      traps-compositor: Reduce a complex clip generation to an ADD operator
      xlib: Trim the intermediate upload image to match the upload extents
      xlib: Correct the device-offset applied to the map-to-image result
      xlib: Make the core compositor actually paint
      xlib: Trim the ximage to match the trimming of the intermediate
      traps-compositor: add a missing release()
      script: Update mesh pattern for earlier change of csi operators
      image: Tidy reduction to EXTEND_NONE for replay surfaces
      surface-wrapper: Transform the clip by the device-transform correctly
      xlib-xcb: Wrap cairo_xlib_device_debug_cap_xrender_version
      xlib: Tidy conversion of xrender format to cairo_content_t
      xlib: Handle window-to-window copies by avoiding the use of a clip region
      {mask,traps}-composite: Restore unsetting of the is-clear flags for the mask
      image: Handle recursive drawing of recording surface
      debug: Add some TRACE statements for recording surfaces and snapshots
      recording: Optimize a copy of one recording surface onto another
      subsurface: Fix typo in snapshot creation
      test: Add a couple of reference images for the recording surface
      recording: Remove superfluous reset
      test: a1-line-width is a test of rasterisation, so skip for the vector backends
      pdf,ps: The device offset only needs to taken into account for raster patterns
      test: Verify scaled replay of a recording surface
      surface-wrapper: Apply replay transforms to scaled font
      test/record: Fix typo in record*-text-transform
      test: Set record2x-fill-alpha as an xfail
      scaled-font: Key the cache on the original font face
      scaled-font: Refactor the hash computation
      test: Add record90 to exercise replaying a rotated recording surface
      scaled-font: Assign a temporary hash value for the placeholder
      test: Regenerate reference images for vanilla record tests
      surface-wrapper: Apply the scaled-font ctm and non-default font-options
      spans+image: Fix clipping with polygons and spans
      gl: Various fixes for glyphs
      ft: Remove unused HINT_METRICS from ft_font.extra-flags
      ft: Export FreeType synthesis options
      spans,traps-compositor: Check for all-clipped after intersecting clip with boxes
      test/record1414: Pixel align the clip for replay
      base: Remove the double application of the clip boxes
      image: Correct origin of unbound recording surface source
      spans: Pass antialiasing hint down to the backends
      image: Add a fast path for solid-filled polygons
      spans: Retrim extents to clipped polygon
      image: Perform the general composite operation inplace for mono rasterisation
      image: Add a fast-path for mono-rasterised blits
      spans: Reduce composite_aligned_boxes with over to source for opaque patterns
      spans,image,gl: Add fast-path for simple copies
      traps: Use the mono-scan-converter to reduce the number of traps
      traps: First attempt to convert curvy unantialiased polygon to scanlines
      spans: Handle fallbacks from upload-boxes by reverting to the normal composite
      image: Perform the simple solid-fill spans inplace
      image: Add a simple inplace blitter for spans
      image: Try performing span composition a row at a time
      surface-wrapper: Only apply the wrapped transform to the scaled-font
      image: Add unbounded support to the mono rasteriser fast-paths
      clip: Use the boxes-intersection routine for computing the clip polygon
      traps: Avoid double application of unaligned clip boxes
      traps: The CompositeTrapezoids requires the unbounded fixup for clipping
      xlib: Apply the glyph offset
      surface: Relax assertion about not rendering to a snapshot
      test: Refresh the fallback-resolution reference images
      hash: Keep a simple lut in front of the main hash
      bentley-ottmann: Skip intersection check if the bounds do not overlap
      bentley-ottmann: Sort by edge bounding boxes before computing x
      mono-scan-converter: Use edge->is_vertical flag
      stroke: Do not initialise the pen if will not use it
      skia: compile fix
      test: Restore 'release-verify-sane-tests' makefile target
      version: Bump for snapshot 1.11.4
      version: Post-release version bump to 1.11.5

Chuanbo Weng (1):
      gl: fix bug in _cairo_gl_surface_embedded_operand_init()

Dagobert Michelsen (1):
      Use detected EGREP instead of generic grep

Dave Yeo (3):
      os2-surface needs to include cairo-image-surface-private.h
      Fix the number of parameters for cairo_os2_surface_set_size()
      On OS/2, WIFSIGNALED and WTERMSIG are prototyped in sys/wait.h

Ehsan Akhgari (1):
      Avoid defining inline when compling C++ on MSVC.

Eric Anholt (4):
      gl: Don't reset the FBO draw/readbuffers every time we bind the FBO.
      gl: Add a first bit of general documentation on cairo-gl usage.
      gl: Take advantage of GLX_MESA_multithread_makecurrent to avoid unbinding.
      gl: Bind samplers just once at program compile time.

Haithem Rahmani (1):
      boilerplate: Use correct flag type in DFBWindowDescription

Henry (Yu) Song (1):
      gl: initialize temporary surface with size same as subsurface

Jeff Muizelaar (5):
      Add UINT32_MAX define.
      Add an implementation of fmax for use with MSVC
      Remove quartz-image extents.
      win32: Explain the purpose of the surface extents
      Avoid implicit conversion to double when rounding

Jesse Barnes (1):
      Expose 30bpp/10bpc support: CAIRO_FORMAT_RGB30

Jesse van den Kieboom (1):
      quartz: Rename declaration of _cairo_quartz_create_cgimage

Keith Packard (4):
      cairo-xcb: gtk-doc doesn't like _ in parameter names
      Create XCB documentation.
      Add cairo_xcb_surface_set_drawable
      Clip rectangles are not necessarily YSorted

Krzysztof Kosinski (1):
      test: Add radial-outer-focus

Krzysztof Kosiński (1):
      test: Add test case from bug-40410

M Joonas Pihlaja (1):
      image: Avoid reusing pixman images for threadsafety.

Martin Robinson (14):
      gl/msaa: Introduce an MSAA compositor for OpenGL
      gl/msaa: Implement basic solid color fill
      gl/msaa: Add clipping support
      gl/msaa: Support for solid color strokes.
      gl/msaa: Fix glScissor bounds
      gl/msaa: Fix scissor bounds
      gl: Fix offset for non-texture surface patterns
      gl: Properly prepare the source when compositing glyphs with a mask.
      gl/msaa: If stenciling the clip fails, reset the color mask.
      gl/msaa: Ignore the antialiasing property of the clip.
      gl/msaa: Scissor simple rectangular clips
      gl: Fix the offset of non-texture source surfaces
      gl: Fix gl-source-surface test
      gl/msaa: Do not attach a depth-stencil attachment to the default framebuffer

Matt Peterson (1):
      gl: Use cairo_rectangle_int_t

Murray Cumming (2):
      cairo: Remove trailing comma from cairo_format_t
      cairo_surface_observer_mode_t: Remove trailing comma.

Nis Martensen (24):
      Fix typos
      Mark the new API as such
      doc: Fix pattern name mismatch
      doc: fix typo
      doc: add missing colons to since tags
      doc: typo
      doc: add index of new symbols in 1.12
      doc: add colon to .._padded_image_from_image
      doc: add missing _face to function names
      doc: do not confuse gtk-doc by @ and double *
      doc: Add colon to Returns statement
      doc: script_mode_t needs at least one line of text
      doc: fix a few typos found by codespell
      doc: preserve whitespace by using docbook screen tag
      doc: symbol names in header and comment must match
      doc: ensure "compatibility" spelling
      doc: move value descriptions up
      doc: avoid confusing gtk-doc by double asterisks
      doc: describe cairo_recording_surface_get_extents
      doc/ft-font: add reference to cairo_ft_synthesize_t
      doc/ps-surface: minor improvements
      doc/xlib/xcb: document get/set_precision API
      doc/xcb: document cairo_xcb_device_get_connection
      doc: fix broken link

Oleg Romashin (1):
      qt: Fix compilation, also minor fix for building against Qt5

Paulo Zanoni (3):
      test: fix append_argv()
      test/README: add missing "S"
      cairo-test-runner: don't leak argv

Pekka Paalanen (1):
      egl: do not destroy dummy_surface if it does not exist

Pino Toscano (1):
      LD_PRELOAD is supported on Hurd

Rob Bradford (1):
      build: Specify the reference images as a directory for EXTRA_DIST

Robert Bragg (1):
      backends: Adds a new Cogl based backend

Seongwon Cho (1):
      mono-scan-convertor: Include space for the closing span

Søren Sandmann Pedersen (1):
      Include pixman.h in cairo-xlib-private.h

Taekyun Kim (4):
      tessellator: Fix boxes tessellator to handle num_boxes <= 1 correctly
      tessellator: Fixed to produce an output box with x1 <= x2 for single box input
      Fix intersect_with_boxes() to produce tight clip extents
      image: Maximum number of spans can be upto (extents->width + 1)

Uli Schlachter (131):
      xcb: Fix a BadPicture when clearing a surface
      xcb: Automatically enable the backend if the libs are available
      xcb: Document all public functions
      User fonts: Make it clear what should NOT be freed
      scaled font: Fix the docs for cairo_scaled_font_get_font_face
      xcb: Limit the amount of SHM used
      xcb: Remove a duplicate static function
      xcb: Move the allocation of a shm surface into its own function
      xcb: Use a normal image surface if SHM fails
      XCB: Fix build with xcb-shm disabled
      ps: Update xlib-surface-source ref images
      xcb-surface-source: Add image16 and ps ref images
      Finish devices after their finish callback returns
      xcb: Fix a crash when finishing a device
      xcb: Remove the surface pattern cache
      Fix errors from src/check-plt.sh
      arc-looping-dash: Add a missing cairo_restore ()
      xcb: Remove some unused code
      xcb: Fix for PDF operators with RENDER 0.11
      xcb: Remove CAIRO_XCB_RENDER_HAS_COMPOSITE_SPANS
      xcb boilerplate: Handle device offsets correctly
      xcb: Remove _cairo_xcb_picture_copy
      xcb: Never return NULL from create_similar
      xcb-drm: Fix undeclared variable error
      Add unaligned boxes to "operator-source" test
      image: Don't use the fast path if it's wrong
      test/Makefile.am: Don't reference non-existant files
      Revert "xcb: Never return NULL from create_similar"
      XCB: Implement PDF blend operators natively
      xcb: Fallback to image surface for create similar
      xcb,xlib,surface: Check for too small sizes
      xcb: Don't hardcode the RENDER version number
      xcb: Prettify some code
      xcb: Initialize the new precision fields
      xcb: Use defines instead of magic numbers
      xlib-xcb: Use slim_hidden_proto correctly
      xlib-xcb: Fix api-special-cases test
      xlib-xcb: Verify we really have an xcb surface
      xlib-xcb: Fix cairo_surface_flush()
      xcb: Remove an unused function argument
      xlib-xcb: Fix some use-after-free
      xlib-xcb: Don't call directly into the xcb backend
      Xlib: Fix boilerplate to work with xlib-xcb
      xlib-xcb: Register a XCloseDisplay hook
      xcb: Move cairo_xcb_picture_t to cairo-xcb-private.h
      xcb: Track cairo_xcb_picture_t surfaces
      Add a test case that asserts on xcb
      xcb: Don't use xcb surfaces as snapshots
      Handle CAIRO_STATUS_DEVICE_FINISHED in switches
      cairo-trace: Fix mark-dirty with xcb backend
      xlib-xcb: Fix an "extension leak"
      cairo-xcb: Drop some unused definitions/file
      xcb: Fix _set_clip_region for many rectangles
      xcb: Fix a GC leak when a screen is finished
      xlib-xcb: Fix 'incompatible pointer type' warnings
      XCB: Store the flags per-connection only
      xcb: Make it possible to undo _cairo_xcb_device_debug_cap_*
      Xlib,xcb: Make *_debug_[sg]et_precision() more robust
      xcb: Parse $CAIRO_DEBUG just like cairo-xlib does
      xcb: Fix a NULL dereference
      xcb: Handle deferred_clear in _get_image
      xcb: Unset the deferred_clear flag on fallback
      xcb: Work around wrong extent computation in the X server
      xlib: Fix a typo
      xcb: Check that the extents are inside our surface
      Make _cairo_xcb_surface_get_extents no_warn
      xcb: Assert that pixmap sizes are positive
      xcb: Error on 0x0 source surfaces
      xcb: Handle deferred clear in map_to_image
      xcb: _get_image only works without fallback
      xcb: Handle fallback in map_to_image
      xcb: Handle deferred clear in _upload_image_inplace
      surface_unmap_image: Fix fallback
      xlib-xcb: Implement the new backend functions
      perf: Also build the code in perf/micro
      Clarify the API docs for the newest functions
      cairo.h: Document CAIRO_DEVICE_TYPE_INVALID
      xlib-xcb: Fix a double free in surface_unmap
      map_to_image: Verify the given extents
      map-to-image: Handle non-32bpp formats
      xcb: Fallback to image if allocating SHM fails
      xcb: Merge two functions for creating shm images
      test: Add a test that maps a huge surface
      xcb: Handle SHM exhaustion via falling back
      xcb-shm: Fix a logic error while allocating mem
      test: Add tighten-bounds
      xcb: Add an assert for the tighten-bounds test
      xcb: Fix fallback for *_shm_put_image
      xcb: Skip drawing if bounded extents are empty
      xcb: Fix fixup_unbounded_with_mask
      xcb: Steal from the pending list for GetImage
      cairo_clip_path_t: Remove extents
      xcb: Remove some dead code
      xlib-xcb: Make this compile again
      Tee: compile fix for recent compositor API
      Revert "xcb: Error on 0x0 source surfaces"
      xcb: Improve error cases in _clip_and_composite_combine
      cairo-xcb: Require libxcb 1.6
      boilerplate-xcb: Print sequence numbers
      path: Fix a minor oversight in 1ce5d4707cf26061
      _cairo_clip_get_surface(): Don't lose errors
      xcb: Stop using _cairo_clip_get_surface()
      xcb: Use a mask in _composite_boxes() when needed
      xcb: Remove an unused variable
      xcb: Don't try to fallback more than once
      xcb: Honor clips for defer clear
      xcb: Fix a "incompatible pointer" compiler warning
      xcb: Fix device offsets with unmap_image()
      test: Add mime-surface-api
      Make the new mime-surface-api succeed
      xlib: Fix compilation with --disable-xlib-xrender
      create-from-png*: Test mark_dirty with mime data
      flush: Detach mime data
      test: Add clip-double-free
      clip: Fix clip-double-free
      clip_intersect_boxes: Fix memleak
      test: Add text-antialias-subpixel-{,v}{bgr,rgb}
      xcb: Fix some invalid casts
      xcb: Fix xcb-huge-image-shm
      xcb: Fixup some internal state in set_{drawable,size}
      xlib-xcb: Implement surface_set_drawable
      xcb: Fix invalid casts from cairo_content_t to cairo_format_t
      xcb: Silence a compiler warning for mixing type and internal type enums
      xcb: Silence compiler warnings about ignored return values
      xcb: Move the surface picture setup into its own function
      xcb: Add a special case for recording surface
      xcb: Use int instead of uint16_t for rowstride
      xlib-xcb: Make this compile again
      Wrapper: Don't translate clips extents' origin
      Fix docs for cairo_xlib_device_debug_cap_xrender_version
      xlib-xcb: Fix make check

Zhigang Gong (1):
      mono: Always bias initial edge advancement
```
