/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 13:52:19 by aarlena           #+#    #+#             */
/*   Updated: 2020/10/31 14:44:52 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t b_size)
{
	unsigned char	*p_arr;

	p_arr = dest;
	while (b_size > 0)
	{
		*(p_arr++) = c;
		b_size--;
	}
	return (dest);
}
