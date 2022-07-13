/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:53:41 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/16 09:05:39 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	hex_to_c(char c)
{
	char	*base_hex;

	base_hex = "0123456789abcdef";
	if (c > 16)
	{
		hex_to_c(c / 16);
		hex_to_c(c % 16);
	}
	else
		ft_putchar(base_hex[c]);
	return (c);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			if (str[i] < 16)
				ft_putchar('0');
			hex_to_c(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
