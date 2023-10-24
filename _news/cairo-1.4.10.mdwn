---
title: cairo 1.4.10 release available
layout: news
date: 2007-06-27
---

From: Carl Worth <cworth@cworth.org>
Date: Wed, 27 Jun 2007 14:43:25 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo release 1.4.10 now available

A new cairo release 1.4.10 is now available from:

http://cairographics.org/releases/cairo-1.4.10.tar.gz

    which can be verified with:

http://cairographics.org/releases/cairo-1.4.10.tar.gz.sha1
8371097e30650ec817b24694367110139627403e  cairo-1.4.10.tar.gz

http://cairographics.org/releases/cairo-1.4.10.tar.gz.sha1.asc
(signed by Carl Worth)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.10 tag which points to a commit named:
107a74885a25e585b467c7841c6929a12aa62565

    which can be verified with:
git verify-tag 1.4.10

    and can be checked out with a command such as:
git checkout -b build 1.4.10

This is the fifth update in cairo's stable 1.4 series. It comes
roughly three weeks after the 1.4.8 release. The most significant
change in this release is a fix to avoid an X error in certain cases,
(that were causing OpenOffice.org to crash in Fedora). There is also a
semantic change to include child window contents when using an xlib
surface as a source, an optimization when drawing many rectangles, and
several minor fixes.

-Carl

Significant changes from cairo 1.4.8 to 1.4.10
==============================================

Eliminate X errors that were killing OO.o (Chris Wilson)
--------------------------------------------------------
Cairo is fixed to avoid the X errors propagated when cleaning up
Render Pictures after the application had already destroyed the
Drawable they reference. (It would be nice if the X server wouldn't
complain that some cleanup work is already done, but there you have
it.) This fixes the bug causing OpenOffice.org to crash as described
here:

XError on right click menus in OOo.
https://bugzilla.redhat.com/bugzilla/show_bug.cgi?id=243811

Use IncludeInferiors when using xlib surface as a source (Ryan Lortie)
----------------------------------------------------------------------
When an xlib surface is used as the source of a draw operation the
contents of child windows are now included in the source data. The
semantics of drawing to xlib surfaces are unchanged (ie: draws are
still clipped by child windows overlapping the destination window).

Optimize drawing of many rectangles (Vladimir Vukicevic)
--------------------------------------------------------
Avoid O(N*N) loop when filling many axis-aligned rectangles, (either
many rectangles as separate sub-paths or due to dashing).

Miscellaneous fixes
-------------------
Fix cairo-perf on Solaris by linking to librt. (Behdad Esfahbod)

Fix make check for systems that require executable files to have a
particular extension. (Behdad Esfahbod)

Eliminate some warnings in cairo-quartz. (Brian Ewins)

Fix build-breaking typo for cairo-directfb. (Chris Wilson)
