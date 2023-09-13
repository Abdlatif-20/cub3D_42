/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:20:04 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/12 13:00:33 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_wall(t_data *data, double x, double y)
{
	if (data->map[(int)(y) / WALL_SIZE][(int)(x + 5) / WALL_SIZE] != '1' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x - 5) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 5) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y - 5) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 5) / WALL_SIZE][(int)(x + 5) / WALL_SIZE] != '1' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1')
		return (true);
	return (false);
}

bool	check_door(t_data *data, double x, double y)
{
	if ((data->map[(int)(y) / WALL_SIZE][(int)(x + 25) / WALL_SIZE] != 'D' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x - 25) / WALL_SIZE] != 'D' &&
		data->map[(int)(y + 25) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D' &&
		data->map[(int)(y - 25) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D' &&
		data->map[(int)(y + 25) / WALL_SIZE][(int)(x + 25) / WALL_SIZE] != 'D' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D') || data->open_door)
		return (true);
	return (false);
}
