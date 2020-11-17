/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarlena <aarlena@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:36 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/17 19:33:08 by aarlena          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PIRNTF_H

#include <stdarg.h>
#include <unistd.h>
#define ON 1
#define OFF -1
#define SPECIFIER "cspdiuxX%"
typedef struct s_args
{
	//Flags
	int		f_flag;
	int		f_width;
	int		f_precision;
	int		f_type;

	//Values
	int		flag;
	int		width;
	int		precision;
	int		type;

	char 	*format;
	va_list	arg_pointer;

	int		printed_symb_cntr;
}				t_args;

# endif
