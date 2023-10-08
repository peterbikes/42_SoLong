/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 16:38:13 by psotto-m          #+#    #+#             */
/*   Updated: 2023/10/08 15:57:53 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	handle_right_mov(t_game *so_long, int exit)
{
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length + 1] == '1')
		return (0);
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length + 1] == 'E')
		exit = 1;
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length + 1] == 'C')
	{
		so_long->map[so_long->player_location_height] \
		[so_long->player_location_length + 1] = '0';
		so_long->collectibles--;
	}
	so_long->movements += 1;
	so_long->player_location_length += 1;
	print_moves(so_long);
	return (exit);
}

int	handle_left_mov(t_game *so_long, int exit)
{
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length - 1] == '1')
		return (0);
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length - 1] == 'E')
		exit = 1;
	if (so_long->map[so_long->player_location_height] \
	[so_long->player_location_length - 1] == 'C')
	{
		so_long->map[so_long->player_location_height] \
		[so_long->player_location_length - 1] = '0';
		so_long->collectibles--;
	}
	so_long->movements += 1;
	so_long->player_location_length -= 1;
	print_moves(so_long);
	return (exit);
}

int	handle_down_mov(t_game *so_long, int exit)
{
	if (so_long->map[so_long->player_location_height - 1] \
	[so_long->player_location_length] == '1')
		return (0);
	if (so_long->map[so_long->player_location_height - 1] \
	[so_long->player_location_length] == 'E')
		exit = 1;
	if (so_long->map[so_long->player_location_height - 1] \
	[so_long->player_location_length] == 'C')
	{
		so_long->map[so_long->player_location_height - 1] \
		[so_long->player_location_length] = '0';
		so_long->collectibles--;
	}
	so_long->movements += 1;
	so_long->player_location_height -= 1;
	print_moves(so_long);
	return (exit);
}

int	handle_up_mov(t_game *so_long, int exit)
{
	if (so_long->map[so_long->player_location_height + 1] \
	[so_long->player_location_length] == '1')
		return (0);
	if (so_long->map[so_long->player_location_height + 1] \
	[so_long->player_location_length] == 'E')
		exit = 1;
	if (so_long->map[so_long->player_location_height + 1] \
	[so_long->player_location_length] == 'C')
	{
		so_long->map[so_long->player_location_height + 1] \
		[so_long->player_location_length] = '0';
		so_long->collectibles--;
	}
	so_long->movements += 1;
	so_long->player_location_height += 1;
	print_moves(so_long);
	return (exit);
}
