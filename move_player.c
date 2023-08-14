/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:43:30 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/12 18:07:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int code, t_data *data)
{
	if (code == W)
		data->flags.flag_up = 1;
	else if (code == S)
		data->flags.flag_down = 1;
	else if (code == A)
		data->flags.flag_left = 1;
	else if (code == D)
		data->flags.flag_right = 1;
	else if (code == RIGHT)
		data->flags.rotate_right = 1;
	else if (code == LEFT)
		data->flags.rotate_left = 1;
	else if (code == ESC)
		exit(0);
	return (0);
}

bool	check_wall(t_data *data, double x, double y)
{
	if (data->map[(int)(y) / SCALE][(int)(x + 1) / SCALE] != '1' &&
		data->map[(int)(y) / SCALE][(int)(x - 1) / SCALE] != '1' &&
		data->map[(int)(y + 1) / SCALE][(int)(x) / SCALE] != '1' &&
		data->map[(int)(y - 1) / SCALE][(int)(x) / SCALE] != '1' &&
		data->map[(int)(y + 1) / SCALE][(int)(x + 1) / SCALE] != '1' &&
		data->map[(int)(y) / SCALE][(int)(x) / SCALE] != '1')
		return (true);
	return (false);
}

int	key_hook2(int code, t_data *data)
{
	if (code == W)
		data->flags.flag_up = 0;
	else if (code == S)
		data->flags.flag_down = 0;
	else if (code == A)
		data->flags.flag_left = 0;
	else if (code == D)
		data->flags.flag_right = 0;
	else if (code == RIGHT)
		data->flags.rotate_right = 0;
	else if (code == LEFT)
		data->flags.rotate_left = 0;
//	else if (code == 69)
//	{
//		if (data->more_speed >= 0 && data->more_speed < 3)
//			data->more_speed += 0.5;
//	}
//	else if (code == 78)
//	{
//		if (data->more_speed > 0.5 && data->more_speed <= 3)
//			data->more_speed -= 0.5;
//	}
	else if (code == 53)
		exit(0);
	return (0);
}

void	key_hook4(t_data *data)
{
	double	x;
	double	y;

	if (data->flags.flag_up)
	{
		x = data->player.x + cos(data->player.rotation_angle)
			* SPEED;
		y = data->player.y + sin(data->player.rotation_angle)
			* SPEED;
		if (check_wall(data, x, y))
		{
			data->player.y = y;
			data->player.x = x;
		}
	}
	else if (data->flags.flag_down)
	{
		x = data->player.x - cos(data->player.rotation_angle)
			* SPEED;
		y = data->player.y - sin(data->player.rotation_angle)
			* SPEED;
		if (check_wall(data, x, y))
		{
			data->player.y = y;
			data->player.x = x;
		}
	}
	else if (data->flags.flag_left)
	{
		x = data->player.x - cos(data->player.rotation_angle
				+ (M_PI / 2)) * SPEED;
		y = data->player.y - sin(data->player.rotation_angle
				+ (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->player.y = y;
			data->player.x = x;
		}
	}
	else if (data->flags.flag_right)
	{
		x = data->player.x + cos(data->player.rotation_angle
				+ (M_PI / 2)) * SPEED;
		y = data->player.y + sin(data->player.rotation_angle
				+ (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->player.y = y;
			data->player.x = x;
		}
	}
	else if (data->flags.rotate_right)
		data->player.rotation_angle += 1 * (M_PI / 180);
	else if (data->flags.rotate_left)
		data->player.rotation_angle -= 1 * (M_PI / 180);
}

int	key_hook3(t_data *data)
{
	t_point	p;

	mlx_destroy_image(data->mlx.mlx, data->mlx.img);
	mlx_clear_window(data->mlx.mlx, data->mlx.win);
	data->mlx.img = mlx_new_image(data->mlx.mlx, 1200, 1200);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	key_hook4(data);
	mini_map(data);
	color_player(data);
	drawing_line(&data->player, &p, data);
	casting_rays(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, data->mlx.img, 0, 0);
	return (0);
}
