/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 16:20:22 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:40:08 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_map2(char **map, int height, int length, t_game *so_long)
{
	int	k;
	int	i;

	k = 1;
	i = 0;
	while (k < height - 1)
	{
		if (map[k][0] != '1' || map[k][length - 2] != '1')
			layout_errors(so_long, 2);
		while (map[k][i])
		{
			if (map[k][i] != '1' && map[k][i] != '0' && map[k][i] != 'P'
			&& map[k][i] != 'C' && map[k][i] != 'E')
				layout_errors(so_long, 3);
			else
				symbol_control(map[k][i], so_long);
			i++;
		}
		i = 0;
		k++;
	}
	elements_control(so_long);
	find_player(map, height, so_long);
}

void	check_map(char **map, t_game *so_long)
{
	int	height;
	int	length;
	int	i;

	height = so_long->map_height;
	length = so_long->map_length;
	i = 0;
	while (map[0][i])
	{
		if (map[0][i] != '1' && map[0][i] != '\0')
			layout_errors(so_long, 0);
		if (map[height - 1][i] != '1' && map[height - 1][i] != '\0')
			layout_errors(so_long, 1);
		i++;
	}
	check_map2(map, height, length, so_long);
	flood_fill(so_long);
}
