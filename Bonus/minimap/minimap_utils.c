/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:57:31 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/26 20:10:10 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	dda(t_data *data, t_vars vars, unsigned int color)
{
	t_vars	var;

	var.dx = vars.x1 - vars.x;
	var.dy = vars.y1 - vars.y;
	if (abs(var.dx) > abs(var.dy))
		var.steps = abs(var.dx);
	else
		var.steps = abs(var.dy);
	var.xinc = var.dx / (float)var.steps;
	var.yinc = var.dy / (float)var.steps;
	var.cur_x = vars.x;
	var.cur_y = vars.y;
	var.i = 0;
	while (var.i <= var.steps)
	{
		my_mlx_pixel_put(data, round(var.cur_x), round(var.cur_y), color);
		var.cur_x += var.xinc;
		var.cur_y += var.yinc;
		var.i++;
	}
}
