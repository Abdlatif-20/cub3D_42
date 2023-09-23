/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 09:19:12 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/23 17:02:29 by aben-nei         ###   ########.fr       */
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
int	*get_door_xy(char **map)
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
			if (map[y][x] == 'D')
				return (xy[0] = x, xy[1] = y, xy);
			x++;
		}
		y++;
	}
	return (xy);
}

void	num_of_door(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		if (ft_strchr(data->map[i], 'D'))
			data->num_door++;
		i++;
	}
}