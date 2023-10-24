---
title: cairo 1.2.4 release available
layout: news
date: 2006-08-18
---

Subject: cairo release 1.2.4 now available
From: Carl Worth <cworth@cworth.org>
Date: 18 Aug 2006
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org

A new cairo release 1.2.4 is now available from:

        http://cairographics.org/releases/cairo-1.2.4.tar.gz

    which can be verified with:

        http://cairographics.org/releases/cairo-1.2.4.tar.gz.sha1
        5520b771c8b85acea78fa56fc4c39b4dca6bcc7c  cairo-1.2.4.tar.gz

        http://cairographics.org/releases/cairo-1.2.4.tar.gz.sha1.asc
        (signed by Carl Worth)
  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.2.4 tag which points to a commit named:
        54755b2d9891981d813384bccde84998def96abf

    which can be verified with:
        git verify-tag 1.2.4

    and can be checked out with a command such as:
        git checkout -b build 1.2.4

This is the second bug fix release in the 1.2 series, coming less than
two weeks after the 1.2.2 release made on August 8.

The big motivation for a quick release was that there were a log of
build system snags that people ran into with the 1.2.2 release. But,
by the time we got those all done, we found that we had a bunch of
fixes for cairo's rendering as well. So there's a lot of goodness in
here for such a short time period.

As always, have lots of fun with cairo everybody!

-Carl

What's new in cairo 1.2.4 compared to 1.2.2
===========================================

Rendering fixes
---------------
Fix image surfaces to not be clipped when used as a source (Vladimir Vukicevic)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=72e25648c4c4bc82ddd938aa4e05887a293f0d8b

Fix a couple of corner cases in dashing degenerate paths (Jeff Muizelaar)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=fbb1758ba8384650157b2bbbc93d161b0c2a05f0

Fix support for type1 fonts on win32 (Adrian Johnson)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=da1019c9138695cb838a54f8b871bbfd0e8996d7

Fix assertion failure when rotating bitmap fonts (Carl Worth)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=0bfa6d4f33b8ddb5dc55bbe419c15df4af856ff9

Fix assertion failure when calling cairo_text_path with bitmap fonts (Carl Worth)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=9878a033531e6b96b5f27e69e10e90dee7440cd9

Fix mis-handling of cairo_close_path in some situations (Tim Rowley, Carl Worth)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=53f74e59faf1af78f2f0741ccf1f23aa5dad4efc

Respect font_matrix translation in _cairo_gstate_glyph_path (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=f183b835b111d23e838889178aa8106ec84663b3

Fix vertical metrics adjustment to work with non-identity shapes (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=b7bc263842a798d657a95e539e1693372448837f

[PS] Set correct ImageMatrix in _cairo_ps_surface_emit_bitmap_glyph_data (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=d47388ad759b0a1a0869655a87d9b5eb6ae2445d

Build system fixes
------------------
Fix xlib detection to prefer pkg-config to avoid false libXt dependency (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=0e78e7144353703cbd28aae6a67cd9ca261f1d68

Fix typos causing win32 build problem with PS,PDF, and SVG backends (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=aea83b908d020e26732753830bb3056e6702a774

Fix configure cache to not use stale results (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=6d0e3260444a2d5b6fb0cb223ac79f1c0e7b3a6e

Fix to not pass unsupported warning options to the compiler (Jens Granseuer)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=97524a8fdb899de1ae4a3e920fb7bda6d76c5571

Fix to allow env. variables such as png_REQUIRES to override configure detection (Jens Granseuer)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=abd16e47d6331bd3811c908e524b4dcb6bd23bf0

Fix test suite to not use an old system cairo when converting svg2png (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=6122cc85c8f71b1ba2df3ab86907768edebe1781

Fix test suite to not require signal.h to be present (Behdad Esfahbod)
http://gitweb.freedesktop.org/?p=cairo;a=commit;h=6f8cf53b1e1ccdbe1ab6a275656b19c6e5120e40

Code cleanups
-------------
Many useful warnings cleanups from sparse, valgrind, and careful eyes
(Kjartan Maraas, Pavel Roskin)
