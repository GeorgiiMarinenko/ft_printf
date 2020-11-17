/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 19:39:01 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/03 15:53:47 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	char	*temp_symb;

	temp_symb = NULL;
	while (1)
	{
		if (*str == (char)ch)
			temp_symb = (char *)str;
		if (!*str)
			break ;
		str++;
	}
	return (temp_symb);
}
