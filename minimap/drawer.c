/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:17:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/11 15:17:21 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_square(t_data *data, int i, int j, int color)
{
	int	x;
	int	y;
	int	scale_x;
	int	scale_y;

	y = 0;
	scale_y = i * SZ;
	scale_x = j * SZ;
	while (y < SZ)
	{
		x = 0;
		while (x < SZ)
		{
			mlx_pixel_put(data->mlx->mlx, data->mlx->win,
				scale_x + x, scale_y + y, color);
			x++;
		}
		y++;
	}
}

static void	draw_player(t_data *data, int i, int j)
{
	int	x;
	int	y;
	int	scale_y;
	int	scale_x;

	y = 0;
	scale_y = i * SZ;
	scale_x = j * SZ;
	while (y < 8)
	{
		x = 0;
		while (x < 8)
		{
			mlx_pixel_put(data->mlx->mlx, data->mlx->win,
				scale_x + 12 + x, scale_y + 12 + y, 0x2ed573);
			x++;
		}
		y++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '1')
				draw_square(data, i, j, 0x8e44ad);
			if (data->map[i][j] == '0')
				draw_square(data, i, j, 0xffffff);
			else if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W')
			{
				draw_square(data, i, j, 0xffffff);
				draw_player(data, i, j);
			}
			j++;
		}
		i++;
	}
}
