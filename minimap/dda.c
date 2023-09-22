/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 15:11:06 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/21 11:45:21 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fill_dda_vars(t_data *data, double x1, double y1, double x2, double y2)
{
	// data->dda_vars->x1 = data->px;
	// data->dda_vars->y1 = data->py;
	data->dda_vars->dx = x2 - x1;
	data->dda_vars->dy = y2 - y1;
	if (fabs(data->dda_vars->dx) > fabs(data->dda_vars->dy))
		data->dda_vars->steps = fabs(data->dda_vars->dx);
	else
		data->dda_vars->steps = fabs(data->dda_vars->dy);
	data->dda_vars->x_inc = data->dda_vars->dx / data->dda_vars->steps;
	data->dda_vars->y_inc = data->dda_vars->dy / data->dda_vars->steps;
}

void	dda(t_data *data, double x1, double y1, double x2, double y2)
{
	int		i;
	double	x;
	double	y;

	if (x2 < 0 || x2 > SCREEN_WIDTH || y2 < 0 || y2 > SCREEN_HEIGHT
		|| x1 < 0 || x1 > SCREEN_WIDTH || y1 < 0 || y1 > SCREEN_HEIGHT)
		return ;
	i = 0;
	fill_dda_vars(data, x1, y1, x2, y2);
	x = x1;
	y = y1;
	while (i < (int)floor(data->dda_vars->steps))
	{
		my_mlx_pixel_put(data, (int)round(x), (int)round(y), 0x00FF00);
		x += data->dda_vars->x_inc;
		y += data->dda_vars->y_inc;
		i++;
	}
}
// green color = 0x00FF00