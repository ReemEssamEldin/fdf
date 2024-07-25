/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:21:43 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/25 15:28:54 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	put_pixel(t_fdf *fdf, int x, int y, int color)
{
	char	*pixel_addr;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		pixel_addr = fdf->addr + (y * fdf->line_length)
			+ (x * (fdf->bits_per_pixel / 8));
		*(unsigned int *)pixel_addr = color;
	}
}

void	draw_line(t_fdf *fdf, t_point p1, t_point p2)
{
	t_math	math;
	int		err_term;

	math = get_line_math(p1, p2);
	while (1)
	{
		put_pixel(fdf, p1.x, p1.y, p1.color);
		if (p1.x == p2.x && p1.y == p2.y)
			break ;
		err_term = math.err;
		if (err_term > -math.dx)
		{
			math.err -= math.dy;
			p1.x += math.sx;
		}
		if (err_term < math.dy)
		{
			math.err += math.dx;
			p1.y += math.sy;
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
		y++;
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	}
	return (1);
}
