/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 23:25:03 by georgy            #+#    #+#             */
/*   Updated: 2020/11/03 15:13:26 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isprint(int c)
{
	int	flag;

	flag = 0;
	if (c < 32 || c > 126)
		return (0);
	else
	{
		flag = 1;
		return (flag);
	}
}
