# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: georgy <georgy@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/24 17:06:31 by georgy            #+#    #+#              #
#    Updated: 2020/12/04 16:16:42 by georgy           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FT_PRINTF_SRC = ft_printf.c \
				ft_init_struct.c \
				ft_process_string.c \
				ft_parse_modifiers.c \
				\
				ft_print_char.c \
				ft_print_string.c \
				ft_print_decimal.c \
				ft_print_insigned_decimal.c \
				\
				ft_reset_struct.c \
				ft_putwchar_pf.c \
				ft_wstrsize_pf.c \
				ft_putwstr_pf.c \
				ft_itoa_base_pf.c \
				ft_unsigned_itoa_base.c \
				print_dec_padding.c \
				ft_signed_nbr_len.c \
				ft_unsigned_nbr_len.c \


LIBFT_PATH = libft/
LIBFT_SRC = ft_bzero.c ft_calloc.c \
			ft_strlen.c ft_strdup.c ft_strcpy.c ft_strchr.c ft_strcmp.c \
			ft_atoi.c ft_isdigit.c ft_isspace.c \

OBJ += $(FT_PRINTF_SRC:.c=.o)
OBJ += $(addprefix $(LIBFT_PATH),$(LIBFT_SRC:.c=.o))

CC = gcc
CFLAGS = -Wall -Werror -Wextra

CLEAR_LINE = \033[2K\c

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\nCreating $@"
	make -C libft/
	cp libft/libft.a .
	mv libft.a libftprintf.a
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	@echo "$(CLEAR_LINE)"
	@echo "Compiling $<\r\c"
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
