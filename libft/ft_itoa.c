/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 23:52:09 by georgy            #+#    #+#             */
/*   Updated: 2020/11/12 18:17:44 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cnt_rank_number(int n, int minus)
{
	int	numb_len;

	numb_len = 1;
	while ((n /= 10))
		numb_len++;
	return (numb_len + minus);
}

static int	ft_abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (n * (-1));
}

static char	*return_zero(void)
{
	char	*zero;

	zero = (char *)malloc(sizeof(char) * 2);
	zero[1] = '\0';
	zero[0] = 0 + '0';
	return (zero);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		numb_len;
	int		minus;
	int		digit;

	if (n < 0)
		minus = 1;
	else if (n == 0)
		return (return_zero());
	else
		minus = 0;
	numb_len = cnt_rank_number(n, minus);
	if (!(res = (char *)malloc(sizeof(char) * (numb_len + 1))))
		return (NULL);
	res[numb_len] = '\0';
	while (n != 0)
	{
		digit = n % 10;
		numb_len--;
		res[numb_len] = ft_abs(digit) + '0';
		n /= 10;
	}
	if (minus > 0)
		res[0] = '-';
	return (res);
}
