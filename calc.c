/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:19:12 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/13 09:19:35 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_width(char **map)
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

int	get_height(char **map)
{
	static int	height;

	if (!*map)
		return (height);
	height++;
	return (get_height(map + 1));
}

int	*get_player_xy(char **map)
{
	static int	xy[2];
	int			x;
	int			y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'N' || map[y][x] == 'S'
				|| map[y][x] == 'E' || map[y][x] == 'W')
				return (xy[0] = x, xy[1] = y, xy);
			x++;
		}
		y++;
	}
	return (xy);
}
