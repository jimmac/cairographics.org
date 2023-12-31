---
title: cairo 1.12.4 release available
layout: news
date: 2012-10-05
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Fri, 05 Oct 2012 17:31:00 +1000
To: cairo-announce@cairographics.org

A new cairo release 1.12.4 is now available from:

http://cairographics.org/releases/cairo-1.12.4.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.4.tar.xz.sha1
f4158981ed01e73c94fb8072074b17feee61a68b  cairo-1.12.4.tar.xz

http://cairographics.org/releases/cairo-1.12.4.tar.xz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.4 tag which points to a commit named:
117abd85ac7ff41e484fe0d98f16704ec30abd09

    which can be verified with:
git verify-tag 1.12.4

    and can be checked out with a command such as:
git checkout -b build 1.12.4


Release 1.12.4 (2012-10-05 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
More bugs, and more importantly, more fixes. On the cairo-gl side, we
have refinements to the MSAA compositor which enables hardware
acceleration of comparatively low-quality antialiasing - which is useful
in animations and on very high density screens. For cairo-xlib, we have
finally enabled SHM transport for image transfers to and from the X
server. A long standing required feature, SHM transport offers a notable
reduction in rendering latency by reducing the number of copies
required to upload image data - given hardware and driver support,
cairo-xlib can now perform zero copy uploads onto the GPU. And as usual
Adrian Johnson has been very busy fixing many different corner cases in
cairo-pdf, impoving opacity groups and font subsetting. Last, but not
least, for cairo-image S=F8ren Sandmann Pedersen added support for
rendering glyphs to pixman and using that from within cairo. The new
glyph rendering facility reduces the overhead for setting up the
compositing operation, improving glyph thoughput for the image backend
by a factor of about 4. And before he did so, he also fixed up a few
bugs in the existing glyph rendering code. So many thanks to Andrea
Canciani, Adrian Johnson, Chuanbo Weng, Dongyeon Kim, Henry Song, Martin
Robinson, S=F8ren Sandmann Pedersen and Uli Schlachter for their
contributions, finding and fixing bugs.
-Chris

Bug fixes
---------

 Interior boxes were being dropped when amalgamating regions during
 tesselation.
 https://bugs.freedesktop.org/show_bug.cgi?id=49446

 Allow building without gtk-doc installed

 Invalid edge generation whilst reducing complex polygons.
 https://bugs.freedesktop.org/show_bug.cgi?id=50852

 Stroking around tight cusps

 Use locale correct formats for reading font subsetting and valid
 buffers.
 https://bugs.freedesktop.org/show_bug.cgi?id=51443

 Ensure that the type1 subset includes all the glyph encodings
 https://bugs.freedesktop.org/show_bug.cgi?id=53040

 Upload the whole source for a repeating pattern.
 https://bugs.freedesktop.org/show_bug.cgi?id=51910

 Fix damage tracking to handle continuation chunks corectly and so
 prevent crashes on win32.
 https://bugs.freedesktop.org/show_bug.cgi?id=53384

 Avoid emitting miter joins for degenerate line segments
 https://bugzilla.mozilla.org/show_bug.cgi?id=407107

 Convert the relative path semgents into the backend coordinates
 and then back again to user coordinates (cairo_copy_path,
 cairo_append_path)
 https://bugs.freedesktop.org/show_bug.cgi?id=54732

 Fix extents computations for a degenerate path consisting only of a
 move-to
 https://bugs.freedesktop.org/show_bug.cgi?id=54549

 Prevent crashing on a degenerate project edge after polygon
 intersection
 https://bugs.freedesktop.org/show_bug.cgi?id=54822

List of all changes since 1.12.2
--------------------------------

Adrian Johnson (12):
      pdf: check if EXTEND_PAD group can be painted with EXTEND_NONE
      pdf: fix smask gradient bbox
      ps: check if EXTEND_PAD group can be painted with EXTEND_NONE
      pdf: merge _emit_recording_surface and _emit_recording_subsurface into the one function
      pdf: Don't use extents when acquiring a RASTER_SOURCE pattern
      pdf: fix the offset of padded images
      cff-subsetting: Ignore charset for non cid fonts
      cff: convert '.' to locale specific decimal point before using sscanf
      cff: use correct size for buffer
      cff: initialise variable to prevent valgrind warning
      cff subsetting: widths can be floating point
      type1 subset: ensure encoding includes all glyphs

Alexandros Frantzis (2):
      gl: Simplify GL wrap parameter setting code
      gl: Provide a shader implementation of repeat wrap modes

Andrea Canciani (15):
      build: Allow autogen-eration on systems without GTK-doc
      build: Do not replace existing files
      png: Implement conversion of CAIRO_FORMAT_RGB30 to string
      surface: Define private map/unmap functions
      surface: Make map_to_image return cairo_image_surface_t*
      surface: Make backend-specific map/unmap functions symmetric
      surface: Only use non-NULL extents for internal mapping
      surface: Use the internal map/unmap
      quartz: Silence warning
      quartz: Mark surfaces created clear as is_clear
      quartz: Provide a valid implementation of map_to_image
      quart-image: Fix compilation
      xcb: Fix make check
      quartz: Use the correct transform when replaying recording surfaces
      test: Add degenerate closed path case to get-path-extents

Behdad Esfahbod (2):
      [util/malloc-stats] Use tighter spacing.
      Fix malloc-stats for newer glibc

Chris Wilson (129):
      version: Post release bump to 1.12.3
      snapshot: Hold a reference to target whilst querying
      snapshot: Avoid triggering assertion for grabbing the target during destroy
      Split finish into multiple stages
      damage: Avoid freeing the NIL error object
      damage: Prevent accumulating damage to an error object
      damage: Prevent reducing an error object
      gl: Reject SOURCE + mask in composite_boxes()
      test: Fix tighten-bounds reference images
      spans-compositor: Handle unaligned unbounded boxes
      spans-compositor: Add tracepoints for debugging
      traps,spans-compositor: Avoid mistreating unaligned clips as aligned
      spans: Only fallback for a clipmask if unbounded
      clip: Apply clip boxes to the clip surface
      arc: Use user endpoint for final step
      spans: Debug input paths and polygons
      stroke: Don't drop clockwise==0 lines
      image: Tidy lerp8x4
      win32: Fix return value for cairo_time_get
      wideint: Fix compilation failure for bare use of uint64_t for !HAVE_UINT64_T
      test: Fix leak from xcb-snapshort-assert
      gl: Replace vbo with static allocation and immediate arrays
      test: Exercise rectangular bo bug
      bo-rectangular: Emit subsummed boxes for overlapping edges
      test: Refresh unbounded-operator
      test/record90: Rotate the reference so that it is wholly visible
      test: Increase surface size for get-path-extents
      gl: Use core GL_STENCIL8_DEPTH24 for gl_flavor=desktop
      image: Propagate errors from clone_subimage
      surface: Kill imagesurf temporary variable
      gl: Do no access ctx after release during map-to-image
      test: Restore bug-seams reference
      image: Upconvert glyphs through a WHITE source when adding to the glyph mask
      image: silence make check
      surface: Eliminate PLT entries for map-to-image
      gl: Add missing cairo-private to _cairo_gl_composite_with_clip
      surface: replace map-to-image clone's use of user_data with parent pointer
      Erradicate internal use of cairo_surface_get_content()
      Erradicate internal use of cairo_surface_get_type()
      composite-rectangles,scaled-font: Use accurate extents if the font is broken
      scaled-font: Take lock around disposing of an empty page upon alloc failure
      spans-compositor: After polygon intersection the fill rule is always non-zero
      tor-scan-converter: Always recompute min-height following edge removal
      polygon-reduce: Reduce broken stopped-edge continuation
      image: Fix up glyphs compositing
      gl: Trim the glyph mask to the operation extents
      test: Exercise bug in joining together spline segments around cusps
      stroke: Use round-joins near inflection points of splines
      stroke: Skip inserting a round-join if within tolerance
      ft: Indentation fixup for _get_bitmap_surface()
      boilerplate/gl: Round fractional window sizes up
      test: Add a simple exercise for raster sampling of subpixel geometry
      test: Add example from bug-51910
      xlib: If a sample accesses outside of a repeating image, upload it all
      gl: Add the compile fix that I forgot to add to the previous commit
      perf/chart: Render a solid bar if the column is too narrow for the gradient
      gl: Fallback for copy_boxes if src/dst do not belong to the same device
      trace: Fix propagation of CAIRO_TRACE_OUTDIR to children
      egl: s/EGL_KHR_surfaceless_opengl/EGL_KHR_surfaceless_context/
      gl: Remove unused variable
      xlib: Silence compiler warning
      gl: Use a wide texture ramp to emulate a linear step function
      gl: Fudge gradient color generation to handle multiple stops at 0
      damage: Update tail pointer after allocating new chunk
      skia: Compile fix for changes to map-to-image
      image: Temporarily resurrect the old non-pixman glyph compositor
      xlib: Implement SHM fallbacks and fast upload paths
      tor22: Add a simple method to quickly compute coverage (with saturation)
      configure: Restore previous pixman required version of 0.22.0
      xlib/shm: Fix up the shrinking of the priority queue
      xcb: Migrate to the common mempool implementation
      xlib/shm: Propagate the last-request to the synchronous create
      xlib/shm: Limit use of the impromptu fallback pixmap for uploads
      xlib/shm: Use an impromptu upload ShmSegment
      xlib/shm: Clear the similar image surface
      xlib: Only use CopyArea if the ShmPixmap and destination are the same depth
      xlib/shm: Avoid using a synchronous ShmCreatePixmap if evading the readback
      xlib/shm: Wrap the detection of shm with locking
      xlib/shm: Fix runtime checking of has-shm-pixmaps for !shm case
      xlib/shm: Mark the ShmPixmap as active following an upload flush
      xlib: Drop the false optimisation of using a potentially busy shm upload pixmap
      ft: Only use a specified font filename if its accessible
      xlib: Move the shm cleanup from CloseDisplay to finish()
      tests: Add outline-tolerance
      stroker: Avoid emitting a miter join for across an elided degenerate segment
      ft: Report FILE_NOT_FOUND if creating a font with a specified nonexistent file
      cairo-script: Attempt to fallback for unresolved patterns
      xlib/shm: Use a genuine event rather than an open-ended request
      xlib/shm: Only check if we are expecting an event
      xlib/shm: Reduce the frequency at which we emit events
      xlib/shm: Add missing release of the display after GetImage
      compositor: Skip invisible strokes
      stroke: Skip spline evaluation when stroking to a polygon
      pen: Use bisection to speed up vertex finding
      stroke: Use new pen vertex range finders
      stroke: Precompute the line half-width
      stroke: Convert a very small round-join into a miter
      stroke: Convert fallback stroker to new pen vertex finder
      stroke: Compute bounds for fallback stroker (typically dashing)
      bentley-ottman: Remove a few superfluous status propagation
      bentley-ottmann: Only check the pairs of coordinates for equality.
      bentley-ottmann:  hint that the insertion compare function should be inlined
      bentley-ottmann: Cache the most recent edge colinearity check
      xlib/shm: Masquerade as an ordinary ShmCompletionEvent
      default-context: Convert the relative path segments into the backend coordinates
      path: Update last_move_point after move-to
      image: Check for an error surface before dereferencing the backend
      xlib/shm: Explicitly release shm surface if we do not own the pixmap
      context: Add missing functions to transform between user and backend coordinates
      path: Convert from backend coordinates back into user coordinates
      xcb: Always flush the fallback damage to foreign drawables
      xlib: Fix regression in cairo_xlib_surface_set_drawable()
      xlib: Explicitly discard the fallback shm pixmap upon user modification
      xlib: Force the fallback flush before updating the external Drawable
      xlib: Do not call _cairo_xlib_surface_flush directly
      xlib: Destroy the fallback damage along with the fallback surface
      test: Add clip-disjoint-quad
      polygon-intersect: Exclude non-overlapping clip boxes from consideration
      spans-compositor: Use the tight clip-boxes for polygon construction
      composite-rectangles: Update unbounded (clip extents) after reducing clip
      test: Refresh reference image for clip-disjoint-quad
      spans-compositor: Remove polygon limits after construction
      tor: Fudge the edge if it is projected into a point
      recording: Perform an explicit during snapshot
      stroke: Remove redundant code for computing culling extents
      test: Refresh reference images for slight alteration of curves
      xlib/shm: Discard SHM surfaces upon CloseDisplay
      win32: Compile fix for mismatched surface types
      1.12.4 release

Chuanbo Weng (7):
      gl: fix the translate value in copy_boxes.
      gl: Convert CLEAR to DEST_OUT when there's a mask for composite_boxes.
      gl: Do correct translation and lerp in gl-traps-compositor.
      gl: Set correct clip rectangle for non-texture destination surfaces
      gl: Set correct operation extents.
      gl: Create a new texture surface if the source surface type is gl-window
      gl: copy_boxes() does not support copying from a non-texture source

Daniel Stone (1):
      Fix broken XRender ARGB32 formats

Dongyeon Kim (1):
      gl: Set is_clear flag to FALSE after map_to_image

Henry (Yu) Song (8):
      gl/msaa: Prevent stroke overlap
      gl/msaa: Support for texture sources
      gl/msaa: Support for masking
      gl/msaa: Add support for unbounded operators
      gl/msaa: Add ARB multisampling support
      gl/msaa: Implement paint via masking
      gl/msaa: Use unsigned short to build the index array
      gl/msaa: Support the OpenGLES EXT multisampling extension

Henry (Yu) Song - SISA (2):
      clip: Transform clip path in _cairo_clip_intersect_clip_path_transformed()
      quartz: Never acquire recording surfaces

Henry Song (5):
      subsurface: Disable subsurface-set-snapshot as it creates a ref cycle
      gl: generate correct gradient color texture
      gl: Destroy glyph cache surface during finish
      gl: translate proper matrix depending up type of gl_operand
      gl: use absolute value for color difference between gradient stops

Martin Robinson (9):
      gl/msaa: Support for non-texture surfaces
      gl/msaa: Wait to clip until compositing begins
      gl/msaa: Implement glyph rendering
      gl/msaa: Lazily flush the context
      gl/msaa: Improve fallback detection
      gl: Simplify switching between primitive types
      gl: Fix compilation failure for flush cleanup.
      gl: Remove the shader language version abstraction
      gl: Add a non-thread-aware mode for GL devices

S=F8ren Sandmann Pedersen (4):
      Use pixman glyphs
      Revert "Use pixman glyphs"
      image: Fix bugs related to glyph mask creation
      Use the new pixman_glyph_cache_t API that will be in pixman 0.28.0

Uli Schlachter (18):
      Remove some unused functions
      Remove some dead code
      check-doc-syntax: Make this work again
      check-doc-syntax: Find duplicate "Since:" tags
      c_surface_set_mime_data: Remove duplicate "Since"
      xcb: Handle recording surfaces differently
      xcb: Correctly handle a recording surface's extents
      Fix make check
      Remove an unimplemented function declaration
      xcb: Fix a warn_unused_result warning
      xcb: Remove unimplemented cairo compositor
      xcb: Switch to compositor architecture
      xcb: Verify extension support before sending
      xcb: Check the right flag for FillRectangles
      xcb: Check if traps are supported before using them
      xcb: Add a missing check for FillRectangles
      surface: Check reference count right before free
      mark_dirty: Check surface status

Weng Xuetian (1):
      xlib: Reset fallback counter when discarding the fallback

Yuanhan Liu (2):
      gl: use _cairo_gl_operand_copy to fix unblanced reference count
      configure.ac: remove annoying change of INSTALL file
```
