---
title: cairo 1.5.20 snapshot available
layout: news
date: 2008-04-08
---

From: Carl Worth <cworth@cworth.org>
Date: Tue, 08 Apr 2008 03:11:25 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.20 now available

A new cairo snapshot 1.5.20 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.20.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.20.tar.gz.sha1
        c7793ca5f0e6a9b09dd10394d67629796fc5380e  cairo-1.5.20.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.20.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.20 tag which points to a commit named:
        aadbaf7d990d0d5cd7c25cc856dbcfcc357b44f1

    which can be verified with:
        git verify-tag 1.5.20

    and can be checked out with a command such as:
        git checkout -b build 1.5.20

This is the tenth snapshot in cairo's unstable 1.5 series. It comes
just two days (and only one working day) after the 1.5.18
snapshot. The quick snapshot is due to two embarrassing bugs (both
affecting cairo-xlib) that had been introduced in the 1.5.18
snapshot. The fixes for these are described below along with a few
other fixes, (which hopefully aren't introducing new bugs this time).

We're hopeful that this release candidate holds up better than the
last one, and that we'll be able to make a 1.6.0 release soon with no
major code changes from this snapshot.

Have fun with cairo, everybody!

-Carl

Major changes from cairo 1.5.18 to cairo 1.5.20
===============================================
cairo-xlib
----------
Revert fix from 1.5.18 to allow pattern expansion based on the filter
mode. This fix seemed so boring, (the use case it addresses is almost
never used in practice), that it didn't even get mentioned in the
1.5.18 release notes. However, the "fix" happened to break rendering
that is always used resulting in corrupt image rendering in mozilla,
evolution, and probably everything else that uses cairo.

Fix to avoid BadMatch errors in cairo_surface_create_similar. These
were introduced, (inadvertently, of course), as part of the fix in
1.5.18 for creating similar surfaces without the Render
extension. Again, thanks to mozilla, (and Vladimir Vukicevic in
particular), for noticing our mistake.

general
-------
Correctly handle an in-error surface in
cairo_surface_write_to_png. Previously this function would cause an
assertion failure if you gave it a finished surface. Now it cleanly
returns a CAIRO_STATUS_SURFACE_FINISHED result instead.

Avoid potentially infinite wandering through memory inside
_cairo_hull_prev_valid. Thanks to Jonathan Watt for noticing this
problem:

https://bugzilla.mozilla.org/show_bug.cgi?id=306649#c21

cairo-pdf
---------
Fix generation of "soft" masks made by drawing to a similar surface
and then calling cairo_mask_surface() with it.

cairo-svg
---------
Fix for code that uses cairo_mask() on an intermediate surface which
is later passed to cairo_mask_surface().
