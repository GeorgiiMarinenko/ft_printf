/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 16:14:44 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/25 16:15:21 by aarlena          ###   ########.fr       */
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

void	ft_putwstr_pf(wchar_t *wstr, t_args *f, int max)
{
	int i;
	int size;

	i = 0;
	size = 0;
	ft_check_mb_cur_max(wstr, f);
	if (f->len == -1)
		return ;
	while (wstr[i])
	{
		if (wstr[i] <= 127)
			size += 1;
		else if (wstr[i] >= 128 && wstr[i] <= 2047)
			size += 2;
		else if (wstr[i] >= 2048 && wstr[i] <= 65535)
			size += 3;
		else if (wstr[i] >= 65536 && wstr[i] <= 1114111)
			size += 4;
		if (size <= max)
			ft_putwchar_pf(wstr[i], f);
		else
			break ;
		i++;
	}
}
