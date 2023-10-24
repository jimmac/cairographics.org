---
title: cairo 1.4.0 release available
layout: news
date: 2007-03-06
---

From: Carl Worth <cworth@cworth.org>
Date: 6 Mar 2007
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo release 1.4.0 now available

A new cairo release 1.4.0 is now available from:

        http://cairographics.org/releases/cairo-1.4.0.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.4.0.tar.gz.sha1
        2ce727347d8285cee4ce0c3feb0a2df18316a5d3  cairo-1.4.0.tar.gz

        http://cairographics.org/releases/cairo-1.4.0.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.4.0 tag which points to a commit named:
        5dfa8c23f13f5cafac5cf56f34888a6e01dc79ba

    which can be verified with:
        git verify-tag 1.4.0

    and can be checked out with a command such as:
        git checkout -b build 1.4.0

The many people[*] who have been working hard on cairo are very
pleased to announce the long-awaited release of cairo 1.4. This
release comes 4 months after the last stable update release (1.2.6)
and 9 months since the initial release of 1.2.0.

The release notes below are intended to capture the highlights of the
changes that have occurred from the 1.2 series to the new 1.4.0
release.

Everyone, have fun with cairo!

-Carl

Overview of changes from 1.2.6 to 1.4.0
=======================================
Performance improvements
------------------------
Within the cairo project, the last 6 months or so has seen an intense
effort focusing on the performance of cairo itself. That effort has
paid off considerably, as can be seen in the following highlights of
some of the performance differences from cairo 1.2.6 to cairo 1.4.0.

(Note: The performance results reported here were measured on an x86
laptop. Many of the improvements in 1.4---particular those involving
text rendering---are even more dramatic on embedded platforms without
hardware floating-point units. Such devices played an important part
of many of the optimizations that found their way into cairo over the
last few months.)

• Dramatic improvement when drawing objects that are mostly off-screen
  with the image backend (with the xlib backend this case is still
  slow due to an X server bug):

  image-rgba       long-lines-uncropped-100  479.64 ->  4.98: 96.24x speedup
  ███████████████████████████████████████████████▋

• Dramatic improvement when copying a small fraction of an image
  surface to an xlib surface:

   xlib-rgba              subimage_copy-512    3.93 ->  0.07: 54.52x speedup
  ██████████████████████████▊

• Dramatic improvement to tessellation speed for complex objects:

  image-rgb              tessellate-256-100  874.16 -> 34.79: 25.13x speedup
  ████████████▏
   xlib-rgba        zrusin_another_fill-415  148.40 -> 13.85: 10.72x speedup
  ████▉
   xlib-rgb                  world_map-800  680.20 -> 345.54:  1.97x speedup
  ▌

• Dramatic improvement to the speed of stroking rectilinear shapes,
  (such as the outline of a rectangle or "box"):

  image-rgb          box-outline-stroke-100    0.18 ->  0.01: 24.22x speedup
  ███████████▋
   xlib-rgb          box-outline-stroke-100    0.46 ->  0.06:  8.05x speedup
  ███▌


• Dramatic improvements to text rendering speeds:

   xlib-rgba       text_image_rgba_over-256   63.12 ->  9.61:  6.57x speedup
  ██▊

• 3x improvements to floating-point to fixed-point conversion speeds:

  image-rgba      pattern_create_radial-16     9.29 ->  3.44:  2.70x speedup
  ▉

• 2x improvements to linear gradient computation:

  image-rgb     paint_linear_rgb_source-512   26.22 -> 11.61:  2.26x speedup
  ▋

• 2x improvement to a case common in PDF rendering:

  image-rgb              unaligned_clip-100    0.10 ->  0.06:  1.81x speedup
  ▍

• 1.3x improvement to rectangle filling speed (note: this improvement
  is new since 1.3.16---previously this test case was a 1.3x slowdown
  compared to 1.2.6):

  image-rgba                 rectangles-512    6.19 ->  4.37:  1.42x speedup
  ▎
  xlib-rgba                  rectangles-512    7.48 ->  5.58:  1.34x speedup
  ▏

NOTE: In spite of our best efforts, there are some measurable
performance regressions in 1.4 compared to 1.2. It appears that the
primary problem is the increased overhead of the new tessellator when
drawing many, very simple shapes. The following test cases capture
some of that slowdown:

  image-rgba    mosaic_tessellate_lines-800   11.03 -> 14.29:  1.30x slowdown
  ▏
  image-rgba           box-outline-fill-100    0.01 ->  0.01:  1.26x slowdown
  ▏
  image-rgba        fill_solid_rgb_over-64     0.20 ->  0.22:  1.12x slowdown

  image-rgba       fill_image_rgba_over-64     0.23 ->  0.25:  1.10x slowdown

   xlib-rgb     paint_image_rgba_source-256    3.24 ->  3.47:  1.07x slowdown

We did put some special effort into eliminating this slowdown for the
very common case of drawing axis-aligned rectangles with an identity
matrix (see the box-outline-stroke and rectangles speedup numbers
above). Eliminating the rest of this slowdown will be a worthwhile
project going forward.

Also note that the "box-outline-fill" case is a slowdown while
"box-outline-stroke" is a (huge) speedup. These two test cases
resulted from the fact that some GTK+ theme authors were filling
between two rectangles to avoid slow performance from the more natural
means of achieving the same shape by stroking a single rectangle. With
1.4 that workaround should definitely be eliminated as it will now
cause things to perform more slowly.

