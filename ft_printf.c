/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 14:41:39 by georgy            #+#    #+#             */
/*   Updated: 2020/11/24 17:19:04 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int			len;
	t_args		*arg;
	va_list		ap;//Указатель на аргумент

	arg = NULL;
	if ((arg = ft_init_struct(arg)) == NULL)
		return (-1);
	arg->file_descr = 1;
	va_start(ap, format);
	if (format[0] == '%' && format[1] == '\0')
		;
	else if (!ft_strchr(format, '%')) //Если в строке не встретился %
		arg->len += write(arg->file_descr, format, ft_strlen(format));
	else
		ft_process_string(format, arg, ap);//Обработка строки
	len = arg->len;
	free(arg);
	va_end(ap);
	return (len);
}
