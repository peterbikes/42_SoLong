/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_updates.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:29:59 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:12:51 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	handle_update_up(t_game *so_long)
{
	if (so_long->map[so_long->player_location_height - 1] \
	[so_long->player_location_length] == 'E')
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->exit, so_long->player_location_length * 64, \
		(so_long->player_location_height - 1) * 64);
	else
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->floor, so_long->player_location_length * 64, \
		(so_long->player_location_height - 1) * 64);
}

void	handle_update_down(t_game *so_long)
{
	if (so_long->map[so_long->player_location_height + 1] \
	[so_long->player_location_length] == 'E')
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->exit, so_long->player_location_length * 64, \
		(so_long->player_location_height + 1) * 64);
	else
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->floor, so_long->player_location_length * 64, \
		(so_long->player_location_height + 1) * 64);
}

void	handle_update_left(t_game *so_long)
{
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length + 1] == 'E')
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->exit, (so_long->player_location_length + 1) * 64, \
		so_long->player_location_height * 64);
	else
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->floor, (so_long->player_location_length + 1) * 64, \
		so_long->player_location_height * 64);
}

void	handle_update_right(t_game *so_long)
{
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length - 1] == 'E')
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->exit, (so_long->player_location_length - 1) * 64, \
		so_long->player_location_height * 64);
	else
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->floor, (so_long->player_location_length - 1) * 64, \
		so_long->player_location_height * 64);
}
