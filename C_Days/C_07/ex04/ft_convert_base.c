/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 12:03:12 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/27 18:23:23 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_whitespace(char c);
int		ft_strlen(char *str);
int		ft_find_num_base(char c, char *base);
int		ft_size_num_base(int nbr, char *base);
char	*ft_strcat(char *dest, char c);

char	*ft_putnbr_base(long int nbr, char *base, char *result)
{
	int	base_size;

	base_size = ft_strlen(base);
	if (nbr >= base_size)
	{
		ft_putnbr_base(nbr / base_size, base, result);
		ft_putnbr_base(nbr % base_size, base, result);
	}
	else
		ft_strcat(result, base[nbr]);
	return (result);
}

int	is_base_correct(char *base, int base_size)
{
	int	i;
	int	n;

	if (base_size <= 1)
		return (0);
	i = 0;
	n = 1;
	while (base[i])
	{
		if (is_whitespace(base[i]) || base[i] == '+' || base[i] == '-')
			return (0);
		while (base[i + n])
		{
			if (base[i + n] == base[i])
				return (0);
			n++;
		}
		n = 1;
		i++;
	}
	return (1);
}

int	ft_atoi_base(char *nbr, char *base, int base_size)
{
	int	i;
	int	is_negativ;
	int	nbr_result;

	is_negativ = 1;
	nbr_result = 0;
	i = 0;
	while (is_whitespace(nbr[i]))
		i++;
	while (nbr[i] == '+' || nbr[i] == '-')
	{
		if (nbr[i] == '-')
			is_negativ = -is_negativ;
		i++;
	}
	while (nbr[i] && ft_find_num_base(nbr[i], base))
	{
		nbr_result = nbr_result * base_size + ft_find_num_base(nbr[i], base);
		i++;
	}
	return (nbr_result * is_negativ);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long int	i_nbr;
	int			size_num_base;
	char		*nbr_res;

	if (!is_base_correct(base_from, ft_strlen(base_from))
		|| !is_base_correct(base_to, ft_strlen(base_to)))
		return (NULL);
	i_nbr = ft_atoi_base(nbr, base_from, ft_strlen(base_from));
	size_num_base = ft_size_num_base(i_nbr, base_to);
	nbr_res = (char *)malloc(sizeof(char) * size_num_base + 2);
	if (nbr_res == NULL)
		return (NULL);
	*nbr_res = 0;
	if (i_nbr < 0)
	{
		i_nbr = -i_nbr;
		ft_strcat(nbr_res, '-');
	}
	ft_putnbr_base(i_nbr, base_to, nbr_res);
	return (nbr_res);
}
