/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:18:26 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/24 13:20:12 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define SCALE 15
#define OFFSET_X 200
#define OFFSET_Y 410
#define X_ANGLE 1.0472
#define Y_ANGLE 0.249066
#define Z_HEIGHT 10

t_point	project(t_fdf *fdf, int x, int y)
{
	t_point	point;

	point.x = (x + y) * cos(X_ANGLE) * SCALE + OFFSET_X;
	point.y = (y - x) * sin(Y_ANGLE) * (SCALE)-fdf->z_matrix[y][x] * Z_HEIGHT + OFFSET_Y;
	point.z = fdf->z_matrix[y][x];
	point.color = 0xFFFFFF;
	return (point);
}