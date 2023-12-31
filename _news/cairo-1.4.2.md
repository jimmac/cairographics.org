---
title: cairo 1.4.2 release available
layout: news
date: 2007-03-19
---
```

From: Carl Worth <cworth@cworth.org>
Date: 19 Mar 2007
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo release 1.4.2 now available

A new cairo release 1.4.2 is now available from:

        http://cairographics.org/releases/cairo-1.4.2.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.4.2.tar.gz.sha1
        9e7a323fc7d81d5011044d7eb22db3bf26ff7314  cairo-1.4.2.tar.gz

        http://cairographics.org/releases/cairo-1.4.2.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.2 tag which points to a commit named:
        aba2b299db163d8a5b9d0a0214cd8a485fb87162

    which can be verified with:
        git verify-tag 1.4.2

    and can be checked out with a command such as:
        git checkout -b build 1.4.2

This is the first update release in cairo's stable 1.4 series. It
comes just less than 2 weeks after 1.4.0. We hadn't anticipated an
update this early, but we've managed to collect some important fixes
that we wanted to get out to cairo users as soon as possible, (6 fixes
for crashes, 1 case where graphical elements would not be drawn at
all, a handful of backend-specific bugs, and several important build
fixes).

There's almost nothing but bug fixes in this release, (see below one
optimization that Behdad did sneak in), so we recommend that everyone
upgrade to this release when possible.

Thanks to the many people that worked to fix these bugs, and those
that did the work to report them and to test the fixes, (wherever
possible both names are credited below).

-Carl

What's new in cairo 1.4.2 since 1.4.0
=====================================
Critical fixes
--------------
• Fix a crash due to a LOCK vs. UNLOCK typo (M. Drochner fixing Carl
  Worth's embarrassing typo).

  http://bugs.freedesktop.org/show_bug.cgi?id=10235

• Fix potential buffer overflow, which on some systems with a checking
  variant of snprintf would lead to a crash (Adrian Johnson, Stanislav
  Brabec, and sangu).

  https://bugs.freedesktop.org/show_bug.cgi?id=10267
  https://bugzilla.redhat.com/bugzilla/show_bug.cgi?id=232576

• Fix a crash in cairo_stroke_extents or cairo_in_stroke when line
  width is 0.0. (Carl Worth and Sebastien Bacher)

  https://bugs.freedesktop.org/show_bug.cgi?id=10231

• Fix a crash on certain combinations of X server/video drivers (Carl
  Worth and Tomas Carnecky).

  https://bugs.freedesktop.org/show_bug.cgi?id=10250

• Fix a crash due to mishandling of invalid user input (Carl Worth and
  Alexander Darovsky).

  https://bugs.freedesktop.org/show_bug.cgi?id=9844

• xlib: Cleanup server-side glyph caches on XCloseDisplay. This
  eliminated a crash detected by the perf suite, (and that
  applications could have run into as well). (Chris Wilson)

Other bug fixes
---------------
• Fix for some geometry which simply disappeared under some
  transformations---a stroked line with an extreme skew in X, for
  example (Carl Worth and Jonathan Watt).

  https://bugzilla.mozilla.org/show_bug.cgi?id=373632

• SVG: Fix radial gradients for CAIRO_EXTEND_REFLECT and when r0 > r1
  (Emmanuel Pacaud).

• PDF: Set page group color space to DeviceRGB.

  This fixes incorrect (muddy) transparent colors when rendering cairo
  PDF output in some viewers. (Adrian Johnson, Adam Goode, and
  MenTaLguY).

  http://lists.freedesktop.org/archives/cairo/2006-November/008551.html

• win32: Return correct metrics when hinting is off, and fix font
  descent computation (Behdad Esfahbod).

• quartz: Fix glyph interfaces to correctly return user-space rather
  than device-space coordinates (Brian Ewins).

  https://bugs.freedesktop.org/show_bug.cgi?id=9568

• xcb: Fix parameter-order confusion with xcb_create_pixmap, which now
  makes all tests that pass with xlib now pass with xcb (Carl Worth,
  Jamey Sharp).

• Fix some memory leaks in the perf suite (Chris Wilson).

• Fix perf suite to consider changes in pixman/src (Mathias
  Hasselmann).

Build fixes
-----------
• Don't include pre-generated cairo-features.h file. This was causing
  build failures when building with the directfb backend enabled
  (Behdad Esfahbod).

  https://bugs.freedesktop.org/show_bug.cgi?id=10189

• Eliminate use of maintainer mode from cairo's automake/configure
  script. This means that updates to files such as Makefile.am will
  take effect, (by rerunning automake and friends as necessary) when
  invoking make rather than being silently ignored.  (Behdad Esfahbod)

• Don't compile cairo-deflate-stream.c, which depends on zlib, unless
  building the pdf backend which requires it. (Carl Worth, Tor
  Lillqvist)

  https://bugs.freedesktop.org/show_bug.cgi?id=10202

• Don't make the ps backend link against zlib anymore, since it
  doesn't require it (Carl Worth).

• Use "find !" rather than "find -not" for better portability (Thomas
  Klausner).

  https://bugs.freedesktop.org/show_bug.cgi?id=10226

• Don't use unsupported visibility attribute "hidden" on Solaris
  (Gilles Dauphin, Thomas Klausner).

  https://bugs.freedesktop.org/show_bug.cgi?id=10227

Optimization
------------
• It was Behdad that suggested we focus strictly on bug fixes now that
  we shipped so many performance improvements in 1.4.0, but it was
  also Behdad that got distracted by the chance to remove a lot of
  mallocs from cairo. Paths, gstates, trapezoids, splines, polygons,
  and gradient color stops will now use small, stack-allocated buffers
  in the most common cases rather than calling malloc as
  often. (Behdad Esfahbod). And look for more from Mathias Hasselmann
  soon.

```
