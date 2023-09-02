/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up_down.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:47:58 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/01 22:22:16 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_up(t_data *data)
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
}

void	move_down(t_data *data)
{
	double	x;
	double	y;

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
}