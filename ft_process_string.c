/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_string.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:38:13 by georgy            #+#    #+#             */
/*   Updated: 2020/11/25 21:05:49 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static void		ft_print_type(const char *format, t_args *f, va_list ap)
{
	if (format[f->i] == 'd' || format[f->i] == 'i')
		ft_print_decimal(format[f->i], f, ap);
	// else if (format[f->i] == 'o' || format[f->i] == 'O')
	// 	ft_print_octal(format[f->i], f, ap);
	// else if (format[f->i] == 'u' || format[f->i] == 'U')
	// 	ft_print_unsigned_decimal(format[f->i], f, ap);
	// else if (format[f->i] == 'x' || format[f->i] == 'X')
	// 	ft_print_hex(format[f->i], f, ap);
	// else if (format[f->i] == 'p')
	// 	ft_print_pointer(format[f->i], f, ap);
	// else if (format[f->i] == 'b')
	// 	ft_print_binary(format[f->i], f, ap);
	if (format[f->i] == 'c')
		ft_print_char(format[f->i], f, ap);
	// else if (format[f->i] == 'r')
	// 	ft_print_control_char(format[f->i], f, ap);
	else if (format[f->i] == 's')
		ft_print_string(format[f->i], f, ap);
	// else if (format[f->i] == '%')
	// 	ft_print_percent_sign(format[f->i], f);
}

void			ft_process_string(const char *format, t_args *f, va_list ap)
{
	while (format[f->i] != '\0')
	{
		if (format[f->i] == '%')
		{
			f->i++;
			if (ft_strchr("#-+ .*0123456789hl", format[f->i]))
				ft_parse_modifiers(format, f, ap);
			if (ft_strchr("scpdiouUxXbr%", format[f->i]))
			{
				ft_print_type(format, f, ap);
				if (f->len == -1)
					return ;
				ft_reset_struct(f);
			}
		}
		else
			f->len += write(f->file_descr, &format[f->i], 1);
		f->i++;
	}
}
