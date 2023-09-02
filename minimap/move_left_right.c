/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 21:47:50 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/01 21:57:03 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_left(t_data *data)
{
	double	x;
	double	y;

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
}

void	move_right(t_data *data)
{
	double	x;
	double	y;

	if (data->flag_right)
	{
		x = data->px + (cos(data->angle + (M_PI / 2)) * SPEED);
		y = data->py + sin(data->angle 	+ (M_PI / 2)) * SPEED;
		if (check_wall(data, x, y))
		{
			data->py = y;
			data->px = x;
		}
	}
}