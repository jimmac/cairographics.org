---
title: cairo 1.9.4 snapshot available
layout: news
date: 2009-10-15
---

From: Carl Worth <cworth@cworth.org>
Date: Thu, 15 Oct 2009 16:34:18 -0700
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.9.4 now available

A new cairo snapshot 1.9.4 is now available.

This is a slightly more "raw" snapshot than many we've done in the
past. But it's been over 4 months since the last cairo snapshot, and
cairo internals have been shaken up quite a bit since then, (thanks,
Chris!).

We hope that most of the fallout from the big rewrites is over now,
(such as a recent fix to prevent WebKit from misrendering images). But
we are aware that some bugs still remain, (such as issues with images
in PDF output as well as PS and EPS page sizes).

As you encounter any major bugs, please ensure that the bugs are
listed as dependencies of the following tracker bug so that we will be
sure to fix them before the cairo 1.10 release:

http://bugs.freedesktop.org/show_bug.cgi?id=cairo-1.10

And of course, as with all cairo snapshots (as opposed to "releases"),
any API that is new in cairo 1.9 compared to 1.8 is subject to
change. (For example, I'm not totally happy with the
cairo_gl_surface_create functions so they might be changing.)

Please have fun with cairo, everyone!

-Carl

Where to obtain cairo 1.9.4
---------------------------
  http://cairographics.org/snapshots/cairo-1.9.4.tar.gz

    which can be verified with:

    http://cairographics.org/snapshots/cairo-1.9.4.tar.gz.sha1
    144d80cf01758a0f048b149b4c54aa792e401ae3  cairo-1.9.4.tar.gz

    http://cairographics.org/snapshots/cairo-1.9.4.tar.gz.sha1.asc
    (signed by Carl Worth)

  Additionally, a git clone of the source tree:

  git clone git://git.cairographics.org/git/cairo

    will include a signed 1.9.4 tag which points to a commit named:
    ad6334b9870c63e641b531d6e910c084b587d0f9

    which can be verified with:
    git verify-tag 1.9.4

    and can be checked out with a command such as:
    git checkout -b build 1.9.4


What's new in cairo 1.9.4 (compared to cairo 1.9.2)
===========================
API additions:

  cairo_meta_surface_create()
  cairo_meta_surface_ink_extents()

    Finally exporting the internal meta-surface so that applications
    have a method to record and replay a sequence of drawing commands.

  cairo_in_clip()

    Determines whether a given point is inside the current clip.
    ??? Should this be called cairo_in_paint() instead? in-clip is the test
    that is performed, but in-paint would be similar to in-fill and in-stroke.

New utilities:

  cairo-test-trace

    A companion to cairo-perf-trace, this utility replays a trace against
    multiple targets in parallel and looks for differences in the output,
    and then records any drawing commands that cause a failure.
    Future plans:
      Further minimisation of the fail trace using "delta debugging".
      More control over test/reference targets.

Backend improvements:

  xlib

     Server-side gradients. The theory is that we can offload computation
     of gradients to the GPU and avoid pushing large images over the
     connection. Even if the driver has to fallback and use pixman to render
     a temporary source, it should be able to do so in a more efficient manner
     than Cairo itself. However, cairo-perf suggests otherwise:

     On tiny, Celeron/i915:

      before: firefox-20090601 211.585
       after: firefox-20090601 270.939

     and on tiger, CoreDuo/nvidia:

      before: firefox-20090601 70.143
       after: firefox-20090601 87.326

     In particular, looking at tiny:

     xlib-rgba paint-with-alpha_linear-rgba_over-512   47.11 (47.16 0.05%) -> 123.42 (123.72 0.13%):  2.62x slowdown
     █▋
     xlib-rgba paint-with-alpha_linear3-rgba_over-512   47.27 (47.32 0.04%) -> 123.78 (124.04 0.13%):  2.62x slowdown
     █▋


New experimental backends:

   QT

   OpenVG - The initial work was done by Øyvind Kolås, and made ready for
            inclusion by Pierre Tardy.

   OpenGL - An advanced OpenGL compositor. The aim is to write a integrate
            directed rendering using OpenGL at a high-level into Cairo. In
    contrast to the previous attempt using Glitz which tried to
    implement the RENDER protocol on top of OpenGL, using the
    high-level interface should permit greater flexibility and
    more offloading onto the GPU.
    The initial work on the backend was performed by Eric Anholt.

Long standing bugs fixed:

  Self-intersecting strokes.

    A long standing bug where the coverage from overlapping semi-opaque
    strokes (including neighbouring edges) was simply summed in lieu of
    a costly global calculation has been fixed (by performing the costly
    global calculation!) In order to mitigate the extra cost, the
    tessellator has been overhauled and tune, which handles the fallback
    for when we are unable to use the new span rasteriser on the stroke
    (e.g. when using the current RENDER protocol). The large number of
    pixel artefacts that implementing self-intersection elimination
    removes is ample justification for the potential performance
    regression. If you unfortunately do suffer a substantial performance
    regression in your application, please consider obtaining a
    cairo-trace and submitting it to us for analysis and inclusion into
    our performance suite.

Special thanks:

   To the AuroraUX team for providing access to one of their OpenSolaris
   machines for cairo and pixman development.  http://www.auroraux.org/
