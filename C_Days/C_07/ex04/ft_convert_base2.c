/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 13:42:47 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/27 18:23:26 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_find_num_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] && base[i] != c)
		i++;
	if (base[i] == c)
		return (i);
	else
		return (0);
}

int	ft_size_num_base(long int nbr, char *base)
{
	int	i;
	int	base_size;

	base_size = ft_strlen(base);
	i = 0;
	while (nbr >= base_size)
	{
		nbr = nbr / base_size;
		i++;
	}
	return (i + 1);
}

char	*ft_strcat(char *dest, char c)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	dest[i] = c;
	dest[i + 1] = '\0';
	return (dest);
}
