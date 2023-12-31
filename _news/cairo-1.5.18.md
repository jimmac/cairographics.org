---
title: cairo 1.5.18 snapshot available
layout: news
date: 2008-04-06
---
```

From: Carl Worth <cworth@cworth.org>
Date: Sun, 06 Apr 2008 03:31:08 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.18 now available

A new cairo snapshot 1.5.18 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.18.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.18.tar.gz.sha1
        68d9e7fed9158d8584cf8a7831fe7b3441f7970f  cairo-1.5.18.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.18.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.18 tag which points to a commit named:
        6d6c8aa643603c2b5fd7baedc897d4698ba8bafb

    which can be verified with:
        git verify-tag 1.5.18

    and can be checked out with a command such as:
        git checkout -b build 1.5.18

This is the ninth snapshot in cairo's unstable 1.5 series. It comes
just 4 days after the 1.5.16 snapshot. We had hoped to not need
another snapshot before the final 1.6.0 release, but several critical
bugs were found and fixed in the last few days, so we thought it
important to let people test the fixes with this snapshot. See below
for details.

Have fun with cairo!

-Carl

Summary of changes from cairo 1.5.16 to 1.5.18
==============================================
documentation
-------------
The README now lists necessary dependencies.

Various graphics state defaults are now documented, (source pattern is
opaque black, line width is 2.0, line join is miter, line cap is butt,
miter limit is 10.0, etc.).

general
-------
Several cleanups have been made along many error-path returns,
(carefully propagating up the original error status values, cleaning
up memory leaks during error recovery, etc.). This is yet another in
Chris "ickle" Wilson's long series of error-handling cleanups during
the 1.5 series.

Avoid undesired clipping when drawing scaled surface patterns with
bilinear filtering.

cairo-pdf
---------
Fix emission of 1-bit alpha masks in PDF output.

Fix a bug that would cause glyphs to be misplaced along the Y axis:

    http://bugs.debian.org/cgi-bin/bugreport.cgi?bug=%23474136

    Originally, an issue about a crash, but later leading to the
    misplaced glyphs issue being discovered.

cairo-ps
--------
Fix misplaced glyphs in cairo's PostScript output.

    This issue occurs when consecutive glyphs are placed far
    apart. This case is exercised by the new ft-show-glyphs-table test
    case, which was originally inspired by the Debian bug #23474136
    mentioned above.

Fix more misplaced glyphs in cairo's PostScript output:

    The issue here showed up under very particular circumstance, (when
    converting a PDF file with a CFF font with CID Identity-H encoding
    and using glyph 0, (defined by the CFF specification as .notdef)
    as a space instead). More concretely, this problem appeared when
    converting the UbuntuDesktop.pdf file mentioned in this bug
    report:

https://bugs.freedesktop.org/show_bug.cgi?id=15348#c3

    As usual with arcane font-encoding-specific bugs like this, many
    thanks to Adrian Johnson for his magical ability to dive into
    specifications and emerge almost instantaneously with fixes. And
    thanks to Sebastien Bacher for bringing the bug to our attention.

cairo-xlib
----------
Fix serious failure on X servers without the Render extension.

    Since the 1.5.14 snapshot (with support for PseudoColor visuals),
    any application attempting to create a "similar" xlib surface would
    fail on an X server without the Render extension. Thanks to
    Frederic Crozat for pointing out that cairo's test suite was
    entirely failing when run against Xvfb.

Avoid crashing cairo-xlib applications for too-large glyphs

    Naively sending glyphs of any size to the X server will eventually
    violate the X limit on maximum request sizes. We now properly
    detect when a glyph would be too large and use existing fallbacks
    to render the glyph rather than trying to send it to the X server.

Enable the buggy_repeat workaround for Xorg servers < 1.4

    We have determined that Xorg 1.3.0 (as packaged in Fedora 8 at
    least) has a bug that can result in an X server crash when cairo
    uses certain X Render repeat operations, (as exercised by cairo's
    extend-reflect test). We avoid this crash by using fallbacks
    whenever a repeating surface is needed for any Xorg server with a
    version less than 1.4. This is slower, but should prevent the
    crash.

    (Meanwhile, there appears to be a separate bug where some X
    servers or specific X-server drivers will use random pixmap data
    when asked to draw a repeating surface. The buggy_repeat
    workaround would also avoid those problems, but we have not yet
    characterized whether the new "version < 1.4" is a good
    characterization of those problems or not.)

cairo-quartz-font
-----------------
Implement cairo_font_extents for this backend.

The cairo-quartz-font implementation added in the 1.5.14 snapshot was
entirely missing support for the cairo_font_extents function. Thanks to
Richard Hult for pointing out this obvious shortcoming, (and obvious
lack of coverage in our test suite):

CGFont backend returns 0 font extents
https://bugs.freedesktop.org/show_bug.cgi?id=15319
```
