/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:17:40 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/24 14:22:49 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>

int	main(void)
{
	void	*mlx;
	void	*win;

	mlx = mlx_init();
	if (mlx == NULL)
	{
		printf("mlx_init failed\n");
		return (1);
	}
	win = mlx_new_window(mlx, 800, 600, "Test Window");
	if (win == NULL)
	{
		return (1);
	}
	mlx_loop(mlx);
	return (0);
}