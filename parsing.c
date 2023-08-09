/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:38:57 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/09 18:44:48 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void	check_name_of_map(char *str, char *find)
{
	int	i;
	int	j;

	i = (int)ft_strlen(str) - 1;
	j = 0;
	while (str[i] || find[j])
	{
		while (str[i] && str[i] != '.')
			i--;
		if (i < 0)
			return (ft_putendl_fd("Wrong file extension.", 2), exit(1));
		if (str[i] && str[i] == '.')
		{
			if (str[0] == '.')
				return (ft_putendl_fd("Wrong name of file.", 2), exit(1));
			while (str[i])
			{
				if (str[i] != find[j])
					return (ft_putendl_fd("Wrong file extension.", 2), exit(1));
				i++;
				j++;
			}
		}
	}
}

void	length_of_map(char *av, t_data *data)
{
	size_t	len;
	size_t	height;
	size_t	final_len;
	char	*line;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("no such file: ", 2),
			ft_putendl_fd(av, 2), exit(1));
	line = get_next_line(fd);
	len = 0;
	final_len = ft_strlen(line);
	height = 1;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		len = ft_strlen(line);
		if (final_len < len)
			final_len = len;
		height++;
	}
	data->height = height;
	data->width = final_len;
}

void	fill_map(char *av, char **map)
{
	int		fd;
	char	*line;
	int		i;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (ft_putstr_fd("no such file: ", 2),
			ft_putendl_fd(av, 2), exit(1));
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		if (line[0] != '1' && line[0] != ' ')
			line = get_next_line(fd);
		else
		{
			map[i] = ft_strdup(line);
			i++;
			line = get_next_line(fd);
		}
	}
	map[i] = NULL;
}

void	check_map_is_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	if (check_map_is_closed(map[0]))
		return (printf("Error\nMap is not closed\n"), exit(1));
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!check_map(map[i][j]))
				return (printf("Error\n"), exit(1));
			if (map[i][j] == ' ' && (map[i][j + 1] == '0'
				|| map[i + 1][j] == '0'))
				return (printf("Error\nMap is not closed\n"), exit(1));
			j++;
		}
		i++;
	}
	if (check_map_is_closed(map[i - 1]))
		return (printf("Error\nMap is not closed\n"), exit(1));
}
