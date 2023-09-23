/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:17:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/23 16:44:47 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static void	draw_square(t_data *data, int x, int y, int color, int square_size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < square_size)
// 	{
// 		j = 0;
// 		while (j < square_size)
// 		{
// 			my_mlx_pixel_put(data, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

static void	draw_player(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			my_mlx_pixel_put(data, j + 100, i + 100, color);
			j++;
		}
		i++;
	}
	
}

void draw_map(t_data *data)
{
	int i;
	int j;
	int px;
	int py;
	int radius = 100; // Radius of the circle
	int border_width = 3; // Width of the border

	i = 0;
	py = (int)data->py - radius - border_width;
	while (py < (int)data->py + radius + border_width)
	{
		px = (int)data->px - radius - border_width;
		j = 0;
		while (px < data->px + radius + border_width)
		{
			// Calculate the distance from the current pixel to the center of the circle
			int distance = (px - (int)data->px) * (px - (int)data->px) + (py - (int)data->py) * (py - (int)data->py);

			if (distance <= (radius + border_width) * (radius + border_width))
			{
				if (distance <= radius * radius)
				{
					if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE]
					&& data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == '1')
						my_mlx_pixel_put(data, j, i, 0x40513B);
				else if (data->door[data->index_door].open_door && (int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE]
					&& data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == 'D')
						my_mlx_pixel_put(data, j, i, 0xE5D283);
				else if (!data->door[data->index_door].open_door && (int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map)
					&& data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == 'D')
						my_mlx_pixel_put(data, j, i, 0xffffff);
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