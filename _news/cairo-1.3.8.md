---
title: cairo 1.3.8 snapshot available
layout: news
date: 2006-12-14
---
```

From: Carl Worth <cworth@cworth.org>
Date: 14 Dec 2006
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.3.8 now available

A new cairo snapshot 1.3.8 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.8.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.8.tar.gz.sha1
        c2e939f56eb10e1ca90be1a03e4ee6145be37172  cairo-1.3.8.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.8.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.8 tag which points to a commit named:
        129b55f5fcc4c2ae5b63ac6eb73fce8a708e4874

    which can be verified with:
        git verify-tag 1.3.8

    and can be checked out with a command such as:
        git checkout -b build 1.3.8

This is the fourth development snapshot in the 1.3 series. It comes
just slightly more than one week after the 1.3.6 snapshot.

After the bug fixes in 1.3.6, we're back to our original program of
weekly snapshots, each one faster than the one from the week
before. Cairo 1.3.8 brings a 2x improvement in the speed of rendering
linear gradients (thanks to David Turner), and a significant reduction
in X traffic when rendering text (thanks to Xan Lopez and Behdad
Esfahbod), making cairo behave very much like Xft does.

A few other things in the 1.3.8 snapshot worth noting include a more
forgiving image comparator in the test suite, (using the "perceptual
diff" metric and GPL implementation by Hector Yee[*]), a bug fix for
broken linking on x86_64 (thanks to M Joonas Pihlaja) and an even
better implementation of _cairo_lround, (not faster, but supporting a
more complete input range), from Daniel Amelang.

[*] http://pdiff.sourceforge.net/

Have fun with cairo, everybody!

-Carl
```
