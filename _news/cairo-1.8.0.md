---
title: cairo 1.8.0 release available
layout: news
date: 2008-09-25
---
```

From: Carl Worth <cworth@cworth.org>
Date: Thu, 25 Sep 2008 16:11:33 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, pr@lwn.net
Subject: cairo release 1.8.0 now available

A new cairo release 1.8.0 is now available from:

        http://cairographics.org/releases/cairo-1.8.0.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.8.0.tar.gz.sha1
        8a689ca47c24216f37bb8cabae21ff08a7f47899  cairo-1.8.0.tar.gz

        http://cairographics.org/releases/cairo-1.8.0.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.8.0 tag which points to a commit named:
        6b3aa86b1c5b2fce3e56b43142c4ec2664a37032

    which can be verified with:
        git verify-tag 1.8.0

    and can be checked out with a command such as:
        git checkout -b build 1.8.0

The cairo community is happy (and relieved) to announce the 1.8.0
release of the cairo graphics library. This is a major update to
cairo, with new features and enhanced functionality which maintains
compatibility for applications written using any previous major cairo
release, (1.6, 1.4, 1.2, or 1.0). We recommend that anybody using a
previous version of cairo upgrade to cairo 1.8.0.

The dominant theme of this release is improvements to cairo's ability
to handle text. The highlights include a new "user fonts" feature as
well as a new cairo_show_text_glyphs API which allows glyphs to be
embedded in PDF output along with their original text, (for searching,
selection, and copy-and-paste). Another major feature is a revamp of
cairo's build system making it much easier to build cairo on various
platforms.

See below for more details.

User fonts
----------
This new API allows the user of cairo API to provide drawings for
glyphs in a font. A common use for this is implementing fonts in
non-standard formats, like SVG fonts and Flash fonts. This API can
also be used by applications to provide custom glyph shapes for fonts
while still getting access to cairo's glyph caches. See
test/user-font.c and test/user-font-proxy.c for usage examples. This
is based on early work by Kristian Høgsberg. Thanks Kristian!

This new API consists of the following functions (and corresponding
_get functions):

cairo_user_font_face_create

cairo_user_font_face_set_init_func
cairo_user_font_face_set_render_glyph_func
cairo_user_font_face_set_text_to_glyphs_func
cairo_user_font_face_set_unicode_to_glyph_func

An additional, new API is

cairo_scaled_font_text_to_glyphs

We were previously reluctant to provide this function as
text-to-glyphs support in cairo was limited to "toy" font
functionality, not really interesting for real-world text
processing. However, with user fonts landing, this API is needed to
expose full access to how user fonts convert text to glyphs. This is
expected to be used by text toolkits like Pango, as well as "proxy"
user-font implementations.

cairo_show_text_glyphs
----------------------
This new API allows the caller of cairo to provide text data
corresponding to glyphs being drawn. The PDF backend implements this
new API so that complex text can be copied out of cairo's PDF output
correctly and reliably, (assuming the user of cairo calls
cairo_show_text_glyphs). The cairo_show_text_glyphs API is definitely
the most daunting API to debut in cairo. It is anticipated that pango
(and similar high-level text libraries) will be the primary users of
this API. In fact, pango 1.22 already uses cairo_show_text_glyphs.
Behdad was the architect and implementor of this effort. Thanks,
Behdad!

The cairo_show_text_glyphs API includes the following new functions:

cairo_show_text_glyphs

cairo_glyph_allocate
cairo_glyph_free

cairo_text_cluster_allocate
cairo_text_cluster_free

cairo_surface_has_show_text_glyphs

Build system revamp
-------------------
The primary goal of the revamp is to make the build system less
fragile, (particularly for non-Linux platforms). For example, now
people building on win32 will no longer need to maintain a
platform-specific list of files to be built. See the new README.win32
for details. Also, the .so file will now be installed with a different
naming scheme, (for example, 1.8.0 will install with a .10800
suffix). Many thanks to Behdad and his small army of helpers!

Assorted API additions
----------------------
For API completeness, several missing "getter" functions were added:

cairo_scaled_font_get_scale_matrix

cairo_surface_get_fallback_resolution

cairo_toy_font_face_create
cairo_toy_font_face_get_family
cairo_toy_font_face_get_slant
cairo_toy_font_face_get_weight

The new cairo_toy_font_face functions provide access to functionality
and settings provided by cairo_select_font_face(). Thanks Behdad!

cairo-ps/cairo-pdf: More efficient output
-----------------------------------------
Adrian Johnson has been busy fixing all kinds of bugs in PS and PDF
backends, as well making them generate much more compact output by
avoiding things like re-emitting the color or linestyle on every
drawing operation. Thanks Adrian!

cairo-xlib: dithering
---------------------
Dithering: Cairo now does simple dithering when rendering to legacy X
servers. This is most visible with 8-bit visuals. Thanks Behdad!

cairo-xlib: Avoid rendering glyphs out of surface bounds
--------------------------------------------------------
This seemingly harmless optimization exposed a bug in OpenOffice.org 3
versions where OO.o was passing bogus surface extents to cairo,
resulting in no text rendered in OO.o. Please contact your
distribution's OO.o maintainers if you see this bug and point them to
the following URL:

 https://bugs.freedesktop.org/show_bug.cgi?id=16209

cairo-xlib: Improved performance with X server without Render
-------------------------------------------------------------
Cairo now performs better on remote X servers that lack the Render
extension by being smarter about using X core protocol facilities
instead of falling back to doing all rendering on the client side.

cairo-ft: respecting FC_FT_FACE
-------------------------------
Previously it was impossible to instruct cairo to do emboldening on a
font face object created from an FT_Face. Cairo now respects and uses
the FC_FT_FACE fontconfig pattern element, so emboldening can be
achieved by using cairo_ft_font_face_create_for_pattern() and a
carefully crafted pattern using FC_FT_FACE and FC_EMBOLDEN. Thanks
Behdad!

cairo-directfb: backend improvements
------------------------------------
The directfb backend, though still unsupported, has seen a good deal
of improvements. Thanks Vlad!

Bug fixing and optimizations
----------------------------
xlib: Faster bookkeeping (Karl Tomlinson)
https://bugzilla.mozilla.org/show_bug.cgi?id=453199#c5

PS: Fix gradients with non-constant alpha (Chris Wilson)

Fix deadlock in user-font code (Richard Hughes and Behdad Esfahbod)
http://bugs.freedesktop.org/show_bug.cgi?id=16819

Countless other bugs have been fixed and optimizations made, many of
them thanks to Chris Wilson. Thanks Chris and others!

Note also that the code that had been in cairo 1.7.x calling into
freetype's optional lcd_filter function was removed from cairo before
the 1.8.0 release. We do expect this code to come back in some form in
the future.

```
