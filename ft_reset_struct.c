/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:39:47 by georgy            #+#    #+#             */
/*   Updated: 2020/12/09 13:20:50 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_struct(t_args *f)
{
	f->f_minus = OFF;
	f->f_zero = OFF;
	f->f_width = OFF;
	f->f_precision = OFF;
	f->precision = OFF;
	f->precision_cpy = OFF;
}
