# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: udraugr- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/08 13:12:03 by udraugr-          #+#    #+#              #
#    Updated: 2018/12/08 13:26:22 by udraugr-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ./fillit_project/*.c

LIB = ./libft/*.a

all: $(NAME)

$(NAME):
			make -C libft/ fclean && make -C libft/
			gcc -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIB)
clean:
			/bin/rm -f ./libft/*.o

fclean: clean
			/bin/rm -f $(NAME)
			/bin/rm -f $(LIB)

re:		fclean all
