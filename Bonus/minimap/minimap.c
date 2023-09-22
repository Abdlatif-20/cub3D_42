/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:49:49 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/21 16:57:03 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_player(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			my_mlx_pixel_put(data, j + 100, i + 100, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;
	int px;
	int py;

	i = 0;
	py = (int)data->player->y - 100;
	while (py < (int)data->player->y + 100)
	{
		px = (int)data->player->x - 100;
		j = 0;
		while (px < data->player->x + 100)
		{
			if ((int)py / SCALE_SIZE >= 0 && (int)py / SCALE_SIZE < tab_size(data->map) && data->map[(int)py / SCALE_SIZE] && data->map[(int)py / SCALE_SIZE][(int)px / SCALE_SIZE] == '1')
				my_mlx_pixel_put(data, j, i, 0x000000);
			else if ((int)py / SCALE_SIZE >= 0 && (int)py / SCALE_SIZE < tab_size(data->map) && data->map[(int)py / SCALE_SIZE] && data->map[(int)py / SCALE_SIZE][(int)px / SCALE_SIZE] == 'D')
				my_mlx_pixel_put(data, j, i, 0x808080);
			else
				my_mlx_pixel_put(data, j, i, 0xffffff);
			px++;
			j++;
		}
		py++;
		i++;
	}
	draw_player(data, 0xff3f34);
}