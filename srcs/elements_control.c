/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_control.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:22:22 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:12:04 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	elements_control(t_game *so_long)
{
	if (so_long->player_check == 0)
		layout_errors(so_long, 4);
	if (so_long->player_check > 1)
		layout_errors(so_long, 5);
	if (so_long->exit_check == 0)
		layout_errors(so_long, 6);
	if (so_long->exit_check > 1)
		layout_errors(so_long, 7);
	if (so_long->collectibles < 1)
		layout_errors(so_long, 8);
}
