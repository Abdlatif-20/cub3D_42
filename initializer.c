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

static t_dict	*init_textures(char **full_map, t_garbage **heap)
{
	int		i;
	t_dict	*new;
	t_dict	*head;

	i = 0;
	head = NULL;
	while (full_map[i] && i < 4)
	{
		new = create_node(full_map[i], heap);
		if (i == 0)
		{
			head = new;
			head->next = NULL;
			head->last = new;
		}
		else
		{
			head->last->next = new;
			head->last = new;
		}
		i++;
	}
	return (head);
}

static void	init_rgb(int *rgb, char *rgb_str, t_garbage **heap)
{
	char	**spl;
	int		j;
	char	*key;
	char	*value;

	if (!rgb_str)
		throw_error(MAP_ERROR, heap);
	j = 0;
	key = get_key_value(rgb_str, 0, heap);
	value = get_key_value(rgb_str, 1, heap);
	if (ft_strcmp(key, "C") && ft_strcmp(key, "F"))
		throw_error(MAP_ERROR, heap);
	spl = ft_split(value, ',', &j);
	if (!spl || j != 2)
		throw_error(MAP_ERROR, heap);
	j = 0;
	while (spl[j])
		add_to_garbage(heap, spl[j++]);
	add_to_garbage(heap, spl);
	if (!is_number(spl[0]) || !is_number(spl[1]) || !is_number(spl[2]))
		throw_error(MAP_ERROR, heap);
	rgb[0] = ft_atoi(spl[0]);
	rgb[1] = ft_atoi(spl[1]);
	rgb[2] = ft_atoi(spl[2]);
	check_rgb_code(rgb, heap);
}

void	init_data(t_data *data, char **full_map, t_garbage **heap)
{
	data->textures = init_textures(full_map, heap);
	check_textures(data->textures, heap);
	init_rgb(data->ceiling, full_map[4], heap);
	init_rgb(data->floor, full_map[5], heap);
}
