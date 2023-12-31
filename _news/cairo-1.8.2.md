---
title: cairo 1.8.2 release available
layout: news
date: 2008-10-30
---
```

From: Carl Worth <cworth@cworth.org>
Date: Thu, 30 Oct 2008 08:36:56 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, ftp-release@lists.freedesktop.org, pr@lwn.net
Subject: cairo release 1.8.2 now available

A new cairo release 1.8.2 is now available from:

        http://cairographics.org/releases/cairo-1.8.2.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.8.2.tar.gz.sha1
        41e94d94e7f379551f556dd71979aca239a688c6  cairo-1.8.2.tar.gz

        http://cairographics.org/releases/cairo-1.8.2.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.8.2 tag which points to a commit named:
        f7c958d97221375fdcbb6c58c3b58c07676b7589

    which can be verified with:
        git verify-tag 1.8.2

    and can be checked out with a command such as:
        git checkout -b build 1.8.2

The cairo community is pleased to announce the 1.8.2 release of the
cairo graphics library. This is the first update to cairo's stable 1.8
series and contains a large number of bug fixes. It is being released
just over one month since cairo 1.8.0.

This release consists primarily of bug fixes, but there is one notable
new feature, (the ability to build cairo without an external font
backend), and there are a few optimizations as well. See below for
details on these changes and the most important bug fixes.

While many people have contributed to this release, Chris Wilson
deserves particular mention. He has contributed well over twice as
many changes to cairo since 1.8.0 than everyone else combined. We
greatly appreciate the tremendous efforts of Chris and all cairo
contributors.

We recommend everyone upgrade to cairo 1.8.2 and hope that everyone
will have lots of fun with cairo!

-Carl

New feature
-----------
It is now possible to build cairo without any font backend, (such as
freetype, win32 or quartz). This is most useful when the application
provides custom font rendering through the user-font API. But in the
case where no external font backend is available, and no user-font is
provided, cairo will render with a failsafe font, (a stroked font
covering visible ASCII character). (Behdad Esfahbod)

Optimizations
-------------
Dramatically speed up compilation with dolt (removes much of the
libtool overhead) (Behdad Esfahbod with thanks to Josh Triplett).

Several minor optimizations to tessellator (special-cased comparisons,
faster insert for skiplist, etc.) (Chris Wilson).

Optimize away fractional translation component when doing
EXTEND_NEAREST filtering, (for better performance).

General bug fixes
-----------------
Allow cloning sub-regions of similar surfaces to fix this bug
(Chris Wilson):

Crafted gif file will crash firefox
[XError: 'BadAlloc (insufficient resources for operation)']
https://bugzilla.mozilla.org/show_bug.cgi?id=424333

Fix some matrix confusion to fix this regression (Chris Wilson):

Translucent star exports in a wrong way to PDF
https://bugs.launchpad.net/inkscape/+bug/234546

Fix some long-standing bugs with respect to properly computing the
extents of transformed, filtered surfaces (Owen Taylor, Carl Worth,
and Chris Wilson):

Bad clipping with EXTEND_NONE
http://bugs.freedesktop.org/show_bug.cgi?id=15349

Improve filtering handling in cairo-pattern.c
http://bugs.freedesktop.org/show_bug.cgi?id=15367

Many thanks to Chris Wilson for digging out and cleaning up
these fixes.

Fix compilation on Solaris 10 (Chris Wilson):

Cairo requires -DREENTRANT (along with	-D_POSIX_THREAD_SEMANTICS)
to compile on Solaris 10 with pthreads
https://bugs.freedesktop.org/show_bug.cgi?id=18010

Fix very old bug causing dashes to be rendered at the wrong length in
fallback images (Adrian Johnson)

Dashed strokes too long in fallback images
https://bugs.freedesktop.org/show_bug.cgi?id=9189

Fix broken dashing when a dashed path starts outside the clip region
(Chris Wilson).

Avoid range overflow when computing large patterns (Benjamin Otte and
Chris Wilson).

Avoid crashing due to an invalid font with an incorrect entry in its
CMAP table (Adrian Johnson).

Fix bugs in computing maximum size of text requests that can be sent
with the Render extension, (avoiding potential crashes when rendering
large amounts of text) (Behdad Esfahbod and Chris Wilson).

Fix rendering of operators unbounded by the mask (Chris Wilson).

Fix compilation on systems without compiler support for a native
64-bit type (Chris Wilson).

Fix several cases of missing error-status propagation. (Chris Wilson,
doing the work he seems to never tire of).

Fix several locking issues found with the lockdep valgrind skin (Chris
Wilson).

Backend-specific bug fixes
--------------------------
xlib: Avoid crash due to attempting XRender calls on pixmaps with
formats not supported by the Render extension (Chris Wilson):

XRender crashes due to NULL pointer from Cairo on SGI O2
https://bugs.freedesktop.org/show_bug.cgi?id=11734

xlib: Add support for XImages with depth of 4, 20, 24, or 28 bits
(Chris Wilson):

cairo doesn't support 24 bits per pixel mode on X11
https://bugs.freedesktop.org/show_bug.cgi?id=9102

xlib: Avoid mistakenly considering two surfaces as similar just
because their depths match (while their Render formats do not) (Karl
Tomlinson).

ps: Fix slight mis-scaling of bitmapped fonts (Adrian Johnson)

svg: Correctly emit comp-op for paint, mask, and show_glyphs
operations (Emmanuel Pacaud).

svg: Use finer-grained fallbacks for SVG 1.2 (as PS and PDF backends
have been doing since 1.6.0) (Chris Wilson).

win32: Fallback to DIB if DDB create fails for
cairo_surface_create_similar (Vladimir Vukicevic).

win32: Fix compatibility with Windows Mobile (Vladimir Vukicevic).

win32: Fix static builds to not do __declspec(dllimport) on public
functions. This requires the user to set a CAIRO_WIN32_STATIC_BUILD
environment variable when compiling (Behdad Esfahbod).
```
