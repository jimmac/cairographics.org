---
title: cairo 1.9.6 snapshot available
layout: news
date: 2010-02-19
---
```

From: Carl Worth <cworth@cworth.org>
Date: Fri, 19 Feb 2010 17:56:14 -0800
To: cairo-announce@cairographics.org
Subject: cairo snapshot 1.9.6 now available

A new cairo snapshot 1.9.6 is now available from:

        http://cairographics.org/snapshots/cairo-1.9.6.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.9.6.tar.gz.sha1
        0e204b2c4f062dc65c1b854d4b1ccf360f3cb255  cairo-1.9.6.tar.gz

        http://cairographics.org/snapshots/cairo-1.9.6.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.9.6 tag which points to a commit named:
        cb090136b2b0b89bde69d9575f2f592b46e144e8

    which can be verified with:
        git verify-tag 1.9.6

    and can be checked out with a command such as:
        git checkout -b build 1.9.6

We're happy to share this snapshot of recent cairo development. We
apologize that it has been so long since the last snapshot, (snapshot
1.9.4 was 4 months ago), but we are optimistic that we can finish up
cairo 1.10 in the next month or so. Our goal going forward is to have
major cairo releases on a time-based schedule with releases at the end
of every March and September (or so).

This 1.9.6 snapshot is really exactly that---it's a snapshot of current
development. There hasn't been as much testing through the test suite as
we would normally do for a cairo release. But that's what we'll be doing
From now until cairo 1.10. We also hope that many of you will also test
this snapshot with your cairo applications and report back to us.

One of the most exciting things in the 1.9.6 snapshot is the cairo-gl
backend with dramatic improvements compared to cairo-gl in any previous
snapshots, (it's now using shaders to accelerate many operations). See
Eric's post here for some performance numbers:

        http://anholt.livejournal.com/42146.html

and please join me in thanking Eric and T. Zachary Laine (a welcome new
contributor!) for this work.

As usual, Chris Wilson has put in a remarkable amount of effort as
reflected in this snapshot. I give him my heartfelt thanks for keeping
cairo so vibrant while I have not been able to give it much personal
attention lately.

This snapshot also includes the cairo-drm backend worked on by Chris
Wilson and Kristian Høgsber. This is another interesting experimental
backend which currently outperforms cairo-gl in several benchmarks, (and
sets the bar for cairo-gl to reach). This direct-rendering backend only
support Intel graphics chipsets in the i915 and i965 families.

I've written a quick summary of other improvements in 1.9.6 below. I've
certainly missed many interesting things that have been done. If you are
aware of interesting work that I neglected, please let me know so that
we can get that work mentioned for the 1.10 release notes. (Best would
be a patch to the NEWS file adding the information).

I hope that everyone will have lots of fun with cairo!

-Carl

API additions
-------------
    Add cairo_device_t

    The device is a generic method for accessing the underlying interface
    with the native graphics subsystem, typically the X connection or
    perhaps the GL context. By exposing a cairo_device_t on a surface and
    its various methods we enable finer control over interoperability with
    external interactions of the device by applications. The use case in
    mind is, for example, a multi-threaded gstreamer which needs to serialise
    its own direct access to the device along with Cairo's across many
    threads.

    Secondly, the cairo_device_t is a unifying API for the mismash of
    backend specific methods for controlling creation of surfaces with
    explicit devices and a convenient hook for debugging and introspection.

    The principal components of the API are the memory management of:

      cairo_device_reference(),
      cairo_device_finish() and
      cairo_device_destroy();

    along with a pair of routines for serialising interaction:

      cairo_device_acquire() and
      cairo_device_release()

    and a method to flush any outstanding accesses:

      cairo_device_flush().

    The device for a particular surface may be retrieved using:

      cairo_surface_get_device().

    The device returned is owned by the surface.

API changes (to API new in the cairo 1.9.x series)
--------------------------------------------------
  cairo_recording_surface_create()
  cairo_recording_surface_ink_extents()

    These are the replacement names for the functions previously named
    cairo_meta_surface_create and cairo_meta_surface_ink_extents.

  cairo_surface_set_mime_data

    This interface is now changed such that the MIME data will be
    detached if the surface is modified at all. This guarantees that
    the MIME data will not become out of synch due to surface
    modifications, and also means that for the MIME data to be useful,
    it must be set after all modifications to the surface are
    complete.

API removal (of experiment API)
-------------------------------
  The cairo-glitz backend is removed entirely, (in favor of the new
  cairo-gl backend). See below for more on cairo-gl.

Generic fixes
-------------

  Many improvements for drawing of dashed strokes

        Fix incorrect handling of negative offset
        Faster computation of first dash (avoids near-infinite looping)
        Approximate extremely fine dash patterns with appropriate alpha value

  Optimize spans-based renderers for repeated rows, (such as in a rounded rectangle)

Backend-specific improvements
-----------------------------
cairo-drm

  This is a new, direct-rendering backend that supports Intel graphics
  chipsets in the i915 and i965 families. It's still experimental and
  will likely remain that way for a while. It's already got extremely
  good performance on the hardware it supports, so if nothing else
  provides a working proof and performance target for the cairo-gl
  work for Intel graphics.

cairo-gl

  Start using GLSL to accelerate many operations. Many thanks to Eric
  Anholt and T. Zachary Laine for this work. For the first time, we
  have what looks like what will be a very compelling OpenGL-based
  backend for cairo (in terms of both quality and performance).

  See this writeup from Eric for more details on recent progress of
  cairo-gl (which he presented at FOSDEM 2010):

        http://anholt.livejournal.com/42146.html

cairo-image

  The image backend is made dramatically faster (3-5 times faster for
  benchmarks consisting primarily of glyph rendering).

cairo-quartz fixes:

  Many fixes from Robert O'Callahan and Andrea Canciani including:

        Fixed gradient pattern painting
        Improved A8 image handling
        Fixes for "unbounded" and other compositing operators

cairo-pdf fixes:

  Improvements to embedding of JPEG and JPEG2000 data.

cairo-ps fixes:

  Fix printing of rotated user fonts.
```
