---
title: cairo 1.4.4 release available
layout: news
date: 2007-04-13
---
```

From: Carl Worth <cworth@cworth.org>
Date: 13 Apr 2007
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo release 1.4.4 now available

A new cairo release 1.4.4 is now available from:

        http://cairographics.org/releases/cairo-1.4.4.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.4.4.tar.gz.sha1
        71a7ce8352500944f7b2b73d4dc25ee947ec56ec  cairo-1.4.4.tar.gz

        http://cairographics.org/releases/cairo-1.4.4.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.4 tag which points to a commit named:
        ebba4a6d1467a8e5db5cc43eb08e8fc98c39b30a

    which can be verified with:
        git verify-tag 1.4.4

    and can be checked out with a command such as:
        git checkout -b build 1.4.4

This is the second update release in cairo's stable 1.4 series. It
comes just less than a month after 1.4.2. The changes since 1.4.2
consist primarily of bug fixes, but also include at least one
optimization. See below for details.

Thanks, and have fun with cairo!

-Carl

There have been lots of individuals doing lots of great work on cairo,
but two efforts during the 1.4.4 series deserve particular mention:

Internal cleanup of error handling, (Chris Wilson)
--------------------------------------------------
Chris contributed a tremendous series of patches (74 patches!) to
improve cairo's handling of out-of-memory and other errors. He began
by adding gcc's warn_unused_attribute to as many functions as
possible, and then launched into the ambitious efforts of adding
correct code to quiet the dozens of resulting warnings.

Chris also wrote a custom valgrind skin to systematically inject
malloc failures into cairo, and did all the work necessary to verify
that cairo's performance test suite runs to completion without
crashing.

The end result is a much more robust implementation. Previously, many
error conditions would have gone unnoticed and would have led to
assertion failures, segmentation faults, or other harder-to-diagnose
problems. Now, more than ever, cairo should cleanly let the user know
of problems through cairo_status and other similar status
functions. Well done, Chris!

More malloc reduction, (Mathias Hasselmann)
-------------------------------------------
After 1.4.0, Behdad launched an effort to chase down excessive calls
to malloc within the implementation of cairo. He fixed a lot of
malloc-happy objects for 1.4.2, but one of the worst offenders,
(pixman regions), was left around. Mathias contributed an excellent
series of 15 patches to finish off this effort.

The end result is a cairo that calls malloc much less often than it
did before. Compared to 1.4.2, 55% of the calls to malloc have been
eliminate, (and 60% have been eliminated compared to 1.4.0). Well
done, Mathias!

Other improvements since 1.4.2
------------------------------
• Centralize mutex declarations (will reduce future build breaks),
  (Mathias Hasselmann)

• Reduce malloc by caching recently freed pattern objects (Chris
  Wilson)

• Fix some broken composite operations (David Reveman)
        https://bugs.freedesktop.org/show_bug.cgi?id=5777

Backend-specific fixes
----------------------
PDF:
 • Use TJ operator for more compact representation of glyphs (Adrian
   Johnson)

 • Fix glyph positioning bug when glyphs are not horizontal
        http://lists.freedesktop.org/archives/cairo/2007-April/010337.html

win32:
 • Fix crash when rendering with bitmap fonts (Carl Worth)
        https://bugzilla.mozilla.org/show_bug.cgi?id=376498

xlib:
 • Turn metrics-hinting on by default (Behdad Esfahbod)

 • Fix edge-effect problem with transformed images drawn to xlib
   (Behdad Esfahbod)
        https://bugs.freedesktop.org/show_bug.cgi?id=10508

 • Avoid dereferencing a NULL screen. (Chris Wilson)
        https://bugs.freedesktop.org/show_bug.cgi?id=10517

Quartz/ATSUI:
 • Fix scaling of glyph surfaces
   (Brian Ewins)
        https://bugs.freedesktop.org/show_bug.cgi?id=9568

 • Fix compilation failure when both xlib and quartz enabled
   (Brian Ewins)

 • Fix rounding bug leading to incorrectly positioned glyphs
   (Robert O'Callahan)
        https://bugs.freedesktop.org/show_bug.cgi?id=10531

```
