# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriling <eriling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 08:44:26 by eriling           #+#    #+#              #
#    Updated: 2021/01/22 13:52:24 by eriling          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
HEAD = -Iinclude
CFLAGS = -Wall -Wextra -Werror
FILES = printf.c \
		./print_c_percent/print_c_percent.c \
		./print_diu_hex/is_else.c \
		./print_diu_hex/res_is_blank.c \
		./print_diu_hex/precision_is_positive.c \
		./print_diu_hex/res_is_neg.c \
		./print_diu_hex/print_diu_hex.c \
		./print_diu_hex/var_init_int.c \
		./print_p/p_is_else.c \
		./print_p/p_res_is_blank.c \
		./print_p/p_precision_is_positive.c \
		./print_p/print_p.c \
		./print_s/print_s.c \
		./print_s/res_is_minus.c \
		./src/check.c \
		./src/conversion.c \
		./src/format.c \
		./src/handle_flag.c \
		./src/handle_main.c \
		./src/struct_init.c \
		./utils/ft_itoa_base.c \
		./utils/ft_putstr.c \
		./utils/ft_strdup.c \
		./utils/print_space.c \
		./utils/ft_numlen.c \
		./utils/ft_strcmp.c \
		./utils/ft_strlen.c \
		./utils/ft_atoi.c \
		./utils/print_struct.c \


OBJ=$(FILES:.c=.o)

all :   $(NAME)

$(NAME) : $(OBJ) ./include/printf.h
			ar rc $(NAME) $(OBJ)

.c.o: $(FILES)
		$(CC) $(CFLAGS) -c $(HEAD) $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean

	rm -rf $(NAME)
re: fclean all
