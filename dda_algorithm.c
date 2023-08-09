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

void	drawing_line1(t_point *p1, t_point *p2, t_data *data)
{
	data->x = p1->x;
	data->y = p1->y;
	data->dx = p2->x - p1->x;
	data->dy = p2->y - p1->y;
	if (fabs(data->dx) > fabs(data->dy))
		data->steps = fabs(data->dx);
	else
		data->steps = fabs(data->dy);
	data->inc_x = data->dx / data->steps;
	data->inc_y = data->dy / data->steps;
}

void	drawing_line(t_point *p1, t_point *p2, t_data *data)
{
	int	i;

	p2->x = p1->x + (cos(data->player.rotation_angle) * 50);
	p2->y = p1->y + (sin(data->player.rotation_angle) * 50);
	drawing_line1(p1, p2, data);
	i = 0;
	while (i < data->steps)
	{
		my_mlx_pixel_put(data, data->x, data->y, 0x0000FF00);
		data->x += data->inc_x;
		data->y += data->inc_y;
		i++;
	}
}

//void	ft_draw_map(char **map, t_data *data)
//{
//	int		i;
//	int		j;
//	t_point	p1;
//	t_point	p2;
//
//	(void)map;
//	i = -1;
//	while ()
//}
// colors
// 0x00FF0000 red
// 0x0000FF00 green