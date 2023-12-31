---
title: cairo 1.12.6 release available
layout: news
date: 2012-10-22
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Mon, 22 Oct 2012 14:22:00 +1000
To: cairo-announce@cairographics.org

A new cairo release 1.12.6 is now available from:

http://cairographics.org/releases/cairo-1.12.6.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.6.tar.xz.sha1
a383c6cb4495e18848ea43e1031c294aa9417a43  cairo-1.12.6.tar.xz

http://cairographics.org/releases/cairo-1.12.6.tar.xz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.6 tag which points to a commit named:
fab6958eff35a94cf46e38f19a7e75e10aa2b182

    which can be verified with:
git verify-tag 1.12.6

    and can be checked out with a command such as:
git checkout -b build 1.12.6

Release 1.12.6 (2012-10-22 Chris Wilson <chris@chris-wilson.co.uk>)
===================================================================
Thanks to everyone who download cairo-1.12.4 and gave us their feedback.
It truly was invaluable and has helped us to fix many portability issues
that crept in with some of the new features. This release aims to fix
those stability issues and run on a wider range of systems.
-Chris

Bug fixes
---------

  Fix the recording surface to actually snapshot the source and so fix
  PDF drawing.

  Calling XSendEvent with an XShmCompletionEvent is incompatabile with
  older Xorg servers.

  Reorder CloseDisplay chain so that XShm is not reinstantiated after
  shutdown, causing a potential crash if the Display was immediately
  recreated using the same memory address.

  Make sure that the Xserver has attached to the SHM segment before
  deleting it from the global namespace on systems that do not support
  deferred deletion.

  Type1 subsetting support for PDF (and PS) was once again improved to
  work with a larger number of PDF readers.

  GLESv2 build fixes and improved support for embedded GPUs.

  Tweak the invisible pen detection for applications that are currently
  using too large values for geometric tolerance.

  A build fix for older freetype libraries.

Complete list of changes since 1.12.4
-------------------------------------

Adrian Johnson (2):
      type1: convert '.' to locale specific decimal point before using sscanf
      remove debug code

Alexis Ballier (2):
      cairo-fdr: protect -ldl link with CAIRO_HAS_DL like in cairo-trace.
      cairo-sphinx: protect -ldl link with CAIRO_HAS_DL like in cairo-trace.

Chris Wilson (11):
      version: Post release bump to 1.12.5
      xlib/shm: Avoid using XSendEvent with old versions of Xorg
      xlib/shm: Note the bug is an interaction between libXext and xorg
      win32: Use the image surface below the fallback when unmapping an HDC
      compositor: Reduce glyph "overlap" if the inked pixels are opaque
      xlib: Reorder CloseDisplay hooks
      recording: Copy across the is-clear? during snapshotting
      xlib/shm: Sync the XShmAttach before removing the ShmSegment id
      pen: Relax invisibility criteria from half-tolerance to quarter-tolerance
      1.12.6 release
      version: Post release bump to 1.12.7

David Maxwell (3):
      type1: buildchar stack fix
      type1: lenIV support
      type1-subset: always subset subroutines 0-3 (Flex/hint replacement)

Gilles Espinasse (3):
      ft: Fix compilation on 1.12 without FT_Get_X11_Font_Format
      configure: fix PKG_CHECK_MODULES tests displaying no no
      configure: fix unrecognized -Wno option

Henry Song (3):
      gl: gles2 only supports GL_DEPTH24_STENCIL8_OES
      gl/traps: ensure RGBA surface before upload image to texture for GLES2
      recording: copy reverses its dst and src parameters

Uli Schlachter (2):
      xcb: Clear the result of create_similar_image
      test: Define optional exception classes
```
