---
title: cairo 1.12.12 release available
layout: news
date: 2013-01-31
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
To: cairo-announce@cairographics.org
Date: Thu, 31 Jan 2013 16:29:00 +0000

A new cairo release 1.12.12 is now available from:

http://cairographics.org/releases/cairo-1.12.12.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.12.tar.xz.sha1
8e597874da5b861287893d87dd4ab32471e99c82  cairo-1.12.12.tar.xz

http://cairographics.org/releases/cairo-1.12.12.tar.xz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.12 tag which points to a commit named:
a201a1169f472e822a66275b7dffe62f241d8ec0

    which can be verified with:
git verify-tag 1.12.12

    and can be checked out with a command such as:
git checkout -b build 1.12.12


Release 1.12.12 (2013-01-31 Chris Wilson <chris@chris-wilson.co.uk>)
====================================================================
The goal of this release is to fix the synchronisation problems that
were exhibited in the SHM transport for cairo-xlib. This cropped up
any place that tried to rapidly push fresh pixel data to the X server
through an ordinary image surface, such as gimp-2.9 and evince.

Bug fixes
---------

   Avoid replacing the entire image when uploading subimages
   https://bugs.freedesktop.org/show_bug.cgi?id=59635

   Force synchronisation for scratch SHM image buffers, so that we do
   not overwrite data as it is being read by X.
   https://bugs.freedesktop.org/show_bug.cgi?id=59635 (also)

   Fix typos in detecting multisampling for the GL (MSAA) backend.

   Fix a memory leak in the GL (MSAA) backend.

   Fix a reference counting bug when mapping a GL surface to an image.

Complete list of changes from 1.12.10 to 1.12.12
------------------------------------------------

Chris Wilson (22):
      version: Post-release bump to 1.12.11
      xlib: Do not upload the whole image just because we want an entire row
      image: Enable inplace compositing with opacities for general routines
      image: Fix opaque span fills
      Mark _cairo_path_is_simple_quad as private
      image: And more fallout from c986a73, restore the absent short runs
      perf; Do not allow the backends to optimize away the clear before sync
      xlib/shm: Tighten mark-active to the actual CopyArea on the ShmPixmap
      xlib/shm: Skip creating new SHM segments if the data is already in the xserver
      xlib/shm: Tidy creation of the proxy source for ShmPixmaps
      xlib/shm: Tidy up destroying the mempool for a shm block
      xlib/shm: Always request a CompletionEvent from ShmPutImage
      xlib/shm: Force synchronisation for scratch SHM image buffers
      xlib/shm: Simplify uploading of SHM image data
      xlib/shm: Appease the compiler for a 'maybe used uninitialised' variable
      configure: Include X11.h before testing for usability of Xrender.h
      xlib/shm: Clarify testing of seqno
      xlib/shm: More clarification of seqno required
      perf: Synchronize before stopping the timers
      image: Add a reference for the clone's parent image
      test: Refresh refs for aa noise following reduction of the 2-stage compositing
      1.12.12 release

Henry Song (5):
      gl: Don't query the display when checking if the context changed
      gl/msaa: Fix a memory leak in _clip_to_traps
      gl: Fix typos in multisampling detection
      gl: Use GL_ALPHA textures for CAIRO_CONTENT_ALPHA glyph caching
      gl/msaa: Don't emit alpha when emitting vertices

Martin Robinson (1):
      gl/msaa: Add a fast path for fills that are simple quads
```
