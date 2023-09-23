/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:20:04 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/23 16:43:01 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_wall(t_data *data, double x, double y)
{
	// static int	flag;
	// printf("|%c|\n", data->map[(int)(y) / WALL_SIZE][(int)(x + 2) / WALL_SIZE]);
	// printf("index_door: %d\n", data->index_door);
	// flag = data->index_door;
	// if (data->map[(int)(y - 8) / WALL_SIZE][(int)(x - 8) / WALL_SIZE] == 'D' &&
	// 	data->door[flag].open_door == 1)
	// 	return (false);
	if (data->map[(int)(y) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y - 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != 'D' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] != 'D' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D' &&
		data->map[(int)(y - 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != 'D' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x) / WALL_SIZE] != 'D')
		{puts
			return (true);
		}
		// else if (!data->door[data->index_door].open_door)
		// 	return (true);
	return (false);
}
