/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:01:28 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/08 17:26:28 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	colors(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = y;
	while (i < y + 32)
	{
		j = x;
		while (j < x + 32)
		{
			my_mlx_pixel_put(data, j, i, color);
			j++;
		}
		i++;
	}
}

void	mini_map(t_data *data, char **map)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		y = i * 32;
		while (map[i][j])
		{
			x = j * 32;
			if (map[i][j] == '1')
				colors(data, x, y, 0x00800080);
			else if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				colors(data, x, y, 0x00FFFFFF);
			j++;
		}
		i++;
	}
}

void	color_player(t_data *data)
{
	int	x;
	int	y;

	y = data->player.y - 5;
	while (y < data->player.y + 5)
	{
		x = data->player.x - 5;
		while (x < data->player.x + 5)
		{
			my_mlx_pixel_put(data, x, y, 0x000000FF);
			x++;
		}
		y++;
	}
}

void	get_position_of_player(char **map, t_data *data)
{
	int	x;
	int	y;
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		y = i * 32;
		while (map[i][j])
		{
			x = j * 32;
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				data->player.x = x + (32 / 2);
				data->player.y = y + (32 / 2);
			}
			j++;
		}
		i++;
	}
}
