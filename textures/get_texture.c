/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:01:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/31 21:02:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void	get_texture_offset(t_data *data, t_texture *texture)
{
	double  start_y;

	start_y = (SCREEN_HEIGHT / 2) - (data->height_of_wall / 2);
	if (data->rays[(int)data->x_wall].flag_color == 0)
		texture->x_texture = fmod(data->rays[(int)data->x_wall].wall_hit_x
			* texture->texture_width / WALL_SIZE, texture->texture_width);
	else
		texture->x_texture = fmod(data->rays[(int)data->x_wall].wall_hit_y
			* texture->texture_width / WALL_SIZE, texture->texture_width);
	texture->y_texture = (data->y_wall - start_y) * (texture->texture_height / data->height_of_wall);
}

void	get_door_texture_offset(t_data *data)
{
	double  start_y;

	start_y = ((SCREEN_HEIGHT / 2) - (data->height_of_wall / 2));
	if (data->rays[(int)data->x_wall].flag_color == 0)
		data->doors.x_texture = fmod(data->rays[(int)data->x_wall].wall_hit_x
			* data->doors.texture_width / WALL_SIZE, data->doors.texture_width);
	else
		data->doors.x_texture = fmod(data->rays[(int)data->x_wall].wall_hit_y
			* data->doors.texture_width / WALL_SIZE, data->doors.texture_width);
	data->doors.y_texture = (data->y_wall - start_y) * (double)data->doors.texture_height / data->height_of_wall;
}

void	my_pixel_put(t_texture *data, int x, int y, int *color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img_addr + (y * data->line_length + x
			* (data->bpp / 8));
	*color = *(unsigned int *)dst;
}

void	my_pixel_door_put(t_data *data, int x, int y, int *color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->doors.img_addr + (y * data->doors.line_length + x
			* (data->doors.bpp / 8));
	*color = *(unsigned int *)dst;
}