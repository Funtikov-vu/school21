NAME = libftprintf.a

SOURCE1 = ft_printf.c	ft_printf_ouxx.c\
ft_printf_csp.c			ft_printf_parser.c\
ft_printf_csp_sub.c		ft_printf_parser_utils.c\
ft_printf_decimal.c		ft_printf_float.c		ft_printf_utils.c\
ft_printf_format.c

SOURCE2 = ft_add_char.c ft_addr_char.c \
ft_itoa_base_unsgn.c ft_isdigit.c \
ft_max.c ft_memset.c ft_putchar.c \
ft_putchar_fd.c ft_putendl.c ft_putnbr.c \
ft_putnbr_base.c ft_putnstr_fd.c ft_putnwstr_fd.c \
ft_putstr_fd.c ft_putstr.c ft_putwchar.c  ft_putwchar_fd.c\
ft_strchr.c ft_strchrpos.c ft_strdup.c \
ft_strequ.c ft_strfreejoin.c ft_strjdelsnd.c \
ft_strlen.c ft_strncat.c ft_strnchr.c \
ft_strncmp.c ft_strnewchr.c ft_strwlen.c \
ft_wcharlen.c ft_abs.c ft_memalloc.c \
ft_myrealloc.c ft_strcpy.c ft_strjoin.c \
ft_memmove.c

INCL = ./includes/

LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

DIR_S1 = ./srcs/

DIR_S2 = ./libft/

SRCS = $(addprefix $(DIR_S1),$(SOURCE1)) $(addprefix $(DIR_S2),$(SOURCE2))

OBJECTS = $(SOURCE1:.c=.o) $(SOURCE2:.c=.o)

all: $(NAME)

$(NAME):
		gcc -c $(FLAGS) $(SRCS) -I $(INCL)
		ar rc libftprintf.a *.o
		ranlib libftprintf.a

clean:
		rm -f $(OBJECTS) ./libft/*.o

fclean: clean
		rm -f $(NAME) $(LIB)

re:	fclean all
