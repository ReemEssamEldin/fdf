/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reldahli <reldahli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 14:08:11 by reldahli          #+#    #+#             */
/*   Updated: 2024/07/24 17:28:42 by reldahli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	word_count(char *s, char separator)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != separator)
		{
			count++;
			while (s[i] && s[i] != separator)
				i++;
		}
		else
			i++;
	}
	return (count);
}

void	parse_data(t_fdf *fdf, char **map)
{
	int		i;
	int		j;
	char	**split;

	fdf->height = 0;
	while (map[fdf->height])
		fdf->height++;
	fdf->width = word_count(map[0], ' ');
	fdf->z_matrix = (int **)malloc(sizeof(int *) * fdf->height);
	i = 0;
	while (i < fdf->height)
	{
		fdf->z_matrix[i] = (int *)malloc(sizeof(int) * fdf->width);
		split = ft_split(map[i], ' ');
		j = 0;
		while (j < fdf->width)
		{
			fdf->z_matrix[i][j] = ft_atoi(split[j]);
			free(split[j]);
			j++;
		}
		free(split);
		i++;
	}
}
