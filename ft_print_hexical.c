/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexical.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 23:22:21 by georgy            #+#    #+#             */
/*   Updated: 2020/12/05 00:05:03 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_hex_left_align(intmax_t nbr, t_args *f, char letter)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16);
	if (nbr == 0 && f->f_precision && !f->precision)
	{
		while (f->f_width)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		return ;
	}
	while (nbrlen++ < f->precision)
		f->len += write(f->file_descr, "0", 1);
	f->len += ft_uitoa_base_pf(f->file_descr, nbr, 16, letter);
	while (f->f_width-- >= nbrlen)
		f->len += write(f->file_descr, " ", 1);
}

static void	ft_padding(int nbrlen, t_args *f)
{
	if (!f->f_precision)
		while (f->f_width-- > nbrlen)
		{
			if (f->f_zero)
				f->len += write(f->file_descr, "0", 1);
			else
				f->len += write(f->file_descr, " ", 1);
		}
	else
	{
		f->precision = (f->precision < nbrlen) ? nbrlen : f->precision;
		while (f->f_width-- > f->precision)
		{
			if (f->f_zero)
				f->len += write(f->file_descr, " ", 1);
			else
				f->len += write(f->file_descr, " ", 1);
		}
	}
}

static void	ft_print_hex_right_align(uintmax_t nbr, t_args *f, char letter)
{
	int nbrlen;

	nbrlen = ft_unsigned_nbr_len(nbr, 16);
	if (nbr == 0 && f->f_precision && !f->precision)
	{
		while (f->f_width)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		return ;
	}
	ft_padding(nbrlen, f);
	while (nbrlen++ < f->precision)
		f->len += write(f->file_descr, "0", 1);
	f->len += ft_uitoa_base_pf(f->file_descr, nbr, 16, letter);
}

void		ft_print_hex(char type, t_args *f, va_list ap)
{
	uintmax_t nbr;

	if (type == 'x' || type == 'X')
	{
		nbr = va_arg(ap, unsigned int);
		if (f->f_minus)
			ft_print_hex_left_align(nbr, f, type);
		else
			ft_print_hex_right_align(nbr, f, type);
	}
}
