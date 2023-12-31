---
title: cairo 1.12.16 snapshot available
layout: news
date: 2013-08-26
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
To: cairo-announce@cairographics.org
Date: Mon, 26 Feb 2013 18:57:00 +0100

A new cairo release 1.12.16 is now available from:

http://cairographics.org/releases/cairo-1.12.16.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.16.tar.xz.sha1
4f6e337d5d3edd7ea79d1426f575331552b003ec  cairo-1.12.16.tar.xz

http://cairographics.org/releases/cairo-1.12.16.tar.xz.sha1.asc
(signed by )

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.16 tag which points to a commit named:
8e11a42e3e9b679dce97ac45cd8b47322536a253

    which can be verified with:
git verify-tag 1.12.16

    and can be checked out with a command such as:
git checkout -b build 1.12.16


Release 1.12.16 (2013-08-21 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
Thanks to everybody who reported a bug and helped us develop a fix,
we have amassed quite a few bug fixes. There are still more outstanding
bugs that seek attention and a little bit of TLC, but this release has
been delayed long enough...

Bug fixes
---------

  Set the correct orientation for simple boxes with a negative scale
  factor.

  Fix the creation of the shading dictionary in PDF.

  Fix a crash in PDF when incorporating an image with CAIRO_EXTEND_PAD.
  https://bugs.freedesktop.org/show_bug.cgi?id=61451

  Avoid upscaling bitmap fonts if possible.

  Fix an assertion failure within the mempool allocator for shared memory.

  Fix allocation size for CFF subsets.

  Export cairo_matrix_t for GObject bindings.

  Fix a double free in the Quartz backend.
  https://bugs.freedesktop.org/show_bug.cgi?id=62885

  Fix origin of GDI StretchBlits for the Windows backend
  https://bugs.freedesktop.org/show_bug.cgi?id=61876

  Fix error propagation for requests to create a similar surface with
  negative size.
  https://bugs.freedesktop.org/show_bug.cgi?id=63196

  Fix complex clipping of trapezoids with regions
  https://bugzilla.gnome.org/show_bug.cgi?id=697357

  Stop leaking the image data when loading PNGs

  Fix unbounded operations with a clip mask through the span compositor
  https://bugs.freedesktop.org/show_bug.cgi?id=61592

  Add missing checks before rendering to a finished surface - so we return
  an error rather than hit an assert.
  https://bugs.freedesktop.org/show_bug.cgi?id=68014

  Prevent an assertion failure when creating similar GL surfaces larger
  than supported by hardware.

  Prevent a double free of a similar image under Windows.
  https://bugs.freedesktop.org/show_bug.cgi?id=63787


Complete list of changes from 1.12.14 to 1.12.16
------------------------------------------------

Adrian Johnson (3):
      pdf: add missing 'endobj' to shading dict
      pdf: fix typo in bbox check
      type1-subset: Don't try to rename non winansi glyphs

Behdad Esfahbod (12):
      [FT] Prefer downscaling bitmap glyphs to upscaling
      [test] Set font size
      [ft] I meant fabs(), not abs()
      [ft] Fix memory bug in copying bitmaps
      [ft] Fix wrong assumptions
      Towards support loading color glyphs from FreeType
      Support 2bit and 4bit embedded bitmaps
      [ft] Fix math
      [ft] Add missing include
      Revert accidentally committed stuff
      [ft] Fix alignment
      [ft] Ensure alignment of bitmaps received from FreeType

Bryce W. Harrington (16):
      test: Fix typo in sample_horizontal to use horizontal, not vertical.
      image: Quell warning about signed/unsigned int comparison.
      type1-subset: Quell warning about uninitialized array_start
      type1-subset: Fix typos in function comment
      pdf: Assure compiler that data, data_size will always be initialized
      gl: Quell warning about incompatible pointer type
      test: Note naming scheme for XFAIL images in README
      test: Fix make check-ref-dups due to move of ref images to reference/
      test: Add script to check for redundant reference images
      test: Use cmp to catch byte-by-byte identical files
      test: Make check-ref-dups utilize perceptualdiff for comparisons
      pdiff: Quell warning about signed/unsigned comparisons
      pdiff: Drop unused variable
      test: Add special cases for create-from-png and fallback-resolution
      HACKING: Make mention of the separate cairo-traces repo
      perf: Move macro-benchmark documentation to cairo-traces

Chris Wilson (45):
      Post release version bump to 1.12.15
      spans: Mark the surface as cleared in preparing for recording surface playback
      recording: Avoid indirection through indices array if not reduced
      path: Fix bbox computation for negative scale factors
      test: Exercise replaying a recording surface through a flip matrix
      win32: Free the fallback upon finish
      image: Compare against the true size of the embedded buffer
      xlib: Fix invocation of XRenderFindFormat()
      gl: Fix typo s/bool/cairo_bool_t/
      mempool: Reduce an assert into an error return for get_buddy()
      perf: Iteratively prune outliers
      xlib: Wrap errors generating sources in an error surface
      xlib: Trim uploads for surfaces extended by PAD
      png: Avoid marking the surface as in error after a png warning
      directfb: Correctly chain up map-to-image/unmap to the image backend
      traps: Ensure that we correctly clip when using multiple clip boxes
      xlib: Unlike the visual when destroying it
      test: Expand testing of caps for fine strokes
      test: Extend testing of joins for fine lines
      trace: Improve operand emission
      recording: Fix inconsistent usage of types for indices
      perf: Rudimentary histogram printing for cairo-perf-print
      perf: Rescale the histogram for the terminal
      perf: Avoid vertically stretching the histogram
      perf: Remove a debug artifact
      recording: Prevent invalid memory access with zero length command array
      scaled-font: Prevent a recursive mutex lock for removing a failed glyph
      pdf: Improve consistency in use of cairo_int_status_t
      pdf: Fix compiler warning for use of unitialised variable along error path
      image: Mark the data as owned after stealing the snapshot's image
      test/get-path-extents: Check exact matches within tolerance
      gstate: Speed up stroked path extents
      svg: Unwrap recording surfaces
      xml: Handle clip-boxes in the updated cairo_clip_t
      cairo-perf-print: Do not free the uninitialised histogram
      test: Use the highest precision rendering for shapes for generating ref results
      check: Fix check-def.sh for variations in GCC's linker
      test: Remove all identical (cmp & pdiff) reference images
      test: Add a few reference images found lurking on my machine
      test: Remove conflicting .ref.png, .argb32.ref.png, .rgb24.ref.png
      test: Amend check-refs.sh to support out-of-tree builds
      Provide backwards compatibilty with old pixman
      win32: Prevent double-free of similar images
      Make "make check" happy
      1.12.16 release

Eric Anholt (1):
      gl: Move glGetUniformLocation to shader compile time.

Henry Song (8):
      gl: disable GL_DITHER
      gl: Export query for EGLContext and EGLDisplay from device
      gl: Fix typo in gles2 shader cache lookup
      gl/msaa: Resolve multisampling on surface flush
      gl/msaa: Properly destroy stencil buffer clip cache
      gl/msaa: Disable stencil and scissor during framebuffer blit
      gl/msaa: Always use scissor when clipping
      gl/msaa: Clean up msaa depth/stencil buffer for OpenGLES

Jana Saout (1):
      pdf: Fix crash

Marc-André Lureau (1):
      win32: fix corrupted drawing

Marek Kasik (1):
      cff-subset: Fix allocation of width arrays

Martin Robinson (12):
      gl: Setup operands when the vertex size changes
      path: Fix a bug in line intersection
      stroke: Fix large line widths for fallback stroke shaper
      stroke: Use round-joins near inflection points of splines
      boilerplate: Add a mode for running threaded perf tests
      boilerplate/gl: Disable thread awareness
      gl: Separate framebuffer bind from destination selection
      gl: Update transformation when surface size changes
      gl: Bind the default framebuffer before calling gl{Read|Draw}Buffer
      gl: Fix compiler warnings in the GL backend
      gles: Switch default framebuffer destinations properly
      gl: Return surface in error when creating oversized texture surfaces

Matt Sealey (1):
      gitignore: negate gitignore for static pkgconfig files

Matthew Fischer (1):
      Adding a simple usage statement to cairo-perf-chart

Michael Hutchinson (1):
      quartz: Don't release memory we don't own

Nicola Fontana (1):
      gobject: Add wrapper around cairo_matrix_t

Uli Schlachter (13):
      test: Fix CAIRO_REF_DIR
      test: Fix handling of dots in CAIRO_TEST_TARGET
      boilerplate: rename xcb-render-0.0 to xcb-render-0_0
      Fix "make check" standalone header check
      xcb: Clear temporary replay image in recording playback
      Fix caps-tails-curve reference images
      Add new test for bug 61592
      image compositor: Always finish the span renderer
      xcb: Fix some uninitialized variable warnings
      api-special-cases: Also test contexts
      surface: Error out on finished surfaces
      push_group: Refuse working with unusable surface
      surface_get_extents: Reject finished or error surface

egag (1):
      xlib: Aquire display before using it in DEBUG message.

--
Chris Wilson, Intel Open Source Technology Centre
```
