/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:36 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/18 20:12:04 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PIRNTF_H

#include "../libft/libft.h"
#include <stdarg.h>
#include <unistd.h>
#define ON 1
#define OFF -1
#define SPECIFIERS "cspdiuxX%"
typedef struct s_args
{
	char 	*format;
	va_list	arg_pointer;

	int		f_minus;
	int		f_plus;
	int		f_space;
	int		f_zero;
	int		f_hash;

	int		f_width;
	int		f_precision;
	int		precision;
	int		f_type;
	int		length;

	int		printed_symb;

	int		i;
	int		len;
	int		file_descr;
}				t_args;

int	ft_printf(const char *format, ...);

static t_args	*ft_init_struct(t_args *arg);


# endif
