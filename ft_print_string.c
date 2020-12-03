/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:19:07 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/25 14:21:03 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_string_left_align(char *str, t_args *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->f_precision && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	f->len += write(f->file_descr, str, strlen);
	while (f->f_width > strlen)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_string_right_align(char *str, t_args *f)
{
	int strlen;

	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (f->f_precision && strlen > 0 && strlen > f->precision)
		strlen = f->precision;
	while (f->f_width > strlen)
	{
		if (f->f_zero)
			f->len += write(f->file_descr, "0", 1);
		else
			f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
	f->len += write(f->file_descr, str, strlen);
}

static void	ft_print_wide_string_left_align(wchar_t *wstr, t_args *f)
{
	int wstrsize;

	if (!wstr)
		wstr = L"(null)";
	wstrsize = ft_wstrsize_pf(wstr);
	if (f->f_precision && wstrsize > 0 && wstrsize > f->precision)
		wstrsize = f->precision;
	ft_putwstr_pf(wstr, f, wstrsize);
	if (f->len == -1)
		return ;
	while (f->f_width > wstrsize)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_wide_string_right_align(wchar_t *wstr, t_args *f)
{
	int wstrsize;

	if (!wstr)
		wstr = L"(null)";
	wstrsize = ft_wstrsize_pf(wstr);
	if (f->f_precision && wstrsize > 0 && wstrsize > f->precision)
		wstrsize = f->precision;
	ft_check_mb_cur_max(wstr, f);
	if (f->len == -1)
		return ;
	while (f->f_width > wstrsize)
	{
		if (f->f_zero)
			f->len += write(f->file_descr, "0", 1);
		else
			f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
	ft_putwstr_pf(wstr, f, wstrsize);
}

void		ft_print_string(char type, t_args *f, va_list ap)
{
	char	*str;
	wchar_t	*wstr;

	if ((type == 's' && f->length == L) || type == 'S')
	{
		wstr = va_arg(ap, wchar_t *);
		if (f->f_minus)
			ft_print_wide_string_left_align(wstr, f);
		else
			ft_print_wide_string_right_align(wstr, f);
	}
	else if (type == 's')
	{
		str = va_arg(ap, char *);
		if (f->f_minus)
			ft_print_string_left_align(str, f);
		else
			ft_print_string_right_align(str, f);
	}
}
