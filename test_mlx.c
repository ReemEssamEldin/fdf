#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (mlx == NULL)
    {
        printf("mlx_init failed\n");
        return (1); // mlx_init failed
    }

    win = mlx_new_window(mlx, 800, 600, "Test Window");
    if (win == NULL)
    {
        return (1); // mlx_new_window failed
    }

    mlx_loop(mlx);
    return (0);
}
