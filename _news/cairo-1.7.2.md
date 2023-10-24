---
title: cairo 1.7.2 snapshot available
layout: news
date: 2008-08-11
---
```

From: Behdad Esfahbod <behdad@behdad.org>
Date: Mon, 11 Aug 2008 13:05:45 -0400
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.7.2 now available

A new cairo snapshot 1.7.2 is now available from:

http://cairographics.org/snapshots/cairo-1.7.2.tar.gz

    which can be verified with:

http://cairographics.org/snapshots/cairo-1.7.2.tar.gz.sha1
29569943dad4a4e5bbe16495404288a466e1bd0f  cairo-1.7.2.tar.gz

http://cairographics.org/snapshots/cairo-1.7.2.tar.gz.sha1.asc
(signed by Behdad Esfahbod)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.7.2 tag which points to a commit named:
057a832f9e806f9321648e47ee314a62e82e6ba4

    which can be verified with:
git verify-tag 1.7.2

    and can be checked out with a command such as:
git checkout -b build 1.7.2

Release 1.7.2 (2008-08-11 Behdad Esfahbod <behdad@behdad.org>)
==============================================================
The cairo community is finally ready to announce availability of the 1.7.2
snapshot of the cairo graphics library.  This is embarrissingly the first
snapshot in the 1.7 unstable series of cairo, leading to the eventual release
of cairo 1.8, currently planned for late September.

This snapshot comes four months after the 1.6.4 release.  We have done a
really bad job on getting development stapshots out this cycle, but
hopefully all the API changes for 1.8 are now finished and the remaining
weeks will be spent on bug-fixing.  There is more than 400 commits worth
of changes in this snapshot, and those can use some testing.  Read on!

Text, text, and more text!
- --------------------------
The dominant theme of this release, and 1.8 in general, is improvements
around cairo text API.  Here is a high-level list of changes with text
handling:

User fonts
- ----------
This is new API allowing the user of cairo API to provide drawings for glyphs
in a font.  This is most useful in implementing fonts in non-standard formats,
like SVG fonts and Flash fonts, but can also be used by games and other
applications to draw "funky" fonts.  See test/user-font.c and
test/user-font-proxy.c for usage examples.  This is based on early work by
Kristian Høgsberg.  Thanks Kristian!

show_text_glyphs
- ----------------
This new API allows the caller of cairo to mark text glyphs with their
original text.  The PDF backend implements this new API and latest Pango
master uses it.  The result is (when bugs are fixed) that complex text can be
copied out of pangocairo's PDF output correctly and reliably.  There are bugs
to fix though.  A few poppler bugs, and some more in cairo and pango.

To test show_text_glyph, just grab pango master and this cairo snapshot and
print text in gedit.  Open in acroread or evince, select all, copy, paste
in gedit and compare.  The Arabic text with diacritic marks is particularly
showing bad.  Try with pango/pango-view/HELLO.txt if you are brave
enough.  The Indic text is showing improvements, but is still coming out
buggy.

LCD subpixel filtering using FreeType
- -------------------------------------
FreeType 2.3.5 added support for various LCD subpixel filtering, and
fontconfig 2.6.0 added support for configuring LCD filter on a font by font
basis.  Cairo now relies on FreeType and fontconfig for subpixel filtering.
This work is based on David Turner's original patch to cairo, maintained
and tested by Sylvain Pasche and others.  Thanks all!

Toy font face constructor and getter
- ------------------------------------
Mostly for API completion, but also useful for higher level (like Pango) to
hook into what the user has set using cairo_select_font_face(), making that
toy API a bit more useful.

FreeType: respecting FC_FT_FACE
- -------------------------------
Previously it was impossible to instruct cairo to do emboldening on a font
face object created from an FT_Face.  Cairo now respects and uses the
FC_FT_FACE fontconfig pattern element, so emboldening can be achieved by
using cairo_ft_font_face_create_for_pattern() and a carefully crafted pattern
using FC_FT_FACE and FC_EMBOLDEN.


PS/PDF: More efficient output
- -----------------------------
Adrian Johnson has been busy fixing all kinds of bugs in PS and PDF
backends, as well making them generate much more compact output by avoiding
things like re-emitting the color or linestyle on every drawing operation.
Thanks Adrian!


Xlib: Dithering
- ---------------
Cairo now does simple dithering when rendering to legacy X servers.  This is
mostly visible with 8-bit visuals.

Xlib: Avoid rendering glyphs out of surface bounds
- --------------------------------------------------
This seemingly harmless change manifested a bug with OpenOffice.org 3 versions
where OO.o was passing bogus surface extents to cairo, resulting in no text
rendered in OO.o.  Please contact your distro's OO.o maintainers if you see
this bug and point them to the following URL:

  https://bugs.freedesktop.org/show_bug.cgi?id=16209

Xlib: Improved performance with Xrender-less X servers
- ------------------------------------------------------
Cairo now performs better on remote, Xrender-less X servers by being smarter
about using X core protocol facilities instead of falling back to doing all
rendering on the client side.


Directfb: backend improvements
- ------------------------------
The directfb backend, though still unsupported, has seen a good deal of
improvements.  Thanks Vlad!


Bug fixing and optimizations
- ----------------------------
Countless bugs have been fixed and optimizations made, many of them thanks to
Chris Wilson.  Thanks Chris!


API additions
- -------------

cairo_show_text_glyphs

  This is a new text rendering API.  Being a more advanced version of
  cairo_show_glyphs(), it is aimed for use by higher-level text toolkits like
  Pango, and enables better text extraction from output generated by backends
  like PDF and SVG.  The PDF backend already implements it, and the upcoming
  Pango release will use it.

  To make that API work, a bunch of other additions were made:

cairo_glyph_allocate
cairo_glyph_free
cairo_text_cluster_t
cairo_text_cluster_allocate
cairo_text_cluster_free
cairo_has_show_text_glyphs


cairo_user_font_face_create

  This is the "user" font face constructor, accompanied by a variety of method
  signatures, getters, and setters for a callback-based font backend:

CAIRO_FONT_TYPE_USER
cairo_user_scaled_font_init_func_t
cairo_user_scaled_font_render_glyph_func_t
cairo_user_scaled_font_text_to_glyphs_func_t
cairo_user_scaled_font_unicode_to_glyph_func_t
cairo_user_font_face_set_init_func
cairo_user_font_face_set_render_glyph_func
cairo_user_font_face_set_text_to_glyphs_func
cairo_user_font_face_set_unicode_to_glyph_func
cairo_user_font_face_get_init_func
cairo_user_font_face_get_render_glyph_func
cairo_user_font_face_get_text_to_glyphs_func
cairo_user_font_face_get_unicode_to_glyph_func


cairo_scaled_font_text_to_glyphs

  We were previously reluctant to provide this function as text-to-glyphs
  support in cairo was limited to "toy" font functionality, not really
  interesting for real-world text processing.  However, with user-fonts
  landing, this API is needed to expose full access to how user-fonts
  convert text to glyphs.  This is expected to be used by text toolkits like
  Pango, as well as "proxy" user-font implementations.


cairo_lcd_filter_t
cairo_font_options_set_lcd_filter
cairo_font_options_get_lcd_filter

  These add the possibility to choose between various available LCD subpixel
  filters.  The available filter values are modeled after what FreeType
  provides.


cairo_toy_font_face_create
cairo_toy_font_face_get_family
cairo_toy_font_face_get_slant
cairo_toy_font_face_get_weight

  These provide access to functionality and settings provided by
  cairo_select_font_face().


cairo_scaled_font_get_scale_matrix
cairo_surface_get_fallback_resolution

  For API completeness.


Various new values for cairo_status_t enum


Known issues:

- - Type3 fonts generated by cairo's PDF backend may show up in poppler/Evince
  in a different color than expected.  This is fixed in poppler master branch.
  This mostly affects cairo user fonts.  The test case test/user-font.c
  demonstrates this.

- - User fonts using other fonts in their rendering are currently embedded in
  PDF as fallback bitmap glyphs.  This will be (hopefully) fixed before 1.8.
  The test case test/user-font-proxy.c demonstrates this.
```
