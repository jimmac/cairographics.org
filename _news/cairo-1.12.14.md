---
title: cairo 1.12.14 release available
layout: news
date: 2013-02-10
---

From: Chris Wilson <chris@chris-wilson.co.uk>
To: cairo-announce@cairographics.org
Date: Sun, 10 Feb 2013 14:15:00 +0000

A new cairo release 1.12.14 is now available from:

http://cairographics.org/releases/cairo-1.12.14.tar.xz

    which can be verified with:

http://cairographics.org/releases/cairo-1.12.14.tar.xz.sha1
9106ab09b2e7b9f90521b18dd4a7e9577eba6c15  cairo-1.12.14.tar.xz

http://cairographics.org/releases/cairo-1.12.14.tar.xz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.12.14 tag which points to a commit named:
0dac37c41473deafa4a2f154187c5c3d08b07c91

    which can be verified with:
git verify-tag 1.12.14

    and can be checked out with a command such as:
git checkout -b build 1.12.14

Release 1.12.14 (2013-02-10 Chris Wilson <chris@chris-wilson.co.uk>)
====================================================================
In the last week we had a few more bugs reported and promptly resolved.
As these are a combination of regressions and stability issues, it is
time for a prompt update and release. Many thanks to everyone for
testing and reporting issues, and helping to make Cairo better.

Bug fixes
---------

  Prevent user callbacks accessing user-data during destroy to prevent
  use-after-free bugs.
  https://bugzilla.mozilla.org/show_bug.cgi?id=722975

  Use standard names for glyphs in subset fonts (PDF).
  https://bugs.freedesktop.org/show_bug.cgi?id=60248

  Fix detection of Win98. The logic for detecting Win98 (and its broken
  AlphaBlend()) was inverted, disabling AlphaBlend() for everyone.

  Prevent numeric overflow from extrapolating polygon edges to the clip
  boundary and causing severe render artifacts.
  https://bugs.freedesktop.org/show_bug.cgi?id=60489

  Fix computation of glyph string coordinates when breaking up runs
  for xlib.

  Fix an assertion in the win32 backend for failing to clear its
  similar-images.
  https://bugs.freedesktop.org/show_bug.cgi?id=60519

