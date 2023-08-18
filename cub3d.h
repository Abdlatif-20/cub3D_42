/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/17 17:48:22 by mel-yous         ###   ########.fr       */
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
# include <mlx.h>
# include <math.h>
# include "get_next_line/get_next_line.h"

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_dict		t_dict;
typedef struct s_mlx		t_mlx;
typedef struct s_player		t_player;
typedef struct s_dda		t_dda;

# define MAP_ERROR "Error: something is wrong in the map"
# define WALL_SIZE 32
# define PLAYER_SIZE 8
# define SPEED 2
# define ROT_SPEED 0.025
# define LINE_LENGTH 64

enum e_keycode
{
	KEY_A = 0,
	KEY_W = 13,
	KEY_D = 2,
	KEY_S = 1,

	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_UP = 126,
	KEY_DOWN = 125
};

struct s_garbage
{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
};

struct s_dict
{
	char	*key;
	char	*value;
	t_dict	*next;
	t_dict	*last;
};

struct s_dda
{
	double	x1;
	double	y1;
	double	dx;
	double	dy;
	double	steps;
	double	x_inc;
	double	y_inc;
};

struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;

	char		*img_data;
	int			bpp;
	int			line_length;
	int			endian;

	t_dict		*textures;
	int			ceiling[3];
	int			floor[3];
	char		**map;
	int			width;
	int			height;

	double		px;
	double		py;
	double		angle;
	t_dda		*dda_vars;

	int			keycode;
};

/*-----------------------------cub_utils.c-----------------------------*/
void	throw_error(char *msg, t_garbage **heap);
char	*free_s1_join(char *s1, char *s2);
int		tab_size(char **tab);
int		ft_strcmp(char *s1, char *s2);
bool	is_number(char *str);

/*-----------------------------parsing.c-----------------------------*/
void	check_textures(t_dict *textures, t_garbage **heap);
void	check_rgb_code(int *rgb, t_garbage **heap);
void	check_map_components(char **map, t_garbage **heap);
void	map_is_closed(char **map, t_garbage **heap);
void	space_checker(char **map, t_garbage **heap);

/*-----------------------------map_reader.c-----------------------------*/
char	**get_full_map(char *path, t_garbage **heap);

/*-----------------------------g_collector.c-----------------------------*/
void	add_to_garbage(t_garbage **heap, void *address);
void	empty_trash(t_garbage **heap);

/*-----------------------------dict_utils.c-----------------------------*/
char	*get_key_value(char *str, short option, t_garbage **heap);
void	add_to_texture(t_dict **texture, char *key,
			char *value, t_garbage **heap);

/*-----------------------------initializer.c-----------------------------*/
void	init_data(t_data *data, char **full_map, t_garbage **heap);

/*-----------------------------calc.c-----------------------------*/
int		get_width(char **map);
int		get_height(char **map);
int		*get_player_xy(char **map);

/*-----------------------------parsing_utils.c-----------------------------*/
bool	is_valid_component(char c);
void	skip_spaces(char *line, int *i);

/*-----------------------------drawer.c-----------------------------*/
void	draw_map(t_data *data);

/*-----------------------------engine.c-----------------------------*/
int		move_player(int keycode, t_data *data);
int		render_frame(t_data *data);

/*-----------------------------mlx_func.c-----------------------------*/
void	pixel_put(t_data *data, int x, int y, int color);

/*-----------------------------dda.c-----------------------------*/
void	dda(t_data *data, double x2, double y2);

/*-----------------------------rotation.c-----------------------------*/
void	rotate_left(t_data *data);
void	rotate_right(t_data *data);

#endif