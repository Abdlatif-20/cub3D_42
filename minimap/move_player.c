/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:19:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/02 15:29:55 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	key_press(int code, t_data *data)
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
	else if (code == 12)
	{
		if (data->hide_mouse == 1)
		{
			mlx_mouse_show();
			data->hide_mouse = 0;
		}
		else
		{
			mlx_mouse_hide();
			data->hide_mouse = 1;
		}
	}
	return (0);
}

int	key_release(int code, t_data *data)
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

void	render_frame_helper(t_data *data)
{
	double	x;
	double	y;

	if (data->flag_up)
	{
		x = data->px + cos(data->angle) * SPEED;
		y = data->py + sin(data->angle) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	if (data->flag_down)
	{
		x = data->px - cos(data->angle) * SPEED;
		y = data->py - sin(data->angle) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	if (data->flag_left)
	{
		x = data->px - cos(data->angle + (M_PI / 2)) * SPEED;
		y = data->py - sin(data->angle + (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	if (data->flag_right)
	{
		x = data->px + cos(data->angle + (M_PI / 2)) * SPEED;
		y = data->py + sin(data->angle 	+ (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
	if (data->rotate_right)
		data->angle += KEYBOARD_ROTSPEED * (M_PI / 180);
	if (data->rotate_left)
		data->angle -= KEYBOARD_ROTSPEED * (M_PI / 180);
}

int	render_frame(t_data *data)
{
	render_frame_helper(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	cast_all_rays(data);
	draw_walls(data);
	return (0);
}
