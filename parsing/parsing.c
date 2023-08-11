/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 09:10:57 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/06 16:47:24 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_textures(t_dict *textures, t_garbage **heap)
{
	int			fd;

	while (textures)
	{
		fd = open(textures->value, O_RDONLY);
		if (fd == -1)
			throw_error(MAP_ERROR, heap);
		close(fd);
		textures = textures->next;
	}
}

void	check_map_components(char **map, t_garbage **heap)
{
	char		*line;
	int			i;
	static int	p;

	line = *map;
	if (!line)
	{
		if (p == 0)
			throw_error(MAP_ERROR, heap);
		return ;
	}
	i = 0;
	while (line[i])
	{
		if (!is_valid_component(line[i]))
			throw_error(MAP_ERROR, heap);
		if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W'
			|| line[i] == 'E')
			p++;
		i++;
	}
	if (p > 1)
		throw_error(MAP_ERROR, heap);
	check_map_components(map + 1, heap);
}

void	map_is_closed(char **map, t_garbage **heap)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		skip_spaces(map[i], &j);
		if (i == 0 || i == tab_size(map) - 1)
		{
			while (map[i][j] && map[i][j] == '1')
				j++;
			if (map[i][j] != '\0')
				throw_error(MAP_ERROR, heap);
		}
		else
			if (map[i][j] != '1' || map[i][ft_strlen(map[i]) - 1] != '1')
				throw_error(MAP_ERROR, heap);
		i++;
	}
}

void	space_checker(char **map, t_garbage **heap)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0')
			{
				if (((map[i][j - 1] && map[i][j - 1] == ' ')
					|| (map[i][j + 1] && map[i][j + 1] == ' ')))
					throw_error(MAP_ERROR, heap);
				if ((map[i - 1][j] && map[i - 1][j] == ' ')
					|| (map[i + 1][j] && map[i + 1][j] == ' '))
					throw_error(MAP_ERROR, heap);
			}
			j++;
		}
		i++;
	}
}
