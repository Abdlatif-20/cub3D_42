/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 19:37:12 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/26 22:34:39 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_wall(t_data *data, float x, float y, int flag)
{
	if (data->map[(int)(y) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != '1' &&
		data->map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] != '1' &&
		data->map[(int)(y + 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		data->map[(int)(y - 2) / SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' &&
		data->map[(int)(y + 2) / SCALE_SIZE]
		[(int)(x + 2) / SCALE_SIZE] != '1' && data->map[(int)(y)
		/ SCALE_SIZE][(int)(x) / SCALE_SIZE] != '1' && data->map[(int)(y - 2)
		/ SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] != 'D' &&
		data->map[(int)(y + 2) / SCALE_SIZE][(int)(x + 2) / SCALE_SIZE] != 'D')
		return (data->player->hit_wall = false, 
			data->player->already_hit = false, true);
	if (data->door->door_distance > 40 && (data->map[(int)(y) / SCALE_SIZE]
		[(int)(x) / SCALE_SIZE] == 'D' ||
		data->map[(int)(y) / SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] == 'D'))
		flag = 0;
	if (!flag)
	{
		if (data->map[(int)(y) / SCALE_SIZE][(int)(x) / SCALE_SIZE] == 'D' ||
			data->map[(int)(y - 2) / SCALE_SIZE][(int)(x - 2)
			/ SCALE_SIZE] == 'D' || data->map[(int)(y + 2) / SCALE_SIZE]
			[(int)(x + 2) / SCALE_SIZE] == 'D' || data->map[(int)(y - 2)
			/ SCALE_SIZE][(int)(x - 2) / SCALE_SIZE] == '0')
			return (true);
	}
	return (data->player->hit_wall = true, false);
}
