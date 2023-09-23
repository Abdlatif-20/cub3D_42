/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:47:58 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/23 21:12:56 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_data *data)
{
	double	x;
	double	y;

	if (data->flag_up)
	{
		x = data->px + cos(data->angle) * SPEED * data->flag_speed;
		y = data->py + sin(data->angle) * SPEED * data->flag_speed;
		if (check_wall(data, x, y, data->door[data->index_door].open_door))
		{
			data->py = y;
			data->px = x;
		}
	}
}

void	move_down(t_data *data)
{
	double	x;
	double	y;

	if (data->flag_down)
	{
		x = data->px - cos(data->angle) * SPEED * data->flag_speed;
		y = data->py - sin(data->angle) * SPEED * data->flag_speed;
		if (check_wall(data, x, y, data->door[data->index_door].open_door))
		{
			data->py = y;
			data->px = x;
		}
	}
}