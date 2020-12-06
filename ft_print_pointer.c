/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 17:12:28 by aarlena           #+#    #+#             */
/*   Updated: 2020/12/06 03:10:35 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_pointer_left_align(intmax_t nbr, t_args *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16) + 2;
	f->len += write(f->file_descr, "0x", 2);
	if (nbr == 0 && f->f_precision && !f->precision)
	{
		while (f->f_width >= nbrlen)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		return ;
	}
	while (f->precision > (nbrlen - 2))
	{
		f->len += write(f->file_descr, "0", 1);
		f->precision--;
	}
	f->len += ft_uitoa_base_pf(f->file_descr, nbr, 16, 0);
	while (f->f_width > nbrlen)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_pointer_right_align(uintmax_t nbr, t_args *f)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16) + 2;
	if (nbr == 0 && f->f_precision)
	{
		while (f->f_width >= nbrlen)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
	}
	else
	{
		while (f->f_width > nbrlen)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
	}
	f->len += write(f->file_descr, "0x", 2);
	if (nbr == 0 && f->f_precision && !f->precision)
		return ;
	while ((nbrlen - 2) < f->precision)
	{
		f->len += write(f->file_descr, "0", 1);
		nbrlen++;
	}
	f->len += ft_uitoa_base_pf(f->file_descr, nbr, 16, 0);
}

void		ft_print_pointer(char type, t_args *f, va_list ap)
{
	uintmax_t	nbr;

	if (type == 'p')
		nbr = (long long)va_arg(ap, unsigned long long);
	if (f->f_minus)
		ft_print_pointer_left_align(nbr, f);
	else
		ft_print_pointer_right_align(nbr, f);
}
