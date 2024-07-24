#ifndef FDF_H
#define FDF_H

#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <math.h>
#include "libft/inc/libft.h"
#include "libft/inc/get_next_line.h"
#include "libft/inc/ft_printf.h"

#define WIDTH 1920
#define HEIGHT 1080

// Structure to hold a point's coordinates
typedef struct s_point
{
    int x;
    int y;
    int z;
    int color;
} t_point;

// Structure to hold the main FDF data
typedef struct s_fdf
{
    void *mlx;
    void *win;
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
    int **z_matrix;
    int width;
    int height;
} t_fdf;

// Function prototypes
void init_fdf(t_fdf *fdf, char *filename);
char **read_file(char *filename);
void parse_data(t_fdf *fdf, char **map);
int render(t_fdf *fdf);
void draw_line(t_fdf *fdf, t_point p1, t_point p2);
void put_pixel(t_fdf *fdf, int x, int y, int color);
int handle_key(int key, t_fdf *fdf);
void free_memory(t_fdf *fdf);
t_point project(t_fdf *fdf, int x, int y);

#endif
