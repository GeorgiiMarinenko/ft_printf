/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_percent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 18:58:40 by aarlena           #+#    #+#             */
/*   Updated: 2020/12/05 19:26:45 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_percent_sign_left_align(t_args *f)
{
	f->len += write(f->file_descr, "%", 1);
	while (f->f_width > 1)
	{
		f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
}

static void	ft_print_percent_sign_right_align(t_args *f)
{
	while (f->f_width > 1)
	{
		if (f->f_zero)
			f->len += write(f->file_descr, "0", 1);
		else
			f->len += write(f->file_descr, " ", 1);
		f->f_width--;
	}
	f->len += write(f->file_descr, "%", 1);
}

void		ft_print_percent(char type, t_args *f)
{
	if (type == '%')
	{
		if (f->f_minus)
			ft_print_percent_sign_left_align(f);
		else
			ft_print_percent_sign_right_align(f);
	}
}
