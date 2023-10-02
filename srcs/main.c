/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:58:42 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/20 10:12:33 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_game	so_long;

	if (ac != 2)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (0);
	}
	struct_initiation(&so_long);
	ber_check(av[1]);
	map_sizer(av[1], &so_long, 0, 0);
	if (so_long.map_length == 0)
	{
		write(2, "Error\nEmpty map x_x\n", 20);
		return (0);
	}
	so_long.map = map_creation(av[1], so_long.map_height);
	so_long.flood_fill = map_creation(av[1], so_long.map_height);
	check_map(so_long.map, &so_long);
	lets_play(&so_long);
}
