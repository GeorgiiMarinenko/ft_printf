/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 19:21:17 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/03 15:33:25 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t b_size)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;
	unsigned char		*last_dst;
	const unsigned char	*last_src;

	p_dst = dst;
	p_src = src;
	if ((p_dst == NULL) && (src == NULL))
		return ((char *)src);
	if (p_dst < p_src)
	{
		while (b_size-- > 0)
			*p_dst++ = *p_src++;
	}
	else
	{
		last_dst = dst + (b_size - 1);
		last_src = src + (b_size - 1);
		while (b_size-- > 0)
			*last_dst-- = *last_src--;
	}
	return (dst);
}
