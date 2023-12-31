---
title: cairo 1.8.6 release available
layout: news
date: 2008-12-13
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Sun, 13 Dec 2008 17:00:04 +0000
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, ftp-release@lists.freedesktop.org, pr@lwn.net
Subject: cairo release 1.8.6 now available

A new cairo release 1.8.6 is now available from:

http://cairographics.org/releases/cairo-1.8.6.tar.gz

    which can be verified with:

http://cairographics.org/releases/cairo-1.8.6.tar.gz.sha1
d1e5479d4eeb7b1a3589672e3ef8f4899e7c5eba  cairo-1.8.6.tar.gz

http://cairographics.org/releases/cairo-1.8.6.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.8.6 tag which points to a commit named:
e2a2eddcfb8fc73f3decdb91c00e8e6d5282e09c

    which can be verified with:
git verify-tag 1.8.6

    and can be checked out with a command such as:
git checkout -b build 1.8.6

The cairo community is pleased to announce the 1.8.6 release of the
cairo graphics library. This is the third update to cairo's stable
1.8 series and contains a small number of bug fixes (in particular a
few fixes for failures of cairo 1.8.4 on Quartz and PDF, and build fixes
for a couple of backends). This is being released just under a month
after cairo 1.8.4.

We recommend that everyone using cairo upgrade to 1.8.6.

-Chris

Build fixes
-----------
Fix build of DirectFB backend with debugging enabled:

   Bug in _cairo_directfb_surface_release_source_image function
   http://bugs.freedesktop.org/show_bug.cgi?id=18322

Fix build on OS/2.

Bug fixes
---------
Workaround a mis-compilation of cairo_matrix_invert() that generated
invalid matrices and triggered assertion failures later. The issue was
reported by Peter Hercek.

Invalid computation of the modulus:

   https://bugzilla.mozilla.org/show_bug.cgi?id=466258

Invalid referencing of patterns in the Quartz backend:

   Failed assertion `CAIRO_REFERENCE_COUNT_HAS_REFERENCE
   (&pattern->ref_count)' when using cairo quartz backend
   http://bugs.freedesktop.org/show_bug.cgi?id=18632

Invalid references to glyphs after early culling, causing segmentation
faults in the PDF backend:

http://lists.cairographics.org/archives/cairo/2008-December/015976.html

Check for XRender in the XCB backend, or else we may attempt an invalid
memory access:

    XCB backend fails with missing render.
    https://bugs.freedesktop.org/show_bug.cgi?id=18588
```
