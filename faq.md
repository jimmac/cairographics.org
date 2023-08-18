---
layout: default
---
This is a list of answers to questions that are frequently asked by new users to cairo.

1.  [Getting Started](#getting-started)
    1.  [What would a minimal C program look like using cairo?](#what-would-a-minimal-c-program-look-like-using-cairo)
    2.  [What compilation flags are required to compile that code?](#what-compilation-flags-are-required-to-compile-that-code)
2.  [Drawing Questions](#drawing-questions)
    1.  [How do I clear a surface?](#how-do-i-clear-a-surface)
    2.  [How do I paint from one surface to another?](#how-do-i-paint-from-one-surface-to-another)
    3.  [How do I draw a sharp, single-pixel-wide line?](#how-do-i-draw-a-sharp-single-pixel-wide-line)
    4.  [How do I use pango instead of cairo's "toy" text API?](#how-do-i-use-pango-instead-of-cairos-toy-text-api)
3.  [Performance Concerns](#performance-concerns)
    1.  [Clipping should only make things faster, right?](#clipping-should-only-make-things-faster-right)
    2.  [My application's slower than I think it should be. What can I do to help the cairo community find the problem?](#my-applications-slower-than-i-think-it-should-be-what-can-i-do-to-help-the-cairo-community-find-the-problem)

# Getting Started

## What would a minimal C program look like using cairo?

Create a file called `hello.c` containing

```C
    #include <cairo.h>

    int
    main (int argc, char *argv[])
    {
            cairo_surface_t *surface =
                cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 240, 80);
            cairo_t *cr =
                cairo_create (surface);

            cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
            cairo_set_font_size (cr, 32.0);
            cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
            cairo_move_to (cr, 10.0, 50.0);
            cairo_show_text (cr, "Hello, world");

            cairo_destroy (cr);
            cairo_surface_write_to_png (surface, "hello.png");
            cairo_surface_destroy (surface);
            return 0;
    }
```

After compiling, run the resulting `hello` program you'll have a PNG image file named `hello.png` with "Hello World" written in blue.

## What compilation flags are required to compile that code?

You will need to instruct the compiler where to find the cairo.h file, (generally something like `-I /usr/include/cairo`), and tell the linker where to find the cairo library and to link with it, (often something like `-L /usr/lib -lcairo`).

But the exact flags and paths will depend on your compiler and your installation of cairo. To simplify this, cairo uses pkg-config which can help you determine the correct flags to use. If you have pkg-config installed, then you can compile the above hello.c with:

```bash
    cc -o hello $(pkg-config --cflags --libs cairo) hello.c
```

If you are using a csh style shell, use backquotes:

```bash
    cc -o hello `pkg-config --cflags --libs cairo` hello.c
```

If cairo is not installed to a system directory that pkg-config is aware of, then you will need to tell pkg-config about the directory by setting the `PKG_CONFIG_PATH` environment variable to point to the directory into which cairo.pc is installed, For example, with bash:

```bash
    export PKG_CONFIG_PATH=/usr/local/lib/pkgconfig
```

or for csh:

```bash
    setenv PKG_CONFIG_PATH /usr/local/lib/pkgconfig
```

# Drawing questions

## How do I clear a surface?

If you want to clear your surface to a uniform, opaque color then it is quite straightforward:

```C
    /* Set surface to opaque color (r, g, b) */
    cairo_set_source_rgb (cr, r, g, b);
    cairo_paint (cr);
```

However, what if you want to clear the surface to something other than an opaque color. Simply modifying the above code to use "`cairo_set_source_rgba` (cr, 0, 0, 0, 0);" will not work since cairo uses the `OVER` compositing operator by default, and blending something entirely transparent `OVER` something else has no effect at all. Instead, you can use the `SOURCE` operator which copies both color and alpha values directly from the source to the destination instead of blending:

```C
    /* Set surface to translucent color (r, g, b, a) */
    cairo_set_source_rgba (cr, r, g, b, a);
    cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint (cr);
```

Of course, you won't want to forget to set the default `CAIRO_OPERATOR_OVER` again when you're finished. And the most convenient habit for doing that is to just use `cairo_save`/`cairo_restore` around the whole block:

```C
    /* Set surface to translucent color (r, g, b, a) without disturbing graphics state. */
    cairo_save (cr);
    cairo_set_source_rgba (cr, r, g, b, a);
    cairo_set_operator (cr, CAIRO_OPERATOR_SOURCE);
    cairo_paint (cr);
    cairo_restore (cr);
```

Finally, to clear a surface to all transparent, one could simply use `CAIRO_OPERATOR_CLEAR` instead of `CAIRO_OPERATOR_SOURCE`, in which case the call to `cairo_set_source_rgba` would not be needed at all, (the `CLEAR` operator always sets the destination to 0 in every channel regardless of what the source pattern contains). But the above approach with `CAIRO_OPERATOR_SOURCE` is a more general way to clear the surface since it allows for "clearing" to a translucent color such as 50% red rather than just clearing to entirely transparent.

## How do I paint from one surface to another?

If you have some surface _source_ which you'd like to paint to some surface _destination_ at position (`x`, `y`) you would use code as follows:

```C
    cairo_t *cr = cairo_create (destination);
    cairo_set_source_surface (cr, source, x, y);
    cairo_paint (cr);
```

Note that the paint operation will copy the entire surface. If you'd like to instead copy some (`width`, `height`) rectangle from (`source_x`, `source_y`) to some point (`dest_x`, `dest_y`) on the destination you would instead compute a new position for the source surface origin and then use `cairo_fill` instead of `cairo_paint`:

```C
    cairo_set_source_surface (cr, source, dest_x - source_x, dest_y - source_y)
    cairo_rectangle (cr, dest_x, dest_y, width, height);
    cairo_fill (cr);
```

And note that using a surface as the source pattern will work with any other cairo drawing operation as well. You can use `cairo_set_source_surface` to get patterned effects from cairo_stroke or `cairo_show_text` just as easily.

Finally, by default cairo uses the `OVER` operator when drawing, so if the source surface contains alpha content, then it will be used to blend the source over the destination. This is often exactly what is desired, but if you would like to directly copy alpha information from the source to the destination without blending, then you can use `cairo_set_operator` with `CAIRO_OPERATOR_SOURCE` to do that, (see [clearing a surface](#clear_a_surface) for some examples using `CAIRO_OPERATOR_SOURCE`).

## How do I draw a sharp, single-pixel-wide line?

Question: Whenever I try drawing with a line-width of 1.0, my horizontal/vertical lines come out fat and blurry (eg. 2 pixels wide and half-intensity). What's wrong?

Answer: This problem usually shows up with code like the following, (and with the default transformation matrix):

```C
    cairo_move_to (cr, 10, 10);
    cairo_line_to (cr, 20, 10);
    cairo_set_line_width (cr, 1);
    cairo_stroke (cr);
```

The user expects 10 pixels in one row to be affected, but instead the line is "smeared" over 20 pixels in two rows.

The reason this happens is easy to explain to someone who believes pixels are little squares. By default, integer coordinates map to the intersections of the pixel squares. So a width-1 horizontal/vertical line is centered on the boundary between pixel rows and extends half way into the pixels on either side.

When some people hear pixels described as little squares it sets their teeth on edge. For them we have this alternate explanation. By default, integer coordinates map to points half way between sample point locations. So a width-1 horizontal/vertical will be centered between two rows of pixel sample points and will contribute equally to the pixels on either side, (assuming a symmetric filter which is always the case when synthesizing images in cairo).

Either way, you can avoid the issue by using an even-integer line width, (note that the default line width in cairo is 2.0). A line drawn this way will still affect just as many pixels, but they will be affected at full intensity.

Otherwise, if you really want to light up a single row of pixels at full intensity, you can do that by adjusting the endpoints by 0.5 in the appropriate direction. For example, by changing the above code to:

```C
    cairo_move_to (cr, 10, 10.5);
    cairo_line_to (cr, 20, 10.5);
    cairo_set_line_width (cr, 1);
    cairo_stroke (cr);
```

The reason that cairo does it this way is so that fills align nicely, at the cost that some strokes do not. It is not possible to set up sample locations in a way so that both fills and strokes with integer coordinates work nicely, so one had to be preferred over the other. One argument in favor of preferring fills is that all fills with integer coordinates align nicely this way. The best that can be done with strokes is to make all even-integer-width strokes align nicely (as they do in cairo) or to make odd-integer-width strokes align (which would then break the fill alignment).

It is important to note that all of this discussion assumes the default transformation matrix. Under other transformations, the relationship between user-space coordinates and device-space pixels may be quite different. Guaranteeing alignment with the device-pixel grid, "snapping", in such cases is still possible and is often worth doing (except in situations such as animated zooms where the snapping would lead to undesired jitter in the result). The trick to snapping is simply to perform rounding in device-space so that rectilinear geometry lands at integer position in the device-space grid. So, the process might look something like:

```C
    cairo_user_to_device (cr, &x, &y);
    do_rounding (&x, &y);
    cairo_device_to_user (cr, &x, &y);
```

and then using the resulting x and y values to construct a path. Note that the `do_rounding` function will likely need to be different depending on how the coordinates are being used. For example, for a fill or a stroke with an even-integer line width, this function might round to the nearest integer. For a stroke with an odd-integer line width, it might round to the nearest half integer.

## How do I use pango instead of cairo's "toy" text API?

In the [getting started](#getting_started) example, we showed how simple it can be to display a few text characters with cairo:

```C
    cairo_select_font_face (cr, "serif", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_font_size (cr, 32.0);
    cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
    cairo_move_to (cr, 10.0, 50.0);
    cairo_show_text (cr, "Hello, world");
```

But as you read the cairo documentation and talk to expert cairo users, you learn that `cairo_show_text` is part of cairo's "toy" text API. It's fine for quick demos, and for learning how to use cairo, but it's not intended for use in actual applications.

It's not hard to run into some of the limitations of `cairo_show_text`. For example, it will only display glyphs from a single font. So if you happen to choose a font that doesn't provide glyphs covering every character in your string, then some characters just won't appear. It has a host of other limitations with respect to layout, ligatures, and shaping. We won't go into all of those details here, but suffice it to say that if you have any aspirations of having reasonable, internationalized text display in your application, then you don't want to be using `cairo_show_text`.

Meanwhile, the non-toy APIs in cairo, (`cairo_show_glyphs` and `cairo_show_text_glyphs`), are really hard to use. Compared to `cairo_show_text`, these still don't do any of the heavy lifting of text, but instead expect that the caller has done all of that already. So you could use these as the basis of a sophisticated text-layout engine, but chances are that you'd rather spend the next several years on your application instead.

Fortunately, the pango library exists and does do sophisticated text layout, shaping, etc. and integrates very nicely with cairo. We heartily recommend that "real" applications wanting to display text with cairo use pango to do it.

And it's really not that hard to get started using pango. The pango-using equivalent of our code above is:

```C
    #include <pango/pangocairo.h>
    PangoLayout *layout;
    PangoFontDescription *font_description;

    font_description = pango_font_description_new ();
    pango_font_description_set_family (font_description, "serif");
    pango_font_description_set_weight (font_description, PANGO_WEIGHT_BOLD);
    pango_font_description_set_absolute_size (font_description, 32 * PANGO_SCALE);

    layout = pango_cairo_create_layout (cr);
    pango_layout_set_font_description (layout, font_description);
    pango_layout_set_text (layout, "Hello, world", -1);

    cairo_set_source_rgb (cr, 0.0, 0.0, 1.0);
    cairo_move_to (cr, 10.0, 50.0);
    pango_cairo_show_layout (cr, layout);

    g_object_unref (layout);
    pango_font_description_free (font_description);
```

Note that this does have slightly different text placement from the previous example. To get the same text origin as `cairo_show_text`, (baseline left, instead of Pango's top left), replace the `pango_cairo_show_layout` line with this:

    pango_cairo_show_layout_line (cr, pango_layout_get_line (layout, 0));

Finally, to compile a pango-using program, you'll want to change the compilation flags we suggested before from `$(pkg-config --cflags --libs cairo)` to `$(pkg-config --cflags --libs pangocairo)`.

Hopefully that's enough to get started using pango. See the [Pango Reference Manual](http://library.gnome.org/devel/pango/stable/) for more details as needed.

# Performance concerns

## Clipping should only make things faster, right?

The `cairo_clip` function can be used for two different operations. The first is to restrict the set of pixels that need to be updated, (imagine needing to draw only half of a window that was just uncovered by another window). While the second is to modify what is being drawn with some non-pixel-aligned shape (imagine a circular clip path, for example).

These two uses result in very different code paths inside cairo and in the underlying window system. The first case can result in faster performance compared to unclipped drawing, since the same drawing operations can be performed but fewer pixels are updated. The second case can actually result in slower performance as an extra compositing step must be added to get the clipped result. This is because the pixels on the edge of the mask will have different values than they would in the unclipped case, (a non-pixel-aligned clip path results in antialiased clipping).

So there's a bit of a performance trap there as one might add clipping to try to speed things up and inadvertently cause things to go slower. The trick to get fast clipping is to ensure the path is always aligned with integer positions on the device-pixel grid. And the easiest way to do that is to use an identity transformation, (`cairo_identity_matrix`), and construct the path by calling `cairo_rectangle` with integer values.

## My application's slower than I think it should be. What can I do to help the cairo community find the problem?

The first step in analysing any problem is constructing a reproducible test case. Cairo provides a cairo-trace utility (currently only available from the git development tree and in the 1.9.6 [snapshot](/snapshots) but also planned for inclusion with Cairo 1.10). This utility records all Cairo calls made by an application and allows you, and everyone else in the community, to replay the exact same sequence. This trace can be reviewed by others and they may be able to suggest alternative methods of achieving the same results. Or it may provide the developers with a useful benchmark for improving Cairo.

### How to generate a trace:

After installing Cairo from git, a 1.9 snapshot or a later release the cairo-trace utility will be available.

```bash
    $ cairo-trace
    usage: cairo-trace [--no-file] command
    cairo-trace will generate a log of all calls made by command to
    cairo. This log will be stored in a file in the local directory
    called command.pid.trace.
    Whatever else happens is driven by its argument:
      --flush         - Flush the output trace after every call.
      --no-file       - Disable the creation of an output file. Outputs to the terminal instead.
      --no-callers    - Do not lookup the caller address/symbol/line whilst tracing.
      --mark-dirty    - Record image data for cairo_mark_dirty() [default]
      --no-mark-dirty - Do not record image data for cairo_mark_dirty()
      --compress      - Compress the output with LZMA
      --profile       - Combine --no-callers and --no-mark-dirty and --compress
```

That is performing

    $ cairo-trace any-application

and then operating the application as desired will generate an output file called any-application.$pid.trace.

If you want to record a trace to share with others for performance measurement, then use the --profile option to cairo-trace as follows:

```bash
    $ cairo-trace --profile any-application
```

This eliminates the extra caller information from the trace, (which reduces overhead when replaying), and compresses the output, (decompress with the "lzma -cd").

### How to benchmark an existing trace:

To benchmark the performance of a trace, run:

```bash
    $ cairo-perf-trace application.trace
```

which will replay the trace several times against multiple backends and report the time required for replay against each backend.

### What traces has the community collected?

A compilation of "interesting" traces can be found in the [cairo-traces repository](http://cgit.freedesktop.org/cairo-traces). This collection includes traces of various uses of common applications such as firefox, gnome-terminal, swfdec (including viewing youtube), and poppler.

By checking this repository out to perf/cairo-traces in the cairo source directory, these traces will be automatically run by "cairo-perf-trace" (with no arguments) as well as by "make perf". Note that some of these traces are very long and intended to stress the system, and so we keep a representative selection of shorter traces which can be run using "./cairo-perf-trace -i3 cairo-traces/benchmark".


Written with love using [Apostrophe](https://flathub.org/apps/details/org.gnome.gitlab.somas.Apostrophe).
