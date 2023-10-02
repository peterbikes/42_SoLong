/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_creation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:26:59 by psotto-m          #+#    #+#             */
/*   Updated: 2023/03/21 21:32:52 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**map_creation(char *str, int height)
{
	int		ber;
	char	**map;
	int		i;

	i = 0;
	ber = open(str, O_RDONLY);
	str = get_next_line(ber);
	map = malloc(sizeof(char *) * height);
	while (i < height)
	{
		map[i] = ft_strtrim(str, "\n");
		free(str);
		str = get_next_line(ber);
		i++;
	}
	close(ber);
	free(str);
	return (map);
}
