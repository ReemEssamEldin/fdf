/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:43:24 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/24 15:07:16 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_fdf(t_fdf *fdf, char *filename)
{
	char	**map;
	int		i;

	map = read_file(filename);
	if (!map)
		exit(1);
	parse_data(fdf, map);
	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit(1);
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HEIGHT, "FDF");
	if (!fdf->win)
		exit(1);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	if (!fdf->img)
		exit(1);
	fdf->addr = mlx_get_data_addr(fdf->img, &fdf->bits_per_pixel, &fdf->line_length, &fdf->endian);
}
