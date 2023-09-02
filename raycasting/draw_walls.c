/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:26:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/02 14:03:23 by aben-nei         ###   ########.fr       */
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
				pixel_put(data, j, i, rgb2int_converter(data->ceiling));
			else
				pixel_put(data, j, i, rgb2int_converter(data->floor));
			j++;
		}
		i++;
	}
}

void	get_color_texture(t_data *data, int x, int *color)
{
	if (!data->rays[x].flag_color)
	{
		if (data->rays[x].ray_angle > M_PI)
			my_pixel_put(data->textures, data->textures->x_texture,
				data->textures->y_texture, color);
		else
			my_pixel_put(data->textures->next,
				data->textures->x_texture, data->textures->y_texture, color);
	}
	else
	{
		if (data->rays[x].ray_angle < 0.5 * M_PI
			|| data->rays[x].ray_angle > 1.5 * M_PI)
			my_pixel_put(data->textures->next->next,
				data->textures->x_texture, data->textures->y_texture, color);
		else
			my_pixel_put(data->textures->next->next->next,
				data->textures->x_texture, data->textures->y_texture, color);
	}
}

void	wall_drawing(int x, double height, t_data *data)
{
	double	y;
	int		color;
	double	y_temp;

	y = (SCREEN_HEIGHT / 2) - (height / 2);
	color = 0;
	y_temp = ((SCREEN_HEIGHT / 2) - (height / 2)) + height;
	while (y < y_temp && y < SCREEN_HEIGHT)
	{
		get_texture_offset(data, x, y, height);
		get_color_texture(data, x, &color);
		my_mlx_pixel_put(data, x, y, color);
		y++;
	}
}

void	draw_walls(t_data *data)
{
	t_ray	*rays;
	int		i;
	double	proj_slice_height;
	double	height_of_wall;
	double	distance_player_proj;

	rays = data->rays;
	i = 0;
	proj_slice_height = 0;
	distance_player_proj = (SCREEN_WIDTH / 2) / tan(FOV / 2);
	colorize_window(data);
	while (i < SCREEN_WIDTH)
	{
		height_of_wall = (WALL_SIZE * distance_player_proj) / (rays[i].distance
				* cos(rays[i].ray_angle - data->angle));
		wall_drawing(i, height_of_wall, data);
		i++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
