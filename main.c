// main.c
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

// Entry point of the program
int main(int argc, char **argv)
{
    t_fdf *fdf;

    // Check if the correct number of arguments is provided
    if (argc != 2)
    {
        return (1);
    }

    // Allocate memory for the t_fdf structure
    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    if (!fdf)
        return (1);

    // Initialize the fdf structure
    init_fdf(fdf, argv[1]);

    // Render the fdf
    // render(fdf);

    mlx_loop_hook(fdf->mlx, render, fdf);

    // Set the key hook for handling keyboard events
    mlx_key_hook(fdf->win, handle_key, fdf);

    // Start the main event loop
    mlx_loop(fdf->mlx);

    // Free the allocated memory
    free_memory(fdf);

    return (0);
}
