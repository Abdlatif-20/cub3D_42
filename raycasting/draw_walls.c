/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:26:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/29 12:07:57 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    colorize_window(t_data *data)
{
    int i;
    int j;
    int half_screen;

    i = 0;
    half_screen = SCREEN_HEIGHT / 2;
    while (i < SCREEN_HEIGHT)
    {
        j = 0;
        while (j < SCREEN_WIDTH)
        {
            if (i < half_screen)
                pixel_put(data, j, i, rgb2int_converter(data->ceiling));
            else
                pixel_put(data, j, i, rgb2int_converter(data->floor));
            j++;
        }
        i++;
    }
}

void    draw_walls(t_data *data)
{
	t_ray	*rays;
	int		i;
	double	proj_slice_height;
	double	proj_center;
	
	double		m = 0;
	double		k = 0;
	
	rays = data->rays;
	i = 0;
	proj_slice_height = 0;
	proj_center = SCREEN_HEIGHT / 2;
	colorize_window(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
