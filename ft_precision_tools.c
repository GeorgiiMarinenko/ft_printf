/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision_tools.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:36:54 by georgy            #+#    #+#             */
/*   Updated: 2020/12/07 21:49:33 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_condition_1(t_args *f,int nbrlen)
{
	f->precision_cpy = f->precision;
	f->precision = (nbrlen > f->precision) ? nbrlen : f->precision;
}

void	ft_condition_2(t_args *f)
{
	f->precision = f->precision_cpy;
	f->precision = (f->f_width > f->precision) ? f->f_width : f->precision;
}
