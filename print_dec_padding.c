/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:11:54 by georgy            #+#    #+#             */
/*   Updated: 2020/12/07 22:39:15 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_padding_left_align(int nbrlen, t_args *f)
{
	while (f->f_width >= nbrlen)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

void	ft_padding_right_align(int nbrlen, int n, t_args *f, int repits)
{
	if (!f->f_precision)
	{
		while (f->f_width-- > nbrlen)
		{
			if (f->f_zero)
				f->len += write(f->file_descr, "0", 1);
			else
				f->len += write(f->file_descr, " ", 1);
		}
	}
	else
	{
		if (f->f_width > f->f_precision && f->precision_cpy == nbrlen && n == 1)
			f->f_width -= 1;
		while (f->f_width-- > f->precision)
		{
			if ((f->f_zero && f->f_width != f->precision) || n == 1)
			{
				if (f->f_width && f->f_precision)
					f->f_width = (f->precision > nbrlen &&
					!repits++ && n == 1) ? f->f_width - 1 : f->f_width;
			}
			f->len += write(f->file_descr, " ", 1);
		}
	}
}
