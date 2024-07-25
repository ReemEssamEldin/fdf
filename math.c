/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:18:44 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/25 13:10:23 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_math	get_line_math(t_point p1, t_point p2)
{
	t_math	math;

	math.dx = abs(p2.x - p1.x);
	math.dy = abs(p2.y - p1.y);
	math.sx = get_movement_direction(p1.x, p2.x);
	math.sy = get_movement_direction(p1.y, p2.y);
	math.err = calculate_error_term(math.dx, math.dy);
	return (math);
}

int	get_movement_direction(int p1, int p2)
{
	if (p1 < p2)
		return (1);
	else
		return (-1);
}

int	calculate_error_term(int dx, int dy)
{
	if (dx > dy)
		return (dx / 2);
	else
		return (-dy / 2);
}
