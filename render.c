/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:21:43 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/24 14:17:33 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel_addr;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_addr = fdf->addr + (y * fdf->line_length) + (x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)pixel_addr = color;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;

	dx = abs(p2.x - p1.x);
	dy = abs(p2.y - p1.y);
	sx = p1.x < p2.x ? 1 : -1;
	sy = p1.y < p2.y ? 1 : -1;
	err = (dx > dy ? dx : -dy) / 2;
	while (1)
	{
		put_pixel(fdf, p1.x, p1.y, p1.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			p1.x += sx;
		}
		if (e2 < dy)
		{
			err += dx;
			p1.y += sy;
		}
	}
}

int	render(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->height)
	{
		x = 0;
		while (x < fdf->width)
		{
			if (x < fdf->width - 1)
				draw_line(fdf, project(fdf, x, y), project(fdf, x + 1, y));
			if (y < fdf->height - 1)
				draw_line(fdf, project(fdf, x, y), project(fdf, x, y + 1));
			x++;
		}
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
		y++;
	}
	return (1);
}
