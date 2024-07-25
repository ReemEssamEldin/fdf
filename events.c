/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:10:58 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/24 16:21:22 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include "fdf.h"

int	handle_key(int key, t_fdf *fdf)
{
	printf("Key pressed: %d\n", key);
	if (key == ESCAPE_KEY)
	{
		close_window(fdf);
	}
	return (0);
}

int	close_window(t_fdf *fdf)
{
	free_memory(fdf);

	mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);

	free(fdf->mlx);
	free(fdf);

	exit(0);
}
