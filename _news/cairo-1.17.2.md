---
date: 2019-01-31
layout: news
title: cairo snapshot 1.17.2 is now available 
---
```
A new cairo snapshot 1.17.2 is now available from:

https://cairographics.org/snapshots/cairo-1.17.2.tar.xz

    which can be verified with:

https://cairographics.org/snapshots/cairo-1.17.2.tar.xz.sha1
c5d6f12701f23b2dc2988a5a5586848e70e858fe  cairo-1.17.2.tar.xz

https://cairographics.org/snapshots/cairo-1.17.2.tar.xz.sha1.asc
(signed by Bryce Harrington)

  Additionally, a git clone of the source tree:

git clone git://git.cairographics.org/git/cairo

    will include a signed 1.17.2 tag which points to a commit named:
d67be70805fc422aacdb75fb14f6fa482db649c0

    which can be verified with:
git verify-tag 1.17.2

    and can be checked out with a command such as:
git checkout -b build 1.17.2

Release 1.17.2 (2019-01-31 Bryce Harrington <bryce@bryceharrington.org>)
========================================================================
This snapshot provides the new support for writing floating point
formats as 16 bpc PNGs, with support for RGBA128F and RGB96F formats.
This new feature increases Cairo's pixman version requirement to 0.36.0.

Beyond this are a range of bugfixes and some work on establishing CI for
Cairo.

For a complete log of changes, please see

    https://cairographics.org/releases/ChangeLog.cairo-1.17.2

API Changes
-----------
        * CAIRO_FORMAT_RGB96F, CAIRO_FORMAT_RGBA128F

Dependency Changes
------------------
pixman 0.36.0


------------------------------------------------------------------------
List of changes in this release:

Adrian Johnson (6):
      type1: fallback if the font matrix is not a uniform scale
      doc: fix link tags code example
      pdf: add missing flush
      ps: fix invalid matrix in eps embedding
      tag_attributes: Allow decimal points in non decimal point locales
      scaled-subsets: always include glyphs maps to character 0

Bryce Harrington (5):
      Bump version for 1.17.1
      RELEASING: Bugzilla no longer needs updated
      clip-boxes:  Drop too-early return
      Release 1.17.2

Carlos Garcia Campos (1):
      ft: Use FT_Done_MM_Var instead of free when available in cairo_ft_apply_variations

Jordan Petridis (1):
      CI: Fix Docker image uris

Maarten Lankhorst (4):
      cairo-trace: Simplify bigendian case in emit_image.
      Add support for RGBA128F and RGB96F formats.
      png: Add support for writing new floating point formats as 16 bpc png.
      png: Add support for 16 bpc png reading as floating point format

Uli Schlachter (3):
      .gitlab-ci.yml: Do a verbose build
      Remove all traces of NUM_THREADS
      Merge branch 'ft-crash' of gitlab.freedesktop.org:carlosgc/cairo

luz.paz (1):
      Misc. typos

suzuki toshiya (1):
      [cairo-ft-font.c] conditionalize the changes by 3ec4aa24 on 2018-07-16 for legacy FreeType2 without color font feature

```
