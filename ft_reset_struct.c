/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reset_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:39:47 by georgy            #+#    #+#             */
/*   Updated: 2020/11/24 17:41:03 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_reset_struct(t_args *f)
{
	f->f_minus = 0;
	f->f_plus = 0;
	f->f_space = 0;
	f->f_zero = 0;
	f->f_hash = 0;
	f->f_width = 0;
	f->f_precision = 0;
	f->f_precision = 0;
	f->length = 0;
}
