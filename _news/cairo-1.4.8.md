---
title: cairo 1.4.8 release available
layout: news
date: 2007-06-08
---
```

From: Carl Worth <cworth@cworth.org>
Date: Fri, 08 Jun 2007 16:14:28 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo release 1.4.8 now available

A new cairo release 1.4.8 is now available from:

http://cairographics.org/releases/cairo-1.4.8.tar.gz

    which can be verified with:

http://cairographics.org/releases/cairo-1.4.8.tar.gz.sha1
e0730d852262d68a68d5a4c4a99657b0baeed13c  cairo-1.4.8.tar.gz

http://cairographics.org/releases/cairo-1.4.8.tar.gz.sha1.asc
(signed by Carl Worth)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.8 tag which points to a commit named:
fea4f344c46cf5f85c6af3102333008768c55063

    which can be verified with:
git verify-tag 1.4.8

    and can be checked out with a command such as:
git checkout -b build 1.4.8

This is the fourth update in cairo's stable 1.4 series. It comes just
over five weeks after the 1.4.6 release. This release includes a
thread-safe surface-cache for solid patterns which significantly
improves text rendering with the xlib backend. Also, dozens of error
paths in cairo have been fixed thanks to extensive fault-injection
testing by Chris Wilson.

Have fun!

-Carl

What's new in 1.4.8 compared to 1.4.9
=====================================

Surface cache for solid patterns
--------------------------------
Originally written by Jorn Baayen, the introduction of a small cache
for surfaces created for solid patterns improves performance
dramatically. For example, this reduces the volume of X requests
during text rendering to the same level as Xft.

This cache first made its appearance in a 1.3.x snapshot, but was
removed before appearing in any previous major release due to
complications with multi-threaded programs. For example, programs like
evince that would carefully restrict usage of cairo-xlib to a single
thread were unpleasantly surprised to find that using cairo-image in a
separate thread could trigger X requests.

Behdad Esfahbod designed a fix which was implemented by Chris
Wilson. Now, the necessary X requests are queued up until the next
time the application directly operates on an xlib surface.

Improved error handling paths
------------------------------
Chris Wilson continued the excellent work he started in cairo 1.4.4 to
make cairo much more robust against out-of-memory and other errors. He
applied his memory allocation fault injection cairo's main test suite,
(previously he had applied it to cairo's performance suite).

Chris's testing found dozens of bugs which he fixed. Many of these
bugs had perhaps never been hit by any users. But at least one was
hit by the gnome-about program which resulted in dozens of duplicated
bug reports against that program:

http://bugzilla.gnome.org/show_bug.cgi?id=431990

We were very pleasantly surprised to see this bug get fixed as a
side-effect of Chris's work. Well done, Chris!

Other fixes
-----------
Cleanup of mutex declarations (Behdad Esfahbod)

Remove unnecessary clip region from SVG output (Emmanuel Pacaud)

Remove Xsun from the buggy_repeat blacklist (Elaine Xiong)

ATSUI: Fix glyph measurement: faster and more correct (Brian Ewins)

Quartz: fixed 'extend' behaviour for patterns, improved pattern performance,
and a few smaller correctness fixes. (Brian Ewins, Vladimir Vukicevic)
```
