---
title: cairo 1.1.10 snapshot available
layout: news
date: 2006-06-16
---
```

From: Carl Worth <cworth@cworth.org>
Date: 16 Jun 2006
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo snapshot 1.1.10 now available

A new cairo snapshot 1.1.10 is now available from:

        http://cairographics.org/snapshots/cairo-1.1.10.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.1.10.tar.gz.sha1
        709d48dbcd0ac806e4f7bfd1f69314e4dfb57329  cairo-1.1.10.tar.gz

        http://cairographics.org/snapshots/cairo-1.1.10.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.1.10 tag which points to a commit named:
        65e73c81b83222de873935cf384e514ea20ac854

    which can be verified with:
        git verify-tag 1.1.10

    and can be checked out with a command such as:
        git checkout -b build 1.1.10

Snapshot 1.1.10 (2006-06-16 Carl Worth <cworth@cworth.org>)
===========================================================
This is the fifth in a series of snapshots working toward the 1.2
release of cairo.

The primary motivation for this snapshot is to fix a long-standing bug
that had long been silent, but as of the 1.1.8 snapshot started
causing crashes when run against 16-bit depth X servers, (often Xvnc
or Xnest). The fix for this adds a new CAIRO_FORMAT_RGB16_565 to the
API.

This snapshot also includes a rewrite of cairo's SVG backend to
eliminate the dependency on libxml2. With this in place, cairo 1.2
will not depend on any libraries that cairo 1.0 did not.

As usual, there are also a few fixes for minor bugs.
```
