# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriling <eriling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 08:44:26 by eriling           #+#    #+#              #
#    Updated: 2021/01/22 09:18:11 by eriling          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = libftprintf.a
HEAD := -I../printf/include
CFLAGS = -Wall -Wextra -Werror
SRC := *.c\
      */*.c
all :   $(NAME)

$(NAME) :
	@gcc -c ${CFLAGS} ${HEAD} ${SRC}
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
clean :
	@rm -f *.o
	@rm -f */*.o

fclean :	clean
	@rm -f $(NAME) 
	@rm -f a.out

re :	fclean all
