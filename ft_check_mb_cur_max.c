/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_mb_cur_max.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:16:27 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/25 16:29:13 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_mb_cur_max(wchar_t *wstr, t_args *f)
{
	int i;

	i = 0;
	while (wstr[i])
	{
		if (wstr[i] >= 0 && wstr[i] <= 127)
			;
		else if (wstr[i] >= 0 && wstr[i] <= 255 && MB_CUR_MAX == 1)
			;
		else if (wstr[i] >= 128 && wstr[i] <= 2047 && MB_CUR_MAX >= 2)
			;
		else if (wstr[i] >= 2048 && wstr[i] <= 65535 && MB_CUR_MAX >= 3)
			;
		else if (wstr[i] >= 65536 && wstr[i] <= 1114111 && MB_CUR_MAX == 4)
			;
		else
			f->len = -1;
		i++;
	}
}
