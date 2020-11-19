/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_treatment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 19:56:13 by georgy            #+#    #+#             */
/*   Updated: 2020/11/19 23:10:22 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

void			ft_process_string(const char *format, t_args *arg, va_list ap)
{
	while (format[arg->i] != '\0')
	{
		if (format[arg->i] == '%')
		{
			arg->i++;
			if (ft_strchr("#-+ .*0123456789hljz", format[arg->i]))//Обработка вхождения всех флагов
				ft_parse_flags(format, arg, ap);
			if (ft_strchr(SPECIFIERS, format[arg->i]))//Обработка спецефикаторов
			{
				ft_specifiers(format, arg, ap);
				if (arg->len == -1)
					return ;
				ft_reset_struct(arg);
			}
		}
		else
			arg->len += write(arg->file_descr, &format[arg->i], 1);
		arg->i++;
	}
}
