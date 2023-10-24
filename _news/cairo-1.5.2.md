---
title: cairo 1.5.2 snapshot available
layout: news
date: 2007-10-30
---
```

From: Carl Worth <cworth@cworth.org>
Date: Tue, 30 Oct 2007 22:47:52 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.5.2 now available

A new cairo snapshot 1.5.2 is now available from:

        http://cairographics.org/snapshots/cairo-1.5.2.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.5.2.tar.gz.sha1
        39d6593433ce4896a065a6c4ad2882a5cc1fe05a  cairo-1.5.2.tar.gz

        http://cairographics.org/snapshots/cairo-1.5.2.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.5.2 tag which points to a commit named:
        ee5dc04aaf81d6ce9c496c7966ceebfbd6ab12fb

    which can be verified with:
        git verify-tag 1.5.2

    and can be checked out with a command such as:
        git checkout -b build 1.5.2

This is the first snapshot in cairo's unstable 1.5 series. It comes 4
months after the 1.4.10 release. This snapshot includes significant
improvements to PDF and PostScript output, which is one of the things
in which we're most interested in getting feedback. There are a couple
of minor API additions, and several optimizations, (primarily in the
"print/vector" backends). And there are dozens of bug fixes and
robustness improvements.

NOTE: This is a snapshot of in-progress development, not a "release".
So it is expected that there will be more rough edges than one would
find in a major release. For example, various tests in the test suite
are currently failing against the PDF backend, and we'll get those
fixed before the 1.6 release. But you're likely to notice more
improvements than problems, so give this snapshot a try and let us
know how it goes for you. Read more below for many details on the
exciting things in cairo 1.5.2 compared to cairo 1.4.10.

Have fun with cairo!

-Carl

Snapshot 1.5.2 (2007-10-30 Carl Worth <cworth@cworth.org>)
==========================================================
This is the first snapshot in cairo's unstable 1.5 series. It comes 4
months after the 1.4.10 release. This snapshot includes significant
improvements to PDF and PostScript output, which is one of the things
in which we're most interested in getting feedback. There are a couple
of minor API additions, and several optimizations, (primarily in the
"print/vector" backends). And there are dozens of bug fixes and
robustness improvements.

New dependency on external pixman library
-----------------------------------------
A significant change in this snapshot compared to all previous cairo
releases is that cairo now depends on an external "pixman" library for
its software rendering. Previously this same code was compiled
internally as part of cairo, but now the code is separate so that both
cairo and the X server can now share common code, (thanks very much to
Søren Sandmann for his work on separating pixman and maintaining it).

So users will need to acquire and build pixman before being able to
build cairo. The current release is 0.9.6 and can be obtained from
here:

http://cairographics.org/releases/pixman-0.9.6.tar.gz

 which can be verified with:

http://cairographics.org/releases/pixman-0.9.6.tar.gz.sha1
66f01a682c64403a3d7a855ba5aa609ed93bcb9e  pixman-0.9.6.tar.gz

http://cairographics.org/releases/pixman-0.9.6.tar.gz.sha1.asc
(signed by Carl Worth)

Major PDF/PostScript improvements
---------------------------------
Adrian Johnson has done some long-awaited work to make cairo's PDF and
PostScript output more interesting than ever before. First, many
operations that previously triggered image fallbacks will now be
rendered as native vectors. These operations include:

PDF: cairo_push_group, cairo_surface_create_similar,
cairo_mask, A8/A1 surface sources, repeating/reflecting linear
gradients.

PostScript: cairo_push_group, cairo_surface_create_similar,
gradients, bilevel alpha masks, (for example, all values either 0 or
255 for an A8 mask).

Not only that, but when an image fallback is required, it will now be
limited to only the necessary region. For example, a tiny translucent
image overlaying a small portion of text would previously caused an
entire PostScript page to be rendered as a giant image. Now, the
majority of that page will be nice text, and there will only be a tiny
image in the output.

Additionally, the PostScript output now carefully encodes text so that
if it is subsequently converted to PDF, the text will be
selectable.

This is very exciting progress, and we're hoping to hear from users
during the 1.5 series about how things have improved, (for example,
inkscape users doing cairo-based PDF export: please let us know how
things look). And feel free to pass your thanks along to Adrian for his excellent work.

NOTE: This much improved PDF output makes more sophisticated use of
functionality in the PDF specification. This means that cairo's output
will sometimes expose bugs in some free software PDF viewers, (evince,
poppler, and xpdf, for example), that are not yet ready for such PDF
files. We're working with the poppler maintainers to get these bugs
fixed as quickly as possible. In the meantime, please double-check
with other PDF viewers if cairo-generated PDF files are not being
rendered correctly. It may be due to a bug in the viewer rather than
in the PDF file that cairo has created.

Robustness improvements
-----------------------
Chris Wilson has made the largest contribution by far to cairo 1.5.2,
(in number of commits). His more than 150 commits include a huge
number of fixes to increase cairo's robustness. These fixes make cairo
more robust against invalid and degenerate input, (NaN, empty path,
etc.), against size-0 malloc calls, against memory leaks on
error-recovery paths, and against other failures during error
handling. He also implemented atomic operations to cairo, and used
them to fix cairo's previously non-thread-safe reference counting,
again improving robustness.

Chris has put a tremendous amount of time and effort into writing
analysis tools for this work, and in running those tools and fixing
the problems they report. We're very grateful for this work, and hope
that all cairo users appreciate the more robust implementation that
results from it.

This work is largely thankless, so it might make sense to notice
sometime that cairo has been running quite smoothly for you, and when
you do, send a quick "thank you" off to Chris Wilson, since it
is all definitely running smoother thanks to his work.

New API
-------
There are no major additions to cairo's core API. The only new,
generic functions are:

void
cairo_surface_copy_page (cairo_surface_t *surface);

void
cairo_surface_show_page (cairo_surface_t *surface);

which can now be used much more conveniently than the existing
cairo_copy_page and cairo_show_page functions in some
situations. These functions act identically, but require only a
cairo_surface_t* and not a cairo_t*.

All other API additions are specific to particular backends.

New cairo-win32 API (new font face function and "win32 printing" surface)
-------------------------------------------------------------------------
There is a new function for creating a win32 font face for both a
logfontw and an hfont together. This complements the existing
functions for creating a font face from one or the other:

cairo_font_face_t *
cairo_win32_font_face_create_for_logfontw_hfont (LOGFONTW *logfont,
 HFONT font);

There is also a new "win32 printing" surface:

cairo_surface_t *
cairo_win32_printing_surface_create (HDC hdc);

This interface looks identical to the original
cairo_win32_surface_create, (both accept and HDC), but the behavior of
this new surface is very different. It should only be called with a
printing DC, and will result in all drawing commands being stored into
a meta-surface and emitted after each page is complete, with analysis
to do as minimal image-based fallbacks as necessary. The behavior and
implementation shares much with the PDF and PostScript backends.

New cairo-ps API (EPS and PostScript level control)
---------------------------------------------------
An often requested feature has been the ability to generate
Encapsulated PostScript (EPS) with cairo. We have that now with the
following very simple API. Just do cairo_ps_surface_create as usual
then call this function with a true value:

void
cairo_ps_surface_set_eps (cairo_surface_t       *surface,
  cairo_bool_t           eps);

[NOTE: As always with snapshots, it's possible---though not very
likely---that the API could still be modified before a final
release. For example, this is the first public cairo function that
accepts a Boolean parameter. I'm generally opposed to Boolean
parameters, but this is probably the one case where I'm willing to
accept one, (namely a "set" function that accepts a single Boolean).]

Also, it is now possible to control what PostScript level to target,
(either level 2 or level 3), with the following new API:

typedef enum _cairo_ps_level {
    CAIRO_PS_LEVEL_2,
    CAIRO_PS_LEVEL_3
} cairo_ps_level_t;

void
cairo_ps_surface_restrict_to_level (cairo_surface_t    *surface,
    cairo_ps_level_t    level);

void
cairo_ps_get_levels (cairo_ps_level_t const  **levels,
     int                      *num_levels);

const char *
cairo_ps_level_to_string (cairo_ps_level_t level);

Improvement for cairo-quartz
----------------------------
Brian Ewins had contributed several improvements to cairo-quartz. These
include an implementation of EXTEND_NONE for linear and radial
gradients, (so this extend mode will no longer trigger image fallbacks
for these gradients), as well as native surface-mask clipping, (only
on OS X 10.4+ where the CGContextClipToMask function is available).

He also fixed a semantic mismatch between cairo and quartz for dashing
with an odd number of entries in the dash array.

We're grateful for Brian since not many quartz-specific improvements
to cairo would be happening without him.

Optimizations
-------------
Optimize SVG output for when the same path is both filled and stroked,
and avoid unnecessary identity matrix in SVG output. (Emmanuel Pacaud).

Optimize PS output to take less space (Ken Herron).

Make PS output more compliant with DSC recommendations (avoid initclip
and copy_page) (Adrian Johnson).

Make PDF output more compact (Adrian Johnson).

Release glyph surfaces after uploading them to the X server, (should
save some memory for many xlib-using cairo application). (Behdad
Esfahbod).

Optimize cairo-win32 to use fewer GDI objects (Vladimir Vukicevic).

win32-printing: Avoid falling back to images when alpha == 255
everywhere. (Adrian Johnson).

win32-printing: Avoid falling back for cairo_push_group and
cairo_surface_create_similar. (Adrian Johnson)

Bug fixes
---------
Avoid potential integer overflows when allocating large buffers
(Vladimir Vukicevic).

Preparations to allow the 16.16 fixed-point format to change to
24.8 (Vladimir Vukicevic).

Fix bugs for unsupported X server visuals (rgb565, rgb555, bgr888, and
abgr8888). (Carl Worth and Vladimir Vukicevic)

Fix bugs in PDF gradients (Adrian Johnson).

Fix cairo-xlib to build without requiring Xrender header
files (Behdad Esfahbod).

Make cairo more resilient in the case of glyphs not being available in
the current font. (Behdad Esfahbod)

Prevent crashes when both atsui and ft font backends are compiled in
(Brian Ewins).

Make font subsetting code more robust against fonts that don't include
optional tables (Adrian Johnson).

Fix CFF subsetting bug, (which manifested by generating PDF files that
Apple's Preview viewer could not read) (Adrian Johnson).

Fixed error handling for quartz and ATSUI backends (Brian Ewins).

Avoid rounding problems by pre-transforming to avoid integer-only
restrictions on transformation in GDI (Adrian Johnson).

Fixed an obscure bug (#7245) computing extents for some stroked
paths (Carl Worth).

Fix crashes due to extreme transformation of the pen, (seems to show
up in many .swf files for some reason) (Carl Worth).

```
