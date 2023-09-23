/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 17:20:04 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/23 19:20:02 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

bool	check_wall(t_data *data, double x, double y)
{
	if (data->map[(int)(y) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y) / WALL_SIZE][(int)(x - 2) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y - 2) / WALL_SIZE][(int)(x) / WALL_SIZE] != '1' &&
		data->map[(int)(y + 2) / WALL_SIZE][(int)(x + 2) / WALL_SIZE] != '1')
			return (true);
	return (false);
}
