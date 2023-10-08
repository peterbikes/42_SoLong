/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 15:29:11 by psotto-m          #+#    #+#             */
/*   Updated: 2023/10/08 15:58:39 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	find_player(char **map, int height, t_game *so_long)
{
	int	k;
	int	i;

	k = 1;
	i = 0;
	while (k < height - 1)
	{
		while (map[k][i])
		{
			if (map[k][i] == 'P')
			{
				so_long->player_location_length = i;
				so_long->player_location_height = k;
				break ;
			}
			i++;
		}
		i = 0;
		k++;
	}
}