Greatly improved PDF output
---------------------------
We are very happy to be able to announce that cairo-generated PDF
output will now have text that can be selected, cut-and-pasted, and
searched with most capable PDF viewer applications. This is something
that was not ever possible with cairo 1.2.

Also, the PDF output now has much more compact encoding of text than
before. Cairo is now much more careful to not embed multiple copies of
the same font at different sizes. It also compresses text and font
streams within the PDF output.

API additions
-------------
There are several new functions available in 1.4 that were not
available in 1.2. Curiously, almost all of the new functions simply
allow the user to query state that has been set in cairo (many new
"get" functions) rather than providing any fundamentally new
operations. The new functionality is:

• Getting information about the current clip region

  cairo_clip_extents
  cairo_copy_clip_rectangle_list
  cairo_rectangle_list_destroy

• Getting information about the current dash setting

  cairo_get_dash_count
  cairo_get_dash

• Getting information from a pattern

  cairo_pattern_get_rgba
  cairo_pattern_get_surface
  cairo_pattern_get_color_stop_rgba
  cairo_pattern_get_color_stop_count
  cairo_pattern_get_linear_points
  cairo_pattern_get_radial_circles

• Getting the current scaled font

  cairo_get_scaled_font

• Getting reference counts

  cairo_get_reference_count
  cairo_surface_get_reference_count
  cairo_pattern_get_reference_count
  cairo_font_face_get_reference_count
  cairo_scaled_font_get_reference_count

• Setting/getting user data on objects

  cairo_set_user_data
  cairo_get_user_data
  cairo_pattern_set_user_data
  cairo_pattern_get_user_data
  cairo_scaled_font_set_user_data
  cairo_scaled_font_get_user_data

• New cairo-win32 functions:

  cairo_win32_surface_create_with_ddb
  cairo_win32_surface_get_image
  cairo_win32_scaled_font_get_logical_to_device
  cairo_win32_scaled_font_get_device_to_logical

API deprecation
---------------
The CAIRO_FORMAT_RGB16_565 enum value has been deprecated. It never
worked as a format value for cairo_image_surface_create, and it wasn't
necessary for supporting 16-bit 565 X server visuals.

A sampling of bug fixes in cairo 1.4
------------------------------------
  • Fixed radial gradients
  • Fixed dashing (degenerate and "leaky" cases)
  • Fixed transformed images in PDF/PS output (eliminate bogus repeating)
  • Eliminate errors from CAIRO_EXTEND_REFLECT and CAIRO_EXTEND_PAD
  • cairo_show_page no longer needed for single-page output
  • SVG: Fix bug preventing text from appearing in many viewers
  • cairo-ft: Return correct metrics when hinting is off
  • Eliminate crash in cairo_create_similar if nil surface is returned
  • Eliminate crash after INVALID_RESTORE error
  • Fix many bugs related to multi-threaded use and locking
  • Fix for glyph spacing 32 times larger than desired (cairo-win32)
  • Fixed several problems in cairo-atsui (assertion failures)
  • Fix PDF output to avoid problems when printing from Acrobat Reader
  • Fix segfault on Mac OS X (measuring a zero-length string)
  • Fix text extents to not include the size of non-inked characters
  • Fix for glyph cache race condition in glitz backend (Jinghua Luo)
  • Fix make check to work on OPD platforms (IA64 or PPC64)
  • Fix compilation problems of cairo "wideint" code on some platforms
  • Many, many others...

Experimental backends (quartz, XCB, OS/2, BeOS, directfb)
---------------------------------------------------------
None of cairo's experimental backends are graduating to "supported"
status with 1.4.0, but two of them in particular (quartz and xcb), are
very close.

The quartz baceknd has been entirely rewritten and is now much more
efficient. The XCB backend has been updated to track the latest XCB
API (which recently had a 1.0 release).

We hope to see these backends become supported in a future release,
(once they are passing all the tests in cairo's test suite).

The experimental OS/2 backend is new in cairo 1.4 compared to cairo
1.2.

Documentation improvements
--------------------------
We have added documentation for several functions and types that
were previously undocumented, and improved documentation on other
ones.  As of this release, there remain only two undocumented
symbols: cairo_filter_t and cairo_operator_t.

[*]Thanks to everyone
---------------------
I've accounted for 41 distinct people with attributed code added to
cairo between 1.2.6 and 1.4.0, (their names are below). That's an
impressive number, but there are certainly dozens more that
contributed with testing, suggestions, clarifying questions, and
encouragement. I'm grateful for the friendships that have developed as
we have worked on cairo together. Thanks to everyone for making this
all so much fun!

Adrian Johnson, Alfred Peng, Alp Toker, Behdad Esfahbod,
Benjamin Otte, Brian Ewins, Carl Worth, Christian Biesinger,
Christopher (Monty) Montgomery, Daniel Amelang, Dan Williams,
Dave Yeo, David Turner, Emmanuel Pacaud, Eugeniy Meshcheryakov,
Frederic Crozat, Hans Breuer, Ian Osgood, Jamey Sharp, Jeff Muizelaar,
Jeff Smith, Jinghua Luo, Jonathan Watt, Joonas Pihlaja, Jorn Baayen,
Kalle Vahlman, Kjartan Maraas, Kristian Høgsberg, M Joonas Pihlaja,
Mathias Hasselmann, Mathieu Lacage, Michael Emmel, Nicholas Miell,
Pavel Roskin, Peter Weilbacher, Robert O'Callahan,
Soren Sandmann Pedersen, Stuart Parmenter, T Rowley,
Vladimir Vukicevic
