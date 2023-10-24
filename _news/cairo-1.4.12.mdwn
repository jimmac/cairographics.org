---
title: cairo 1.4.12 release available
layout: news
date: 2007-11-27
---

From: Carl Worth <cworth@cworth.org>
Date: Tue, 27 Nov 2007 08:15:50 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo release 1.4.12 now available

A new cairo release 1.4.12 is now available from:

        http://cairographics.org/releases/cairo-1.4.12.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.4.12.tar.gz.sha1
        45d5257e5a0c1524bcc25660a96b2c79d012ad3f  cairo-1.4.12.tar.gz

        http://cairographics.org/releases/cairo-1.4.12.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.12 tag which points to a commit named:
        442fa9a106b01f17699397dcc95298071a50fd6d

    which can be verified with:
        git verify-tag 1.4.12

    and can be checked out with a command such as:
        git checkout -b build 1.4.12

This is the sixth update in cairo's stable 1.4 series. It comes five
months after the 1.4.10 release. This fix includes various bug fixes
originally developed during the 1.5.x development and backported to
1.4.

We hope that this is a nice release, of similar robustness to 1.4.10
but with many additional fixes. Distributions might choose to use the
new 1.4.12 directly. Or the most conservative distributions might use
the 1.4.12 branch as a starting point for looking for the most
significant bug fixes to patch onto 1.4.10.

Have fun with cairo!

-Carl

Summary of changes in cairo 1.4.12 since 1.4.10
===============================================
Some of the most significant bug fixes prevent crashes:

  * Avoid overflow when allocating large buffers (Vladimir Vukicevic)

  * Fix crash with cairo_pattern_set_user_data (Carl Worth)

  * Fix broken locking in cairo-ft error path (Chris Wilson)

  * Avoid crash when cleaning up after Render extension (Carl Worth)

  * Avoid crash for zero-sized bitmap glyph (Chris Wilson)

  * Avoid crash with type-1 fonts and ft and atsui enabled (Brian Ewins)

  * Fix many error-handling cases in the Quartz/ATSUI code (Brian Ewins)

  * Eliminate cairo_stroke crash with scaling near zero (Carl Worth)

Other fixes address rendering problems:

  * Fix PDF linear gradients without stops at 0.0 and 1.0 (Adrian Johnson)

  * Fix PDF CFF subsetting to work with Apple Preview (Adrian Johnson)

  * Report proper errors on out-of-memory on win32 (Vladimir Vukicevic)

  * Fix EXTEND_NONE gradients for cairo-quartz (Brian Ewins)

  * Fix odd-number-of-dashes dashing for cairo-quartz (Brian Ewins)

  * Fix erroneous results from cairo_stroke_extents (Carl Worth)

  * Force non-AA text when bitmap strikes are available (Keith Packard)

  * Fix cairo-atsui font metrics (Richard Hult)

And some avoid raising cairo errors for innocent problems:

  * Avoid drawing shutdown for glyph-not-found in font (Behdad Esfahbod)

  * Don't raise an error for creating an empty path (Chris Wilson)

At least one optimization managed to sneak in:

  * Free glyph surfaces after uploading to X server cache (Behdad Esfahbod)

And there are a few very minor fixes, (such as build fixes).

Note: For anyone attempting to backport these fixes to 1.4.10, please
take care since several of the fixes are spread across multiple
commits in cairo's history. And the related commits are not always
adjacent to each other. Please don't hesitate to ask for help or
review of anything you might do.
