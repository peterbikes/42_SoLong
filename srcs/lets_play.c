/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lets_play.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:53:59 by psotto-m          #+#    #+#             */
/*   Updated: 2023/03/28 14:54:39 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	controls(int keycode, t_game *so_long)
{
	if (keycode == W)
		movement(so_long, 'y');
	if (keycode == A)
		movement(so_long, 'x');
	if (keycode == S)
		movement(so_long, 'Y');
	if (keycode == D)
		movement(so_long, 'X');
	if (keycode == ESC)
		game_over(so_long);
	return (0);
}

void	lets_play(t_game *so_long)
{
	so_long->mlx_init = mlx_init();
	find_xpm(so_long);
	so_long->game_window = mlx_new_window(so_long->mlx_init, \
	(so_long->map_length - 1) * 64, so_long->map_height * 64, "So LOOOOOONG");
	render_map(so_long);
	mlx_hook(so_long->game_window, 2, 1L << 0, controls, so_long);
	mlx_hook(so_long->game_window, 17, 1L << 2, game_over, so_long);
	mlx_loop(so_long->mlx_init);
}
