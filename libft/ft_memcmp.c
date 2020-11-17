/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 12:30:38 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/03 15:14:01 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *arr1, const void *arr2, size_t b_size)
{
	size_t				i;
	const unsigned char	*p_arr1;
	unsigned char		*p_arr2;

	p_arr1 = (const unsigned char *)arr1;
	p_arr2 = (unsigned char *)arr2;
	i = 0;
	if (b_size <= 0)
		return (0);
	while (i < b_size)
	{
		if (p_arr1[i] != p_arr2[i])
			return (p_arr1[i] - p_arr2[i]);
		i++;
	}
	return (0);
}
