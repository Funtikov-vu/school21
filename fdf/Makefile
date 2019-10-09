NAME = fdf

INCL = ./incl

LIBFT = ./libft/libft.a

LIB = /usr/local/lib ./libft/libft.a

SRC = ./srcs/*.c 

FW = -lmlx -framework OpenGl -framework AppKit

all: $(NAME)

$(NAME):
		make -C libft/
		gcc -o $(NAME) -I $(INCL) -I /usr/local/include $(SRC) -L $(LIB) $(FW)

clean:
		rm -rf *.o
		make -C libft/ clean

fclean: clean
		rm -rf $(NAME)
		rm -rf $(LIBFT)

re: fclean all
