/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:47:45 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/24 15:57:24 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rgb(char *str, unsigned int *rgb_arr, t_garbage **heap)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rgb = ft_split(str, ',', &j);
	if (!rgb || tab_size(rgb) != 3)
		throw_error(MAP_ERROR, heap);
	while (rgb[i])
		add_to_garbage(heap, rgb[i++]);
	add_to_garbage(heap, rgb);
	if (j != 2)
		throw_error(MAP_ERROR, heap);
	i = 0;
	while (rgb[i])
	{
		if (!is_number(rgb[i]))
			throw_error(MAP_ERROR, heap);
		rgb_arr[i] = ft_atoi(rgb[i]);
		if (rgb_arr[i] < 0 || rgb_arr[i] > 255)
			throw_error(MAP_ERROR, heap);
		i++;
	}
}

static void	init_data_helper(t_data *data, int *state,
						char **full_map, t_garbage **heap)
{
	int			*player_xy;
	t_texture	*textures;

	if (state[0] && state[1] && state[2] && state[3] && state[4] && state[5])
	{
		check_textures(data->textures, heap);
		if (!full_map[6])
			throw_error(MAP_ERROR, heap);
		data->map = full_map + 6;
		space_checker(data->map, heap);
		check_map_components(data->map, heap);
		map_is_closed(data->map, heap);
	}
	else
		throw_error(MAP_ERROR, heap);
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT, "cub3D");
	data->width = get_width(data->map);
	data->height = get_height(data->map);
	data->img_ptr = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_length, &data->endian);
	textures = data->textures;
	while (data->textures)
	{
		data->textures->texture_ptr = mlx_xpm_file_to_image(data->mlx_ptr, data->textures->value,
					&data->textures->texture_width, &data->textures->texture_height);
		if (!data->textures->texture_ptr)
			return (throw_error(TEXTURE_ERROR, heap), exit(0));
		data->textures->img_addr = mlx_get_data_addr(data->textures->texture_ptr, &data->textures->bpp,
					&data->textures->line_length, &data->textures->endian);
		data->textures = data->textures->next;
	}
		data->doors.texture_ptr = mlx_xpm_file_to_image(data->mlx_ptr, "texture_files/door_frames/door2.xpm",
					&data->doors.texture_width, &data->doors.texture_height);
		if (!data->doors.texture_ptr)
			return (throw_error(TEXTURE_ERROR, heap), exit(0));
		data->doors.img_addr = mlx_get_data_addr(data->doors.texture_ptr, &data->doors.bpp,
					&data->doors.line_length, &data->doors.endian);
	data->halfscreen = SCREEN_HEIGHT / 2;
	data->textures = textures;
	player_xy = get_player_xy(data->map);
	data->keycode = -1;
	if (data->map[player_xy[1]][player_xy[0]] == 'E')
		data->angle = 2 * M_PI;
	else if (data->map[player_xy[1]][player_xy[0]] == 'S')
		data->angle = M_PI / 2;
	else if (data->map[player_xy[1]][player_xy[0]] == 'W')
		data->angle = M_PI;
	else
		data->angle = (3 * M_PI) / 2;
	/*Initialize move & rotation flags with zero value*/
	data->flag_down = 0;
	data->flag_left = 0;
	data->flag_right = 0;
	data->flag_up = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->rotate_top = 0;
	data->rotate_bottom = 0;
	data->flag_speed = 1;
	data->open_door = 0;
	data->doors.open_door = 1;
	data->flag_open = 0;
	data->index_door = 0;
	data->num_door = 0;
	data->px = WALL_SIZE * player_xy[0] + WALL_SIZE / 2;
	data->py =  WALL_SIZE * player_xy[1] + WALL_SIZE / 2;
	mlx_mouse_move(data->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
	data->mouse_x = SCREEN_WIDTH / 2;
	data->mouse_y = SCREEN_HEIGHT / 2;
	data->hide_mouse = 1;
	mlx_mouse_hide();
}

static void	fill_state_tbl(char *key, int *state, t_garbage **heap)
{
	if (!ft_strcmp(key, "NO"))
		state[0] = 1;
	else if (!ft_strcmp(key, "SO"))
		state[1] = 1;
	else if (!ft_strcmp(key, "WE"))
		state[2] = 1;
	else if (!ft_strcmp(key, "EA"))
		state[3] = 1;
	else if (!ft_strcmp(key, "C"))
		state[4] = 1;
	else if (!ft_strcmp(key, "F"))
		state[5] = 1;
	else
		throw_error(MAP_ERROR, heap);
}

void	init_data(t_data *data, char **full_map, t_garbage **heap)
{
	int			i;
	char		*key;
	char		*value;
	static int	state[6] = {0, 0, 0, 0, 0, 0};
	t_anim		*knife;

	i = 0;
	data->textures = NULL;
	while (full_map && full_map[i] && i < 6)
	{
		key = get_key_value(full_map[i], 0, heap);
		value = get_key_value(full_map[i], 1, heap);
		fill_state_tbl(key, state, heap);
		if (!ft_strcmp(key, "NO") || !ft_strcmp(key, "SO")
			|| !ft_strcmp(key, "WE") || !ft_strcmp(key, "EA"))
			add_to_texture(&data->textures, key, value, heap);
		else if (!ft_strcmp(key, "C"))
			init_rgb(value, data->ceiling, heap);
		else if (!ft_strcmp(key, "F"))
			init_rgb(value, data->floor, heap);
		i++;
	}
	init_data_helper(data, state, full_map, heap);
	knife = malloc(16 * sizeof(t_anim));
	if (!knife)
		throw_error("Error: malloc failed", heap);
	knife[0].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/0.xpm", &knife[0].width, &knife[0].height);
	knife[1].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/1.xpm", &knife[1].width, &knife[1].height);
	knife[2].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/2.xpm", &knife[2].width, &knife[2].height);
	knife[3].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/3.xpm", &knife[3].width, &knife[3].height);
	knife[4].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/4.xpm", &knife[4].width, &knife[4].height);
	knife[5].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/5.xpm", &knife[5].width, &knife[5].height);
	knife[6].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/6.xpm", &knife[6].width, &knife[6].height);
	knife[7].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/7.xpm", &knife[7].width, &knife[7].height);
	knife[8].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/8.xpm", &knife[8].width, &knife[8].height);
	knife[9].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/9.xpm", &knife[9].width, &knife[9].height);
	knife[10].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/10.xpm", &knife[10].width, &knife[10].height);
	knife[11].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/11.xpm", &knife[11].width, &knife[11].height);
	knife[12].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/12.xpm", &knife[12].width, &knife[12].height);
	knife[13].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/13.xpm", &knife[13].width, &knife[13].height);
	knife[14].img = mlx_xpm_file_to_image(data->mlx_ptr, "./texture_files/hand/14.xpm", &knife[14].width, &knife[14].height);

	knife[15].img = NULL;
	data->knife = knife;
	data->lmouse_pressed = false;
}
