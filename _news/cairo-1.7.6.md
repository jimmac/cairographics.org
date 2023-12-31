---
title: cairo 1.7.6 snapshot available
layout: news
date: 2008-09-18
---
```

From: Carl Worth <cworth@cworth.org>
Date: Thu, 18 Sep 2008 15:26:44 -0700
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.7.6 now available

A new cairo snapshot 1.7.6 is now available from:

        http://cairographics.org/snapshots/cairo-1.7.6.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.7.6.tar.gz.sha1
        07be7452ddd24df4841c13bc73f76c2543f1d849  cairo-1.7.6.tar.gz

        http://cairographics.org/snapshots/cairo-1.7.6.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.7.6 tag which points to a commit named:
        005dd8499bca9521ab934a56c68d2b85042359b7

    which can be verified with:
        git verify-tag 1.7.6

    and can be checked out with a command such as:
        git checkout -b build 1.7.6

The cairo community is happy to announce the 1.7.6 snapshot of the
cairo graphics library. This is a "release candidate" for the upcoming
1.8.0 release, so we will greatly appreciate any reports of problems
in this release, and no major changes are currently planned before
1.8.

See below for details, and have fun!

-Carl

The cairo community is happy to announce the 1.7.6 snapshot of the
cairo graphics library. This is a "release candidate" for the upcoming
1.8.0 release, so we will greatly appreciate any reports of problems
in this release, and no major changes are currently planned before
1.8.

Notable changes in 1.7.6
------------------------
The largest number of changes since 1.7.4 did not change the
implementation of cairo itself, but instead revamped cairo's build
system. The primary goal of the revamp is to make the build system
less fragile, (particularly for non-Linux platforms). For example, now
people building on win32 will no longer need to maintain a
platform-specific list of files to be built. Also, the .so file will
now be installed with a different naming scheme, (for example, 1.7.6
will install with a .10706 suffix). Much thanks, Behdad!

And, as usual, Chris Wilson has made another large round of robustness
improvements, (eliminating dead code, fixing propagation of error
status values, test suite improvements, etc. etc.). Thanks as always,
Chris!

API changes since 1.7.4
-----------------------
There have been a few changes of API that was new during the 1.7
series:

* Remove cairo_font_options_set_lcd_filter
   and cairo_font_options_get_lcd_filter

  Motivation: At the Cairo Summit, this API was determined to be too
specific to the freetype font backend to be in the general
API. A similar API with a cairo_ft prefix might be introduced
in the future. Note that cairo will still respect the
corresponding fontconfig settings for these options.

* Replace cairo_has_show_glyphs
     with cairo_surface_has_show_glyphs

  Motivation: This really is a surface-specific interface, and the
convenience function on the cairo_t is not obviously
necessary. An application can easily call:

cairo_surface_has_show_glyphs (cairo_get_target (cr));

as needed.

* Add cairo_text_cluster_flags_t
   to cairo_show_text_glyphs
      cairo_scaled_font_text_to_glyphs
      cairo_user_scaled_font_text_to_glyphs_func_t

  Motivation: This flag, (and specifically the
CAIRO_TEXT_CLUSTER_FLAG_BACKWARD value), replaces the
cairo_bool_t backward argument in each of the above
interfaces. This leads to more readable user code, and also
allows future extensibility.

As always, there are no changes to any API from any major cairo
release, (1.0.x, 1.2.x, 1.4.x, 1.6.x). Cairo maintains the same
compatibility promise it always has.

Bug fixes since 1.7.4
---------------------
xlib: Faster bookkeeping (Karl Tomlinson)
https://bugzilla.mozilla.org/show_bug.cgi?id=453199#c5

PS: Fix gradients with non-constant alpha (Chris Wilson)

Fix deadlock in user-font code (Richard Hughes and Behdad Esfahbod)
http://bugs.freedesktop.org/show_bug.cgi?id=16819

Several other minor fixes.

```
