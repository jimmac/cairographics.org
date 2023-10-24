---
title: cairo 1.4.6 release available
layout: news
date: 2007-05-01
---

From: Carl Worth <cworth@cworth.org>
Date: 1 May 2007
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo release 1.4.6 now available

A new cairo release 1.4.6 is now available from:

        http://cairographics.org/releases/cairo-1.4.6.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.4.6.tar.gz.sha1
        bfd1532e10789fc4f87a196540c049d88c6ece42  cairo-1.4.6.tar.gz

        http://cairographics.org/releases/cairo-1.4.6.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.6 tag which points to a commit named:
        ddca8fec07ff95caeda6e4ce9efc3239b146bd2d

    which can be verified with:
        git verify-tag 1.4.6

    and can be checked out with a command such as:
        git checkout -b build 1.4.6

This is the third update in cairo's stable 1.4 series. It comes a
little less than three weeks since the 1.4.4 release. This release
fixes the broken mutex initialization that made cairo 1.4.4 unusable
on win32, OS/2, and BeOS systems. This release also adds significant
improvements to cairo's PDF backend, (native gradients!), and a couple
of performance optimizations, (one of which is very significant for
users of the xlib backend). See below for more details.

-Carl

Summary of changes from 1.4.4 to 1.4.6
======================================
Repaired mutex initialization
-----------------------------
We apologize that cairo 1.4.4 did little more than crash on many
platforms which are less-frequently used by the most regular cairo
maintainers, (win32, OS/2, and BeOS). The mutex initialization
problems that caused those crashes should be fixed now. And to avoid
similar problems in the future, we've now started posting pre-release
snapshots to get better testing, (subscribe to cairo@cairographics.org
if you're interested in getting notified of those and testing them).

PDF Improvements
----------------
Thanks to Adrian Johnson, (cairo PDF hacker extraordinaire), we have
several improvements to cairo's PDF backend to announce:

Native gradients:

  As of cairo 1.4.6, cairo will now generate native PDF gradients in
  many cases, (previously, the presence of a gradient on any page
  would force rasterized output for that page). Currently, only
  gradients with extend types of PAD (the default) or NONE will
  generate native PDF gradients---others will still trigger
  rasterization, (but look for support for other extend modes in a
  future release). Many thanks to Miklós Erdélyi as well, who did the
  initial work for this support.

Better compatibility with PDF viewers:

  The PDF output from cairo should now be displayed correctly by a
  wider range of PDF viewers. Adrian tested cairo's PDF output against
  many PDF viewers, identified a common bug in many of those viewers
  (ignoring the CTM matrix in some cases), and modified cairo's output
  to avoid triggering that bugs (pre-transforming coordinates and
  using an identity matrix).

Better OpenType/CFF subsetting:

  Cairo will now embed CFF and TrueType fonts as CID fonts.

Performance optimizations
-------------------------
Faster cairo_paint_with_alpha:

  The cairo_paint_with_alpha call is used to apply a uniform alpha
  mask to a pattern. For example, it can be used to gradually fade an
  image out or in. Jeff Muizelaar fixed some missing/broken
  optimizations within the implementation of this function resulting
  in cairo_paint_with_alpha being up to 4 times faster when using
  cairo's image backend.

Optimize rendering of "off-screen" geometry:

  Something that applications often do is to ask cairo to render
  things that are either partially or wholly outside the current clip
  region. Since 1.4.0 the image backend has been fixed to not waste
  too much time in this case. But other backends have still been
  suffering.

  In particular, the xlib backend has often performed quite badly in
  this situation. This is due to a bug in the implementation of
  trapezoid rasterization in many X servers.

  Now, in cairo 1.4.6 there is a higher-level fix for this
  situation. Cairo now eliminates or clips trapezoids that are wholly
  or partially outside the clip region before handing the trapezoids
  to the backend. This means that the X server's performance bug is
  avoided in almost all cases.

  The net result is that doing an extreme zoom-in of vector-based
  objects drawn with cairo might have previously brought the X server
  to its knees as it allocated buffers large enough to fit all of the
  geometry, (whether visible or not). But now the memory usage should
  be bounded and performance should be dramatically better.

Miscellaneous
-------------
Behdad contributed an impressively long series of changes that
organizes cairo's internals in several ways that will be very
beneficial to cairo developers. Thanks, Behdad!

Behdad has also provided a utility for generating malloc statistics,
(which was used during the great malloc purges of 1.4.2 and
1.4.4). This utility isn't specific to cairo so may be of benefit to
others. It is found in cairo/util/malloc-stats.c and here are Behdad's
notes on using it:

    To build, do:

        make malloc-stats.so

    inside util/, and to use, run:

        LD_PRELOAD=malloc-stats.so some-program

    For binaries managed by libtool, eg, cairo-perf, do:

        ../libtool --mode=execute /bin/true ./cairo-perf
        LD_PRELOAD="../util/malloc-stats.so" .libs/lt-cairo-perf

Finally, the cairo-perf-diff-files utility was enhanced to allow for
generating performance reports from several runs of the same backend
while some system variables were changed. For example, this is now
being used to allow cairo-perf to measure the performance of various
different acceleration architectures and configuration options of the
X.org X server.
