---
title: cairo 1.14.0 snapshot available
layout: news
date: 2014-10-13
---
```

 Date: Mon, 13 Oct 2014 20:31:36 -0700
 From: Bryce Harrington <bryce@osg.samsung.com>
 Subject: [cairo] cairo release 1.14.0 now available

 A new cairo release 1.14.0 is now available from:

   http://cairographics.org/releases/cairo-1.14.0.tar.xz

     which can be verified with:

     http://cairographics.org/releases/cairo-1.14.0.tar.xz.sha1
     53cf589b983412ea7f78feee2e1ba9cea6e3ebae  cairo-1.14.0.tar.xz

     http://cairographics.org/releases/cairo-1.14.0.tar.xz.sha1.asc
     (signed by Bryce Harrington)

   Additionally, a git clone of the source tree:

   git clone git://git.cairographics.org/git/cairo

     will include a signed 1.14.0 tag which points to a commit named:
     f6fd372a8b31a0bebbdfe36090d6ffc7bab9a2f8

     which can be verified with:
     git verify-tag 1.14.0

     and can be checked out with a command such as:
     git checkout -b build 1.14.0


 Release 1.14.0 (2014-10-13 Bryce Harrington <bryce@osg.samsung.com>)
 ====================================================================
 Hard to believe it's been over a year since our last release, but it's
 not for lack of activity.  This release includes contributions of a wide
 assortment of bug fixes, build system improvements, warnings cleanups,
 codebase refactoring, test suite repairs, and static analysis work.

 This release is lighter on features (compared with 1.12.10) but includes
 a highly demanded rehaul of our image downscaling functionality, which
 solves a serious problem experienced by Inkscape users when shrinking
 embedded bitmaps in SVG files.  The new scaling algorithms are used by
 the image backend and by other backends as needed for fallbacks.


 Features
 --------

   Filtering improvements for the image backend, in particular
   down-scaling of images produces filtered images that depend on all the
   pixels of the source. When using the image backend you get the
   following settings:

   CAIRO_FILTER_GOOD: uses a box filter for scales less than .75 in
     either direction. For scales larger than this, the same filter as
     CAIRO_FILTER_BILINEAR is used.

   CAIRO_FILTER_BEST: uses a Catmull-Rom filter always. When upscaling
     more than 2x this will produce anti-aliased square pixels, similar
     to OS/X.

   CAIRO_FILTER_GAUSSIAN: uses PIXMAN_FILTER_BEST, which in current
     pixman is the same as BILINEAR. (This is subject to change in the
     future).

   xlib and xcb also use the image fallback for GOOD/BEST filters, but
   note that other backends do not implement these filtering fixes yet,
   however other actions may cause them to use an image fallback which
   will cause these filters to be used.

   Improve handling of device transformation and scaling, allowing Cairo
   to now support scaling at a device level, permitting easier, more
   transparent HiDPI support.

   Support JBIG2 mime data in PDF.  This allows embedding of more
   compressed JPEG formats within PDF, rather than including the full
   uncompressed image.  Also, reduce the number of transparency groups
   used by PDF to keep the file size small and viewing/printing of the
   PDF fast.

   Expand the embedding section to include stencil mask support.

   Reorder font declarations to be in natural order.

   Update the Skia backend to build against current Skia (as of June
   2014).

   Drop Link-Time Optimization (LTO) support from build system.  This
   seems to have caused much trouble for unclear benefit, and most
   distros are reverting or disabling it anyway.

   Optimize VBO size on GL to 1M and to 16k for EGL.  This improves
   (theoretical) performance for desktop GLX use cases while avoiding
   hitting VBO memory size limitations on embedded devices.

 API Changes
 -----------

   cairo_surface_set_device_scale, cairo_surface_get_device_scale:

     Sets a scale that is multiplied to the device coordinates
     determined by the CTM when drawing to @surface. One common use for
     this is to render to very high resolution display devices at a scale
     factor, so that code that assumes 1 pixel will be a certain size
     will still work.

   cairo_egl_device_get_display, cairo_egl_device_get_context:

     Support get/set of EGLContext and EGLDisplay for egl-based cairo
     devices, similar to GLX.

 Dependency Changes
 ------------------

   Cairo now requires glib 2.14 for its gobject helper functions,
   and pixman 0.30 for downscaling.


 Bug fixes
 ---------

   Don't embed CMYK Jpeg images in svg.

   Fix tests to place output in proper location.

   Fix determination of alpha for all surfaces when recording.

   Extend oversize check to cairo_gl_surface_create_for_texture, so an
   error surface is returned if the texture is too large to render to.

   Fix embedding of mime data in PDF and PS files.

   Remove useless error handling in *_reply() functions in XCB.

   Fix a double-free exposed by multithreaded apps creating and
   destroying the same font concurrently.
   https://bugs.freedesktop.org/show_bug.cgi?id=69470

   Fix corrupt stacks produced by bugs in operand emission for trace.

   Fix out of bounds array access in format cache for xlib

   Don't rename glyphs used by seac operator.  This can cause certain
   combined characters to use their decorations (e.g. umlauts on ö) to be
   lost during printing of PDFs using evince.
   https://bugs.freedesktop.org/show_bug.cgi?id=70364

   Fix crash on calling cairo_create with a finished surface

   Fix SSIZE_T definition problem when making with MSYS on Windows7

   Fix one off issue in gl context cleanup

   Fix usage of CAIRO_STACK_ARRAY_LENGTH

   Fix rectangle stroke with non rectilinear pen

   Fix imagemask with pattern source failure on some printers.  This bug
   could cause files converted using pdftops to fail for example on Ricoh
   printers, or opening in Adobe Distiller on Windows.
   https://bugs.freedesktop.org/show_bug.cgi?id=69485

   Fix whitespace in font names

   Fix page size in generated PDFs.  When printing using pdftocairo on
   larger page sizes, such as 11x17, the image would be cropped to letter
   size.
   https://bugs.freedesktop.org/show_bug.cgi?id=73452

   Fix path-currentpoint test by preserving current-point in
   copy_path()/append_path() sequence

   Fix generation of HTML in code docs for
   cairo-format-stride-for-width.  Raw HTML code was being passed
   to the browser, instead of displaying normally.
   https://bugs.freedesktop.org/show_bug.cgi?id=63257

   Fix spelling of "tessellator" throughout code.  We're using the
   American rather than British spelling of this word.
   https://bugs.freedesktop.org/show_bug.cgi?id=50411

   Fix crash in pixman_image_composite32

   Fix crash when trying to modify a (const) all-clipped cairo_clip_t
   https://bugs.freedesktop.org/show_bug.cgi?id=75819

   Add check_composite method to all compositors, to fix crashes in the
   test suite.

   Fix crash in Firefox when scrolling on certain pages.

   Fix memory leaks found by static analysis.

   Fix build of any2ppm if fork is not available.

   Fix broken build for Qt backend, due to missing libstdc++.

   Fix typo in two cairo_uint128 functions.  Fixes potential build issues
   on systems without a uint128 type.

   Fix build when --enable-pdf=no

   Fix cache_frozen assertions for Win32 print.

   Correctly check for xcb image surface for inplace upload

   Fix webkit-based web browser crashes due to empty boxes by skipping
   over them when tesselating.

   Make pixman, libpng, and zlib paths commandline configurable for win32
   builds.

   Fix image scale on Win32 when GDI scale is not identity.

   Fix float endian configure test when using clang -O4

   Fix compilation with Android bionic libc

   Don't try to build util/sphinx on Windows

   Fix loss of precision when emitting joins.  This was caused by
   discrepancies in line gradients when passing trapezoids around.

   Fix loss of precision and associated rendering issues in
   cairo-tor-scan-converter from projection onto sample grid.

   Fix pixman oversampling of neighbouring edges within a cell by
   eliminating self-intersections for the pixman traps compositor.

   Fix multi-line string splitting in PDFs

   Various cleanups and fixes to warnings, documentation, tests, and
   build system.  Improve error handling and return value checks.
   Cleanup XFAIL tests and reference images.  Cover recently added
   functionality.



 Complete list of changes from 1.12.16 to 1.14.0
 -----------------------------------------------

 Adrian Johnson (24):
       Downscaling requires pixman 0.30
       svg: Don't embed CMYK Jpeg images
       pdf: avoid making groups a transparency group if not required
       pdf: fix embedding of mime data that has been broken since 0a10982f
       ps: fix embedding of mime data
       pdf: support JBIG2 mime data
       test: update mime-data to test jbig2 mime types
       pdf: combine source and mask images into single image
       pdf: Support stencil masks with jpeg/jpx/jbig2 embedding
       pdf: stencil masks may be opaque
       type1-subset: don't rename glyphs used by seac operator
       pdf/ps: avoid outputting excess decimal places in matrices
       Add test for rectangle path optimization with non rectilinear pen
       pdf: fix rectangle stroke with non rectilinear pen
       Add test for paint with alpha and clipping bug
       ps: remove duplicate /Interpolate from image dictionary
       ps: fix imagemask with pattern source failure on some printers
       ps: use setpagedevice to set page size
       ps: cairo_set_page_size does not need to be in eps output
       ps: add font DSC comments
       type1: strip space from end of font name
       win32 printing: fix image scale when GDI scale is not identity
       Fix compilation with bionic libc
       pdf: don't use '\' to split strings across multiple lines

 Alexander Larsson (10):
       gstate: Respect device transform in stroke
       default-context: Inherit device scale in push_group surface
       subsurface: Handle device scales
       gstate: Move device-scale font scaling to gstate
       gstate: Handle device scale on surface as source
       surface: expose the device scale
       tests: Add device scale test to "full" testrun similar to offsets
       surface: Opencode create_similar
       surface: Merge scratch construction into _cairo_surface_create_scratch
       surface: Inherit device scale in cairo_surface_create_similar()

 Andrea Canciani (2):
       quartz: Fix build
       quartz-image: Fix build

 Behdad Esfahbod (9):
       Check for XRenderSolidFill()
       [tests] Add path-currentpoint
       Preserve current-point in copy_path()/append_path() sequence
       Revert "[ft] Fix memory bug in copying bitmaps"
       chmod a+x cairo-trace
       [trace] Don't print FC_CHARSET, FC_LANG, and FC_CAPABILITY
       [cairo-trace] Work around fontconfig :charset= parse format change
       Binary mode in any2ppm
       More binary mode for Windows

 Benjamin Otte (1):
       xlib: Fix typo in documentation

 Bill Spitzak (8):
       V6 image: Use convolution filters for sample reconstruction when downscaling
       V5: Use NEAREST filter when possible
       image: Move filter decision to _cairo_pattern_analyze_filter
       xlib: Add symbols to indicate if XRender supports GOOD/BEST filtering
       xlib: Use image fallback for GOOD/BEST filters
       xcb: Add switches for whether XRender supports GOOD/BEST filtering
       xcb: Use image fallback for GOOD/BEST filters
       image: Corrected extents calculations

 Bryce Harrington (65):
       test: Add test for image downscaling
       test: Test a variety of scales when downscaling
       test: Exercise image scaling quality when downscaling
       test: Move cairo_pattern_set_filter to after cairo_set_source_surface
       test:  Drop unnecessary math.h include
       Fix SSIZE_T definition problem when making with MSYS on Windows7
       test:  Replace deprecated rsvg_init() in any2ppm test
       test:  Handle error in fgets call in ps-eps test
       test:  Drop unused path variable in two recently added tests
       cairo-trace:  Stringify CAIRO_STATUS_JBIG2_GLOBAL_MISSING
       cairo-script: Error if asked to decompress with missing compression lib
       cairo-script: Compare status with CSI enums
       perf: Guarantee path width is non-negative
       test: Quell warning for inclusion of old rsvg header files
       test: Quell warning for deprecated g_type_init()
       xml: Drop unused variable
       xml: constify source objects for emit routines
       mesh: Avoid theoretical infinite loops
       gl: Handle PIXMAN_a8r8g8b8_sRGB format in switch
       image: Fix bad HTML generation in code docs for cairo-format-stride-for-width
       Add explanation to enum _cairo_int_status
       Add explanation to _cairo_surface_create_in_error
       Add comment to explain _cairo_edge_compute_intersection_*
       Correct spelling of "tessellator" throughout code
       gitignore: Ignore generated tmpl dir in public docs
       doc: Add missing sections and symbols for public docs
       doc: Drop a couple quartz routines which distcheck claims don't exist
       Mark recently added _cairo_output_stream_print_matrix private symbol
       surface: Make parameter naming consistent between header and impl
       Document that libglib2.0-doc is needed to avoid some xref warnings
       skia: Add section definitions and code docs for skia backend
       perf: Refactor some common macros to cairo-perf.h
       NEWS: Add bug links and reword feature and bug descriptions
       Fix segfault in firefox when scrolling on certain pages
       .gitignore: Ignore two generated files in build/
       configure.ac: Quell warnings about AM_PROG_AR when using automake 1.12
       configure.ac: Add a --disable-lto configure option
       configure.ac: Fix broken build for Qt backend
       cairo-wideint:  Fix typo in two cairo_uint128 functions
       xlib: Fix mispelling in a comment
       Disable font options for xcb.
       NEWS:  Bring up to date with recent bug fixes.
       README:  Update required dependencies
       AUTHORS: Add Ravi, myself, and a couple other frequent contributors
       NEWS: Drop unfinished thought
       cairo-gl: Make VBO size run-time settable
       gl: Track the VBO size as a property of the ctx
       gl: Increase default VBO size on GL to 1M
       NEWS: Note that downscaling changes only affect image + fallback
       Don't return NULL to clients when getting image
       Don't return NULL to clients when getting device
       build:  Fix float endian configure test when using clang -O4
       NEWS: Revise downscaling feature description
       sphinx: Add ickle's explanation of what sphinx does
       quartz: Check for quartz surface type before conversion
       Declare as private the new cairo_lines_compare_at_y symbol
       Get make check back to a happy spot
       test: Fix error message to specify the executable that was missing
       test: Add an update-refs.sh script to update reference images
       test: Update pixman downscaling 95 reference images
       NEWS: Update with latest changes and finalize for release
       NEWS: Flesh out docs for new APIs
       1.14.0 release
       pattern: Restore dropped inclusion of cairoint.h
       Start 1.14.1 development

 Bryce W. Harrington (10):
       test: Don't ignore test output files left in test directory
       test: Fix several tests to place output files in the output directory
       test: Make cairo_test_mkdir() usable throughout tests.
       test: Ensure output dirs exist, falling back to current dir if needed
       svg, test: Refer to output filename by variable, not a hardcoded value
       gitignore: Ignore build chaff when configuring with --enable-gtk-doc
       test: Comma separate keywords
       test: Space out keywords for clarity
       test: Document use of -k and CAIRO_TEST_TARGET to run test subsets
       NEWS: Summarize recent changes

 Chris Wilson (35):
       Post-release version bump
       Bump version for new development tree, 1.13.1
       spans,traps: Undo device transform from source matrix for recording replays
       test: Allow CAIRO_TEST_MODE to independently enable extended testing
       trace: Record set-device-scale
       script: Add support for replaying device-scale
       test/pixman-downscale: Open-code fmin()
       font: Push the last reference dec into the backend->destroy() callback
       trace: Fix operand emission
       win32: Reorder font declarations to be in natural order
       clip: Do not modify the special all-clipped cairo_clip_t
       xlib: Undo debug hack to force fallbacks
       traps,xcb: Prefilter zero-area boxes when converting traps
       traps,xcb: Set the box count after filtering
       arc: Insert the initial point on the arc
       test: Exercise stroking bugs with xlib/trapezoids
       test/coverage: Exercise invariance under mirror symmetry
       stroke,traps: Emit join without loss of precision
       test: Remove redundant reference images
       tor: Fix loss of precision from projection onto sample grid
       test: Include coverage in the normal test run
       tor: Review full-row walker
       test: Remove more duplicated reference images
       test: Explicitly flip the reference image for recordflip
       test: Add another coverage example demonstrating the seams in tor
       test: Fix coverage-abutting
       test: Add a simple rasteriser to check fidelity of edge rendering
       test/simple: Tighten sanity checks in reference image generator
       tor: Perform analytic coverage over the pixel not sample points
       tor: Enable analytic processing for starting rows
       test: Refresh reference images for tor rendering changes
       image: Eliminate self-intersections for the pixman traps compositor
       test: Add whole flipped replays
       test: Teach check-preprocessor-syntax.sh about -inlines.h
       test: Fix conflation of different device scales in index.html

 David Weiß (1):
       made paths to pixman, libpng and zlib configurable by commandline for win32 builds

 Eric Le Bihan (1):
       test: fix build of any2ppm if fork not available

 Henry Song (1):
       gl: Fix one off issue in context cleanup

 Jeff Muizelaar (2):
       Don't use __FUNCTION__ as a string literal
       clang-cl: Use size of the pointer explicitly

 Koji Egashira (1):
       image: Add NULL checks for return value of _pixman_image_for_color()

 Kouhei Sutou (1):
       cairo_create(): Add finished surface check

 Krzysztof Kosiński (1):
       image: Use convolution filters for sample reconstruction when downscaling

 Lukáš Lalinský (1):
       xcb: Initialize font options from Xft resources

 Maks Naumov (3):
       Fix width and height args for _cairo_xcb_connection_copy_area()
       Fix font x_scale value in _compute_transform()
       Fix _cairo_mesh_pattern_equal() when cairo_mesh_patch_t structs are different

 Marc-André Lureau (1):
       build-sys: do not try to build util/sphinx on Windows

 Marek Kasik (1):
       font: Generate PDFs with correct font names

 Martin Robinson (1):
       gl: Extend oversize check to cairo_gl_surface_create_for_texture

 Ravi Nanjundappa (22):
       perf: Refactor some macros to cairo-perf.h
       test and util: maintain consistency in the usage of ARRAY_LENGTH macro
       boilerplate: Maintain consistency in the usage of switch cases
       glx: Use GLX_NONE in place of None
       test : Maintain consistency in the usage of xcalloc
       vg: Use EGL_NONE and GLX_NONE in place of None
       src : Fix warn_unused_result warnings from gcc
       xcb: make use of _cairo_surface_is_xcb to check for surface type
       skia: update the source to build with the latest skia
       .gitignore: Ignore the generated profile data files from callgrind tool in test/
       skia : Add Debug support for skia backend
       test : build fix when --enable-pdf=no
       test: Selective execution of Cairo tests based on FORMAT option
       test: improve selective execution of Cairo tests based on FORMAT option
       README : Update README file related to usage of FORMAT make variable
       configure.ac: configuration check to enable either gl or glesv2, not both at the same time
       src: Fix memory issue reported by cppcheck static analysis tool
       test: Fix null pointer issue reported by cppcheck static analysis tool
       qt: Suppress warnings in qt backend build
       test: Add test oversized egl surfaces
       src: check the surface backend for NULL
       test: Add test for egl-surface-source

 Rodrigo Rivas Costa (1):
       win32 print: fix cache_frozen assertions

 Ryan Lortie (1):
       cairo-version: fix docs build

 Sylvestre Ledru (3):
       Remove some useless declarations found by scan-build, the LLVM/clang static analyzer
       Remove some potential double free
       Fix some memory leaks found by scan-build, the LLVM/Clang static analyzer

 Søren Sandmann Pedersen (1):
       _cairo_color_double_to_short(): Use standard rounding algorithm

 Uli Schlachter (23):
       recording: Fix unitialized variable 'free_me'
       recording: Correctly determine alpha of all surfaces
       cairo-gobject: Require at least glib 2.14
       check-doc-syntax: Don't hardcode path to awk
       image: Handle PIXMAN_a8r8g8b8_sRGB in switch
       test/multi-page: Fix use-after-free
       xcb: Remove useless error handling
       fill_reduces_to_source(): Handle failure of color_to_pixel()
       Remove XFAIL_TESTS from Makefile.am
       README: Don't mention XFAIL_TESTS anymore
       Revert "[xlib] Fast-path the likely case of retrieving a known xrender_format"
       cairo-xlib: Fix out of bounds array access in format cache
       Correct usage of CAIRO_STACK_ARRAY_LENGTH
       cairo svg: Use \n instead of /n in bitmap fonts
       clip: Fix handling of special all-clipped cairo_clip_t
       Fix warnings from check-doc-syntax.sh
       mask compositor: Set a check_composite method
       mesh-rasterize: Fix number of iterations
       pthread-same-source: Add ref image generation
       pthread-same-source: Refresh reference images
       Revert "image: Use convolution filters for sample reconstruction when downscaling"
       Remove LTO support
       xcb: Correctly check for image surface for inplace upload

 egag (1):
       Fixes stroke-clipped, i.c. of a dashed stroke

 jimmyfrasche (2):
       Pattern document clarification
       Add more info to cairo_surface_set_mime_data docs.



 --
 Bryce Harrington
 Senior Open Source Developer  -  bryce@osg.samsung.com
 Open Source Group             -  Samsung Research America


```
