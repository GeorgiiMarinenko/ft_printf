/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:07:15 by aarlena           #+#    #+#             */
/*   Updated: 2020/12/09 13:23:15 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decimal_left2(intmax_t nbr, t_args *f)
{
	if (nbr == 0 && f->f_precision && !f->precision)
	{
		while (f->f_width)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		return (1);
	}
	return (0);
}

static void	ft_print_decimal_left_align(intmax_t nbr, t_args *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_signed_nbr_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_decimal_left2(nbr, f))
		return ;
	if (n == 1)
	{
		f->len += write(f->file_descr, "-", 1);
		nbrlen--;
		f->f_width--;
	}
	while (nbrlen++ < f->precision)
		f->len += write(f->file_descr, "0", 1);
	f->len += ft_itoa_base_pf(f->file_descr, nbr, 10);
	ft_padding_left_align(nbrlen, f);
}

static int	ft_decimal_right2(intmax_t nbr, int n, t_args *f)
{
	if (nbr == 0 && f->f_precision && !f->precision)
	{
		while (f->f_width)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		return (1);
	}
	if (n == 1 && f->f_zero && !f->f_precision)
		f->len += write(f->file_descr, "-", 1);
	return (0);
}

static void	ft_print_decimal_right_align(intmax_t nbr, t_args *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_signed_nbr_len(nbr, 10);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_decimal_right2(nbr, n, f))
		return ;
	ft_condition_1(f, nbrlen);
	ft_padding_right_align(nbrlen, n, f, 0);
	if (n == 1 && f->f_zero && f->f_precision)
		f->len += write(f->file_descr, "-", 1);
	if (!f->f_zero && n == 1 && nbrlen--)
		f->len += write(f->file_descr, "-", 1);
	ft_condition_2(f);
	if (f->f_zero && f->f_precision && n == 1)
	{
		while (nbrlen++ < f->precision + 1)
			f->len += write(f->file_descr, "0", 1);
	}
	while (nbrlen++ < f->precision)
		f->len += write(f->file_descr, "0", 1);
	f->len += ft_itoa_base_pf(f->file_descr, nbr, 10);
}

void		ft_print_decimal(char type, t_args *f, va_list ap)
{
	intmax_t	nbr;

	if (type == 'd' || type == 'i')
	{
		nbr = va_arg(ap, int);
		if (f->f_minus)
			ft_print_decimal_left_align(nbr, f);
		else
			ft_print_decimal_right_align(nbr, f);
	}
}
