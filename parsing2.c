/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 21:11:28 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/09 18:32:52 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "cub3d.h"

int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	check_color(char *line)
{
	char	**split;
	int		color_of_c;

	color_of_c = 0;
	split = ft_split(line + 2, ',', 0);
	if (split[0] && split[1] && split[2])
	{
		if (line[0] == 'F')
			color_of_c = create_trgb(ft_atoi(split[0]), ft_atoi(split[1]),
					ft_atoi(split[2]));
		else if (line[0] == 'C')
			color_of_c = create_trgb(ft_atoi(split[0]), ft_atoi(split[1]),
					ft_atoi(split[2]));
		if (color_of_c < 0 || color_of_c > 16777215)
			return (printf("Error\nWrong color\n"), exit(1));
	}
	else
		return (printf("Error\nWrong color1\n"), exit(1));
}

void	check_texture(char *av)
{
	int		fd;
	int		fd_texture;
	char	*line;

	fd = open(av, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if ((line[0] == 'N' && line[1] != 'O')
			|| (line[0] == 'S' && line[1] != 'O')
			|| (line[0] == 'W' && line[1] != 'E')
			|| (line[0] == 'E' && line[1] != 'A')
			|| (line[0] == 'F' && line[1] != ' ')
			|| (line[0] == 'C' && line[1] != ' '))
			return (printf("Error\nWrong texture\n"), exit(1));
		else if (line[0] == 'N' || line[0] == 'S' || line[0] == 'W'
			|| line[0] == 'E')
		{
			fd_texture = open(line + 2, O_RDONLY);
			if (fd_texture < 0)
				return (ft_putstr_fd("no such file: ", 2),
					ft_putstr_fd(line + 2, 2), exit(1));
		}
		else if (line[0] == 'F' || line[0] == 'C')
			check_color(line);
		line = get_next_line(fd);
	}
	close(fd);
	close(fd_texture);
}

bool	check_map(char map)
{
	if (map == '1' || map == '0'
		|| map == 'N' || map == 'S'
		|| map == 'E' || map == 'W'
		|| map == ' ' || map == '\n')
		return (true);
	return (false);
}

bool	check_map_is_closed(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] != '1' && map[i] != ' ' && map[i] != '\n')
			return (true);
		i++;
	}
	return (false);
}
