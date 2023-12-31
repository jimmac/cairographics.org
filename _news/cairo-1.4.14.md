---
title: cairo 1.4.14 release available
layout: news
date: 2008-01-14
---
```

From: Carl Worth <cworth@cworth.org>
Date: Mon, 14 Jan 2008 16:55:00 -0800
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo release 1.4.14 now available

A new cairo release 1.4.14 is now available from:

        http://cairographics.org/releases/cairo-1.4.14.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.4.14.tar.gz.sha1
        63310243ba8af949060b06c01fc28ee5471ed5a4  cairo-1.4.14.tar.gz

        http://cairographics.org/releases/cairo-1.4.14.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.14 tag which points to a commit named:
        bdd93f5e8eb5726315cca396240afe7a084348ae

    which can be verified with:
        git verify-tag 1.4.14

    and can be checked out with a command such as:
        git checkout -b build 1.4.14

This is the seventh update in cairo's stable 1.4 series. It comes
little more than a month after the 1.4.12 release. Compared to 1.4.12,
this release adds only a handful of bug fixes all of which were
cherry-picked from the 1.5 series. One of these fixes a miter-join
regression introduced during the 1.4.12 series. See below for details.

It would not be surprising if this were the last release in the 1.4
series. We're working hard on getting 1.6 out soon, and unless some
new, big bugs are discovered in 1.4.14, this will be the end of a good
run. We do recommend that anybody running any 1.4.x release, (and
particularly 1.4.12), consider upgrading to 1.4.14.

Have fun with cairo!

-Carl

Bugs fixed between cairo 1.4.12 and 1.4.14
==========================================
Fix a regression (which first appeared in 1.4.12) where stroking under
a large scale would sometimes incorrectly replace a miter join with a
bevel join. (Thanks to Keith Packard.)

Fix handling of fonts that contain a mixture of outline and bitmapped
glyphs. There was a change in this handling in 1.4.12 that improved
some cases and also regressed other cases. Now, all cases should be
handled quite well.

Fix xlib backend to not consider recent X server release as having a
buggy repeat implementation in the Render extension. (Thanks to
Bernardo Innocenti.)

Fix several bugs in cairo's PostScript output. These include making
the PostScript output more compatible with recent versions of
ghostscript that are more strict about Type 3 fonts, for
example. (Many thanks to Adrian Johnson.)

```
