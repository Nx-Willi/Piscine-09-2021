/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 11:20:06 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/10 10:44:40 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(char a, char b)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
	write(1, " ", 1);
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
}

void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	b = 1;
	while (a <= 99)
	{
		ft_putnbr(a, b);
		if (b == 99)
		{
			b = a + 1;
			a++;
		}
		b++;
		if (a == 99)
			break ;
		else
			write(1, ", ", 2);
	}
}
