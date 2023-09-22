/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 11:14:30 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/18 12:06:13 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	default_init(t_data *data)
{
	static t_flags	flags;

	data->textures = NULL;
	data->map = NULL;
	data->celling_color = -1;
	data->floor_color = -1;
	data->half_screen = SCREEN_HEIGHT / 2;
	flags.move_down = false;
	flags.move_up = false;
	flags.move_left = false;
	flags.move_right = false;
	flags.rotate_left = false;
	flags.rotate_right = false;
	flags.redraw_scene = false;
	data->flags = &flags;
}

static void	load_textures(t_data *data)
{
	int			i;
	t_texture	*texture_tmp;
	t_image		*new_img;

	new_img = malloc(sizeof(t_image) * 5);
	if (!new_img)
		throw_error(MALLOC_ERROR, g_heap());
	add_to_garbage(g_heap(), new_img);
	texture_tmp = data->textures;
	texture_tmp->texture_img = new_img;
	i = 0;
	while (i < 4 && texture_tmp)
	{
		new_img[i].img_ptr = my_mlx_xpm_file_to_img(data,
				texture_tmp->value, &texture_tmp->xpm_width,
				&texture_tmp->xpm_height);
		new_img[i].img_data = mlx_get_data_addr(new_img[i].img_ptr,
				&new_img[i].bpp, &new_img[i].line_length, &new_img[i].endian);
		if (!new_img[i].img_data)
			throw_error(FILE_ERROR, g_heap());
		texture_tmp->texture_img = &new_img[i];
		i++;
		texture_tmp = texture_tmp->next;
	}
}

void	init_data(t_data *data, char *path)
{
	default_init(data);
	read_map(path, data);
	textures_checker(data);
	color_checker(data);
	map_checker(data->map);
	data->mlx = init_mlx();
	data->window_img = init_win_image(data);
	data->map_width = get_map_width(data->map);
	data->map_height = get_map_height(data->map);
	data->player = init_player(data);
	data->textures->texture_img = NULL;
	load_textures(data);
}
