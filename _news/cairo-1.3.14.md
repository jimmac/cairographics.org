---
title: cairo 1.3.14 snapshot available
layout: news
date: 2007-02-13
---
```

From: Carl Worth <cworth@cworth.org>
Date: 13 Feb 2007
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.3.14 now available

A new cairo snapshot 1.3.14 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.14.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.14.tar.gz.sha1
        648981b1e04eb231a82befea8eaf39e01502001c  cairo-1.3.14.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.14.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.14 tag which points to a commit named:
        90e453fc22398f31996a6fdbeec6da98e25a160e

    which can be verified with:
        git verify-tag 1.3.14

    and can be checked out with a command such as:
        git checkout -b build 1.3.14

This is the seventh development snapshot in the 1.3 series, (and there
likely won't be many more before the 1.4.0 release). It comes just
over 3 weeks after the 1.3.12 snapshot.

Since we're so close to the 1.4.0 release, there are not a lot of new
features nor even a lot of new performance improvements in this
snapshot. Instead, there are a great number of bug fixes. Some are
long-standing bugs that we're glad to say goodbye to, and several are
fixes for regressions that were introduced as part of the optimization
efforts during the 1.3.x series.

Major improvements between 1.3.12 and 1.3.14
============================================
PDF text selection fixed
------------------------
The inability to correctly select text in cairo-generated PDF has been
a defect ever since the initial support for the PDF backend in the
cairo 1.2.0 release. With the 1.3.14 snapshot, in most situations, and
with most PDF viewer applications, the PDF generated by cairo will
allow text to be correctly selected for copy-and-paste, (as well as
searching).

We're very excited about this new functionality, (and very grateful to
Adrian Johnson, Behdad Esfahbod, and others that have put a lot of
work into this lately). Please test this new ability and give feedback
on the cairo@cairographics.org list.

Many thread-safety issues fixed
-------------------------------
We've discovered that no release of cairo has ever provided safe text
rendering from a multi-threaded application. With the 1.3.14 snapshot
a huge number of the bugs in this area have been fixed, and multiple
application developers have now reported success at writing
multi-threaded applications with cairo.

Other fixes
-----------
Fixed a bug that was causing glyph spacing to be 32 times larger than
desired when using cairo-win32.

Fixed a regression in the rendering of linear gradients that had been
present since the 1.3.8 snapshot.

Fixed several problems in cairo-atsui that were leading to assertion
failures when rendering text.

Fix corrupted results when rendering a transformed source image
surface to an xlib surface. This was a regression that had been
present since the 1.3.2 snapshot.

Fixed PDF output to prevent problems printing from some versions of
Acrobat Reader, (a single glyph was being substituted for every
glyph).

And many other fixes as well, (see the logs for details).
```