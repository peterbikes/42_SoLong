/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initiation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 21:53:10 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:13:17 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	struct_initiation(t_game *so_long)
{
	so_long->map_height = 0;
	so_long->map_length = 0;
	so_long->map = NULL;
	so_long->collectibles = 0;
	so_long->player_check = 0;
	so_long->exit_check = 0;
	so_long->mlx_init = 0;
	so_long->movements = 0;
}
