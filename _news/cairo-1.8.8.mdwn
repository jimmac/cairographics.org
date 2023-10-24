---
title: cairo 1.8.8 release available
layout: news
date: 2009-06-16
---

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Tue, 16 Jun 2009 14:26:29 +0100
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, ftp-release@lists.freedesktop.org,  pr@lwn.net
Subject: cairo release 1.8.8 now available

A new cairo release 1.8.8 is now available from:

http://cairographics.org/releases/cairo-1.8.8.tar.gz

which can be verified with:

http://cairographics.org/releases/cairo-1.8.8.tar.gz.sha1
e4b8b219427d1ca3dc95f5f44914dce1ae0c3766  cairo-1.8.8.tar.gz

http://cairographics.org/releases/cairo-1.8.8.tar.gz.sha1.asc
(signed by Chris Wilson)

Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

will include a signed 1.8.8 tag which points to a commit named:
7dd89ff7a1e04930045d9726f5f21330f54d3f24

which can be verified with:
git verify-tag 1.8.8

and can be checked out with a command such as:
git checkout -b build 1.8.8


The cairo community is pleased to announce the 1.8.8 release of the
cairo graphics library. This is the fourth update to cairo's stable
1.8 series and contains a small number of bug fixes (in particular a
few corrections to the documentation and a few fixes in the FreeType font
backend). This is being released just over six months after cairo 1.8.6.

We recommend that everyone using cairo upgrade to 1.8.8.

-Chris

Build fixes
-----------
There were reports of incompatibilities with the autotools bundled in with
the 1.8.6 tarball.  This release has been built with automake-1.10.2 and
autoconf-2.63.

The configure check for FreeType has been improved:

   typo in check for version of freetype in configure script
   https://bugs.freedesktop.org/show_bug.cgi?id=19283

Compilation on 64-bit MacOS/X fixes:

  Cannot build cairo_quartz_font_face_create_for_atsu_font_id on 64-bit Mac OS X
  https://bugs.freedesktop.org/show_bug.cgi?id=15702

Bug fixes
---------
Uninitialised status return within _cairo_clip_intersect_mask(). This caused
random crashes and general mayhem as an error could be generated causing all
rendering to the context to stop.

Avoid transforming nearly-degenerate matrices into degenerate matrices:

   Painting stops in this case, using -moz-transform: scale, rotate and video
   https://bugzilla.mozilla.org/show_bug.cgi?id=467423

A few FreeType font handling bugs were fixed:

   Rendering with PANGO_GRAVITY_EAST leads to different results with image and pdf
   https://bugs.freedesktop.org/show_bug.cgi?id=21985

   Don't call FT_Done_Face() on faces we did not create

   zombie ft_font_face / ft_unscaled_font mutual referencing problems
   http://bugs.freedesktop.org/show_bug.cgi?id=21706

Ensure win32 font backend sets the return value to -1 (indicating the absent
glyph) if the font index lookup for the unicode character fails. And
similarly fix a bug where a fatal error was raised for an invalid glyph.

   cairo_scaled_font_glyph_extents breaks with invalid glyph id
   http://bugs.freedesktop.org/show_bug.cgi?id=20255

Various improvements to the documentation, reported by Truc Troung:

   https://bugs.freedesktop.org/show_bug.cgi?id=20095
   https://bugs.freedesktop.org/show_bug.cgi?id=20154
   https://bugs.freedesktop.org/show_bug.cgi?id=20180
   https://bugs.freedesktop.org/show_bug.cgi?id=20183
   https://bugs.freedesktop.org/show_bug.cgi?id=20182
   https://bugs.freedesktop.org/show_bug.cgi?id=20441

