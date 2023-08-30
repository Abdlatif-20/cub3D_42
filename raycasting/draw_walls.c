/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:26:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/30 13:06:28 by aben-nei         ###   ########.fr       */
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

void    wall_drawing(int x, double height, t_data *data)
{
    double y;

    data->colors[0] = 244;
    data->colors[1] = 237;
    data->colors[2] = 228;
    y = (SCREEN_HEIGHT / 2) - (height / 2);
    while (y < ((SCREEN_HEIGHT / 2) - (height / 2)) + height && y < SCREEN_HEIGHT)
    {
        my_mlx_pixel_put(data, x, y, 0xeccc68);
        y++;
    }
}

void    draw_walls(t_data *data)
{
	t_ray	*rays;
	int	       i;
	double	proj_slice_height;
	double	height_of_wall;
    double  distance_player_proj;
	
	rays = data->rays;
	i = 0;
	proj_slice_height = 0;
	// proj_center = SCREEN_HEIGHT / 2;
    distance_player_proj = (SCREEN_WIDTH / 2) / tan(FOV / 2);
	colorize_window(data);
    while (i < SCREEN_WIDTH)
    {
        height_of_wall = (WALL_SIZE * distance_player_proj) / (rays[i].distance * cos(rays[i].ray_angle - data->angle));
        wall_drawing(i, height_of_wall, data);
        i++;
    }
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
}
// color grey 0x808080