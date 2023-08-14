/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 17:23:23 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/13 17:23:27 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

static void	drawing(t_point *p1, t_point *p2, t_data *data)
{
	data->draw.x = p1->x;
	data->draw.y = p1->y;
	data->draw.dx = p2->x - p1->x;
	data->draw.dy = p2->y - p1->y;
	if (fabs(data->draw.dx) > fabs(data->draw.dy))
		data->draw.steps = fabs(data->draw.dx);
	else
		data->draw.steps = fabs(data->draw.dy);
	data->draw.inc_x = data->draw.dx / data->draw.steps;
	data->draw.inc_y = data->draw.dy / data->draw.steps;
}

void	drawing_rays(t_point *p1, t_point *p2, t_data *data)
{
	int	i;

	p2->x = p1->x + (cos(data->angle_vue) * 50);
	p2->y = p1->y + (sin(data->angle_vue) * 50);
	drawing(p1, p2, data);
	i = 0;
	while (i < data->draw.steps)
	{
		if (data->draw.x > 0 && data->draw.x < 1200
			&& data->draw.y > 0 && data->draw.y < 1200)
			my_mlx_pixel_put(data, data->draw.x, data->draw.y, 0x0000FF00);
		data->draw.x += data->draw.inc_x;
		data->draw.y += data->draw.inc_y;
		i++;
	}
}
