---
title: cairo 1.0.2 released
layout: news
date: 2005-10-03
---
```

2005-10-03:

The cairo team is very pleased to announce cairo 1.0.2 available from:

        http://cairographics.org/releases/cairo-1.0.2.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.0.2.tar.gz.sha1
        3a425049499b0b067ed4dc60d94b4d0819c0841b  cairo-1.0.2.tar.gz

        http://cairographics.org/releases/cairo-1.0.2.tar.gz.sha1.asc
        (signed by Carl Worth)

This is a maintenance (bug-fix only) release in the cairo 1.0 series.
It is the first such release since 1.0.0. (There is no 1.0.1 release
since that number was used during the development between 1.0.0 and
1.0.2.)

This release maintains source and binary compatibility with cairo
1.0.0.

We'd like to give particular thanks to the many individuals who have
tested cairo since 1.0.0, (and turned up a fair number of bugs). The
names of a few of these helpful individuals are listed in the bug
detail below, but there are certainly many more unmentioned. Thanks to
everyone that has helped make this release so solid!

Three fixes in the 1.0.2 release deserve particular mention:

 * Dashed curves
        This is the first release of cairo to provide support for
        dashed curves (splines and arcs).

 * Better support for multi-thread applications
        Many bugs were fixed in the locking of text operations, and
        this is the first release to provide locking primitives on
        win32. More testing of multi-threaded applications with the
        1.0.2 release would be greatly appreciated.

 * Many win32 compilation and rendering fixes
        Many of these fixes can be credited to the Mozilla SVG
        community of developers and testers which has given
        cairo-win32 a much-needed shakedown. Thanks!

More details on other bugs fixed can be seen in the detailed list
below.

Have fun with cairo!

-Carl

What is cairo
=============
Cairo is a 2D graphics library with support for multiple output
devices. Currently supported output targets include the X Window
System, win32, and image buffers. Experimental backends include OpenGL
(through glitz), Quartz, XCB, PostScript and PDF file output.

Cairo is designed to produce consistent output on all output media
while taking advantage of display hardware acceleration when available
(for example, through the X Render Extension).

The cairo API provides operations similar to the drawing operators of
PostScript and PDF. Operations in cairo including stroking and filling
cubic Bézier splines, transforming and compositing translucent images,
and antialiased text rendering. All drawing operations can be
transformed by any affine transformation (scale, rotation, shear,
etc.).

Cairo has been designed to let you draw anything you want in a modern
2D graphical user interface.  At the same time, the cairo API has been
designed to be as fun and easy to learn as possible. If you're not
having fun while programming with cairo, then we have failed
somewhere---let us know and we'll try to fix it next time around.

Cairo is free software and is available to be redistributed and/or
modified under the terms of either the GNU Lesser General Public
License (LGPL) version 2.1 or the Mozilla Public License (MPL) version
1.1.

Where to get more information about cairo
=========================================
The primary source of information about cairo is:

        http://cairographics.org/

The latest releases of cairo can be found at:

        http://cairographics.org/releases

Snapshots of in-development versions of cairo:

        http://cairographics.org/snapshots

The programming manual for using cairo:

        http://cairographics.org/manual

Mailing lists for contacting cairo users and developers:

        http://cairographics.org/lists

Answers to some frequently asked questions about cairo:

        http://cairographics.org/FAQ

Bug fixes in 1.0.2 since 1.0.0
==============================
For each bug number XXXX below, see:

        https://bugs.freedesktop.org/show_bug.cgi?id=XXXX

for more details.

General bug fixes
-----------------
 * 4408 - Add support for dashing of stroked curves
          (Carl Worth)

 * 4409 - Fix dashing so that each dash is capped on both ends
          (Carl Worth)

 * 4414 - Prevent SIGILL failures (proper use of -mmmx and -msse flags)
          (Sebastien Bacher, Billy Biggs)

 * 4299 - Fix crashes with text display in multi-threaded program
          (Alexey Shabalin, Carl Worth)

 * 4401 - Do not use sincos function since it is buggy on some platforms)
          (Tim Mooney, Carl Worth)

 * 4245 - Fix several bugs in the test suite exposed by amd64 systems
          (Seemant Kulleen, Carl Worth)

 * 4321 - Add missing byteswapping on GetImage/PutImage
          (Sjoerd Simons, Owen Taylor)

 * 4220 - Make the check for rectangular trapezoids simpler and more accurate
          (Richard Stellingwerff, Owen Taylor)

 * 4260 - Add missing channel-order swapping for antialiased fonts
          (Barbie LeVile, Owen Taylor)

 * 4283 - Fix compilation failure with aggressive inlining (gcc -O3)
          (Marco Manfredini, Owen Taylor)

 * 4208 - Fix some warnings from sparse
          (Kjartan Maraas, Billy Biggs)

 * 4269 - Fix to not crash when compiled with -fomit-frame-pointer
          (Ronald Wahl, Owen Taylor)

 * 4263 - Improve performance for vertical gradients
          (Richard Stellingwerff, Owen Taylor)

 * 4231
 * 4298 - Accommodate gentoo and Mandriva versions in X server vendor string check
          (Billy Biggs, Frederic Crozat, Owen Taylor)

win32-specific fixes
--------------------
 * 4599 - Fix "missing wedges" on some stroked paths (win32)
          (Tim Rowley, Jonathan Watt, Bertram Felgenhauer, Carl Worth, Keith Packard)

 * 4612 - Fix disappearing text if first character out of surface (win32)
          (Tim Rowley)

 * 4602 - Fix shutdown of cairo from failing intermediate, size-0 bitmaps (win32)
          Aka. the "white rectangles" bug from mozilla-svg testing
          (Tim Rowley)

 * Various portability improvements for win32
          (Hans Breuer, Owen Taylor, Carl Worth)

 * 4593 - Fix font sizes to match user expectations (win32)
          (Tor Lillqvist, Owen Taylor)

 * 3927 - Fix to report metrics of size 0 for glyph-not-available (win32)
          (Hans Breuer, Owen Taylor, Tor Lillqvist)

 * Add locking primitives for win32
          (Hans Breuer)

xlib-specific fixes
-------------------
 * Fix crash from size-0 pixmap due to empty clip region (xlib)
          (Radek Doulík, Carl Worth)
```
