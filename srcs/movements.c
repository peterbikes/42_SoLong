/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 17:43:58 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:13:07 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_map(t_game *so_long, char coord, int exit)
{
	if (exit == 1 && so_long->collectibles == 0)
		game_over(so_long);
	if (exit == 1 && so_long->collectibles > 0)
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->player_exit, so_long->player_location_length * 64, \
		so_long->player_location_height * 64);
	else
		mlx_put_image_to_window (so_long->mlx_init, so_long->game_window, \
		so_long->player, so_long->player_location_length * 64, \
		so_long->player_location_height * 64);
	if (coord == 'Y')
		handle_update_up(so_long);
	if (coord == 'y')
		handle_update_down(so_long);
	if (coord == 'X')
		handle_update_right(so_long);
	if (coord == 'x')
		handle_update_left(so_long);
}

void	movement(t_game *so_long, char coord)
{
	int	exit;
	int	wall_control;

	wall_control = so_long->movements;
	exit = 0;
	if (coord == 'Y')
		exit = handle_up_mov(so_long, exit);
	else if (coord == 'y')
		exit = handle_down_mov(so_long, exit);
	else if (coord == 'X')
		exit = handle_right_mov(so_long, exit);
	else if (coord == 'x')
		exit = handle_left_mov(so_long, exit);
	if (wall_control != so_long->movements)
		update_map(so_long, coord, exit);
}
