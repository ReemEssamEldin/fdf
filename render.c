// render.c
#include "fdf.h"

/**
 * Put a pixel on the image at the given coordinates with the specified color.
 * @param fdf Pointer to the t_fdf structure.
 * @param x X coordinate.
 * @param y Y coordinate.
 * @param color Pixel color.
 */
void put_pixel(t_fdf *fdf, int x, int y, int color)
{
    // Check if coordinates are within bounds.
    if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
    {
        // Calculate the memory address of the pixel.
        // y * fdf->line_length: Move to the correct row.
        // x * (fdf->bits_per_pixel / 8): Move to the correct column within the row.
        char *pixel_addr = fdf->addr + (y * fdf->line_length) + (x * (fdf->bits_per_pixel / 8));

        // Set the pixel color.
        // Assuming 32 bits per pixel, i.e., 4 bytes per pixel.
        *(unsigned int *)pixel_addr = color;
    }
}
void draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
    int dx = abs(p2.x - p1.x);
    int dy = abs(p2.y - p1.y);
    int sx = p1.x < p2.x ? 1 : -1;
    int sy = p1.y < p2.y ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2;
    int e2;

    while (1)
    {
        put_pixel(fdf, p1.x, p1.y, p1.color);
        if (p1.x == p2.x && p1.y == p2.y)
            break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            p1.x += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            p1.y += sy;
        }
    }
}

// render.c
// render.c
int render(t_fdf *fdf)
{
    int x;
    int y;

    y = 0;
    while (y < fdf->height)
    {
        x = 0;
        while (x < fdf->width)
        {
            if (x < fdf->width - 1)
                draw_line(fdf, project(fdf, x, y), project(fdf, x + 1, y));
            if (y < fdf->height - 1)
                draw_line(fdf, project(fdf, x, y), project(fdf, x, y + 1));
            x++;
        }
        mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);

        y++;
    }

    return 1;
}
