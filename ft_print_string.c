/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:19:07 by aarlena           #+#    #+#             */
/*   Updated: 2020/12/02 23:24:39 by georgy           ###   ########.fr       */
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

void		ft_print_string(char type, t_args *f, va_list ap)
{
	char	*str;

	if (type == 's')
	{
		str = va_arg(ap, char *);
		if (f->f_minus)
			ft_print_string_left_align(str, f);
		else
			ft_print_string_right_align(str, f);
	}
}
