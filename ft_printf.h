/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:36 by aarlena           #+#    #+#             */
/*   Updated: 2020/11/24 18:08:13 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>
#define ON 1
#define OFF -1
#define SPECIFIERS "cspdiuxX%"

# define H	1
# define HH 2
# define L	3
# define LL	4
# define J	5
# define Z	6

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

int			ft_printf(const char *format, ...);
t_args		*ft_init_struct(t_args *arg);
void		ft_reset_struct(t_args *f);
void		ft_process_string(const char *format, t_args *f, va_list ap);
void		ft_parse_modifiers(const char *format, t_args *f, va_list ap);
void		ft_print_char(char type, t_args *f, va_list ap);
void		ft_putwchar_pf(wchar_t wc, t_args *f);

# endif
