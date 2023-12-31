---
title: cairo 1.12.8 release available
layout: news
date: 2012-11-04
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Sun, 4 Nov 2012 15:40:51 +0000
To: cairo-announce@cairographics.org

A new cairo release 1.12.8 is now available from:

http://cairographics.org/releases/cairo-1.12.8.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.8.tar.xz.sha1
56a10bf3b804367c97734d655c23a9f652d5c297  cairo-1.12.8.tar.xz

http://cairographics.org/releases/cairo-1.12.8.tar.xz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.8 tag which points to a commit named:
cc162915a55cc67587677352bd9e389f16117853

    which can be verified with:
git verify-tag 1.12.8

    and can be checked out with a command such as:
git checkout -b build 1.12.8

Release 1.12.8 (2012-11-24 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
Another couple of weeks and a few more bugs have been found and fixed,
it is time to push the next point release. Many thanks to everyone who
reported their issues and helped us track down the bugs and helped
testing the fixes.

Bug fixes
---------

  Expand the sanity checking for broken combinations of XSendEvent and
  ShmCompletionEvent.

  Notice that "The X.Org Foundation" sometimes also identifies itself
  as "The Xorg Foundation".

  Handle various ages of libXext and its Shm headers.

  Fix the invalid clipping of the source drawable when using SHM
  transport to upload images.
  https://bugs.freedesktop.org/show_bug.cgi?id=56547

  Handle all Type1 postscript operators for better font compatibility.
  https://bugs.freedesktop.org/show_bug.cgi?id=56265

  Fix a couple of memory leaks in Type1 font subsetting
  https://bugs.freedesktop.org/show_bug.cgi?id=56566

  Tighten the evaluation of the start/stop pen vertices, and catch a few
  instances where we would use a fan instead of a bevel.
  https://bugs.freedesktop.org/show_bug.cgi?id=56432

  Fix assumption that geometric clipping always succeeds with the
  span-compositor.
  https://bugs.freedesktop.org/show_bug.cgi?id=56574

  Fix call to spline intersection when evaluating whether a stoke is
  visible.

  Remember to copy inferior sources when using SHM to readback the
  surface for use as a source.

Complete list of changes since 1.12.6
-------------------------------------

Adrian Johnson (5):
      type1-subset: parse all operators
      type1-subset: restore correct callothersub behavior
      type1-subset: ensure subroutine numnber is an integer
      type1-subset: fix memory leak
      type1-subset: remove unused variable

Chris Wilson (19):
      version: Post release bump to 1.12.7
      xlib/shm: Sanity check that the server handles XSendEvent with ShmCompletion
      xlib: Check for both X.org and Xorg ServerVendors
      xlib/shm: Check for XShm headers
      xlib/shm: Use shmstr.h instead of shmproto.h if available
      xlib: Apply the image offsets to the destination rather the source
      pen: First check whether the in/out edges lie within the single pen vertex
      xlib/shm: Fix bogus assertion without shm available
      image: Add a couple of tracepoints for spans fallbacks
      stroke: Precompute the line half-width
      util/show-polygon: Show the limited range of each edge
      spans: Do not assume that we manage to perform the clip geometrically
      xlib: Fixup standalone header compilation for 'make check'
      gl: Tune the default VBO size to reduce overhead on embedded devices
      pen: Tighten checking for bevel (start==stop) joins
      test: Add stroke-clipped
      stroke: Fix calling '_cairo_spline_intersect' for in-bounds checking of splines
      xlib/shm: Need IncludeInferiors when creating the source fallback
      1.12.8 release

Kevin Tardif (1):
      type1-subset, cff-subset: Plugged 2 memory leaks
```
