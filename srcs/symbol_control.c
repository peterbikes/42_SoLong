/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   symbol_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 19:50:04 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:13:22 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	symbol_control(char element, t_game *so_long)
{
	if (element == 'C')
		so_long->collectibles += 1;
	if (element == 'E')
		so_long->exit_check += 1;
	if (element == 'P')
		so_long->player_check += 1;
}
