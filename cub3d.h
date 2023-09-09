/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/04 12:46:51 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include <math.h>
# include "get_next_line/get_next_line.h"

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_texture	t_texture;
typedef struct s_mlx		t_mlx;
typedef struct s_player		t_player;
typedef struct s_dda		t_dda;
typedef struct s_ray		t_ray;
typedef struct s_vars		t_vars;
typedef struct s_texture	t_texture;

# define MAP_ERROR "Error: something is wrong in the map"
# define WALL_SIZE 32
# define PLAYER_SIZE 8
# define SPEED 6
# define MOUSE_ROTSPEED 0.0007
# define KEYBOARD_ROTSPEED 5
# define LINE_LENGTH 64
# define FOV 60 * (M_PI / 180)
# define SCREEN_WIDTH 1300
# define SCREEN_HEIGHT 850

enum e_keycode
{
	KEY_A = 0,
	KEY_W = 13,
	KEY_D = 2,
	KEY_S = 1,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_ESC = 53,
	KEY_COUNT = 256,
	MOUSE_LEFT = 1,
	MOUSE_RIGHT = 2
};

struct s_garbage
{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
};

struct s_texture
{
	char		*key;
	char		*value;
	double		x_texture;
	double		y_texture;	
	int			texture_height;
	int			texture_width;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	void		*texture_ptr;
	char		*img_addr;
	int			bpp;
	int			line_length;
	int			endian;
	t_texture	*next;
	t_texture	*last;
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

struct s_ray
{
	double		ray_angle;
	double		distance;
	double		wall_hit_x;
	double		wall_hit_y;
	bool		flag_color;
};

struct s_vars
{
	bool	ray_looking_down;
	bool	ray_looking_right;
	double	x_horz_int;
	double	y_horz_int;
	double	x_vert_int;
	double	y_vert_int;
	double	x_step;
	double	y_step;
	double	horz_dist;
	double	vert_dist;
};

struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*img_data;
	int				bpp;
	int				line_length;
	int				endian;
	t_texture		*textures;
	int				ceiling[3];
	int				floor[3];
	int				colors[3];
	char			**map;
	int				width;
	int				height;
	double			px;
	double			py;
	double			angle;
	t_dda			*dda_vars;
	int				keycode;
	t_ray			*rays;
	t_vars			*vars;
	int				flag_up;
	int				flag_down;
	int				flag_left;
	int				flag_right;
	int				rotate_left;
	int				rotate_right;

	int				hide_mouse;
	int				mouse_x;
	int				mouse_y;
};

/*-----------------------------cub_utils.c-----------------------------*/
void	throw_error(char *msg, t_garbage **heap);
char	*free_s1_join(char *s1, char *s2);
int		tab_size(char **tab);
int		ft_strcmp(char *s1, char *s2);
bool	is_number(char *str);

/*-----------------------------parsing.c-----------------------------*/
void	check_textures(t_texture *textures, t_garbage **heap);
void	check_rgb_code(int *rgb, t_garbage **heap);
void	check_map_components(char **map, t_garbage **heap);
void	map_is_closed(char **map, t_garbage **heap);
void	space_checker(char **map, t_garbage **heap);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*-----------------------------map_reader.c-----------------------------*/
char	**get_full_map(char *path, t_garbage **heap);

/*-----------------------------g_collector.c-----------------------------*/
void	add_to_garbage(t_garbage **heap, void *address);
void	empty_trash(t_garbage **heap);

/*-----------------------------texture_utils.c-----------------------------*/
char	*get_key_value(char *str, short option, t_garbage **heap);
void	add_to_texture(t_texture **texture, char *key,
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
int		key_press(int code, t_data *data);
int		key_release(int code, t_data *data);
int		render_frame(t_data *data);
bool	check_wall(t_data *data, double x, double y);

/*-----------------------------mlx_func.c-----------------------------*/
void	pixel_put(t_data *data, int x, int y, int color);

/*-----------------------------dda.c-----------------------------*/
void	dda(t_data *data, double x2, double y2);

/*----------------------------- movement player -----------------------------*/
void	move_up(t_data *data);
void	move_down(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	rotate_left(t_data *data, double rotaion_speed);
void	rotate_right(t_data *data, double rotation_speed);

/*-----------------------------raycasting.c-----------------------------*/
void	cast_all_rays(t_data *data);

/*-----------------------------raycasting_utils.c-----------------------------*/
int		rgb2int_converter(int *rgb);

/*-----------------------------draw_walls.c-----------------------------*/
void	colorize_window(t_data *data);
void	draw_walls(t_data *data);

/*----------------------------- textures -----------------------------*/
void	get_texture_offset(t_data *data, double x, double y, double height);
// void 	my_pixel_put(t_data *data, int x, int y, int *color);
void	my_pixel_put(t_texture *data, int x, int y, int *color);

#endif