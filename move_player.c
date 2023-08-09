/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:43:30 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/08 17:43:35 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_hook(int code, t_data *data)
{
	if (code == 13)
		data->flag_up = 1;
	else if (code == 1)
		data->flag_down = 1;
	else if (code == 0)
		data->flag_left = 1;
	else if (code == 2)
		data->flag_right = 1;
	else if (code == 124)
		data->rotate_right = 1;
	else if (code == 123)
		data->rotate_left = 1;
	else if (code == 53)
		exit(0);
	return (0);
}

int	key_hook2(int code, t_data *data)
{
	if (code == 13)
		data->flag_up = 0;
	else if (code == 1)
		data->flag_down = 0;
	else if (code == 0)
		data->flag_left = 0;
	else if (code == 2)
		data->flag_right = 0;
	else if (code == 124)
		data->rotate_right = 0;
	else if (code == 123)
		data->rotate_left = 0;
	else if (code == 53)
		exit(0);
	return (0);
}

void	key_hook4(t_data *data)
{
	if (data->flag_up)
	{
		if (data->map[(int)(data->player.y
				+ sin(data->player.rotation_angle) * SPEED) / 32]
			[(int)(data->player.x + cos(data->player.rotation_angle)
				* SPEED) / 32] != '1')
		{
			data->player.y += sin(data->player.rotation_angle) * SPEED;
			data->player.x += cos(data->player.rotation_angle) * SPEED;
		}
	}
	else if (data->flag_down)
	{
		if (data->map[(int)(data->player.y
				- sin(data->player.rotation_angle) * SPEED) / 32]
			[(int)(data->player.x - cos(data->player.rotation_angle)
				* SPEED) / 32] != '1')
		{
			data->player.y -= sin(data->player.rotation_angle) * SPEED;
			data->player.x -= cos(data->player.rotation_angle) * SPEED;
		}
	}
	else if (data->flag_left)
	{
		if (data->map[(int)(data->player.y
				- sin(data->player.rotation_angle + (M_PI / 2)) * SPEED) / 32]
			[(int)(data->player.x - cos(data->player.rotation_angle
				+ (M_PI / 2)) * SPEED) / 32] != '1')
		{
			data->player.y -= sin(data->player.rotation_angle
					+ (M_PI / 2)) * SPEED;
			data->player.x -= cos(data->player.rotation_angle
					+ (M_PI / 2)) * SPEED;
		}
	}
	else if (data->flag_right)
	{
		if (data->map[(int)(data->player.y) / 32]
			[(int)(data->player.x + 5) / 32] != '1')
		{
			data->player.y += sin(data->player.rotation_angle
					+ (M_PI / 2)) * SPEED;
			data->player.x += cos(data->player.rotation_angle
					+ (M_PI / 2)) * SPEED;
		}
	}
	else if (data->rotate_right)
		data->player.rotation_angle += 1 * (M_PI / 180);
	else if (data->rotate_left)
		data->player.rotation_angle -= 1 * (M_PI / 180);
}

int	key_hook3(t_data *data)
{
	t_point	p;

	mlx_destroy_image(data->mlx, data->img);
	mlx_clear_window(data->mlx, data->win);
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	key_hook4(data);
	mini_map(data, data->map);
	color_player(data);
	drawing_line(&data->player, &p, data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}
