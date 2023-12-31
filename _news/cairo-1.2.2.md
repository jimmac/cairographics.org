---
title: cairo 1.2.2 release available
layout: news
date: 2006-08-08
---
```

From: Carl Worth <cworth@cworth.org>
Date: 8 Aug 2006
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: [cairo-announce] cairo release 1.2.2 now available

A new cairo release 1.2.2 is now available from:

        http://cairographics.org/releases/cairo-1.2.2.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.2.2.tar.gz.sha1
        859b9ed4eaa200a03b9e41ccc45f3799742e6c5c  cairo-1.2.2.tar.gz

        http://cairographics.org/releases/cairo-1.2.2.tar.gz.sha1.asc
        (signed by Carl Worth)
  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.2.2 tag which points to a commit named:
        ac1c748868bdf4ca6fd195b184ec90827f6e8c94

    which can be verified with:
        git verify-tag 1.2.2

    and can be checked out with a command such as:
        git checkout -b build 1.2.2

This is the first bug fix release in the 1.2 series since the original
1.2.0 release made six weeks ago.

There were some very serious bugs in the 1.2.0 release, (see below),
so everybody is encouraged to upgrade from 1.2.0 to 1.2.2. The 1.2.2
release maintains source and binary compatibility with 1.2.0 and does
not make any API additions.

I'd like to thank everybody who has done so much to make this release
possible. Some people have their names associated with fixes below,
but many more people have been just as valuable in testing and
reporting bugs. And I'd like to extend special recognition to the
people who have been patient with some major failures in cairo 1.2.0!

At the risk of neglecting the dozens of people who have done so much,
I do want to mention two people in particular:

First, Behdad Esfahbod has put an untold number of hours into this
release, with over 80 commits since the 1.2.0 release just a few weeks
ago. His efforts are often behind-the-scenes improving the Makefiles
and the test suites so that everyone working on cairo can do so more
smoothly and easily. Thanks Behdad!

Second, I'd like to extend a special welcome to Adrian Johnson who has
recently started working on cairo and immediately started contributing
very valuable improvement. His work has focused on the printing
backends, (particularly in the area of font subsetting), which are
much better for his efforts. Welcome Adrian!

And to everybody, have fun with cairo!

-Carl

What's new in cairo 1.2.2 compared to 1.2.0
===========================================
Fix crashes with BGR X servers
------------------------------
With cairo 1.2.0 many people reported problems with all cairo-using
programs, (including all GTK+ programs with GTK+ >= 2.8) immediately
crashing with a complaint about an unsupported image format. This bug
affected X servers that do not provide the Render extension and that
provide a visual with BGR rather than RGB channel order.

report: https://bugs.freedesktop.org/show_bug.cgi?id=7294
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=9ae66174e774b57f16ad791452ed44efc2770a59

Fix the "disappearing text" bug
-------------------------------
With cairo 1.2.0 many people reported that text would disappear from
applications, sometimes reappearing with mouse motion or
selection. The text would disappear after the first space in a string
of text. This bug was caused by an underlying bug in (very common) X
servers, and only affected text rendered without antialiasing, (either
a bitmap font or a vector font with antialiasing disabled). The bug
was also exacerbated by a KDE migration bug that caused antialiasing
to be disabled more than desired.

report: https://bugs.freedesktop.org/show_bug.cgi?id=7494
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=456cdb3058f3b416109a9600167cd8842300ae14
see also:
Xorg:   https://bugs.freedesktop.org/show_bug.cgi?id=7681
KDE:    http://qa.mandriva.com/show_bug.cgi?id=23990

Fix broken image fallback scaling (aka. "broken printing")
----------------------------------------------------------
The various "print" backends, (pdf, ps, and svg), sometimes fallback
to using image-based rendering for some operations. In cairo 1.2.0
these image fallbacks were scaled improperly. Applications using cairo
can influence the resolution of the image fallbacks with
cairo_surface_set_fallback_resolution. With the bug, any value other
than 72.0 would lead to incorrect results, (larger values would lead
to increasingly shrunken output).

report: https://bugs.freedesktop.org/show_bug.cgi?id=7533
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=1feb4291cf7813494355459bb547eec604c54ffb

Fix inadvertent semantic change of font matrix translation (Behdad Esfahbod)
----------------------------------------------------------------------------
The 1.2.0 release introduced an inadvertent change to how the
translation components of a font matrix are interpreted. In the 1.0
series, font matrix translation could be used to offset the glyph
origin, (though glyph metrics were reported incorrectly in
1.0). However in 1.2.0, the translation was applied to the advance
values between each glyph. The 1.2.0 behavior is fairly useless in
practice, and it was not intentional to introduce a semantic
change. With 1.2.2 we return to the 1.0 semantics, with a much better
implementation that provides correct glyph metrics.

fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=84840e6bba6e72aa88fad7a0ee929e8955ba9051

Fix create_similar to preserve fallback resolution and font options (Behdad Esfahbod)
-------------------------------------------------------------------------------------
There has been a long-standing issue with cairo_surface_create_similar
such that font options and other settings from the original
destination surface would not be preserved to the intermediate
"similar" surface. This could result in incorrect rendering
(particularly with respect to text hinting/antialiasing) with
fallbacks, for example.

report: https://bugs.freedesktop.org/show_bug.cgi?id=4106
fixes:  http://gitweb.freedesktop.org/?p=cairo;a=commit;h=9fcb3c32c1f16fe6ab913e27eb54d18b7d9a06b0
        http://gitweb.freedesktop.org/?p=cairo;a=commit;h=bdb4e1edadb78a2118ff70b28163f8bd4317f1ec

xlib: Fix text performance regression from 1.0 to 1.2.0 (Vladimir Vukicevic)
----------------------------------------------------------------------------
Several people noticed that upgrading from cairo 1.0 to cairo 1.2.0
caused a significant performance regression when using the xlib
backend. This performance regression was particularly noticeable when
doing lots of text rendering and when using a high-latency connection
to the X server, (such as a remote X server over an ssh
connection). The slowdown was identified and fixed in 1.2.2.

report: https://bugs.freedesktop.org/show_bug.cgi?id=7514
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=b7191885c88068dad57d68ced69a752d1162b12c

PDF: Eliminate dependency on FreeType library dependency (Adrian Johnson)
-------------------------------------------------------------------------
The cairo 1.2 series adds a supported pdf backend to cairo. In cairo
1.2.0 this backend required the freetype library, which was an
undesirable dependency on systems such as win32, (cairo is designed to
always prefer the "native" font system). As of cairo 1.2.2 the
freetype library is not required to use the pdf backend on the win32
platform.

report: https://bugs.freedesktop.org/show_bug.cgi?id=7538
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=a0989f427be87c60415963dd6822b3c5c3781691

PDF: Fix broken output on amd64 (Adrian Johnson)
------------------------------------------------
report: http://bugzilla.gnome.org/show_bug.cgi?id=349826
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=f4b12e497b7ac282b2f6831b8fb68deebc412e60

PS: Fix broken output for truetype fonts > 64k (Adrian Johnson)
---------------------------------------------------------------
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=067d97eb1793a6b0d0dddfbd0b54117844511a94

PDF: Fix so that dashing doesn't get stuck on (Kent Worsnop)
------------------------------------------------------------
Kent notices that with the PDF backend in cairo 1.2.0 as soon as a
stroke was performed with dashing, all subsequent strokes would also
be dashed. There was no way to turn dashing off again.

fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=778c4730a86296bf0a71080cf7008d7291792256

Fix memory leaks in failure paths in gradient creation (Alfred Peng)
--------------------------------------------------------------------
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=db06681b487873788b51a6766894fc619eb8d8f2

Fix memory leak in _cairo_surface_show_glyphs (Chris Wilson)
------------------------------------------------------------
report: https://bugs.freedesktop.org/show_bug.cgi?id=7766
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=e2fddcccb43d06486d3680a19cfdd5a54963fcbd

Solaris: Add definition of cairo_private for some Sun compilers (Alfred Peng)
-----------------------------------------------------------------------------
report: https://bugzilla.mozilla.org/show_bug.cgi?id=341874
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=04757a3aa8deeff3265719ebe01b021638990ec6

Solaris: Change version number of Sun's Xorg server with buggy repeat (Brian Cameron)
-------------------------------------------------------------------------------------
report: https://bugs.freedesktop.org/show_bug.cgi?id=7483
fix:    http://gitweb.freedesktop.org/?p=cairo;a=commit;h=e0ad1aa995bcec4246c0b8ab0d5a5a79871ce235

Various memory leak fixes
-------------------------
Fix memory leak in _cairo_surface_show_glyphs (bug 7766)
Fix file handle leak in failure path (bug 7616)
Fix some memory leaks in the test cases.
Fix some memory leaks in font subsetting code used in print backends.

Documentation improvements (Behdad Esfahbod)
--------------------------------------------
Added new documentation for several functions (cairo_show_page,
cairo_copy_page, cairo_in_stroke, cairo_in_fill).

Fixed some syntax errors that were preventing some existing
documentation from being published.

Fixed several minor typographical errors.

Added an index for new symbols in 1.2.
```
