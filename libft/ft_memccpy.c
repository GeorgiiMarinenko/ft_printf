/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 17:28:02 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/03 15:12:39 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *srcs, int c, size_t b_size)
{
	unsigned char	*p_dest;
	unsigned char	*p_srcs;
	unsigned char	ch;

	p_dest = (unsigned char *)dest;
	p_srcs = (unsigned char *)srcs;
	ch = c;
	while (b_size--)
		if ((*p_dest++ = *p_srcs++) == ch)
			return (p_dest);
	return (NULL);
}
