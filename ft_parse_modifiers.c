/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_modifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:42:14 by georgy            #+#    #+#             */
/*   Updated: 2020/11/25 19:34:26 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(const char *format, t_args *f)
{
	while (ft_strchr("-+ 0#", format[f->i]))
	{
		if (format[f->i] == '-')
			f->f_minus = ON;
		else if (format[f->i] == '+')
			f->f_plus = ON;
		else if (format[f->i] == ' ')
			f->f_space = ON;
		else if (format[f->i] == '0')
			f->f_zero = ON;
		else if (format[f->i] == '#')
			f->f_hash = ON;
		f->i++;
	}
	if (f->f_plus)
		f->f_space = OFF;
}

static void	ft_width(const char *format, t_args *f, va_list ap)
{
	if (format[f->i] == '*')
	{
		f->f_width = va_arg(ap, int);
		f->f_minus = (f->f_width < 0) ? 1 : f->f_minus;
		f->f_width = (f->f_width < 0) ? -f->f_width : f->f_width;
		while (format[f->i] == '*')
			f->i++;
	}
	if (ft_isdigit(format[f->i]))
	{
		f->f_width = ft_atoi(&format[f->i]);
		while (ft_isdigit(format[f->i]))
		{
			f->i++;
			if (format[f->i] == '*')
			{
				f->f_width = va_arg(ap, int);
				f->f_width = (f->f_width < 0) ? -f->f_width : f->f_width;
				while (format[f->i] == '*')
					f->i++;
			}
		}
	}
}

static void	ft_precision(const char *format, t_args *f, va_list ap)
{
	int precision;

	if (format[f->i] == '.')
	{
		f->i++;
		f->f_precision = 1;
		if (ft_isdigit(format[f->i]))
		{
			f->precision = ft_atoi(&format[f->i]);
			while (ft_isdigit(format[f->i]))
				f->i++;
		}
		else if (format[f->i] == '*')
		{
			precision = va_arg(ap, int);
			if (precision >= 0)
				f->precision = precision;
			else
				f->f_precision = 0;
			while (format[f->i] == '*')
				f->i++;
		}
	}
	if (f->f_hash && !f->f_minus)
		f->f_space = 0;
}

void		ft_parse_modifiers(const char *format, t_args *f, va_list ap)
{
	ft_flags(format, f);
	ft_width(format, f, ap);
	ft_precision(format, f, ap);
	//ft_length(format, f);
}
