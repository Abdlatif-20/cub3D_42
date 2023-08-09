/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/01 17:40:57 by aben-nei         ###   ########.fr       */
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

# define CUB_SIZE 18
# define SPEED 5
typedef struct s_garbage
{
	void				*data;
	struct s_garbage	*next;
	struct s_garbage	*last;
}				t_garbage;

typedef struct s_point {
	double	x;
	double	y;
	double	rotation_angle;
}				t_point;

typedef struct s_data {
	void	*mlx;
	void	*win;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	void	*img;
	char	*addr;
	int		x;
	int		y;
	int		dx;
	int		dy;
	int		flag_up;
	int		flag_down;
	int		flag_left;
	int		flag_right;
	int		steps;
	double	inc_x;
	double	inc_y;
	size_t	height;
	size_t	width;
	t_point	player;
	char	**map;
}				t_data;

void	check_name_of_map(char *str, char *find);
void	drawing_line(t_point p1, t_point p2, t_data *data);
void	fill_map(char *av, char **map, t_garbage **heap);
char	*get_next_line(int fd);
void	length_of_map(char *av, t_data *data);
void	check_map_is_valid(char **map);
void	add_to_garbage(t_garbage **garbage, void *ptr);
void	check_texture(char *av, t_garbage **heap);
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
#endif