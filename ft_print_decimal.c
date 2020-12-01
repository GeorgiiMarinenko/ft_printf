/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 21:07:15 by aarlena           #+#    #+#             */
/*   Updated: 2020/12/01 17:22:57 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_decimal_left2(intmax_t nbr, int n, t_args *f)
{
	if (nbr == 0 && f->f_precision && !f->precision)
	{
		if (f->f_plus && f->f_width)
			f->f_width--;
		if (f->f_plus)
			f->len += write(f->file_descr, "+", 1);
		while (f->f_width)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		return (1);
	}
	if (f->f_space && n == 0)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
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
	if (ft_decimal_left2(nbr, n, f))
		return ;
	if (f->f_plus && n == 0)
	{
		f->len += write(f->file_descr, "+", 1);
		nbrlen++;
		f->precision++;
	}
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
		if (f->f_plus && f->f_width)
			f->f_width--;
		while (f->f_width)
		{
			f->len += write(f->file_descr, " ", 1);
			f->f_width--;
		}
		if (f->f_plus)
			f->len += write(f->file_descr, "+", 1);
		return (1);
	}
	if (f->f_space && n == 0 && !f->f_width)
		f->len += write(f->file_descr, " ", 1);
	if (f->f_plus && f->f_zero && n == 0)
		f->len += write(f->file_descr, "+", 1);
	if (n == 1 && f->f_zero)
		f->len += write(f->file_descr, "-", 1);
	return (0);
}

static void	ft_print_decimal_right_align(intmax_t nbr, t_args *f)
{
	int nbrlen;
	int n;

	nbrlen = ft_signed_nbr_len(nbr, 10);
	// printf("___NBR_LEN___%d", nbrlen);
	n = (nbr < 0) ? 1 : 0;
	nbr = (nbr < 0) ? -nbr : nbr;
	if (ft_decimal_right2(nbr, n, f))
		return ;
	if (f->f_plus && n == 0 && f->f_width && !f->f_precision)
		nbrlen++;
	ft_padding_right_align(nbrlen, n, f);
	if (!f->f_zero && f->f_plus && n == 0)
		f->len += write(f->file_descr, "+", 1);
	else if (!f->f_zero && n == 1)
	{
		f->len += write(f->file_descr, "-", 1);
		nbrlen--;
	}
	f->precision = (f->f_width > f->precision) ? f->f_width : f->precision;
	while (nbrlen++ < f->precision)
		f->len += write(f->file_descr, "0", 1);
	f->len += ft_itoa_base_pf(f->file_descr, nbr, 10);
}

void		ft_print_decimal(char type, t_args *f, va_list ap)
{
	intmax_t	nbr;
	(void)ap;
	if (type == 'd' || type == 'i')
	{
		nbr = va_arg(ap, int);
		// printf("_____NBR____%jd\n", nbr);
		if (f->f_minus)
			ft_print_decimal_left_align(nbr, f);
		else
			ft_print_decimal_right_align(nbr, f);
	}
}
