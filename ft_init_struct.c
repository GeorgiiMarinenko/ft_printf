/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:34:51 by georgy            #+#    #+#             */
/*   Updated: 2020/12/05 00:25:02 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args	*ft_init_struct(t_args *f)
{
	if ((f = (t_args*)ft_calloc(1, sizeof(t_args))) == NULL)
		return (NULL);
	f->f_minus = OFF;
	f->f_plus = OFF;
	f->f_space = OFF;
	f->f_zero = OFF;
	f->f_hash = OFF;
	f->f_width = OFF;
	f->f_precision = OFF;
	f->f_precision = OFF;
	f->i = OFF;
	f->len = OFF;
	return (f);
}
