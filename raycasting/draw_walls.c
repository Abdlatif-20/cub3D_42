/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 10:26:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/31 19:07:42 by aben-nei         ###   ########.fr       */
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
    int color;

    y = (SCREEN_HEIGHT / 2) - (height / 2);
    // if (data->rays[x].flag_color == 0)
    // {
    //     if (data->rays[x].ray_angle > M_PI)
    //         color = 0x825e5c;
    //     else
    //         color = 0xcd84f1;
    // }
    // else
    // {
    //     if (data->rays[x].ray_angle < 0.5 * M_PI || data->rays[x].ray_angle > 1.5 * M_PI)
    //         color = 0x7efff5;
    //     else
    //         color =0xeccc68;
    // }
    while (y < ((SCREEN_HEIGHT / 2) - (height / 2)) + height && y < SCREEN_HEIGHT)
    {
        // texture y
        // texture x
        // function to get color from texture
        //fun(x, y, data)
        // printf("color: %d\n", my_pixel_put(data, x, y));
        get_texture(data, x, y, height);
        // my_pixel_put(data,data->texture->x_texture, data->texture->y_texture, &color);
        // my_mlx_pixel_put(data, x, y, my_pixel_put(data,data->texture->x_texture, data->texture->y_texture, &color));
        my_mlx_pixel_put(data, x, y, my_pixel_put(data,data->texture->x_texture, data->texture->y_texture, &color));
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