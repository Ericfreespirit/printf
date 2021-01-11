# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eriling <eriling@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/11 08:44:26 by eriling           #+#    #+#              #
#    Updated: 2021/01/11 09:35:19 by eriling          ###   ########.fr        #
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
	#gcc libft.a test.c
	#rm -f *.o
	#rm libft.a
	#echo "\033[0;32mCompiled\033[0m"
	#echo "== RESULT =="
	#./a.out | cat -e
clean :
	@rm -f *.o
	@rm -f */*.o

fclean :	clean
	@rm -f $(NAME) 
	@rm -f a.out
	@echo "\033[1;31mDelete all\033[0m"

re :	fclean all
