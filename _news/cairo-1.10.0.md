---
title: cairo 1.10.0 release available
layout: news
date: 2010-09-06
---
```

From: Chris Wilson <chris@chris-wilson.co.uk>
Date: Mon, 06 Sep 2010 18:56:33 +0100
To: cairo-announce@cairographics.org
Cc: gnome-announce-list@gnome.org, pr@lwn.net
Subject: cairo release 1.10.0 now available

A new cairo release 1.10.0 is now available from:

http://cairographics.org/releases/cairo-1.10.0.tar.gz

    which can be verified with:

http://cairographics.org/releases/cairo-1.10.0.tar.gz.sha1
efe7e47408d5188690228ccadc8523652f6bf702  cairo-1.10.0.tar.gz

http://cairographics.org/releases/cairo-1.10.0.tar.gz.sha1.asc
(signed by Chris Wilson)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.10.0 tag which points to a commit named:
cb0bc64c16b3a38cbf0c622830c18ac9ea6e2ffe

    which can be verified with:
git verify-tag 1.10.0

    and can be checked out with a command such as:
git checkout -b build 1.10.0

The cairo community is astounded (and flabbergast) to finally announce
the 1.10.0 release of the cairo graphics library. This is a major update
to cairo, with new features and enhanced functionality which maintains
compatibility for applications written using any previous major cairo
release, (1.8, 1.6, 1.4, 1.2, or 1.0). We recommend that anybody using
a previous version of cairo upgrade to cairo 1.10.0.

One of the more interesting departures for cairo for this release is the
inclusion of a tracing utility, cairo-trace. cairo-trace generates a
human-readable, replayable, compact representation of the sequences of
drawing commands made by an application. This can be used to inspecting
applications to understand issues and as a means for profiling
real-world usage of cairo.

The traces generated by cairo-trace have been collected in

  git://git.cairographics.org/git/cairo-traces

and have driven the performance tuning of cairo over the last couple of
years. In particular, the image backend is much faster with a new
polygon rasterisation and a complete overhaul of the tessellator. Not
only is this faster, but also eliminates visual artifacts from
self-intersecting strokes. Not only has cairo-trace been driving
performance improvements within cairo, but as a repeatable means of
driving complex graphics it has been used to tune OpenGL, DDX, and
pixman.

Cairo's API has been extended to better support printing, notably
through the ability to include a single compressed representation of an
image for patterns used throughout a document, leading to dramatic file
size reductions. Also the meta-surface used to record the vector
commands compromising a drawing sequence is now exposed as a
CAIRO_SURFACE_TYPE_RECORDING, along with a new surface that is a child of a
larger surface, CAIRO_SURFACE_TYPE_SUBSURFACE. One typical usage of a
subsurface would be as a source glyph in a texture atlas, or as a
restricted subwindow within a canvas.

Cairo's API has also resurrected the RGB16 format from the past as
the prevalence of 16-bit framebuffers has not diminished and is a
fore-taste of the extended format support we anticipate in the future.
Increasing cairo's utility, we introduce the cairo_region_t for handling
sets of pixel aligned rectangles commonly used in graphics applications.
This is a merger of the GdkRegion and the pixman_region_t, hopefully
providing the utility of the former with the speed of the latter.

Furthermore cairo has been reworked to interoperate more closely with
various acceleration architectures, gaining the ability to share
those hardware resources through the new cairo_device_t. For instance,
with the new OpenGL backend that supersedes the Glitz backend, hardware
and rendering operations can be shared between a classic OpenGL
application mixing libVA for the hardware assisted video decode with
cairo for high quality overlays all within the same OpenGL canvas.

Many thanks for the hard work of Adrian Johnson, Andrea Canciani, Behdad
Esfahbod, Benjamin Otte, Carl Worth, Carlos Garcia Campos, Chris Wilson,
Eric Anholt, Jeff Muizelaar, Karl Tomlinson, M Joonas Pihlaja, Søren
Sandmann Pedersen and many others that have contributed over the last
couple of years to cairo. Thank you all!
```