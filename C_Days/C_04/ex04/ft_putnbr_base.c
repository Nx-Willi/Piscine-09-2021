/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 08:45:01 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/20 16:39:36 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long int nbr, char *base, int base_size)
{
	if (nbr >= base_size)
	{
		ft_putnbr(nbr / base_size, base, base_size);
		ft_putnbr(nbr % base_size, base, base_size);
	}
	else
		ft_putchar(nbr[base]);
}

int	ft_findsamechar_base(char *base)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (base[i] != '\0')
	{
		while (base[i + n] != '\0')
		{
			if (base[i] == base[i + n])
				return (1);
			n++;
		}
		n = 1;
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int			base_size;
	long int	nbr_cast;

	base_size = 0;
	nbr_cast = nbr;
	while (base[base_size])
	{
		if (base[base_size] == '+' || base[base_size] == '-'
			|| base[base_size] <= 32 || base[base_size] >= 126)
			return ;
		base_size++;
	}
	if (base_size <= 1)
		return ;
	if (ft_findsamechar_base(base) == 1)
		return ;
	if (nbr_cast < 0)
	{
		nbr_cast = -nbr_cast;
		ft_putchar('-');
	}
	ft_putnbr(nbr_cast, base, base_size);
}
