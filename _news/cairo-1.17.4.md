---
date: 2020-11-27
layout: news
title: cairo snapshot 1.17.4 is now available
---
### A new cairo snapshot 1.17.4 is now available from:

[https://cairographics.org/snapshots/cairo-1.17.4.tar.xz](https://cairographics.org/snapshots/cairo-1.17.4.tar.xz)

which can be verified with:

```
https://cairographics.org/snapshots/cairo-1.17.4.tar.xz.sha1
68712ae1039b114347be3b7200bc1c901d47a636  cairo-1.17.4.tar.xz

https://cairographics.org/snapshots/cairo-1.17.4.tar.xz.sha1.asc
(signed by Bryce Harrington)
```

Additionally, a git clone of the source tree: `git clone git://git.cairographics.org/git/cairo` will include a signed `1.17.4` tag which points to a commit named `156cd3eaaebfd8635517c2baf61fcf3627ff7ec2` which can be verified with `git verify-tag 1.17.4` and can be checked out with a command such as `git checkout -b build 1.17.4`.


## Release 1.17.4 (2020-11-27 Bryce Harrington <bryce@bryceharrington.org>)

Thank you to the many people who have contributed the large number of
bug fixes and refinements since 1.17.2.

A particularly noteworthy improvement in this release is the addition of
the meson build system as an alternative to autotools.  Autotools is
still used for producing the releases, so will be the default in the
tarball and presumably will still be preferred by distro packagers of
Cairo.  It should be possible to build the release tarball using meson,
but as this is new functionality consider it still a work in progress.
The meson configuration has striven to track the autotools
implementation but be aware there may still be some differences between
the two.

Continuous Integration configurations have been added that enable
testing on a variety of platforms including Fedora, Windows MSVC, etc.
This work has helped in identifying updates and fixes including
adjusting to changes in API calls in dependencies like rsvg and
fontconfig, and to fix platform-specific build issues.

The cogl Cairo backend underwent significant development this cycle.
Cogl provides GPU accelerated drawing support.  The development work
includes implementation of core functionality, performance
optimizations, and stabilization.

Subpixel positioning support allows improved glyph outlines with the
Freetype font backend.

For a complete log of changes, please see

[https://cairographics.org/releases/ChangeLog.1.17.4](https://cairographics.org/releases/ChangeLog.1.17.4)

On a personal note, this will be my last release for Cairo.  My Cairo
time availability has been non-existent (particularly this crazy past
year).  The release process is well documented and hopefully will help
whomever picks up the baton from here.


# Full Changes Since 1.17.2

#### Adrian Johnson (1):
- tags: Don't ignore tag on empty pages

#### Anton Danilkin (1):
- Fix testing in the full mode for PDF, PS and SVG backends

#### Antony Lee (1):
- Fix off-by-one bug in tor22-scan-converter.

#### Bryce Harrington (7):
- Start 1.17.2+1 development
- cairo: Fix Since number for new color formats
- surface: Fix spelling fix
- gitignore: gtk-doc.m4
- Revert "clip-boxes:  Drop too-early return"
- build: Update ssh url for cairographics.org
- Release 1.17.4

#### Carlos Garcia Campos (1):
- ft: Fix memory leak in _cairo_ft_unscaled_font_init

#### Fabrice Fontaine (1):
- test: fix build when SHOULD_FORK is false

#### Federico Mena Quintero (1):
- Don't use deprecated rsvg_set_default_dpi()

#### Florian M=FCllner (1):
- ft-font: Fix color font support

#### F=E9lix Poisot (1):
- The array introduced in bff47b43 isn't cleared on surface finish

#### George Matsumura (48):
- cogl: Update to match changed cogl-experimental public API
- cogl: Futher changes to match new cogl-experimental public API
- cogl: Use new separate functions for offscreen and onscreen framebuff=
ers
- cogl: Add dependency on cogl-path
- cogl: Accommodate new context functions
- cogl: Handle framebuffer formats better in case contents are unknown
- cogl: Correct behavior of boilerplate surface finishing functions
- cogl: Fix passing wrong type to _cairo_cogl_clip_push_box
- cogl: Fix push_group and pop_group context functions
- cogl: Account for new representations of framebuffer types
- cogl: Convert int to fixed-point in rectangle painting fallback
- cogl: Handle recording surface sources properly
- cogl: Move context, device, and surface members to most fitting places
- cogl: Fix crash when specifying only mask surface
- cogl: Trailing whitespace fix
- cogl: Fix handling of translated pattern matrices
- cogl: Fix aliased vertex buffer offset
- cogl: Support combinations of mask and source patterns correctly
- cogl: Support CAIRO_EXTEND_NONE correctly
- cogl: Correct usage of clip boxes
- cogl: Fix rectangle filling conditions
- cogl: Support more unbounded operators
- cogl: Use less memory during recording surface replaying
- cogl: Fix very small surfaces in boilerplate
- cogl: Support raster sources
- cogl: Fix rectangular filling fast path
- cogl: Flush the path before calling functions that require it
- cogl: Avoid duplicate representations of the path
- cogl: Handle negative stride images correctly
- cogl: Properly support unbounded operators
- cogl: Move framebuffer creation functionality out of boilerplate
- cogl: Improve support for hardware without mirrored repeating
- cogl: Ensure onscreen framebuffers have an alpha component if required
- cogl: Support source surfaces without an alpha component
- cogl: Limit size of journal
- cogl: Support mirroring of gradients if no hardware support exists
- cogl: Increase reading performance of RGB-only surfaces
- cogl: Fix reference counting bugs
- cogl: Add minimal font support
- cogl: Add new path cache
- cogl: Remove filling with cogl-path
- meson: Remove unconditional disable of cogl backend build
- meson: Fix musl build
- svg2png: Remove deprecated handle closing function call
- cogl: Add build version requirement
- build: Include correct poll.h
- build: Fix various compiler warnings
- cairo-trace: Fix escape character encoding in string literals

#### Heiko Lewin (1):
- Delete fill_rectangles_shader on device finish

#### Jan Alexander Steffens (heftig) (1):
- image compositor: Remove the right glyph from pixman's cache

#### Jordan Petridis (1):
- port the CI setup to freedesktop/citemplates

#### Marek Kasik (1):
- cff: Allow empty array of operands for certain operators

#### Massimo Valentini (1):
- add a test to exercise tor22 spans allocation code path

#### Mathieu Duponchelle (6):
- record tests: fix when builddir !=3D srcdir
- raster-source: fix when builddir !=3D srcdir
- cairo-qt-surface: fix arguments of _cairo_surface_init()
- script-surface: Fix unitialized variable compiler warning
- Fix build on Windows with recent versions of MSVC
- Add meson build definitions

#### Matthias Clasen (5):
- image compositor: Support subpixel positioning
- Add a testcase for subpixel positioning
- xlib compositor: Support subpixel positioning
- Fix a thinko in composite_color_glyphs
- Fix vertical subpixel positioning

#### Michal Sudolsky (1):
- fix double free and failed assertions in cairo_scaled_font_destroy

#### Nirbheek Chauhan (4):
- meson: Fix win32 libs in cairo-win32*.pc files
- meson: Add dependencies to the declared libcairo dep
- meson: Fix libpng fallback dependency variable
- libpng.wrap: Bump to latest version

#### Sergei Trofimovich (1):
- build/aclocal.float.m4: detect 'strings' with AC_CHECK_TOOL

#### Sven Neumann (1):
- Fix conversion from ISO 8601 to PDF date string

#### Tim-Philipp M=FCller (11):
- meson: fix cairo-script-interpreter library name
- meson: update fontconfig wrap and add gperf wrap
- meson: add summary and flip some options to disabled by default
- meson: ensure srcdir doesn't contain autotools build artifacts
- autotools: dist Meson build system files
- ci: add native Windows MSVC build with Meson
- Retire dummy cairo-version.h header to fix meson subproject build
- meson: extract meson version from cairo-version.h
- meson: align gl backend option defaults with autotools
- ci: require opengl in meson fedora build
- ci: fix default options in meson ci

#### Ting-Wei Lan (1):
- meson: Fix undefined reference when bfd library is installed

#### Uli Schlachter (18):
- steal boxes: Fix an invalif free() exposed by cb871c6c
- .gitlab-ci.yml: Temporarily switch to Fedora rawhide
- Merge branch 'fix-xml-unclosed-scaled-font-element'
- Merge branch 'ft-leak' of gitlab.freedesktop.org:carlosgc/cairo
- Initialize mutexes in _cairo_ft_unscaled_font_map_lock()
- Merge branch 'master' of gitlab.freedesktop.org:trofi/cairo
- Merge branch 'master' of gitlab.freedesktop.org:ffontaine/cairo
- Merge branch 'fix-build-rule-for-font-variations'
- Merge branch 'invalid-free-crash' of gitlab.freedesktop.org:psychon/cairo
- Merge branch 'master' of gitlab.freedesktop.org:sgerwk/cairo
- Make the test suite succeed on GitLab CI
- Fix/silence some warnings in 'make check'
- Merge branch 'meson-ci-require-gl-on-fedora' into 'master'
- Merge branch 'fix-iso8601_to_pdf_date_string' into 'master'
- Merge branch 'empty-delta-arrays' into 'master'
- Merge branch 'trace_parse_fix' into 'master'
- Merge branch 'pdf-leak' into 'master'
- Merge branch 'meson-ci-fix' into 'master'

#### Vasilij Schneidermann (1):
- Disable sphinx build if PNG support is disabled

#### Xavier Claessens (5):
- meson: Fix cross build with Android NDK
- meson: Fix build when libpng is not found
- meson: Use pkgmod.generate() for all cairo pc files
- cairo-gobject: Missing cairo include directories
- meson: cairo-ft depends on fontconfig if available

#### luzpaz (1):
- Fix documentation typo in src/cairo-surface.c

#### sgerwk (1):
- a surface may also be checked for status after finishing

#### suzuki toshiya (3):
- Makefile.sources: move font-variations.c from test_sources
- xml: fix unclosed <scaled-font> element
- regrouping of test sources with new 'fc_font_test_sources' group
