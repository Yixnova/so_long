NAME = so_long
CC = cc
FLAGS = -Wall -Wextra -Werror

UNAME_S := $(shell uname -s)

# macOS
ifeq ($(UNAME_S), Darwin)
	LDFLAGS = -L./minilibx-mac -lmlx -framework OpenGL -framework AppKit
	MLX = ./minilibx-mac/libmlx.a
	MLX_DIR = ./minilibx-mac
else
# Linux
	LDFLAGS = -L./minilibx-linux -lmlx -lX11 -lXext -lm
	MLX = ./minilibx-linux/libmlx.a
	MLX_DIR = ./minilibx-linux
endif

LIBFT = ./lib/libft.a
PRINTF = ./printf/libftprintf.a
GNL = ./gnl/gnl.a

SRC =	map.c\
		main.c\
		utils.c\
		move.c\
		playable.c\
		valid.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(MLX) $(LIBFT) $(GNL) $(PRINTF)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJ) $(MLX) $(LIBFT) $(GNL) $(PRINTF) $(LDFLAGS)

$(MLX):
	@make -C $(MLX_DIR)

$(LIBFT):
	@make -C ./lib

$(PRINTF):
	@make -C ./printf

$(GNL):
	@make -C ./gnl

clean:
	@rm -f $(OBJ)
	@make clean -C ./printf
	@make clean -C $(MLX_DIR)
	@make clean -C ./lib
	@make clean -C ./gnl

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./printf
	@make fclean -C ./lib
	@make fclean -C ./gnl

re: fclean all
