// project.c
#include "fdf.h"


#define SCALE 15
#define OFFSET_X 200
#define OFFSET_Y 410
#define X_ANGLE 1.0472
#define Y_ANGLE 0.249066
#define Z_HEIGHT 10
t_point project(t_fdf *fdf, int x, int y)
{
    t_point point;

    point.x = (x + y) * cos(X_ANGLE) * SCALE + OFFSET_X; // isometric projection with scaling and offset
    point.y = (y - x) * sin(Y_ANGLE) * (SCALE)-fdf->z_matrix[y][x] * Z_HEIGHT + OFFSET_Y;

    point.z = fdf->z_matrix[y][x];
    point.color = 0xFFFFFF; // white color for now
    return point;
}