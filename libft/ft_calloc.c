/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 00:10:27 by georgy            #+#    #+#             */
/*   Updated: 2020/11/03 15:06:56 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t b_size)
{
	void	*arr_pointer;

	arr_pointer = (void *)malloc(num * b_size);
	if (arr_pointer == NULL)
		return (NULL);
	ft_bzero(arr_pointer, num * b_size);
	return (arr_pointer);
}
