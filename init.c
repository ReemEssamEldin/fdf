// init.c
#include "fdf.h"

/**
 * Initializes the FDF structure and sets up the necessary components.
 *
 * @param fdf The FDF structure to initialize.
 * @param filename The name of the file containing the map data.
 */
void init_fdf(t_fdf *fdf, char *filename)
{
    // Initialize the map variable
    char **map;

    // Read the file and store the contents in the map variable
    map = read_file(filename);
    if (!map)
        exit(1);

    // Parse the data from the map and store it in the fdf structure
    parse_data(fdf, map);

    // Free the memory allocated for each row in the map
    for (int i = 0; map[i]; i++)
    {
        free(map[i]);
    }
    free(map);

    // Initialize the mlx (MinilibX) library
    fdf->mlx = mlx_init();

    if (!fdf->mlx)
        exit(1);

    // Create a new window using the mlx library
    fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
    if (!fdf->win)
        exit(1);

    // Create a new image using the mlx library
    fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
    if (!fdf->img)
        exit(1);

    // Get the address, bits per pixel, line length, and endianess of the image
    fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);
}
