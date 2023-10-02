/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:29:16 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:12:19 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ff_helper(char **map, int heigth, int length, t_game *so_long)
{
	static int	collectibles;
	static int	exit;

	if (map[heigth][length] == '1')
		return (0);
	else if (map[heigth][length] == 'C')
		collectibles++;
	else if (map[heigth][length] == 'E')
		exit = 1;
	map[heigth][length] = '1';
	ff_helper(map, heigth + 1, length, so_long);
	ff_helper(map, heigth, length + 1, so_long);
	ff_helper(map, heigth - 1, length, so_long);
	ff_helper(map, heigth, length - 1, so_long);
	if (collectibles != so_long->collectibles || exit == 0)
		return (-1);
	return (1);
}

void	flood_fill(t_game *so_long)
{
	int	solvable;

	solvable = ff_helper(so_long->flood_fill, \
	so_long->player_location_height, so_long->player_location_length, so_long);
	if (solvable == -1)
		layout_errors(so_long, 9);
}
