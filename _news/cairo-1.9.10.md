---
title: cairo 1.9.10 snapshot available
layout: news
date: 2010-06-26
---
```

Date: Sat, 26 Jun 2010 15:06:33 +0100
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.9.10 now available

        A new cairo snapshot 1.9.10 is now available from:

        http://cairographics.org/snapshots/cairo-1.9.10.tar.gz

            which can be verified with:

        http://cairographics.org/snapshots/cairo-1.9.10.tar.gz.sha1
        17062d7562d763234551e9e07be7c4c51686306f  cairo-1.9.10.tar.gz

        http://cairographics.org/snapshots/cairo-1.9.10.tar.gz.sha1.asc
        (signed by Chris Wilson)

          Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

            will include a signed 1.9.10 tag which points to a commit named:
        0f1ff0daab7259ec16076f788760da4f35cb0cdc

            which can be verified with:
        git verify-tag 1.9.10

            and can be checked out with a command such as:
        git checkout -b build 1.9.10


        The first "quick" snapshot in the run up to the stable release.  The
        last snapshot was picked up by the bleeding edge distributions and so the
        bug reports have to started to roll in.  The most frequent of these are the
        introduction of rendering errors by applications that modify a surface
        without subsequently calling cairo_surface_mark_dirty(). Make sure the
        application developers are aware of increased reliance on strict use of the
        Cairo API before 1.10 is released!

        The usual slew of bugs reported and we would like to thank Zoxc for
        contributing the WGL interface for cairo-gl, and finding more build
        failures on win32.  And it just wouldn't be a 1.9 snapshot unless
        Benjamin Otte improved the error handling within cairo-gl, as well as
        isolating and fixing some more errors in the test suite. The biggest bug of
        the snapshot turned out to be a major sign extension issue that had lain
        hidden for many years and was suddenly exposed by incorrectly rounding
        rectangles when performing non-antialiased rendering.  Also to the relief
        of many we have included the downstream patch to honour the user's LCD
        filtering preferences for subpixel rendering of fonts.  The interface
        remains private for the time being, whilst the proposed public API is
        finalized.

-Chris

API additions
-------------
          None
```
