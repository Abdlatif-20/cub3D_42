/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:01:43 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/31 21:02:23 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../cub3d.h"

void    get_texture_offset(t_data *data, double x, double y, double height)
{
    double  start_y;
    
    start_y = ((height / 2) - (SCREEN_HEIGHT / 2));
    if (data->rays[(int)x].flag_color == 0)
        data->textures->x_texture = fmod(data->rays[(int)x].wall_hit_x
            * data->textures->texture_width / WALL_SIZE, data->textures->texture_width);
    else
        data->textures->x_texture = fmod(data->rays[(int)x].wall_hit_y
            * data->textures->texture_width / WALL_SIZE, data->textures->texture_width);
    data->textures->y_texture = (y + start_y) * (data->textures->texture_height / height);
}

void	my_pixel_put(t_texture *data, int x, int y, int *color)
{
	char	*dst;

	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
		return ;
	dst = data->img_addr + (y * data->line_length + x
			* (data->bpp / 8));
	*color = *(unsigned int *)dst;
}