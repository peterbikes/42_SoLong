/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 18:27:44 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:12:34 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(t_game *so_long)
{
	int	i;

	i = 0;
	while (i < so_long->map_height)
	{
		free(so_long->map[i]);
		i++;
	}
	free(so_long->map);
	i = 0;
	while (i < so_long->map_height)
	{
		free(so_long->flood_fill[i]);
		i++;
	}
	free(so_long->flood_fill);
}

int	game_over(t_game *so_long)
{	
	if (!so_long)
		return (0);
	if (so_long->exit)
		mlx_destroy_image(so_long->mlx_init, so_long->exit);
	if (so_long->burger)
		mlx_destroy_image(so_long->mlx_init, so_long->burger);
	if (so_long->player)
		mlx_destroy_image(so_long->mlx_init, so_long->player);
	if (so_long->floor)
		mlx_destroy_image(so_long->mlx_init, so_long->floor);
	if (so_long->wall)
		mlx_destroy_image(so_long->mlx_init, so_long->wall);
	if (so_long->player_exit)
		mlx_destroy_image(so_long->mlx_init, so_long->player_exit);
	mlx_destroy_window(so_long->mlx_init, so_long->game_window);
	mlx_destroy_display(so_long->mlx_init);
	free(so_long->mlx_init);
	free_map(so_long);
	exit (1);
	return (0);
}
