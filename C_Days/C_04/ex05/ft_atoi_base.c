/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/22 11:55:44 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/22 15:20:17 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_get_number_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && c != base[i])
		i++;
	return (i);
}

int	is_base_ok(char *base)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' '
			|| (base[i] >= 9 && base[i] <= 13))
			return (0);
		while (base[i + n] != '\0')
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	is_negativ;
	int	nbr;
	int	base_size;

	base_size = ft_strlen(base);
	if (!is_base_ok(base) || base_size <= 1)
		return (0);
	nbr = 0;
	is_negativ = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			is_negativ = -is_negativ;
		i++;
	}
	while (str[i])
	{
		nbr = nbr * base_size + ft_get_number_base(str[i], base);
		i++;
	}
	return (nbr * is_negativ);
}
