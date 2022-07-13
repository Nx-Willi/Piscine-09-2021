/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 16:10:27 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/28 12:00:38 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strs_total_length(char **strs, int size, char *sep)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (strs[i] != '\0')
	{
		length += ft_strlen(strs[i]);
		i++;
	}
	return (ft_strlen(sep) * (size - 1) + length + 1);
}
//+ 1 pour le backslash 0
//size - 1 pour la derniere chaine backslash 0

char	ft_strcat(char *dest, char *src)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (dest[i])
		i++;
	while (src[n])
	{
		dest[i + n] = src[n];
		n++;
	}
	dest[i + n] = '\0';
	return (*dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		strs_size;
	char	*str_dest;

	if (size == 0)
	{
		str_dest = malloc(sizeof(char));
		*str_dest = 0;
		return (str_dest);
	}
	strs_size = ft_strs_total_length(strs, size, sep);
	str_dest = malloc(sizeof(char) * strs_size);
	if (str_dest == NULL)
		return (str_dest);
	*str_dest = 0;
	i = 0;
	while (i < size)
	{
		ft_strcat(str_dest, strs[i]);
		if (i < size - 1)
			ft_strcat(str_dest, sep);
		i++;
	}
	return (str_dest);
}
