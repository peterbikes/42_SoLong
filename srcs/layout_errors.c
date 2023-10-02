/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   layout_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 18:14:35 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/20 09:54:19 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	layout_errors(t_game *so_long, int flag)
{
	if (flag == 0)
		write(2, "Error\nHole in the top wall x_x\n", 31);
	if (flag == 1)
		write(2, "Error\nHole in the bottom wall x_x\n", 34);
	if (flag == 2)
		write(2, "Error\nHole in the side walls x_x\n", 33);
	if (flag == 3)
		write(2, "Error\nBad symbol somewhere on your map x_x\n", 43);
	if (flag == 4)
		write(2, "Error\nThere is no player on your map x_x\n", 41);
	if (flag == 5)
		write(2, "Error\nThis is a single player game, check your map!\n", 52);
	if (flag == 6)
		write(2, "Error\nThere is no exit on your map x_x\n", 39);
	if (flag == 7)
		write(2, "Error\nNice try, only one exit allowed! x_x\n", 43);
	if (flag == 8)
		write(2, "Error\nYou need something to collect, check your map!\n", 53);
	if (flag == 9)
		write(2, "Error\nThis game is impossible x_x\n", 34);
	free_map(so_long);
	exit (1);
}
