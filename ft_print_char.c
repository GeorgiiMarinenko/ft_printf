/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 17:47:14 by georgy            #+#    #+#             */
/*   Updated: 2020/12/02 23:23:38 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_char_left_align(unsigned char c, t_args *f)
{
	f->len += write(f->file_descr, &c, 1);
	while (f->f_width > 1)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_char_right_align(unsigned char c, t_args *f)
{
	while (f->f_width > 1)
	{
		if (f->f_zero)
			f->len += write(f->file_descr, "0", 1);
		else
			f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
	f->len += write(f->file_descr, &c, 1);
}

void		ft_print_char(char type, t_args *f, va_list ap)
{
	unsigned char	c;

	if (type == 'c')
	{
		c = (unsigned char)va_arg(ap, int);
		if (f->f_minus)
			ft_print_char_left_align(c, f);
		else
			ft_print_char_right_align(c, f);
	}
}
