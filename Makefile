NAME = cub3D
CC = cc -Ofast
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f
HDR = cub3d.h
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIB = libft/
SRC =	parsing/parsing.c \
		parsing/map_reader.c \
		main.c \
		cub_utils.c \
		get_next_line/get_next_line.c \
		get_next_line/get_next_line_utils.c \
		g_collector.c \
		dict_utils.c \
		initializer.c \
		parsing/parsing_utils.c \
		minimap/drawer.c \
		minimap/move_player.c \
		minimap/move_player_utils.c \
		calc.c \
		mlx_func.c \
		minimap/dda.c \
		minimap/rotation.c \
		raycasting/raycasting.c \
		raycasting/raycasting_utils.c \
		raycasting/draw_walls.c \

OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
MLX = mlx/libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit
all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	make -C mlx
	@$(CC) $(CFLAGS) $(MLX) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@clear
	@echo "\033[1;32mCreating\033[0m" $@ "\033[1;32m...\033[0m"

%.o: %.c $(HDR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear
	@echo "\033[1;32mCompiling\033[0m" $< "\033[1;32m...\033[0m"
fclean: clean
	@$(RM) $(NAME) $(NAME_BNS)
	@make fclean -C $(LIB)
	@clear
	@echo "\033[1;31mDeleting\033[0m" $(NAME) $(NAME_BNS) "\033[1;31m...\033[0m"

clean:
	@$(RM) $(OBJ) $(OBJ_BNS)
	@clear
	@echo "\033[1;31mDeleting\033[0m" Object files "\033[1;31m...\033[0m"

re: fclean all