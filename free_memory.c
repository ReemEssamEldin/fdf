// free_memory.c
#include <stdlib.h>
#include "fdf.h"

void free_memory(t_fdf *fdf)
{
    int i;

    i = 0;
    while (i < fdf->height)
    {
        free(fdf->z_matrix[i]);
        i++;
    }
    free(fdf->z_matrix);
}
