/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:26:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/09 17:02:42 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	colorize_window(t_data *data)
{
	int	i;
	int	j;
	int	half_screen;

	i = 0;
	half_screen = SCREEN_HEIGHT / 2;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			if (i < half_screen)
				my_mlx_pixel_put(data, j, i, rgb2int_converter(data->ceiling));
			else
				my_mlx_pixel_put(data, j, i, rgb2int_converter(data->floor));
			j++;
		}
		i++;
	}
}

t_texture	*get_value(t_texture *texture, char *key)
{
	t_texture	*tmp;

	tmp = texture;
	while (tmp)
	{
		if (!ft_strcmp(tmp->key, key))
			break ;
		tmp = tmp->next;
	}
	return (tmp);
}

void	get_color_texture(t_data *data, int *color)
{
	t_texture	*value;

	value = NULL;
	if (!data->rays[(int)data->x_wall].flag_color)
	{
		if (data->rays[(int)data->x_wall].ray_angle > M_PI)
		{
			value = get_value(data->textures, "NO");
			get_texture_offset(data, value);
			my_pixel_put(value, value->x_texture, value->y_texture, color);
		}
		else
		{
			value = get_value(data->textures, "SO");
			get_texture_offset(data, value);
			my_pixel_put(value, value->x_texture, value->y_texture, color);
		}
	}
	else
	{
		if (data->rays[(int)data->x_wall].ray_angle < 0.5 * M_PI
			|| data->rays[(int)data->x_wall].ray_angle > 1.5 * M_PI)
		{
			value = get_value(data->textures, "WE");
			get_texture_offset(data, value);
			my_pixel_put(value, value->x_texture, value->y_texture, color);
		}
		else
		{
			value = get_value(data->textures, "EA");
			get_texture_offset(data, value);
			my_pixel_put(value, value->x_texture, value->y_texture, color);
		}
	}
}

void	wall_drawing(int x, double height, t_data *data)
{
	double	y_top;
	int		color;
	double	y_bottom;

	y_top = (SCREEN_HEIGHT / 2) - (height / 2);
	if (y_top < 0)
		y_top = 0;
	color = 0;
	y_bottom = y_top + height;
	while (y_top < y_bottom && y_top < SCREEN_HEIGHT)
	{
		data->x_wall = x;
		data->y_wall = y_top;
		data->height_of_wall = height;
		get_color_texture(data, &color);
		my_mlx_pixel_put(data, x, y_top, color);
		y_top++;
	}
}

void	get_color_door(t_data *data, int *color)
{
	get_door_texture_offset(data);
	my_pixel_door_put(data, data->doors.x_texture, data->doors.y_texture, color);
}

void	wall_doors(int x, double height, t_data *data)
{
	double	y_top;
	int		color;
	double	y_bottom;

	y_top = (SCREEN_HEIGHT / 2) - (height / 2);
	color = 0;
	y_bottom = y_top + height;
	while (y_top < y_bottom && y_top < SCREEN_HEIGHT)
	{
		data->x_wall = x;
		data->y_wall = y_top;
		get_color_door(data, &color);
		my_mlx_pixel_put(data, x, y_top, color);
		y_top++;
	}
}

void	draw_walls(t_data *data)
{
	t_ray	*rays;
	int		i;
	double	height_of_wall;
	double	distance_player_proj;

	rays = data->rays;
	i = 0;
	height_of_wall = 0;
	distance_player_proj = (SCREEN_WIDTH / 2) / tan(FOV / 2);
	colorize_window(data);
	while (i < SCREEN_WIDTH)
	{
		height_of_wall = (WALL_SIZE * distance_player_proj) / (rays[i].distance
				* cos(rays[i].ray_angle - data->angle));
		wall_drawing(i, height_of_wall, data);
		if (rays[i].is_door == 1)
			wall_doors(i, height_of_wall, data);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
