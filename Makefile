# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/09 19:16:05 by mel-yous          #+#    #+#              #
#    Updated: 2023/09/22 15:08:08 by aben-nei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
CC = cc -Ofast -O3
CFLAGS = -Wall -Wextra -Werror #-g3 -fsanitize=address
RM = rm -f
HDR = cub3d.h
GNL = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
LIB = libft/
OBJ_DIR = obj
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
		minimap/move_up_down.c\
		minimap/move_left_right.c\
		calc.c \
		mlx_func.c \
		minimap/dda.c \
		minimap/rotation.c \
		raycasting/raycasting.c \
		raycasting/raycasting_utils.c \
		textures/draw_walls.c \
		textures/get_texture.c \

# Generate the list of object files with the same structure as SRC but in OBJ_DIR
OBJ = $(addprefix $(OBJ_DIR)/,$(SRC:.c=.o))

LIBFT = $(LIB)/libft.a
MLX = mlx/libmlx.a
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
