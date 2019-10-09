# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharvey <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 12:13:03 by hharvey           #+#    #+#              #
#    Updated: 2018/12/24 14:25:57 by hharvey          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS  = ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c \
ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c \
ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c \
ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
ft_lstfold.c ft_get_wrd.c ft_arrstrdel.c ft_lstprint.c ft_swap_str.c ft_myrealloc.c \
get_next_line.c ft_abs.c ft_strnchr.c ft_add_char.c ft_strfreejoin.c ft_itoa_base.c \
ft_addr_char.c ft_max.c ft_strjdelfst.c ft_strdelchr.c ft_itoa_base_unsgn.c ft_strchrpos.c \
ft_strnewchr.c ft_strjdelsnd.c ft_putwchar.c ft_strwlen.c ft_putwstr_fd.c ft_putnbr_base.c \
ft_putnstr_fd.c ft_putnwstr_fd.c ft_putwchar_fd.c

OBJECTS = $(SRCS:.c=.o)

INCLS = ./includes

all: $(NAME)

$(NAME):
	gcc -c $(SRCS) 
	ar rc libft.a $(OBJECTS)
	ranlib libft.a

clean:
		rm -f $(OBJECTS)

fclean: clean
		rm -f $(NAME)

re:		fclean all
	


