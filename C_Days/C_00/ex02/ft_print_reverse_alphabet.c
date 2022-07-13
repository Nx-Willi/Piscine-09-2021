/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 19:50:15 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/10 09:33:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	revalphabet;

	revalphabet = 'z';
	while (revalphabet >= 'a')
	{
		write(1, &revalphabet, 1);
		revalphabet--;
	}
}
