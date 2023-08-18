/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 07:32:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/16 10:27:45 by mel-yous         ###   ########.fr       */
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
