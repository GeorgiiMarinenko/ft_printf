/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:49:13 by georgy            #+#    #+#             */
/*   Updated: 2020/11/10 16:47:27 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_nonprintable(char str)
{
	char	nonprintable[6];
	int		i;

	nonprintable[0] = ' ';
	nonprintable[1] = '\t';
	nonprintable[2] = '\n';
	nonprintable[3] = '\v';
	nonprintable[4] = '\r';
	nonprintable[5] = '\f';
	i = 0;
	while (i < 6)
	{
		if (str == nonprintable[i])
			return (1);
		i++;
	}
	return (0);
}

int			ft_atoi(char *str)
{
	int	nbr;
	int	sign;
	int	i;

	nbr = 0;
	sign = 1;
	i = 0;
	while (check_nonprintable(str[i]))
		i++;
	if ((str[i] == '+') || (str[i] == '-'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = nbr * 10 + (str[i] - '0');
		i++;
	}
	return (nbr * sign);
}
