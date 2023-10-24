---
title: cairo 1.1.4 snapshot available
layout: news
date: 2006-05-03
---

From: Carl Worth <cworth@cworth.org>
Date: 3 May 2006
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.1.4 now available

A new cairo snapshot 1.1.4 is now available from:

        http://cairographics.org/snapshots/cairo-1.1.4.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.1.4.tar.gz.sha1
        b79306cff7db38227a95929810ad829ed46124f8  cairo-1.1.4.tar.gz

        http://cairographics.org/snapshots/cairo-1.1.4.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.1.4 tag which points to a commit named:
466eab544f120cc89c8adc1be2b522580b978413

    which can be verified with:
git verify-tag 1.1.4

    and can be checked out with a command such as:
git checkout -b build 1.1.4

This is the second in a series of snapshots working toward the
upcoming 1.2 release of cairo. For a list of items still needing work
on the cairo 1.2 roadmap, please see:

http://cairographics.org/ROADMAP

In particular, note that it is still planned for the PDF backend to
get page-resizing support before 1.2, (as PostScript receives here
with the 1.1.4 snapshot).

This snapshot is backwards-compatible with the 1.0 series---it makes a
few API additions but does not remove any API. See a few paragraphs
below for details on what's new in 1.1.4.

-Carl

What's new in 1.1.4 compared to 1.1.2
=====================================
PostScript backend: new printing-oriented API
---------------------------------------------
We anticipate that with cairo 1.2, toolkits will begin to use cairo
for printing on systems that use PostScript as the spool format. To
support this use case, we have added 4 new function calls that are
specific to the PostScript backend:

cairo_ps_surface_set_size
        cairo_ps_surface_dsc_comment
        cairo_ps_surface_dsc_begin_setup
        cairo_ps_surface_dsc_begin_page_setup

These functions allow variation of the page size/orientation from one
page to the next in the PostScript output. They also allow the toolkit
to provide per-document and per-page printer control options in a
device-independent way, (for example, by using PPD options and
emitting them as DSC comments into the PostScript output). This should
allow toolkits to provide very fine-grained control of many options
available in printers, (media size, media type, tray selection, etc.).

SVG backend: builds by default, version control
-----------------------------------------------
The SVG backend continues to see major improvements. It is expected
that the SVG backend will be a supported backend in the 1.2
release. This backend will now be built by default if its dependencies
(freetype and libxml2) are met.

Additionally, the SVG backend now has flexibility with regard to what
version of SVG it targets. It will target SVG 1.1 by default, which
will require image fallbacks for some of the "fancier" cairo
compositing operators. Or with the following new function calls:

cairo_svg_surface_restrict_to_version
cairo_svg_get_versions
cairo_svg_version_to_string

it can be made to target SVG 1.2 in which there is native support for
these compositing operators.

Bug fixes
---------
At least the following bugs have been fixed since the 1.1.2 snapshot:

crash at XRenderAddGlyphs
https://bugs.freedesktop.org/show_bug.cgi?id=4705

Can't build cairo-1.1.2 on opensolaris due to " void function cannot return value"
https://bugs.freedesktop.org/show_bug.cgi?id=6792

Missing out-of-memory check at gfx/cairo/cairo/src/cairo-atsui-font.c:185
https://bugzilla.mozilla.org/show_bug.cgi?id=336129

A couple of memory leaks.
