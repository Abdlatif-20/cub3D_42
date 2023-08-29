/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 19:20:01 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/26 21:54:38 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	move_forward(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (data->px) + (cos(data->angle) * SPEED);
	new_y = (data->py) + (sin(data->angle) * SPEED);
	if ((data->map[(new_y - 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1')
		|| (data->map[(new_y + 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1'))
		return ;
	if (data->map[new_y / WALL_SIZE][new_x / WALL_SIZE] != '1')
	{
		data->px += (cos(data->angle) * SPEED);
		data->py += (sin(data->angle) * SPEED);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_walls(data);
	}
}

static void	move_back(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (data->px) - (cos(data->angle) * SPEED);
	new_y = (data->py) - (sin(data->angle) * SPEED);
	if ((data->map[(new_y - 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1')
		|| (data->map[(new_y + 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1'))
		return ;
	if (data->map[new_y / WALL_SIZE][new_x / WALL_SIZE] != '1')
	{
		data->px -= (cos(data->angle) * SPEED);
		data->py -= (sin(data->angle) * SPEED);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_walls(data);
	}
}

static void	move_right(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (data->px) - (cos(data->angle - (M_PI / 2)) * SPEED);
	new_y = (data->py) - (sin(data->angle - (M_PI / 2)) * SPEED);
	if ((data->map[(new_y - 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1')
		|| (data->map[(new_y + 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1'))
		return ;
	if (data->map[new_y / WALL_SIZE][new_x / WALL_SIZE] != '1')
	{
		data->px += (cos(data->angle + (M_PI / 2)) * SPEED);
		data->py += (sin(data->angle + (M_PI / 2)) * SPEED);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_walls(data);
	}
}

static void	move_left(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = (data->px) + (cos(data->angle - (M_PI / 2)) * SPEED);
	new_y = (data->py) + (sin(data->angle - (M_PI / 2)) * SPEED);
	if ((data->map[(new_y - 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1')
		|| (data->map[(new_y + 4) / WALL_SIZE][new_x / WALL_SIZE] == '1'
		&& data->map[new_y / WALL_SIZE][(new_x + 4) / WALL_SIZE] == '1'))
		return ;
	if (data->map[new_y / WALL_SIZE][new_x / WALL_SIZE] != '1')
	{
		data->px += (cos(data->angle - (M_PI / 2)) * SPEED);
		data->py += (sin(data->angle - (M_PI / 2)) * SPEED);
		mlx_clear_window(data->mlx_ptr, data->win_ptr);
		draw_walls(data);
	}
}

int	render_frame(t_data *data)
{
	if (data->keycode == -1)
		return (1);
	else if (data->keycode == KEY_A)
		move_left(data);
	else if (data->keycode == KEY_D)
		move_right(data);
	else if (data->keycode == KEY_S)
		move_back(data);
	else if (data->keycode == KEY_W)
		move_forward(data);
	else if (data->keycode == KEY_RIGHT)
		rotate_right(data);
	else if (data->keycode == KEY_LEFT)
		rotate_left(data);
	return (1);
}
