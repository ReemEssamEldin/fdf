// parse_data.c
#include <stdlib.h>
#include "fdf.h"

int word_count(char *s, char separator)
{
    int count;
    int i;

    count = 0;
    i = 0;
    while (s[i])
    {
        if (s[i] != separator)
        {
            count++;
            while (s[i] && s[i] != separator)
                i++;
        }
        else
            i++;
    }
    return count;
}

/**
 * Parse the .fdf file data into a 2D array of integers representing the z-coordinates.
 * @param fdf Pointer to the t_fdf structure.
 * @param map Array of strings representing the .fdf file content.
 */
void parse_data(t_fdf *fdf, char **map)
{
    int i;        // Index for map array.
    int j;        // Index for split array.
    char **split; // Array to hold split line elements.

    fdf->height = 0;
    while (map[fdf->height])
        fdf->height++;
    fdf->width = word_count(map[0], ' ');
    fdf->z_matrix = (int **)malloc(sizeof(int *) * fdf->height);
    i = 0;
    while (i < fdf->height)
    {
        fdf->z_matrix[i] = (int *)malloc(sizeof(int) * fdf->width);
        split = ft_split(map[i], ' ');
        j = 0;
        while (j < fdf->width)
        {
            fdf->z_matrix[i][j] = ft_atoi(split[j]);
            free(split[j]);
            j++;
        }
        free(split);
        i++;
    }
}
