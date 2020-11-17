/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 01:34:24 by georgy            #+#    #+#             */
/*   Updated: 2020/11/03 18:23:27 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	size_t			i;
	size_t			res;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	res = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && (res == 0) && (i < n))
	{
		if (str1[i] != str2[i])
			res = str1[i] - str2[i];
		i++;
	}
	return (res);
}
