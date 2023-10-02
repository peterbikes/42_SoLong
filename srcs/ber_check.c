/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ber_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:55:13 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:11:55 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	not_a_ber(void)
{
	write(2, "File does not end with .ber x_x\n", 32);
	write(2, "Or maybe you wrote the wrong path\n", 34);
	exit (1);
}

void	ber_check(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	i--;
	if (str[i] != 'r')
		not_a_ber();
	i--;
	if (str[i] != 'e')
		not_a_ber();
	i--;
	if (str[i] != 'b')
		not_a_ber();
	i--;
	if (str[i] == '.')
		return ;
	not_a_ber();
}
