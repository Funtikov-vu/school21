NAME := ft_ls
INCLUDES := include/ libft/includes/
SRC_DIR := src/
SRC := $(patsubst src/%, %, $(wildcard $(SRC_DIR)*.c))

LIB_DIR := libft/
LIB := $(LIB_DIR)libft.a

OBJ_DIR := out/
OBJ := $(addprefix $(OBJ_DIR), $(patsubst %.c, %.o, $(SRC)))
FLAGS := -Wall -Wextra -Werror
DEBUG_FLAGS := -g -O0

GREEN=\033[0;32m
YELLOW=\033[0;33m
NC=\033[0m # No Color

.PHONY: all run debug add_dflags clean fclean re echo

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		@gcc $(OBJ) $(LIB) $(addprefix -I,$(INCLUDES)) -o $@
		@printf "$@ $(GREEN)✔$(NC)                                        \n"


$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir  -p out/
	gcc $(FLAGS) -c $(addprefix -I,$(INCLUDES)) $< -o $@

$(LIB):
	@$(MAKE) -C $(LIB_DIR) all

debug: add_dflags ft_ls

add_dflags:
	$(eval FLAGS = $(DEBUG_FLAGS))

clean:
	@$(MAKE) -C $(LIB_DIR) clean
	@/bin/rm -f $(OBJ)
	@printf "$(NAME) clean: $(YELLOW)✔$(NC)\n"

fclean: clean
	@$(MAKE) -C $(LIB_DIR) fclean
	@/bin/rm -f $(NAME)
	@rm -rf $(OBJ_DIR)
	@printf "$(NAME) fclean: $(YELLOW)✔$(NC)\n"

re: fclean all

echo:
	@echo $(SRC)
	@echo $(OBJ)

run:
	./ft_ls -R
