/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 16:56:58 by aarlena           #+#    #+#             */
/*   Updated: 2020/10/31 14:53:49 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *srcs, size_t b_size)
{
	unsigned char	*p_dest;
	unsigned char	*p_srcs;

	p_dest = (unsigned char *)dest;
	p_srcs = (unsigned char *)srcs;
	if ((dest == NULL) && (srcs == NULL))
		return (NULL);
	while (b_size--)
		*p_dest++ = *p_srcs++;
	return (dest);
}
