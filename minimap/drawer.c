/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:17:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/09 19:18:31 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_square(t_data *data, int x, int y, int color, int square_size)
{
	int	i;
	int	j;

	i = 0;
	while (i < square_size)
	{
		j = 0;
		while (j < square_size)
		{
			my_mlx_pixel_put(data, x + j, y + i, color);
			j++;
		}
		i++;
	}
}

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

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int px;
	int py;
	
	i = 0;
	py = (int)data->py - 100;
	while (py < (int)data->py + 100)
	{
		px = (int)data->px - 100;
		j = 0;
		while (px < data->px + 100)
		{
			if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == '1')
				my_mlx_pixel_put(data, j, i, 0x000000);
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
