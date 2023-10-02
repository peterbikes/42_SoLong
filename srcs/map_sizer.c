/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_sizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:59:10 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/20 10:42:00 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	not_a_rectangle(void)
{
	write(2, "Error\nMap is not a rectangle\n", 29);
	exit (1);
}

void	map_sizer(char *str, t_game *so_long, int lines, int line_control)
{
	int		map;
	char	*line;
	int		flag;
	size_t	length;

	flag = 0;
	map = open(str, O_RDONLY);
	line = get_next_line(map);
	length = ft_strlen(line);
	while (line)
	{
		free(line);
		line = get_next_line(map);
		if (ft_strlen(line) != length && line != NULL && line_control == 1)
			flag = 1;
		if ((ft_strlen(line) - 1) == length)
			line_control = 1;
		lines++;
	}
	free(line);
	close(map);
	so_long->map_length = length;
	so_long->map_height = lines;
	if (flag == 1)
		not_a_rectangle();
}
