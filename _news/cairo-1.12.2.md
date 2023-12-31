---
title: cairo 1.12.2 release available
layout: news
date: 2012-04-29
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Sun, 29 Arp 2012 21:04:00 +1000
To: cairo-announce@cairographics.org

A new cairo release 1.12.2 is now available from:

http://cairographics.org/releases/cairo-1.12.2.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.2.tar.xz.sha1
bc2ee50690575f16dab33af42a2e6cdc6451e3f9  cairo-1.12.2.tar.xz

http://cairographics.org/releases/cairo-1.12.2.tar.xz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.2 tag which points to a commit named:
dbc0efad7e565558a3abf7f69d7675efddc4688d

    which can be verified with:
git verify-tag 1.12.2

    and can be checked out with a command such as:
git checkout -b build 1.12.2


Release 1.12.2 (2012-04-29 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
After such a long gestation period for the release of Cairo 1.12, we
inevitably accumulated a few bugs that were flushed out by broadening the
test base. Thanks to everybody who tried the release, apologies to any one
unfortunate enough to encounter a bug and many thanks for reporting it. As
a result Adrian Johnson, Alexandros Frantzis, Andrea Canciani, Kalev
Lember, Maarten Bosman, Marcus Meissner, Nis Martensen and Uli Schlachter
have squashed many more bugs and improved the documentation. I would
strongly recommend everyone to upgrade to cairo-1.12.2.
-Chris

Bug fixes
---------

 Allow applications to create 0x0 xlib surfaces, such as used by LibreOffice.
 https://bugs.freedesktop.org/show_bug.cgi?id=49118

 Trim composite extents for SOURCE/CLEAR operators to the mask.

 Use fallback fonts in PDF for unhandled computed glyph widths
 https://bugs.freedesktop.org/show_bug.cgi?id=48349

 Handle snapshots of recording surfaces for analysing pattern extents.
 Fixes a regression of reporting the PDF bounding box as being the page size.

 Fix allocation size for PDF pattern ids.
 Bugzilla: https://bugs.freedesktop.org/show_bug.cgi?id=49089

 Fix emission of rectilinear dashed segments, with and without scaling, and
 application of degenerate line joins.

 Clamp unbounded fixup polygons to the clip extents.

 Prevent infinite loop due to rounding errors whilst incrementing along dashes.

 Prevent overflow for inline a8 span filling.

 Miscellaneous build fixes for Cygwin on Windows and Solaris.

List of all changes since 1.12.0
--------------------------------

Adrian Johnson (10):
      fix bug in _cairo_image_analyze_color
      type1-subset: use fallback font if glyph widths are calculated
      fix indentation in cairo_type1_font_subset_parse_charstring
      type1-subset: if font name is prefixed with a subset tag, strip it off
      fix _cairo_pattern_get_ink_extents to work with snapshot recording surfaces
      test: disable subsurface tests with vector backends
      pdf: avoid unnecessary use of patterns in mask groups
      any2ppm: fix missing enumeration warning
      pdf: support all image types
      ps: support all image types

Alexandros Frantzis (1):
      gl: Fix creation of gradient ramps for GLESv2

Andrea Canciani (12):
      doc: Add script to enforce stricter validation of documentation comments
      doc: Make informational comments syntactically different from docs
      doc: Make documentation comments symmetric
      doc: Manually fix remaining warnings about symmetry
      doc: Make doc ids more consistent my always putting ':' after them
      doc: Make the documentation name match the function name
      doc: Do not use the '@' prefix on some tags
      doc: Add "since" tag to documentation
      doc: Fix some wrong versions
      doc: Add since documentation for enumeration values
      doc: Silence warnings about 'Since' field in private functions
      doc: Silence last 'missing Since field' errors

Behdad Esfahbod (5):
      Typo
      Fix math in comments
      Fix typos
      More typo fixes
      Fix another typo

Chris Wilson (54):
      version: Post release bump to 1.12.1
      test: Add test case for tracking source operator extents
      composite-rectangles: Trim extents for SOURCE and CLEAR to the mask
      test: update two reference images highlighted to be wrong due to source extents
      cairoint: Mark PDF surface as requiring the deflate stream output
      stroke: Fix misuse of half_line_x for vertical caps on dashes
      traps: Clip the trapezoid extents against the clip extents
      build: Disable -Wset-but-unused-variable
      analysis: Apply the integer translation to the bbox as well
      ps (API): Export the ability to set the creation date of the surface
      ps (debug API): Export the ability to force fallbacks
      pdf (debug API): Export the ability to force fallbacks
      Revert accidental push of ps debugging API.
      test: Add rectilinear-dash-scale
      stroke(boxes): Apply user scale factors to dash segments
      image: Split inline SRC composition
      boxes: Remove unused inline function
      Split cairo-box-privates into struct+inlines
      Split cairo-clip-privates into struct+inlines
      Split cairo-combsort-privates into struct+inlines
      Split cairo-contour-privates into struct+inlines
      Split cairo-surface-private into struct+inlines
      Split cairo-surface-observer-private into struct+inlines
      Split cairo-surface-snapshot-private into struct+inlines
      Split cairo-recording-surface-private into struct+inlines
      Split cairo-recording-surface-private into struct+inlines
      Split cairo-pattern-private into struct+inlines
      Split cairo-error-private into struct+inlines
      Split cairo-surface-subsurface-private into struct+inlines
      Split cairo-list into struct+inlines
      dash: Use a epsilon compare for stepping the dash
      dash: Increment dash_remain by the next segment to reduce accumulation errors
      gl: Uses the inline clip function, so update its include
      stroke(boxes): Convert the dash step back into device units before incrementing
      xlib: Allow applications to create 0x0 surfaces
      xlib: Fix inline conversion for TrueColor PutImage
      image: Fix typo in _blit_spans()
      image: Allow a snapshot to steal the original memory upon finish
      snapshot: Perform the cow under a mutex
      Update the remaining backends to handle a NULL extents for _cairo_surface_get_source
      image: Avoid overflow when computing lerp spans for a8
      Satisfy check-doc-syntax.awk for unimplemented functions
      test: Exercise clip inversion imperfections
      test: Exercise degenerate dashes that are wholly solid
      image: Add a little bit of debugging to show number of boxes being drawn
      gstate: Reduce degenerate dash to solid
      test: Fix array lengths for degenerate-solid-dash
      gstate: Correctly compact degenerate dash segments
      test: Update degenerate-solid-dash reference
      path-stroke-boxes: Fix degenerate end-caps for anti-clockwise paths
      check-doc-syntax: Fix handling of return value in make check
      check-doc-syntax: Only parse the source files for incorrect tags
      version: bump for cairo-1.12.2 release
      version: Post release bump to 1.12.3

Dimiter Stanev (1):
      win32: compilation fix for recent private/inline header separation

Gilles Espinasse (1):
      Cosmetic configure fix

Henry (Yu) Song (3):
      gl: use font's antialias option to check whether it needs mask
      gl: fix y-axis origin when map_to_image() for non texture GL surface
      gl: Remove an unused variable

Javier Jardón (4):
      configure.ac: Update autotools configuration
      configure.ac: generate xz tarballs by default
      autogen.sh: User autoreconf instead custom script
      configure.ac: Do not generate template files when building docs

Jeff Mahoney (1):
      pdf: Fix wrong allocation in _cairo_pdf_surface_add_source_surface

Kalev Lember (1):
      win32: Avoid redefining ssize_t

Maarten Bosmans (4):
      test: Give some functions in any2ppm a prefix
      Protect code using dlfcn.h with CAIRO_HAS_DLSYM
      test: Only use alarm() when SIGALRM is also defined
      Add _cairo_win32_print_gdi_error to boilerplate code

Marcus Meissner (1):
      configure: Conditionally include -flto

Nis Martensen (6):
      add unused symbols to sections doc
      doc: no separate cairo-xcb-xrender section
      doc: add returns statement to cairo_surface_supports_mime_type
      doc: do not use / in section title
      doc: add missing chapters
      typo

Uli Schlachter (4):
      xcb/xlib: Add missing "Since: 1.12"
      README: Note that xcb is no longer experimental
      xcb: Fix SHM in _get_image()
      xlib: Disable fallback compositor with xlib-xcb
```
