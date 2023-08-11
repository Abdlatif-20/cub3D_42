/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:47:45 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/08 10:47:50 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	add_to_texture(t_dict **texture, char *key,
							char *value, t_garbage **heap)
{
	t_dict	*new;

	new = malloc(sizeof(t_dict));
	if (!new)
		throw_error("Error: malloc failed", heap);
	new->key = key;
	new->value = value;
	new->next = NULL;
	new->last = NULL;
	add_to_garbage(heap, new);
	if (!*texture)
	{
		*texture = new;
		(*texture)->next = NULL;
		(*texture)->last = new;
	}
	else
	{
		(*texture)->last->next = new;
		(*texture)->last = new;
	}
}

static void	init_rgb(char *str, int *rgb_arr, t_garbage **heap)
{
	char	**rgb;
	int		i;
	int		j;

	i = 0;
	j = 0;
	rgb = ft_split(str, ',', &j);
	if (!rgb)
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

static int	get_width(char **map)
{
	static int	width;
	int			len;

	if (!*map)
		return (width);
	len = ft_strlen(*map);
	if (len > width)
		width = len;
	return (get_width(map + 1));
}

static int	get_height(char **map)
{
	static int	height;

	if (!*map)
		return (height);
	height++;
	return (get_height(map + 1));
}

static void	init_data_helper(t_data *data, int *state,
						char **full_map, t_garbage **heap)
{
	t_mlx	mlx;

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
	data->width = get_width(data->map);
	data->height = get_height(data->map);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 1280,
			720, "cub3D");
	data->mlx = &mlx;
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
