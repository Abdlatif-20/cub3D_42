/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:01:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/31 18:34:44 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void    get_texture(t_data *data, double x, double y, double height)
{
    double  start_y;
    
    start_y = ((height / 2) - (SCREEN_HEIGHT / 2));
    // data->texture->x_texture = (int)data->rays[(int)x].wall_hit_x % WALL_SIZE;
    data->texture->x_texture = fmod(data->rays[(int)x].wall_hit_x * (data->texture->texture_width / WALL_SIZE), (double)(data->texture->texture_width));
    // printf("data->texture->texture_height = %d\n", data->texture->texture_height);
    data->texture->y_texture = (y + start_y) * (data->texture->texture_height / height);
    // printf("x = %f\n", data->texture->x_texture);
    // printf("texture height = %d\n", data->texture->texture_height);
}

int    my_pixel_put(t_data *data, int x, int y, int *color)
{
	char	*dst;
    (void)color;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return 0;
	dst = data->texture->img_addr + (y * data->texture->line_length + x
			* (data->texture->bpp / 8));
    //  *color = *(unsigned int *)dst;
    return (*(unsigned int *)dst);
}