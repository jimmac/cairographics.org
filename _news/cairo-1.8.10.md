---
title: cairo 1.8.10 release available
layout: news
date: 2010-02-19
---

From: Carl Worth <cworth@cworth.org>
Date: Fri, 19 Feb 2010 16:35:42 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, ftp-release@lists.freedesktop.org, pr@lwn.net
Subject: cairo release 1.8.10 now available

A new cairo release 1.8.10 is now available from:

http://cairographics.org/releases/cairo-1.8.10.tar.gz

    which can be verified with:

http://cairographics.org/releases/cairo-1.8.10.tar.gz.sha1
fd5e8ca82ff0e8542ea4c51612cad387f2a49df3  cairo-1.8.10.tar.gz

http://cairographics.org/releases/cairo-1.8.10.tar.gz.sha1.asc
(signed by Carl Worth)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.8.10 tag which points to a commit named:
dc7eba7564c1cf90cb4d330824e63053a51d3450

    which can be verified with:
git verify-tag 1.8.10

    and can be checked out with a command such as:
git checkout -b build 1.8.10

The cairo community is pleased to announce the 1.8.10 release of the
cairo graphics library. This is the fifth update to cairo's stable 1.8
series. This release consists of about a dozen hand-picked fixes
compared to 1.8.8 (which was released about 8 months ago).

We recommend that everyone using cairo upgrade to 1.8.10.

-Carl

General Bug fixes
=================
* Fix path construction for the case of cairo_curve_to immediately
  after cairo_new_sub_path followed at some point by
  cairo_close_path. (Previously, the final point for the close_path
  was computed incorrectly.)

* Fix for cairo_push_group or cairo_pop_group with a non-empty current
  path. (Previously the path may have been erroneously translated when
  either of these functions was called.)

* Fix to correctly report an error if
  cairo_surface_set_fallback_resolution is called with a value of 0
  (in either axis). Previously, an assertion would occur later rather
  than an error being properly reported when the original, invalid
  value was passed.

Bug 23067: Using clear drawing operator crashes printing
http://bugs.freedesktop.org/show_bug.cgi?id=23067

* Fix to handle a cairo_arc of radius 0 as equivalent to a
  cairo_line_to to the center coordinate, (previously cairo would do
  nothing for a cairo_arc call with a radius of 0).

Backend-specific bug fixes
==========================
cairo-xlib
----------
* Fix to correctly copy from a Window source. Previously, cairo was
  failing to include the contents of any sub-windows when copying from
  a Window source.

Bug 12996: Xlib source surface fast-paths do not use
IncludeInferiors, while slow paths do

https://bugs.freedesktop.org/show_bug.cgi?id=12996

cairo-ft
--------
* Fix conversion of freetype index to UCS4 value, (which would
  previously miss the first character and cause the space glyph to map
  to 0x00A0 instead of 0x0020).

cairo-pdf
---------
* Fix Type 1 subsetting to avoid generating corrupt data.

Launchpad Ubuntu/cups bug 419143: Printing from evince (and
perhaps other GTK apps) to PostScript printers is broken

https://bugs.launchpad.net/ubuntu/+source/cups/+bug/419143

* Fix Type 1 subsetting to correctly identify binary eexec data.

* Fix Type 1 subsetting to include fixed-content portion in the
  embedded font, (since some fonts may contain additional PostScript
  code after the cleartomark).

* Fix Type 1 subsetting to append "cleartomark" operator for binary
  fonts that don't include it.

Build fixes
===========
* Fix to compile on OpenBSD, (which has a libpng.pc file but none of
  libpng10.pc, libpng12.pc, or libpng13.pc which cairo was looking for
  previously).
