/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/09 18:30:33 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

# define CUB_SIZE 18
# define SCREEN_WIDTH 1280
# define SCREEN_HEIGHT 720
# define SPEED 2
# define SCALE 32

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_dict		t_dict;
typedef struct s_point		t_point;
typedef struct s_mlx		t_mlx;
typedef struct s_flags		t_flags;
typedef struct s_draw		t_draw;

# define MAP_ERROR "Error: something is wrong in the map"

struct s_garbage{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
};

struct s_dict{
	char	*key;
	char	*value;
	t_dict	*next;
	t_dict	*last;
};

struct s_point {
	double	x;
	double	y;
	double	rotation_angle;
};

struct	s_mlx{
	void	*mlx;
	void	*win;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	void	*img;
	char	*addr;
};

struct	s_flags{
	int		flag_up;
	int		flag_down;
	int		flag_left;
	int		flag_right;
	int		rotate_right;
	int		rotate_left;
};

struct s_draw{
	double	x;
	double	y;
	double	dx;
	double	dy;
	double	steps;
	double	inc_x;
	double	inc_y;
};

typedef struct s_data {
	t_mlx	mlx;
	t_flags	flags;
	t_draw	draw;
	t_point	player;
	t_dict	*textures;
	size_t	height;
	size_t	width;
	float	more_speed;
	char	**map;
	int		ceiling[3];
	int		floor[3];
}				t_data;

void	check_name_of_map(char *str, char *find);
void	fill_map(char *av, char **map);
char	*get_next_line(int fd);
void	drawing_line(t_point *p1, t_point *p2, t_data *data);
void	length_of_map(char *av, t_data *data);
void	check_map_is_valid(char **map);
void	add_to_garbage(t_garbage **garbage, void *ptr);
void	free_garbage(t_garbage **garbage);
bool	check_map(char map);
bool	check_map_is_closed(char *map);
void	ft_draw_map(char **map, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	mini_map(t_data *data, char **map);
void	get_position_of_player(char **map, t_data *data);
void	color_player(t_data *data);
int		key_hook(int code, t_data *data);
void	print(char **map);
void	print_list(t_garbage *garbage);
int		key_hook2(int code, t_data *data);
int		key_hook3(t_data *data);
void	draw_line(t_data *data, double x, double y, int color);

/*-----------------------------cub_utils.c-----------------------------*/
void	throw_error(char *msg, t_garbage **heap);
char	*free_s1_join(char *s1, char *s2);
int		tab_size(char **tab);
int		ft_strcmp(char *s1, char *s2);
bool	is_number(char *str);

/*-----------------------------parsing.c-----------------------------*/
void	check_textures(t_dict *textures, t_garbage **heap);
void	check_rgb_code(int *rgb, t_garbage **heap);

/*-----------------------------map_reader.c-----------------------------*/
char	**get_full_map(char *path, t_garbage **heap);
void	fill_dict(char **full_map, t_dict **dict, t_garbage **heap);

/*-----------------------------g_collector.c-----------------------------*/
void	add_to_garbage(t_garbage **heap, void *address);
void	empty_trash(t_garbage **heap);

/*-----------------------------dict_utils.c-----------------------------*/
char	*get_key_value(char *str, short option, t_garbage **heap);
t_dict	*create_node(char *str, t_garbage **heap);

/*-----------------------------initializer.c-----------------------------*/
void	init_data(t_data *data, char **full_map, t_garbage **heap);

#endif