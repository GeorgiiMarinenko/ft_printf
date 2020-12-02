/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dec_padding.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 12:11:54 by georgy            #+#    #+#             */
/*   Updated: 2020/12/03 00:33:24 by georgy           ###   ########.fr       */
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

void	ft_padding_right_align(int nbrlen, int n, t_args *f)
{
	int	repit = 0;
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
		// printf("____WIDTH____: %d\n",f->f_width);
		// f->f_width -= 1;//? for nofit_fit
		while (f->f_width-- > f->precision)
		{
			if ((f->f_zero && f->f_width != f->precision) || n == 1)
			{
				if (!repit)
				{
					repit = 1;
					f->f_width--;
				}
				f->len += write(f->file_descr, " ", 1);//d_prec_width_fit_fit_neg error is here <0 or > ?
			}
			else
				f->len += write(f->file_descr, " ", 1);
		}
	}
}
