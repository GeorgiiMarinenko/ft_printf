/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: georgy <georgy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 16:14:36 by aarlena           #+#    #+#             */
/*   Updated: 2020/12/09 13:33:36 by georgy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <wchar.h>

# define ON 1
# define OFF 0
# define SPECIFIERS "cspdiuxX%"

typedef struct	s_args
{
	char		*format;
	va_list		arg_pointer;

	int			f_minus;
	int			f_zero;

	int			f_width;
	int			f_precision;
	int			precision;
	int			precision_cpy;
	int			f_type;
	int			length;

	int			i;
	int			len;
	int			file_descr;
}				t_args;

int				ft_printf(const char *format, ...);

t_args			*ft_init_struct(t_args *arg);
void			ft_reset_struct(t_args *f);

void			ft_process_string(const char *format, t_args *f, va_list ap);
void			ft_parse_modifiers(const char *format, t_args *f, va_list ap);

void			ft_print_char(char type, t_args *f, va_list ap);
void			ft_print_string(char type, t_args *f, va_list ap);
void			ft_print_decimal(char type, t_args *f, va_list ap);
void			ft_print_unsigned_decimal(char type, t_args *f, va_list ap);
void			ft_print_hex(char type, t_args *f, va_list ap);
void			ft_print_pointer(char type, t_args *f, va_list ap);
void			ft_print_percent(char type, t_args *f);

void			ft_putwchar_pf(wchar_t wc, t_args *f);
int				ft_wstrsize_pf(wchar_t *wstr);
void			ft_putwstr_pf(wchar_t *wstr, t_args *f, int max);
void			ft_check_mb_cur_max(wchar_t *wstr, t_args *f);
int				ft_signed_nbr_len(intmax_t value, int base);
int				ft_unsigned_nbr_len(uintmax_t value, int base);
int				ft_itoa_base_pf(int fd, intmax_t value, int base);
int				ft_uitoa_base_pf(int fd, uintmax_t value, int base, char x);
void			ft_padding_left_align(int nbrlen, t_args *f);
void			ft_padding_right_align(int nbrlen, int n, t_args *f,
										int repits);
void			ft_condition_1(t_args *f, int nbrlen);
void			ft_condition_2(t_args *f);
void			ft_clean_percision(t_args *f);

#endif
