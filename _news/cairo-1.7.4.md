---
title: cairo 1.7.4 snapshot available
layout: news
date: 2008-08-11
---
```

From: Behdad Esfahbod <behdad@behdad.org>
Date: Mon, 11 Aug 2008 15:25:44 -0400 (12:25 PDT)
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.7.4 now available

A new cairo snapshot 1.7.4 is now available from:

        http://cairographics.org/snapshots/cairo-1.7.4.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.7.4.tar.gz.sha1
        c2b139a11336bf1c7a3423baff12ba949269a36b  cairo-1.7.4.tar.gz

        http://cairographics.org/snapshots/cairo-1.7.4.tar.gz.sha1.asc
        (signed by Behdad Esfahbod)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.7.4 tag which points to a commit named:
        012a12a67b66f3809fa203f91ff8920936c25361

    which can be verified with:
        git verify-tag 1.7.4

    and can be checked out with a command such as:
        git checkout -b build 1.7.4

Release 1.7.4 (2008-08-11 Behdad Esfahbod <behdad@behdad.org>)
==============================================================
The cairo community is embarrassed to announce availability of the 1.7.4
snapshot of the cairo graphics library.  This is a followup release to the
1.7.2 snapshot to ship a tarball that can actually be built.  The only
change since 1.7.4 is including the missing header file
cairo-user-font-private.h in the distribution.
```
