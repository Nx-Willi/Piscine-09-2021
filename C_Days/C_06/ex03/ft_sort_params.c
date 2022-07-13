/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 12:13:08 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/20 20:45:56 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_printstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	ft_strcmp(char *str0, char *str1)
{
	int	i;

	i = 0;
	while (str0[i] != '\0' || str1[i] != '\0')
	{
		if (str0[i] > str1[i])
			return (1);
		else if (str0[i] < str1[i])
			return (-1);
		i++;
	}
	return (0);
}

void	ft_sortparams(char **str)
{
	int		i;
	int		n;
	char	*tmp;

	i = 2;
	n = 2;
	while (str[i] != '\0')
	{
		while (str[n] != '\0')
		{
			if (ft_strcmp(str[n], str[n - 1]) == -1)
			{
				tmp = str[n];
				str[n] = str[n - 1];
				str[n - 1] = tmp;
			}
			n++;
		}
		n = 2;
		i++;
	}
}

int	main(int args, char **argv)
{
	int	i;

	if (args < 2)
		return (1);
	else
	{
		ft_sortparams(argv);
		i = 1;
		while (i < args)
		{
			ft_printstr(argv[i]);
			i++;
		}
	}
	return (0);
}
