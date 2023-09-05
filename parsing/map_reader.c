/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 14:53:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/05 21:44:12 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static bool	is_empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '\0' && line[i] != ' ' && line[i] != '\n')
			return (false);
		i++;
	}
	return (true);
}

/* This function responsible for reading the entire map file */
char	**get_full_map(char *path, t_garbage **heap)
{
	int		fd;
	char	*line;
	char	**tab;
	char	*joined;
	int		i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	i = 0;
	joined = NULL;
	line = get_next_line(fd);
	while (line)
	{
		add_to_garbage(heap, line);
		if (is_empty_line(line) && i < 7)
		{
			line = get_next_line(fd);
			continue ;
		}
		else if (is_empty_line(line) && i > 7)
			throw_error(MAP_ERROR, heap);
		joined = free_s1_join(joined, line);
		line = get_next_line(fd);
		i++;
	}
	i = 0;
	tab = ft_split(joined, '\n', NULL);
	if (!tab)
		return (throw_error(MAP_ERROR, heap), NULL);
	while (tab[i])
		add_to_garbage(heap, tab[i++]);
	return (close(fd), add_to_garbage(heap, tab), free(joined), tab);
}
