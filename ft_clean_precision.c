/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/07 21:24:54 by georgy            #+#    #+#             */
/*   Updated: 2020/12/07 21:26:03 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_clean_percision(t_args *f)
{
	f->f_precision = OFF;
	f->precision = OFF;
	f->precision_cpy = OFF;
}
