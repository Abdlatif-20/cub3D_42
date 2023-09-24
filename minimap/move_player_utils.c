/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:20:04 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/23 22:34:42 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_wall(t_data *data, double x, double y, int flag)
{
	if (data->map[(int)(y) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y - 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != '1'
		&& data->map[(int)(y - 2) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] != 'D' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != 'D' &&
		data->map[(int)(y - 2) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] != 'D')
			return (true);
	if (data->door_dist > 40 && (data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] == 'D' ||
		data->map[(int)(y) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] == 'D'))
		flag = 0;
	if (!flag)
	{
		if (data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] == 'D' ||
			data->map[(int)(y - 2) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] == 'D' ||
			data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] == '0')
			{
				flag = 1;
				return (true);
			}
	}
	return (false);
}
