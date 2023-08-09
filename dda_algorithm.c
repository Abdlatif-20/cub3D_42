/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_algorithm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 15:14:05 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/07 15:14:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	drawing_line1(t_point p1, t_point p2, t_data *data)
{
	data->x = p1.x;
	data->y = p1.y;
	data->dx = p2.x - p1.x;
	data->dy = p2.y - p1.y;
	if (abs(data->dx) > abs(data->dy))
		data->steps = abs(data->dx);
	else
		data->steps = abs(data->dy);
	data->inc_x = (double)data->dx / (double)data->steps;
	data->inc_y = (double)data->dy / (double)data->steps;
}

void	drawing_line(t_point p1, t_point p2, t_data *data)
{
	int	i;

	drawing_line1(p1, p2, data);
	i = 0;
	while (i < data->steps)
	{
		if (data->x >= 0 && data->x <= 500
			&& data->y >= 0 && data->y <= 500)
			my_mlx_pixel_put(data, data->x, data->y, 0x00FF0000);
		data->x += data->inc_x;
		data->y += data->inc_y;
		i++;
	}
}

void	ft_draw_map(char **map, t_data *data)
{
	int		i;
	int		j;
	t_point	p1;
	t_point	p2;

	(void)map;
	i = -1;
	while (++i <= 40)
	{
		j = -1;
		while (++j < 13)
		{
			p1.x = i * CUB_SIZE;
			p1.y = j * CUB_SIZE;
			if (j < 13 - 1)
			{
				p2.x = i * CUB_SIZE;
				p2.y = (j + 1) * CUB_SIZE;
				drawing_line(p1, p2, data);
			}
			if (i < 40 - 1)
			{
				p2.x = (i + 1) * CUB_SIZE;
				p2.y = j * CUB_SIZE;
				drawing_line(p1, p2, data);
			}
		}
	}
}
