/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:39:47 by georgy            #+#    #+#             */
/*   Updated: 2020/12/06 17:12:06 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_struct(t_args *f)
{
	f->f_minus = OFF;
	f->f_plus = OFF;
	f->f_space = OFF;
	f->f_zero = OFF;
	f->f_hash = OFF;
	f->f_width = OFF;
	f->f_precision = OFF;
	f->precision = OFF;
	f->precision_cpy = OFF;
}
