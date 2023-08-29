/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:47:45 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/26 13:25:39 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_rgb(char *str, int *rgb_arr, t_garbage **heap)
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
	int	*player_xy;

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
	if (data->width * WALL_SIZE > SCREEN_WIDTH
		|| data->height * WALL_SIZE > SCREEN_HEIGHT)
		throw_error(MAP_ERROR, heap);
	data->img_ptr = mlx_new_image(data->mlx_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
	data->img_data = mlx_get_data_addr(data->img_ptr, &data->bpp,
			&data->line_length, &data->endian);
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
	data->px = WALL_SIZE * player_xy[0];
	data->py =  WALL_SIZE * player_xy[1];
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

	i = 0;
	data->textures = NULL;
	while (full_map[i] && i < 6)
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
}
