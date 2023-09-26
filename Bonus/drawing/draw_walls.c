/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:30:23 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/26 20:03:42 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	colorize_window(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < SCREEN_HEIGHT)
	{
		j = 0;
		while (j < SCREEN_WIDTH)
		{
			if (i < data->half_screen)
				my_mlx_pixel_put(data, j, i, data->celling_color);
			else
				my_mlx_pixel_put(data, j, i, data->floor_color);
			j++;
		}
		i++;
	}
}

void	shadow(t_data *data, unsigned int *color)
{
	data->vars.color_decrement = (1 / data->ray->distance) * 200;
	if (data->vars.color_decrement > 1)
		data->vars.color_decrement = 1;
	ft_convert_to_rgb(*color, data->vars.rgb);
	decrementbrightness(&data->vars.rgb[0], &data->vars.rgb[1],
		&data->vars.rgb[2], data->vars.color_decrement);
	*color = rgb2int_converter(data->vars.rgb);
}

void	wall_drawing(int x, float height, t_data *data)
{
	float			y_top;
	unsigned int	color;
	float			y_bottom;

	y_top = data->half_screen - (height / 2);
	color = 0x1e272e;
	y_bottom = y_top + height;
	if (y_top < 0)
		y_top = 0;
	if (y_bottom > SCREEN_HEIGHT)
		y_bottom = SCREEN_HEIGHT;
	while (y_top < y_bottom && y_top < SCREEN_HEIGHT)
	{
		data->flags->flag_door = 0;
		get_color_texture(data, &color, height, y_top);
		shadow(data, &color);
		my_mlx_pixel_put(data, x, y_top, color);
		y_top++;
	}
}

void	ft_directions(t_data *data)
{
	mlx_put_image_to_window(data->mlx->mlx_ptr, data->mlx->win_ptr,
		data->window_img->img_ptr, 0, 0);
	data->vars.north = my_mlx_xpm_file_to_img(data,
			"./icons/north.xpm", &data->vars.h, &data->vars.h);
	data->vars.east = my_mlx_xpm_file_to_img(data,
			"./icons/east.xpm", &data->vars.w, &data->vars.h);
	data->vars.south = my_mlx_xpm_file_to_img(data,
			"./icons/south.xpm", &data->vars.w, &data->vars.h);
	data->vars.west = my_mlx_xpm_file_to_img(data,
			"./icons/west.xpm", &data->vars.w, &data->vars.h);
	mlx_put_image_to_window(data->mlx->mlx_ptr,
		data->mlx->win_ptr, data->vars.north, 95, SCREEN_HEIGHT - 205);
	mlx_put_image_to_window(data->mlx->mlx_ptr,
		data->mlx->win_ptr, data->vars.east, 188, (SCREEN_HEIGHT - 218) + 100);
	mlx_put_image_to_window(data->mlx->mlx_ptr,
		data->mlx->win_ptr, data->vars.south, 95, SCREEN_HEIGHT - 23);
	mlx_put_image_to_window(data->mlx->mlx_ptr,
		data->mlx->win_ptr, data->vars.west, 3, (SCREEN_HEIGHT - 218) + 100);
}

void	clear_window_draw(t_data *data)
{
	mlx_clear_window(data->mlx->mlx_ptr, data->mlx->win_ptr);
	colorize_window(data);
	cast_all_rays(data);
	if (data->player->weapon == PISTOL)
	{
		draw_ammo_bar(data);
		dda(data, (t_vars){.x = (SCREEN_WIDTH / 2) - 8, .y = SCREEN_HEIGHT / 2,
			.x1 = (SCREEN_WIDTH / 2) + 8, .y1 = SCREEN_HEIGHT / 2}, 0x32cd32);
		dda(data, (t_vars){.x = SCREEN_WIDTH / 2, .y = (SCREEN_HEIGHT / 2) - 8,
			.x1 = SCREEN_WIDTH / 2, .y1 = (SCREEN_HEIGHT / 2) + 8}, 0x32cd32);
	}
	draw_minimap(data);
	ft_directions(data);
}
