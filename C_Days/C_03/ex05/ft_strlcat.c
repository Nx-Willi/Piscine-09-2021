/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 09:21:25 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/15 14:13:58 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlen(char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i_dest;
	unsigned int	i_src;
	unsigned int	n;

	i_dest = ft_strlen(dest);
	i_src = ft_strlen(src);
	n = 0;
	while (src[n] != '\0' && n < size - 1)
	{
		dest[(i_dest + 1) + n] = src[n];
		n++;
	}
	dest[i_dest + n] = '\0';
	return (i_dest + ft_strlen(src));
}
