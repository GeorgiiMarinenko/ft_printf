/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 15:07:10 by aarlena           #+#    #+#             */
/*   Updated: 2020/10/31 14:26:34 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t b_size)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	i = 0;
	s_len = ft_strlen(src);
	while (*dst && i < b_size)
	{
		i++;
		dst++;
	}
	d_len = i;
	if (b_size != 0)
	{
		while (*src && i < b_size - 1)
		{
			i++;
			*dst = *src;
			src++;
			dst++;
		}
	}
	if (i < b_size)
		*dst = '\0';
	return (d_len + s_len);
}
