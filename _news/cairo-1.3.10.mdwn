---
title: cairo 1.3.10 snapshot available
layout: news
date: 2006-12-23
---

From: Carl Worth <cworth@cworth.org>
Date: 23 Dec 2006
To: cairo-announce@cairographics.org
CC: gnome-announce-list@gnome.org
Subject: cairo snapshot 1.3.10 now available

A new cairo snapshot 1.3.10 is now available from:

        http://cairographics.org/snapshots/cairo-1.3.10.tar.gz

    which can be verified with:

        http://cairographics.org/snapshots/cairo-1.3.10.tar.gz.sha1
        0a899378673bfda49d1b7530405d62c24b9e051a  cairo-1.3.10.tar.gz

        http://cairographics.org/snapshots/cairo-1.3.10.tar.gz.sha1.asc
        (signed by Carl Worth)

  Additionally, a git clone of the source tree:

        git clone git://git.cairographics.org/git/cairo

    will include a signed 1.3.10 tag which points to a commit named:
        b35cfde7f0e2896ccc1453f9716cb9b61c42cf94

    which can be verified with:
        git verify-tag 1.3.10

    and can be checked out with a command such as:
        git checkout -b build 1.3.10

Santa Claus is coming just a little bit early this year, and he's
bringing a shiny new cairo snapshot for all the good little boys and
girls to play with.

This is the fifth development snapshot in the 1.3 series. It comes 9
days after the 1.3.8 snapshot, and still well within our goal of
having a new snapshot every week, (though don't expect one next
week---we'll all be too stuffed with sugar plums).

Speaking of sugar plums, there's a sweet treat waiting in this cairo
snapshot---greatly improved performance for stroking rectilinear
shapes, like the ever common rectangle:

image-rgb          box-outline-stroke-100 0.18 -> 0.01: 25.58x speedup
████████████████████████▋
image-rgba         box-outline-stroke-100 0.18 -> 0.01: 25.57x speedup
████████████████████████▋
xlib-rgb          box-outline-stroke-100 0.49 -> 0.06:  8.67x speedup
███████▋
xlib-rgba         box-outline-stroke-100 0.22 -> 0.04:  5.39x speedup
████▍

In past releases of cairo, some people had noticed that using
cairo_stroke to draw rectilinear shapes could be awfully slow. Many
people had worked around this by using cairo_fill with a more complex
path and gotten a 5-15x performance benefit from that.

If you're one of those people, please rip that workaround out, as now
the more natural use of cairo_stroke should be 1.2-2x faster than the
unnatural use of cairo_fill.

And if you hadn't ever implemented that workaround, then you just
might get to see your stroked rectangles now get drawn 5-25x faster.

Beyond that performance fix, there are a handful of bug fixes in this
snapshot:

 * Fix for glyph cache race condition in glitz backend (Jinghua Luo)

 * Many fixes for ATSUI text rendering (Brian Ewins)

 * Un-break recent optimization-triggered regression in rendering text
   with a translation in the font matrix (Behdad Esfahbod)

 * Fix make check to work on OPD platforms (IA64 or PPC64)
   (Frederic Crozat)

 * Fix a couple of character spacing issues on Windows
    (Jonathan Watt)

Have fun with that, everybody, and we'll be back for more in the new
year, (with a plan to add the last of our performance improvements in
this round, fix a few bad, lingering bugs, and then finish off a nice,
stable 1.4 release before the end of January).

-Carl
