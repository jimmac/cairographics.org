---
title: cairo 1.3.6 snapshot available
layout: news
date: 2006-12-06
---
```

From: Carl Worth <cworth@cworth.org>
Date: 6 Dec 2006
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.3.6 available

A new cairo snapshot 1.3.6 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.6.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.6.tar.gz.sha1
        c69339afca1115815be50b32c3a733d272aaa84c  cairo-1.3.6.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.6.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.6 tag which points to a commit named:
        648ef4487dfa43f20fb2c73e7b8e567f8a25497a

    which can be verified with:
        git verify-tag 1.3.6

    and can be checked out with a command such as:
        git checkout -b build 1.3.6

This is the third development snapshot in the 1.3 series. It comes two
weeks after the 1.3.4 snapshot.

We don't have fancy performance charts this week as the primary
changes in this snapshot are bug fixes. The performance work continues
and the next snapshot (planned for one week from today) should include
several improvements.

-Carl

Summary of changes since 1.3.4
==============================
 * Fix undesirable rounding in glyph positioning (Dan Amelang)

   This bug was noticed by several users, most commonly by seeing
   improper text spacing or scrambled glyphs as drawn by nautilus. For
   example:

Update to cairo-1.3.4 worsen font rendering
https://bugzilla.redhat.com/bugzilla/show_bug.cgi?id=217819

 * Fix reduced range of valid input coordinates to tessellator
   (M Joonas Pihlaja)

   This bug was causing lots of assertion failures in mozilla as
   mentioned here:

CAIRO_BO_GUARD_BITS and coordinate space?
http://lists.freedesktop.org/archives/cairo/2006-December/008743.html

 * Fix several regressions in new tessellator (M Joonas Pihlaja)

   Joonas just had a good eye for detail here. I don't think any
   external cairo users had noticed any of these bugs yet.

 * Fix compilation problems of cairo "wideint" code on some platforms
   (Mathieu Lacage)

 * Fix failed configure due to broken grep (Dan Amelang)

   This bug was reported here:

AX_C_FLOAT_WORDS_BIGENDIAN doesn't work because grep doesn't
work with binary file
https://bugs.freedesktop.org/show_bug.cgi?id=9124

 * Remove the pkg-config minimum version requirement (Behdad Esfahbod)

   Some systems ship with pkg-config 0.15 and there was really no good
   reason for cairo to insist on having version 0.19 before it would
   build.

There is also one new (but inert) feature in this snapshot. There's a
new option that can be passed to cairo's configure script:

--disable-some-floating-point

Disable certain code paths that rely heavily on double precision
floating-point calculation. This option can improve
performance on systems without a double precision floating-point
unit, but might degrade performance on those that do.

As of this snapshot, this option does not make any change to cairo,
but it is possible that future versions of cairo will respect this
option and change the implementation of various functions as
appropriate.
```
