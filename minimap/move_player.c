/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:19:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/30 17:22:36 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_hook(int code, t_data *data)
{
	if (code == KEY_W)
		data->flag_up = 1;
	else if (code == KEY_S)
		data->flag_down = 1;
	else if (code == KEY_A)
		data->flag_left = 1;
	else if (code == KEY_D)
		data->flag_right = 1;
	else if (code == KEY_RIGHT)
		data->rotate_right = 1;
	else if (code == KEY_LEFT)
		data->rotate_left = 1;
	else if (code == KEY_ESC)
		exit(0);
	return (0);
}

int	key_hook2(int code, t_data *data)
{
	if (code == KEY_W)
		data->flag_up = 0;
	else if (code == KEY_S)
		data->flag_down = 0;
	else if (code == KEY_A)
		data->flag_left = 0;
	else if (code == KEY_D)
		data->flag_right = 0;
	else if (code == KEY_RIGHT)
		data->rotate_right = 0;
	else if (code == KEY_LEFT)
		data->rotate_left = 0;
	else if (code == 53)
		exit(0);
	return (0);
}

void	key_hook4(t_data *data)
{
	double	x;
	double	y;

	if (data->flag_up)
	{
		x = data->px + cos(data->angle)
			* SPEED;
		y = data->py + sin(data->angle)
			* SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	else if (data->flag_down)
	{
		x = data->px - cos(data->angle)
			* SPEED;
		y = data->py - sin(data->angle)
			* SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	else if (data->flag_left)
	{
		x = data->px - cos(data->angle - (M_PI / 2)) * SPEED;
		y = data->py - sin(data->angle - (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	else if (data->flag_right)
	{
		x = data->px + cos(data->angle + (M_PI / 2)) * SPEED;
		y = data->py + sin(data->angle 	+ (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	else if (data->rotate_right)
		data->angle += ROT_SPEED * (M_PI / 180);
	else if (data->rotate_left)
		data->angle -= ROT_SPEED * (M_PI / 180);
}

int	key_hook3(t_data *data)
{
	key_hook4(data);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_length, &data->endian);
	// cast_all_rays(data);
	// draw_walls(data);
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}

