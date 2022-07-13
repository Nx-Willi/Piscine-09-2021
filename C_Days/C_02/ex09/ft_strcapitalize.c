/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 18:04:48 by wdebotte          #+#    #+#             */
/*   Updated: 2021/09/13 18:50:43 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_lowercase(char c)
{
	if (!(c >= 97 && c <= 122))
		return (0);
	return (1);
}

int	is_uppercase(char c)
{
	if (!(c >= 65 && c <= 90))
		return (0);
	return (1);
}

int	is_number(char c)
{
	if (!(c >= 48 && c <= 57))
		return (0);
	return (1);
}

int	is_letterornum(char c)
{
	if (is_lowercase(c) == 1 || is_uppercase(c) == 1 || is_number(c) == 1)
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	if (is_lowercase(str[0]) == 1)
		str[0] -= 32;
	while (str[i] != '\0')
	{
		if (is_letterornum(str[i - 1]) == 0)
		{
			if (is_lowercase(str[i]))
				str[i] -= 32;
		}
		else
		{
			if (is_uppercase(str[i]))
				str[i] += 32;
		}
		i++;
	}
	return (str);
}
