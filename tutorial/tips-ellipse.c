#include <math.h>
#include <cairo.h>

int
main (int argc, char *argv[])
{
        cairo_surface_t *surface;
        cairo_t *cr;

        surface = cairo_image_surface_create (CAIRO_FORMAT_ARGB32, 120, 120);
        cr = cairo_create (surface);
	/* Examples are in 1.0 x 1.0 coordinate space */
	cairo_scale (cr, 120, 120);

	/* Drawing code goes here */
	cairo_set_line_width (cr, 0.1);

	cairo_save (cr);
	cairo_scale (cr, 0.5, 1);
	cairo_arc (cr, 0.5, 0.5, 0.40, 0, 2 * M_PI);
	cairo_stroke (cr);

	cairo_translate (cr, 1, 0);
	cairo_arc (cr, 0.5, 0.5, 0.40, 0, 2 * M_PI);
	cairo_restore (cr);
	cairo_stroke (cr);

	/* Write output and clean up */
        cairo_surface_write_to_png (surface, "tips-ellipse.png");
        cairo_destroy (cr);
        cairo_surface_destroy (surface);

        return 0;
}

