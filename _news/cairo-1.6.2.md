---
title: cairo 1.6.2 release available
layout: news
date: 2008-04-11
---
```

From: Carl Worth <cworth@cworth.org>
Date: Fri, 11 Apr 2008 10:24:54 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo release 1.6.2 now available

The cairo community is pleased (but somewhat sheepish) to announce the
1.6.2 release of the cairo graphics library. This is an update to
yesterday's 1.6.0 release with an important fix to prevent cairo's
PostScript output from crashing some printers. This release also
includes a locking fix for cairo's xlib backend to improve thread
safety. There are no changes beyond these two fixes. See below for
more details.

Have fun with cairo!

-Carl

Release 1.6.2 (2008-04-11 Carl Worth <cworth@cworth.org>)
=========================================================
A new cairo release 1.6.2 is now available from:

        http://cairographics.org/releases/cairo-1.6.2.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.6.2.tar.gz.sha1
        5b69fcab20c442df132515c1bfe10b9525f66de0  cairo-1.6.2.tar.gz

        http://cairographics.org/releases/cairo-1.6.2.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.6.2 tag which points to a commit named:
        5bc6fd71398f8aa902fcffe2da5d1e70fb94aa8a

    which can be verified with:
        git verify-tag 1.6.2

    and can be checked out with a command such as:
        git checkout -b build 1.6.2

Summary of changed from cairo 1.6.0 to 1.6.2
============================================

Fix for PostScript printer crash
--------------------------------
Adrian Johnson discovered that cairo 1.6.0 was being a bit hard on
PostScript printers, by changing the font matrix very frequently. This
causes some PostScript interpreters to allocate new font objects every
few glyphs, eventually exhausting available resources. The fix
involves leaving translational components of the font matrix as zero,
so that the PostScript interpreter sees an identical font matrix
repeatedly, and can more easily share internal font object resources.

This fix has been tested to resolve the bugs posted here, (for both
Xerox and Dell printers):

Printing some PDFs from evince is crashing our Xerox printer
http://bugs.freedesktop.org/show_bug.cgi?id=15348

Cairo-generated postscript blocks Dell 5100cn
http://bugs.freedesktop.org/show_bug.cgi?id=15445

Add missing locking in cairo-xlib
---------------------------------
Chris Wilson noticed that cairo 1.6.0 was manipulating an internal
cache of GC object within cairo's Xlib backend without proper
locking. The missing locking could cause failures for multi-threaded
applications. He fixed this in 1.6.2 by adding the missing locks.

Log of all commits from cairo 1.6.0 to 1.6.2
============================================
Adrian Johnson (1):
      PS: Fix inefficient implementation of Tm/Td operators that was
      crashing printers

Carl Worth (3):
      Increment version to 1.6.1 after 1.6.0 release
      NEWS: Add notes for 1.6.2 release
      Increment version to 1.6.2

Chris Wilson (1):
      [xlib] Add locking around GC cache.
```
