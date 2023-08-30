/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:32:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/29 20:59:02 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	int				pos;
	unsigned char	*p;
	int				i;
	int				byte_per_pixel;

	i = 0;
	p = (unsigned char *)&color;
	byte_per_pixel = data->bpp / 8;
	pos = x * byte_per_pixel + y * data->line_length;
	while (i < byte_per_pixel)
	{
		data->img_data[pos + i] = p[i];
		i++;
	}
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img_data + (y * data->line_length + x
			* (data->bpp / 8));
	*(unsigned int *)dst = color;
}
