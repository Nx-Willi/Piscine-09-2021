/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 13:33:56 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/27 16:47:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;
	int	tab_size;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	tab_size = max - min;
	tab = malloc(sizeof(int) * tab_size);
	if (tab == NULL)
		return (-1);
	i = 0;
	while (i < tab_size)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (tab_size);
}
