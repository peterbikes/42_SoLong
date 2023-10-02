/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:55:59 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:13:11 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_map2(t_game *so_long, char tile, int height, int length)
{
	if (tile == '1')
		mlx_put_image_to_window(so_long->mlx_init, so_long->game_window, \
		so_long->wall, length * 64, height * 64);
	if (tile == '0')
		mlx_put_image_to_window(so_long->mlx_init, so_long->game_window, \
		so_long->floor, length * 64, height * 64);
	if (tile == 'P')
		mlx_put_image_to_window(so_long->mlx_init, so_long->game_window, \
		so_long->player, length * 64, height * 64);
	if (tile == 'E')
		mlx_put_image_to_window(so_long->mlx_init, so_long->game_window, \
		so_long->exit, length * 64, height * 64);
	if (tile == 'C')
		mlx_put_image_to_window(so_long->mlx_init, so_long->game_window, \
		so_long->burger, length * 64, height * 64);
}

void	render_map(t_game *so_long)
{
	char	**map;
	int		i;
	int		k;

	map = so_long->map;
	i = 0;
	k = 0;
	while (i < so_long->map_height)
	{
		while (k < so_long->map_length)
		{
			render_map2(so_long, map[i][k], i, k);
			k++;
		}
		k = 0;
		i++;
	}
}
