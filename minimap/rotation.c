/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:54:10 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/16 13:54:11 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_data *data, double rotation_speed)
{
	data->angle -= rotation_speed;
	if (data->angle < 0)
		data->angle = data->angle + (2 * M_PI) * SPEED;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	cast_all_rays(data);
	draw_walls(data);
	// draw_map(data);
}

void	rotate_right(t_data *data, double rotation_speed)
{
	data->angle += rotation_speed;
	if (data->angle > 2 * M_PI)
		data->angle = 0;
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	cast_all_rays(data);
	draw_walls(data);
	// draw_map(data);
}
