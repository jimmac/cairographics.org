---
title: cairo 1.9.2 snapshot available
layout: news
date: 2009-06-12
---
```

From: Carl Worth <cworth@cworth.org>
Date: Fri, 12 Jun 2009 12:25:50 -0700
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.9.2 now available

A new cairo snapshot 1.9.2 is now available.

This is a snapshot of current development leading up to an eventual
1.10 release.

Since this is a development snapshot, (not a "release"), one should not
expect cairo 1.9.2 to meet the same high standards as major cairo
releases. In particular:

* Any new API in this release may change before 1.10

  We think we've got the new API right, but we reserve the right
  to change things as new problems are discovered.

* The test suite is known to not pass, which indicates likely bugs

* There's a serious bug in PDF output related to the new "COW
  snapshots" feature, (see more on this below). When the same
  image is used on multiple pages it can appear in the wrong
  position on pages after the first, (appearing in the same
  position as on the first page).

* Plenty of other bugs are possible.

As always, we appreciate anyone willing to give our half-finished code a
look, and we will greatly appreciate feedback and bug reports.

Have fun with cairo, everybody!

-Carl

PS. I'd like to extend special notice to some particularly prolific
cairo contributors. Adrian Johnson, Behdad Esfahbod, Jeff Muizelaar,
M Joonas Pihlaja, and Søren Sandmann Pedersen have each contributed on
the order of 50 commits to this release. And Chris Wilson has made a
phenomenal 500 commits! Well done, everybody.

Where to get cairo 1.9.2
========================

http://cairographics.org/snapshots/cairo-1.9.2.tar.gz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.9.2.tar.gz.sha1
0dc542447fc46d77a3106afff4445d6e668d76e6  cairo-1.9.2.tar.gz

http://cairographics.org/snapshots/cairo-1.9.2.tar.gz.sha1.asc
(signed by Carl Worth)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.9.2 tag which points to a commit named:
e9b9d2a7c17ca4b2bc2991fdc4893aed850578db

    which can be verified with:
git verify-tag 1.9.2

    and can be checked out with a command such as:
git checkout -b build 1.9.2


What's new in cairo 1.9.2 (compared to cairo 1.8.x)
===================================================
API additions:

  cairo_surface_set_mime_data()
  cairo_surface_get_mime_data()

    Should this take unsigned int, unsigned long or size_t for the length
    parameter? (Some datasets may be >4GiB in size.)

    Associate an alternate, compressed, representation for a surface.
    Currently:
     "image/jp2" (JPEG2000) is understood by PDF >= 1.5
     "image/jpeg" is understood by PDF,PS,SVG,win32-printing.
     "image/png" is understood by SVG.

  cairo_pdf_version_t
  cairo_pdf_surface_restrict_to_version()
  cairo_pdf_get_versions()
  cairo_pdf_version_to_string()

    Similar to restrict to version and level found in SVG and PS,
    these limit the features used in the output to comply with the PDF
    specification for that version.

  CAIRO_STATUS_INVALID_SIZE
    Indicates that the request surface size is not supported by the
    backend.  This generally indicates that the request is too large.

  CAIRO_STATUS_USER_FONT_NOT_IMPLEMENTED
    Indicates that a required callback for a user-font was not implemented.

  CAIRO_STATUS_LAST_STATUS
    This is a special value to indicate the number of status values enumerated
    at compile time. (This may differ to the number known at run-time.)

  The built-in twin font is now called "@cairo:" and supports a limited set
  of options like "@cairo:mono". Where are these specified?

  cairo_in_fill() now uses HTML Canvas semantics, all edges are inside.

New experimental backends:

   CairoScript

New utility:

  cairo-trace and cairo-perf-trace

    cairo-trace generates a human-readable, replayable, compact(-ish!)
    representation of the sequences of drawing commands made by an
    application.

    Under the util/cairo-script directory is a library to replay traces.

    perf/cairo-perf-trace replays traces against multiple backends
    and makes useful benchmark reports. This is integrated with
    'make perf'. You may collect your own traces or take advantage
    of traces collected by the community:

      git://git.cairographics.org/git/cairo-traces

    (Put this into perf/cairo-traces to run these as part of "make perf".)

    There is additional WIP in building a debugging tool for cairo applications
    based on CairoScript (currently very preliminary, mostly serves to show
    that GtkSourceView is too slow) :

      people.freedesktop.org:~ickle/sphinx

Test suite overhaul:

  The test suite is undergoing an overhaul, primarily to improve its speed
  and utility. (Expect more changes in the near future to improve XFAIL
  handling.)

Optimisations:
  polygon rasterisation! Joonas implemented the Tor polygon scan converter,
  on typical geometry is about 30% faster for the image backend.

  Bovine Polaroids! For those not in on the joke, this is the long
  awaited "copy-on-write snapshot" or "COW snapshot" support. The
  user-visible feature is that including the same image multiple times
  into a PDF file should result in only a single instance of that
  image in the final output. This is unlike previous versions of cairo
  which would generate very large PDF files with multiple copies of
  the same image. Adrian says that the PDF is not quite working as
  well as it should yet, so we hope for futher improvements before
  cairo 1.10.

Bug fixes:

  EXTEND_PAD.

  Better handling of large scale-factors on image patterns.

  Emit /Interpolate for PS,PDF images.

  Global glyph cache - cap on the total number of inactive glyphs,
  should prove fairer for fonts with larger glyph sets.

  Compilation without fontconfig

  Improved handling of low-bitdepth sources (e.g. copying the contents
  of 16-bit xserver windows)

Regressions:

  cairo_traps_extract_region >10x slower. Fix pending.

Still to come:

  Region tracking API (ssp) for damage tracking, hit testing etc
  mime-surface

  An expiremental OpenGL backend?

  Tweaks to tessellator, allocations of patterns, delayed
  initialisation of the xlib backend (reduce the cairo overhead of
  render_bench by ~80%).
```
