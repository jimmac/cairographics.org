---
title: cairo 1.12.10 release available
layout: news
date: 2013-01-16
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Wed, 16 Jan 2013 21:03:00 +0000
To: cairo-announce@cairographics.org


Release 1.12.10 (2013-01-16 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
A heap of bug fixes everywhere, and the gradual completion of the MSAA
backend for cairo-gl. Perhaps the most noteworthy set of the bugfixes
was the crusage lead by Behdad Eshfabod to make font handling by
pango/cairo/fontconfig fully threadsafe. This testing revealed a couple
of races that needed fixing in Cairo's scaled-font and glyph cache.

Bug fixes
---------

  Append coincident elements to the recording's surface bbtree so that
  the list is not corrupted and the overlapping elements lost.

  Fix cairo-trace to correctly record map-to-image/unmap-image and then
  replay them.

  Ignore MappingNotifies when running the XCB testsuite as they are sent
  to all clients when the keyboard changes. The testsuite would detect
  the unexpected event and complain.

  Handle very large large images in the XCB backend.

  Fix a memory leak in the xlib/shm layer, and prevent use of the SHM
  surfaces after the display is closed.
  https://bugs.freedesktop.org/show_bug.cgi

  Handle resizing of bitmap fonts, in preparation for a fix to
  fontconfig to correctly pass on the user request for scaling.

  Always include subroutine 4 (hint replacement idion) when subsetting
  type 1 fonts in order to prevent a crash in cgpdftops on Mac OS/X

  Fix a couple of typos in the cairo-gobject.h header files for
  introspection.

  Prevent a mutex deadlock when freeing a scaled-glyph containing a
  recording-surface that itself references another scaled-glyph.
  https://bugs.freedesktop.org/show_bug.cgi?id=54950

  Make scaled-font cache actually thread-safe and prevent
  use-after-frees.

  Restore support for older versions of XRender. A couple of typos and a
  few forgotten chunks prevented the xlib compositor from running
  correctly with XRender < 0.10. Note that there are still a few
  regressions remaining.

Complete list of changes from 1.12.8 to 1.12.10
-----------------------------------------------

Adam Jackson (1):
      xlib/shm: Fix memory leak

Adrian Johnson (1):
      doc: Add CAIRO_MIME_TYPE_UNIQUE_ID to list of supported mime types

Alejandro G. Castro (1):
      gl/msaa: Avoid the stencil buffer when possible during masking

Behdad Esfahbod (3):
      [Minor] Improve logging
      [ft] Remove ancient check for FT_Bitmap_Size.y_ppem
      [ft] Fix resizing of bitmap fonts

Chris Wilson (50):
      version: Post-release bump to 1.12.9
      trace: Fix operand emission for map-to-image and unmap-image
      trace: Do not forcibly add surfaces to the dictionary
      script: Fix map-to-image/unmap stack manipulations
      mempool: Reduce the assertion into an alignment adjustment for the base
      xlib/shm: Populate send_event and serial
      xlib/shm: Rate-limit events and only use as necessary
      xlib/shm: Do not trigger a surplus event from XShmPutImage
      Revert "xlib/shm: Do not trigger a surplus event from XShmPutImage"
      perf/chart: Show the geometric average as an extra column
      perf/chart: Contract the default output filenames
      gl: Use vfunc for vertex emission
      gl: Provide a fast emitter for solid glyphs
      gl: Provide a fast emitter for solid spans
      xlib/shm: Fix typo in creation of a SHM image
      xlib: Use SHM transport for ordinary image uploads
      stroke: Make the incremental trapezoid stroker optionally available again
      xlib: Avoid copying the source twice if it is an image
      scaled-font: Mention ownership of returned object from get_font_face()
      Add missing local slim proto for cairo_recording_surface_create
      gobject: Fix my typo s/TEST/TEXT/ in the previous commit
      script: Recompress strings using LZO whilst binding traces
      xlib/shm: Only mark the shm pixmap as active if we upload into it
      xlib: Simplify source creation by use of map-to-image
      image: Call pixman without a mask for opaque regions of inplace_spans
      script: Attempt to decompress images in place
      script: Simply exchange source/dest images for _set_source_image
      script: Thaw the scaled font cache on the error path
      scaled-font: Always hold the mutex even for single glyph probes
      scaled-font: Free the cached glyphs from the font before taking the global lock
      scaled-font: Assert if attempting to finish a frozen font
      scaled-font: Hold the scaled font mutex whilst reaping from the global cache
      xlib/shm: Discard damage upon shm finish
      xlib/shm: Only destroy an existing damage
      scaled-font: Remove a non-threadsafe double-freeze assert
      image: Allocate a temporary buffer for inline span composition
      scaled-font: Make reset-font-cache threadsafe
      scaled-font: Fix use after free when clearing the glyph cache
      gstate: Use the polygon intermediate for geometry queries
      stroke: Flip the dev slope as well for computing the cusp on a degeneracy
      xlib: map-to-image requires an extents
      xcb: _cairo_scaled_font_reset_cache does it own locking
      xlib: Only fallback through the mask intermediate if we can composite the mask
      xlib: Handle lack of XRenderFillRectangles
      compositor: Convert image surface into backend source
      compositor: Pass back the internal failure
      xlib: Initialise Pixmap for proxy sources
      script: Set decompression length prior to calling decompressors
      1.12.10 release
      version: Post-release bump to 1.12.11

Chuanbo Weng (2):
      gl/msaa: Use GL_IMG_multisampled_render_to_texture when available
      gl: Support the GL_IMG_texture_npot extension

David Maxwell (1):
      type1-subset: always include subroutine 4 (hint replacement idiom)

Henry Song (6):
      gl: Flush context upon evicting a gradient
      gl/msaa: Also setmsaa_active to true for non-texture surfaces
      gl: Properly disable ctx->spans when necessary
      gl/msaa: Add full support for masking with the SOURCE operator
      gl/msaa: Only clear parts of the stencil buffer we will use
      gl: Support for non-texture sources and masks

Kouhei Sutou (2):
      gobject: Add the correct macro name for the hint-metrics type
      gobject: Fix "text_cluster_flags_get_type" typo

Martin Robinson (11):
      gl/msaa: Share the depth/stencil buffer among all surfaces
      gl: Add BGRA download support for GLES2
      Revert "gl/msaa: Share the depth/stencil buffer among all surfaces"
      gl: Cleanup selection of multisampling mode
      boilerplate/glx: Add a target with multisampling and stencil support
      gl: Better handling of clear surfaces
      gl: Do less work when acquiring and releasing devices
      gl/msaa: No need to set the clip when masking
      gl/msaa: Rely on the stencil buffer to cache the clip
      gl/msaa: Check for more extensions before using MSAA
      gl: Follow up fix for the previous commit

Uli Schlachter (4):
      boilerplate-xcb: Ignore MappingNotify events
      context: Use recording surfaces for unbounded groups
      test: Add xcb-huge-subimage
      xcb: Fix xcb-huge-subimage

Zozó Teki (1):
      recording: Append new elements to the end of the bbtree chain

```
