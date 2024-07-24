// events.c
#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int handle_key(int key, t_fdf *fdf) {
    printf("Key pressed: %d\n", key);
    if (key == 53) { // ESC key
        mlx_destroy_window(fdf->mlx, fdf->win);
        exit(0);
    }
    // Add more key handling as needed
    return (0);
}
