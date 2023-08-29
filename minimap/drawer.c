/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:17:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/29 13:04:13 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_square(t_data *data, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WALL_SIZE)
	{
		j = 0;
		while (j < WALL_SIZE)
		{
			pixel_put(data, x + j, y + i, color);
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
			pixel_put(data, data->px + j, data->py + i, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->img_ptr = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_length, &data->endian);
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == '0'
				|| data->map[i][j] == 'N' || data->map[i][j] == 'E'
				|| data->map[i][j] == 'W' || data->map[i][j] == 'S')
				draw_square(data, j * WALL_SIZE, i * WALL_SIZE, 0x3c6382);
			else if (data->map[i][j] == '1')
				draw_square(data, j * WALL_SIZE, i * WALL_SIZE, 0xa6915c);
			j++;
		}
		i++;
	}
	cast_all_rays(data);
	mlx_put_image_to_window (data->mlx_ptr,
		data->win_ptr, data->img_ptr, 0, 0);
}
