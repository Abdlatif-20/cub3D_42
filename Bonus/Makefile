# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 21:30:31 by mel-yous          #+#    #+#              #
#    Updated: 2023/09/24 23:39:16 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc -Ofast -O3 -I ../mlx/ -I ../libft/ -I ../get_next_line/
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
RM = rm -f
HDR = cub3d.h
GNL = ../get_next_line/get_next_line.c ../get_next_line/get_next_line_utils.c
LIB = ../libft/
OBJ_DIR = obj
SRC = main.c \
g_collector.c \
cub3d_utils.c \
parsing/map_reader.c \
initializer/init_data.c \
initializer/init_mlx.c \
initializer/init_player.c \
parsing/color_parser.c \
parsing/texture_parser.c \
parsing/map_parser.c \
parsing/parsing_utils.c \
my_mlx_func.c \
raycasting/raycasting.c \
raycasting/raycasting_utils.c \
info_getter.c \
drawing/draw_walls.c \
drawing/drawing_utils.c \
engine/move_player.c \
engine/move_left_right.c \
engine/move_up_down.c \
engine/move_player_utils.c \
engine/rotation.c \
hooks.c \
animation/knife_animation.c \
animation/pistol_animation.c \
animation/animation_utils.c \
minimap/minimap.c \
minimap/minimap_utils.c \
$(GNL)

# Generate the list of object files with the same structure as SRC but in OBJ_DIR
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

LIBFT = $(LIB)/libft.a
MLX = ../mlx/libmlx.a
MLXFLAGS = -framework OpenGL -framework AppKit
all: $(NAME)

# Rules for creating the executable
$(NAME): $(OBJ)
	make -C $(LIB)
	@$(CC) $(CFLAGS) $(MLX) $(OBJ) $(MLXFLAGS) $(LIBFT) -o $(NAME)
	@clear
	@echo "\033[1;32mCreating\033[0m" $@ "\033[1;32m...\033[0m"

# Rules for creating object files in the OBJ_DIR
$(OBJ_DIR)/%.o: %.c $(HDR)
	@mkdir -p $(@D)  # Create the directory if it doesn't exist
	@$(CC) $(CFLAGS) -c $< -o $@
	@clear
	@echo "\033[1;32mCompiling\033[0m" $< "\033[1;32m...\033[0m"

# Rules for cleaning generated .o files
fclean: clean
	@$(RM) $(NAME) $(NAME_BNS)
	@make fclean -C $(LIB)
	@clear
	@echo "\033[1;31mDeleting\033[0m" $(NAME) $(NAME_BNS) "\033[1;31m...\033[0m"

clean:
	@$(RM) -r $(OBJ_DIR)
	@clear
	@echo "\033[1;31mDeleting\033[0m" Object files "\033[1;31m...\033[0m"

re: fclean all