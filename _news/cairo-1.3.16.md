---
title: cairo 1.3.16 snapshot (1.4.0 release candidate) available
layout: news
date: 2007-03-03
---
```

From: Behdad Esfahbod <behdad@behdad.org>
Date: 3 Mar 2007
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.3.16 (1.4.0 release candidate) now available

A new cairo snapshot 1.3.16 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.16.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.16.tar.gz.sha1
        8c80376b18a58727f03fea05ef191acb19903e01  cairo-1.3.16.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.16.tar.gz.sha1.asc
        (signed by Behdad Esfahbod)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.16 tag which points to a commit named:
        b3e1fd8c1cbfc4db88bec4bb52821ed9380dbb4f

    which can be verified with:
        git verify-tag 1.3.16

    and can be checked out with a command such as:
        git checkout -b build 1.3.16


This is the eighth development snapshot in the 1.3 series, and the
release candidate for 1.4.0, that will be released early next week.
It comes just over 3 weeks after the 1.3.14 snapshot.

New API functions
-----------------
A few new public functions have been added to the cairo API since the
1.3.14 snapshot. These include a function to query the current scaled
font:

        cairo_get_scaled_font

New functions to query the reference count of all cairo objects:

        cairo_get_reference_count

        cairo_surface_get_reference_count
        cairo_pattern_get_reference_count

        cairo_font_face_get_reference_count
        cairo_scaled_font_get_reference_count

And new functions to allow the use of user_data with any cairo object,
(previously these were only available on cairo_surface_t and
cairo_font_face_t objects):

        cairo_set_user_data
        cairo_get_user_data

        cairo_pattern_set_user_data
        cairo_pattern_get_user_data

        cairo_scaled_font_set_user_data
        cairo_scaled_font_get_user_data

Usability improvement for PDF/PS/SVG generation
-----------------------------------------------
In previous versions of cairo, generating single-page output with the
cairo-pdf, cairo-ps, or cairo-svg backends required a final call to
cairo_show_page. This was often quite confusing as people would port
functional code from a non-paginated backend and be totally mystified
as to why the output was blank until they learned to add this call.

Now that call to cairo_show_page is optional, (it will be generated
implicitly if the user does not call it). So cairo_show_page is only
needed to explicitly separate multiple pages.

Greatly improved PDF output
---------------------------
We are very happy to be able to announce that cairo-generated PDF
output will now have text that can be selected, cut-and-paste, and
searched with most capable PDF viewer applications. This is something
that was not ever possible with cairo 1.2.

Also, the PDF output now has much more compact encoding of text than
before. Cairo is now much more careful to not embed multiple copies of
the same font at different sizes. It also compresses text and font
streams within the PDF output.

Major bug fixes
---------------
  • Fixed radial gradients

    The rendering of radial gradients has been greatly improved. In
    the cairo 1.2 series, there was a serious regression affecting
    radial gradients---results would be very incorrect unless one of
    the gradient circles had a radius of 0.0 and a center point within
    the other circle. These bugs have now been fixed.

  • Fixed dashing

    Several fixes have been made to the implementation of dashed
    stroking. Previously, some dashed, stroked rectangles would
    mis-render and fill half of the rectangle with a large triangular
    shape. This bug has now been fixed.

  • Fixed transformed images in PDF/PS output

    In previous versions of cairo, painting with an image-based source
    surface pattern to the PDF or PS backends would cause many kinds
    of incorrect results. One of the most common problems was that an
    image would be repeated many times even when the user had
    explicitly requested no repetition with CAIRO_EXTEND_NONE. These
    bugs have now been fixed.

  • Eliminate errors from CAIRO_EXTEND_REFLECT and CAIRO_EXTEND_PAD

    In the 1.2 version of cairo any use of CAIRO_EXTEND_REFLECT or
    CAIRO_EXTEND_PAD with a surface-based pattern resulted in an
    error, (cairo would stop rendering). This bug has now been
    fixed.

    Now, CAIRO_EXTEND_REFLECT should work properly with surface
    patterns.

    CAIRO_EXTEND_PAD is still not working correctly, but it will now
    simply behave as CAIRO_EXTEND_NONE rather than triggering the
    error.

New rewrite of quartz backend (still experimental)
--------------------------------------------------
Cairo's quartz backend has been entirely rewritten and is now much
more efficient. This backend is still marked as experimental, not
supported, but it is now much closer to becoming an officially
supported backend. (For people that used the experimental nquartz
backend in previous snapshots, that implementation has now been
renamed from "nquartz" to "quartz" and has replaced the old quartz
backend.)

Documentation improvements
--------------------------
We have added documentation for several functions and types that
were previously undocumented, and improved documentation on other
ones.  As of this release, there remain only two undocumented
symbols: cairo_filter_t and cairo_operator_t.

Other bug fixes
---------------
  • cairo-svg: Fix bug that was preventing text from appearing in many
    viewers

  • cairo-ft: Return correct metrics when hinting is off

  • Cairo 1.3.14 deadlocks in cairo_scaled_font_glyph_extents or
    _cairo_ft_unscaled_font_lock_face

    https://bugs.freedesktop.org/show_bug.cgi?id=10035

  • cairo crashes in cairo_create_similar if nil surface returned by
    other->backend->create_similar

    https://bugs.freedesktop.org/show_bug.cgi?id=9844

  • evolution crash in _cairo_gstate_backend_to_user()
    https://bugs.freedesktop.org/show_bug.cgi?id=9906

  • Fix memory leak in rectilinear stroking code

Things not in this release
--------------------------
  • Solid-surface-pattern cache: This patch had been applied during
    the 1.3.x series, but it was reverted due to some inter-thread
    problems it caused. The patch is interesting since it made a big
    benefit for text rendering performance---so we'll work to bring a
    corrected version of this patch back as soon as possible.
```
