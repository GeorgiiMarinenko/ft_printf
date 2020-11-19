/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 20:24:25 by georgy            #+#    #+#             */
/*   Updated: 2020/11/18 20:28:58 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

static void		ft_specifiers(const char *format, t_args *arg, va_list ap)
{
	if (format[arg->i] == 'd' || format[arg->i] == 'i' || format[arg->i] == 'D')
		ft_print_decimal(format[arg->i], arg, ap);
	else if (format[arg->i] == 'o' || format[arg->i] == 'O')
		ft_print_octal(format[arg->i], arg, ap);
	else if (format[arg->i] == 'u' || format[arg->i] == 'U')
		ft_print_unsigned_decimal(format[arg->i], arg, ap);
	else if (format[arg->i] == 'x' || format[arg->i] == 'X')
		ft_print_hex(format[arg->i], arg, ap);
	else if (format[arg->i] == 'p')
		ft_print_pointer(format[arg->i], arg, ap);
	else if (format[arg->i] == 'b')
		ft_print_binary(format[arg->i], arg, ap);
	else if (format[arg->i] == 'c' || format[arg->i] == 'C')
		ft_print_char(format[arg->i], arg, ap);
	else if (format[arg->i] == 'r')
		ft_print_control_char(format[arg->i], arg, ap);
	else if (format[arg->i] == 's' || format[arg->i] == 'S')
		ft_print_string(format[arg->i], arg, ap);
	else if (format[arg->i] == '%')
		ft_print_percent_sign(format[arg->i], arg);
}
