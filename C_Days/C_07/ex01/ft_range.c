/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 10:36:27 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/27 17:24:24 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*tab;
	int	tab_size;

	if (min >= max)
		return (NULL);
	tab_size = max - min;
	tab = malloc(sizeof(int) * (tab_size));
	if (tab == NULL)
		return (NULL);
	i = 0;
	while (i < tab_size)
		tab[i++] = min++;
	return (tab);
}
