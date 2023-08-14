/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:06:14 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/10 16:06:19 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_horizontal(t_data *data)
{
	double x, y;

	y = floor(data->player.y / SCALE) * SCALE;
	if (data->player.rotation_angle > M_PI)
		y += SCALE;
	x = (data->player.y - y / tan(data->player.rotation_angle)) + data->player.x;
}

void casting_rays(t_data *data)
{
	int i;
	t_point p2;

	i = 0;
	data->angle_vue = data->player.rotation_angle - FOV / 2;
	while (i < NUM_RAYS)
	{
		drawing_rays(&data->player, &p2, data);
		data->angle_vue += FOV / NUM_RAYS;
		i++;
	}
}
