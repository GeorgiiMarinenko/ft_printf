/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 13:01:47 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/03 17:22:48 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t b_size)
{
	size_t	i;

	i = 0;
	if ((dst == NULL) && (src == NULL))
		return (0);
	if (ft_strlen(src) + 1 < b_size)
		ft_memcpy(dst, src, ft_strlen(src) + 1);
	else if (b_size)
	{
		ft_memcpy(dst, src, b_size - 1);
		dst[b_size - 1] = '\0';
	}
	return (ft_strlen(src));
}
