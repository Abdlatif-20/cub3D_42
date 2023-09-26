/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:49:49 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/25 12:40:57 by mel-yous         ###   ########.fr       */
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
			my_mlx_pixel_put(data, j + 100, i + (SCREEN_HEIGHT - 210) + 100, color);
			j++;
		}
		i++;
	}
}

void draw_minimap(t_data *data)
{
	int i;
	int j;
	int px;
	int py;
	int radius = 100;
	int border_width = 2;

	i = SCREEN_HEIGHT - 210;
	py = (int)data->player->y - radius - border_width;
	while (py < (int)data->player->y + radius + border_width)
	{
		px = (int)data->player->x - radius - border_width;
		j = 0;
		while (px < data->player->x + radius + border_width)
		{
			int distance = (px - (int)data->player->x) * (px - (int)data->player->x) + (py - (int)data->player->y) * (py - (int)data->player->y);

			if (distance <= (radius + border_width) * (radius + border_width))
			{
				if (distance <= radius * radius)
				{
					if ((int)py / SCALE_SIZE >= 0 && (int)py / SCALE_SIZE < tab_size(data->map) && data->map[(int)py / SCALE_SIZE]
					&& data->map[(int)py / SCALE_SIZE][(int)px / SCALE_SIZE] == '1')
						my_mlx_pixel_put(data, j, i, 0x40513B);
				else if ((int)py / SCALE_SIZE >= 0 && (int)py / SCALE_SIZE < tab_size(data->map) && data->map[(int)py / SCALE_SIZE]
					&& data->map[(int)py / SCALE_SIZE][(int)px / SCALE_SIZE] == 'D')
						my_mlx_pixel_put(data, j, i, 0xE5D283);
				else
					my_mlx_pixel_put(data, j, i, 0xB99B6B);
				}
				else
				{
					// Draw the border color
					my_mlx_pixel_put(data, j, i, 0xffffff); // Set to your desired border color
				}
			}
			px++;
			j++;
		}
		py++;
		i++;
	}
	draw_player(data, 0xAA5656);
}
