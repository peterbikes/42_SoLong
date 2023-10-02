/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:35:40 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:12:13 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_xpm(t_game *so_long)
{
	int	tiles;

	tiles = 64;
	so_long->burger = mlx_xpm_file_to_image(so_long->mlx_init, \
	BURGER, &tiles, &tiles);
	so_long->exit = mlx_xpm_file_to_image(so_long->mlx_init, \
	EXIT, &tiles, &tiles);
	so_long->floor = mlx_xpm_file_to_image(so_long->mlx_init, \
	FLOOR, &tiles, &tiles);
	so_long->player_exit = mlx_xpm_file_to_image(so_long->mlx_init, \
	PLAYER_EXIT, &tiles, &tiles);
	so_long->player = mlx_xpm_file_to_image(so_long->mlx_init, \
	PLAYER, &tiles, &tiles);
	so_long->wall = mlx_xpm_file_to_image(so_long->mlx_init, \
	WALL, &tiles, &tiles);
}
