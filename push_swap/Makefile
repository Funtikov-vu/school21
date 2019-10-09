NAME = makeall

NAME1 = push_swap

NAME2 = checker

INCL = ./incl/

INCLMLX = /usr/local/include

MLXLIB = /usr/local/lib/

LIB = ./libft/libft.a

FLAGS = -Wall -Wextra -Werror

SRCS = ./common_src/*.c

SRCS1 = ./ps_srcs/*.c $(LIB)

SRCS2 = ./checker_src/*.c $(LIB)

FW = -lmlx -framework OpenGl -framework AppKit

FLAGS = -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(NAME1) $(NAME2)

$(NAME1):
		make -C libft/
		gcc -o $(NAME1) $(FLAGS) $(SRCS) $(SRCS1) -I $(INCL)

$(NAME2):
		make -C libft/
		gcc -o $(NAME2) $(FLAGS) -I $(INCL) -I $(INCLMLX) $(SRCS) $(SRCS2) -L $(MLXLIB) $(FW)


clean:
		make -C libft/ clean
		rm -rf *.o

fclean: clean
		rm -rf $(LIB)
		rm -rf $(NAME1) $(NAME2)

re: fclean all
