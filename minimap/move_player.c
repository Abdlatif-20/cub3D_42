/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:19:53 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/07 19:23:10 by aben-nei         ###   ########.fr       */
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
	move_up(data);
	move_down(data);
	move_left(data);
	move_right(data);
	rotate_right(data);
	rotate_left(data);
}

int	render_frame(t_data *data)
{
	render_frame_helper(data);
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	cast_all_rays(data);
	draw_walls(data);
	// draw_map(data);
	// mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
}
