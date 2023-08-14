NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
RM = rm -f
HDR = cub3d.h
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIB = libft/
SRC = main.c\
	draw_line.c\
	draw_mini_map.c\
	move_player.c\
	$(GNL) \
	parsing/parsing.c \
	parsing/map_reader.c \
	cub_utils.c \
	g_collector.c \
	initializer.c\
    dict_utils.c \
    parsing/parsing_utils.c\
    ray_cast.c \
    draw_ray.c

OBJ = $(SRC:.c=.o)
_LIB = libft/libft.a
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	@$(CC) $(CFLAGS) $(OBJ) $(MLX_FLAGS) $(_LIB) -o $(NAME)
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