/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psotto-m <psotto-m@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 14:37:54 by psotto-m          #+#    #+#             */
/*   Updated: 2023/04/18 12:13:03 by psotto-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_putnbr(long long int n)
{
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((char)(n % 10 + '0'));
}

void	print_moves(t_game *so_long)
{	
	write(1, "Moves: ", 7);
	ft_putnbr(so_long->movements);
	write(1, "\n", 1);
}
