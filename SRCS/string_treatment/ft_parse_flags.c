/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 23:10:37 by georgy            #+#    #+#             */
/*   Updated: 2020/11/19 23:11:24 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

void		ft_parse_modifiers(const char *format, t_args *f, va_list arg_pointer)
{
	ft_flags(format, f);
	ft_width(format, f, arg_pointer);
	ft_precision(format, f, arg_pointer);
}
