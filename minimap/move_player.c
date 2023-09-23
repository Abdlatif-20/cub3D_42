/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:19:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/23 18:43:33 by aben-nei         ###   ########.fr       */
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
	else if (code == SPEED_UP)
	{
		if (data->flag_speed < 4)
			data->flag_speed += 0.5;
	}
	else if (code == SPEED_DOWN)
	{
		if (data->flag_speed > 0.5)
			data->flag_speed -= 0.5;
	}
	else if (code == KEY_Q)
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
	else if (code == KEY_SPACE)
	{
		if (data->door_dist < 40 && data->doors.open_door == 1)
			data->door[data->index_door].open_door = 0;
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
	return (0);
}

void	render_frame_helper(t_data *data)
{
	move_up(data);
	move_down(data);
	move_left(data);
	move_right(data);
	rotate_right(data);
	rotate_left(data);
}

static void	draw_pistol(t_data *data)
{
	static bool flag = true;
	static int	y;
	static int	i;

	if (!data->lmouse_pressed)
	{
		if (y < 20 && flag)
			y++;
		if (y >= 20)
			flag = false;
		if (y >= 20 || !flag)
			y--;
		if (y <= 0)
		{
			y = 0;
			flag = true;
		}
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[0].img, 0, y);
	}
	else
	{
		if (i >= 0 && i < 3)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[0].img, 0, 0);
		else if (i >= 3 && i < 6)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[1].img, 0, 0);
		else if (i >= 6 && i < 9)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[2].img, 0, 0);
		else if (i >= 9 && i < 12)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[3].img, 0, 0);
		else if (i >= 12 && i < 15)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[4].img, 0, 0);
		else if (i >= 15 && i < 18)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[5].img, 0, 0);
		else if (i >= 18 && i < 21)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[6].img, 0, 0);
		else if (i >= 21 && i < 24)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[7].img, 0, 0);
		else if (i >= 24 && i < 27)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[8].img, 0, 0);
		else if (i >= 27 && i < 30)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[9].img, 0, 0);
		else if (i >= 30 && i < 33)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[10].img, 0, 0);
		else if (i >= 33 && i < 36)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[11].img, 0, 0);
		else if (i >= 36 && i < 39)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[12].img, 0, 0);
		else if (i >= 39 && i < 42)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[13].img, 0, 0);
		else if (i >= 42 && i < 45)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->knife[14].img, 0, 0);
		i++;
		if (i >= 45)
		{
			i = 0;
			data->lmouse_pressed = false;
		}
	}
}

int	render_frame(t_data *data)
{
	render_frame_helper(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	cast_all_rays(data);
	draw_walls(data);
	draw_pistol(data);
	if (data->door_dist > 30 && !data->door[data->index_door].open_door)
		data->door[data->index_door].open_door = 1;
	return (0);
}
