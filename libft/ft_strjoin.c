/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 13:24:55 by georgy            #+#    #+#             */
/*   Updated: 2020/11/12 19:31:21 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret_str;
	size_t	i;
	size_t	j;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	if (!(ret_str = (char *)malloc(ft_strlen((char *)s1) +
		(ft_strlen((char *)s2) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		ret_str[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		ret_str[i + j] = s2[j];
		j++;
	}
	ret_str[i + j] = '\0';
	return (ret_str);
}
