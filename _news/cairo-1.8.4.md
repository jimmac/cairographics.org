---
title: cairo 1.8.4 release available
layout: news
date: 2008-11-14
---

From: Carl Worth <cworth@cworth.org>
Date: Fri, 14 Nov 2008 15:19:24 +0100
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, ftp-release@lists.freedesktop.org, pr@lwn.net
Subject: cairo release 1.8.4 now available

A new cairo release 1.8.4 is now available from:

  http://cairographics.org/releases/cairo-1.8.4.tar.gz

    which can be verified with:

    http://cairographics.org/releases/cairo-1.8.4.tar.gz.sha1
    57fd2c7e0af16bee7cd53436d7c9dc526784f1da  cairo-1.8.4.tar.gz

    http://cairographics.org/releases/cairo-1.8.4.tar.gz.sha1.asc
    (signed by Carl Worth)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.8.4 tag which points to a commit named:
    66e8f142e381501d114888c2d1fc1e7f6d6a9857

    which can be verified with:
    git verify-tag 1.8.4

    and can be checked out with a command such as:
    git checkout -b build 1.8.4

The cairo community is pleased to announce the 1.8.4 release of the
cairo graphics library. This is the second update to cairo's stable
1.8 series and contains a small number of bug fixes, (in particular a
few fixes for build failures of cairo 1.8.2 on various systems). This
is being released just over two weeks after cairo 1.8.2.

We recommend that everyone using cairo upgrade to 1.8.4.

-Carl

Build fixes
-----------
Fix build with older XRender that doesn't define RepeatNone:

   Build of xlib backend fails against old XRender (RepeatNone undeclared)
   https://bugs.freedesktop.org/show_bug.cgi?id=18385

Fix build with bash version <= 3.0:

   doltlibtool broken on linux with bash 3.00.0
   https://bugs.freedesktop.org/show_bug.cgi?id=18363

Bug fixes
---------
Avoid triggering a bug in X.org server 6.9 resulting in a hung machine
requiring a reboot:

    https://bugs.freedesktop.org/show_bug.cgi?id=15628#c2

Fix display of user fonts as exercised by proposed support for type3
fonts in poppler (unsigned promotion fixes):

    Use cairo user-font for Type 3 fonts
    http://lists.freedesktop.org/archives/poppler/2008-October/004181.html

Avoid miscomputing size of fallback images required when rendering
with CLEAR, IN, or SOURCE operator to vector surfaces, (PS, PDF, SVG,
etc.).

Be more tolerant of broken fonts when subsetting type1 fonts:

   Error handling in cairo_type1_font_subset_get_glyph_names_and_widths
   http://lists.cairographics.org/archives/cairo/2008-October/015569.html

Fix cairo_fill_extents, cairo_stroke_extents, cairo_path_extents, to
correctly allow NULL parameters as documented.

Fix potential crash on emitting a type3 glyph after having drawn text
paths from the same font, (for example with cairo_text_path).
