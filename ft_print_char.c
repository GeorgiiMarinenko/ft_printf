/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:47:14 by georgy            #+#    #+#             */
/*   Updated: 2020/11/24 17:48:33 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char_left_align(unsigned char c, t_args *f)
{
	f->len += write(f->file_descr, &c, 1);
	while (f->f_width > 1)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_char_right_align(unsigned char c, t_args *f)
{
	while (f->f_width > 1)
	{
		if (f->f_zero)
			f->len += write(f->file_descr, "0", 1);
		else
			f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
	f->len += write(f->file_descr, &c, 1);
}

static void	ft_print_wide_char_left_align(wchar_t wc, t_args *f)
{
	int size;

	if (wc < 0 || wc > 1114111)
	{
		f->len = -1;
		return ;
	}
	size = (wc <= 127) ? 1 : 0;
	size = (wc >= 128 && wc <= 2047) ? 2 : size;
	size = (wc >= 2048 && wc <= 65535) ? 3 : size;
	size = (wc >= 65536 && wc <= 1114111) ? 4 : size;
	ft_putwchar_pf(wc, f);
	if (f->len == -1)
		return ;
	while (f->f_width > size)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_wide_char_right_align(wchar_t wc, t_args *f)
{
	int size;

	if (wc < 0 || wc > 1114111)
	{
		f->len = -1;
		return ;
	}
	size = (wc <= 127) ? 1 : 0;
	size = (wc >= 128 && wc <= 2047) ? 2 : size;
	size = (wc >= 2048 && wc <= 65535) ? 3 : size;
	size = (wc >= 65536 && wc <= 1114111) ? 4 : size;
	while (f->f_width > size)
	{
		if (f->f_zero)
			f->len += write(f->file_descr, "0", 1);
		else
			f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
	ft_putwchar_pf(wc, f);
}

void		ft_print_char(char type, t_args *f, va_list ap)
{
	unsigned char	c;
	wchar_t			wc;

	if ((type == 'c' && f->length == L) || type == 'C')
	{
		wc = (wchar_t)va_arg(ap, wint_t);
		if (f->f_minus)
			ft_print_wide_char_left_align(wc, f);
		else
			ft_print_wide_char_right_align(wc, f);
	}
	else if (type == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		if (f->f_minus)
			ft_print_char_left_align(c, f);
		else
			ft_print_char_right_align(c, f);
	}
}
