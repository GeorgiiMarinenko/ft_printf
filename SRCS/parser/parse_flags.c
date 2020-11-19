/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 19:18:42 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/17 19:42:56 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_args	*parse_flags(t_args *arg)
{
	size_t	i;

	i = 0;
	while (arg->format[i] != '\0')
	{
		if (arg->format[i] == '-')
		{
			arg->f_flag = ON;
			arg->flag = arg->format[i];
		}
		if (arg->format[i] == '0')
		{
			arg->f_flag = ON;
			arg->flag = arg->format[i];
		}
		i++;
	}
	return (arg);
}
