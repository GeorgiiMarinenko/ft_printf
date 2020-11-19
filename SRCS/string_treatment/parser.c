/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 21:58:35 by georgy            #+#    #+#             */
/*   Updated: 2020/11/18 21:59:20 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../INCLUDES/ft_printf.h"

void		ft_parse_modifiers(const char *format, t_args *f, va_list ap)
{
	ft_flags(format, f);
	ft_width(format, f, ap);
	ft_precision(format, f, ap);
	ft_length(format, f);
}
