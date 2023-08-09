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
	static int	state[4] = {0, 0, 0, 0};
	int			fd;

	while (textures)
	{
		fd = open(textures->value, O_RDONLY);
		if (fd == -1)
			throw_error(MAP_ERROR, heap);
		if (!ft_strcmp(textures->key, "NO"))
			state[0] = 1;
		else if (!ft_strcmp(textures->key, "SO"))
			state[1] = 1;
		else if (!ft_strcmp(textures->key, "WE"))
			state[2] = 1;
		else if (!ft_strcmp(textures->key, "EA"))
			state[3] = 1;
		else
			throw_error(MAP_ERROR, heap);
		close(fd);
		textures = textures->next;
	}
	if (state[0] && state[1] && state[2] && state[3])
		return ;
	else
		throw_error(MAP_ERROR, heap);
}

void	check_rgb_code(int *rgb, t_garbage **heap)
{
	if (rgb[0] < 0 || rgb[0] > 255 || rgb[1] < 0 || rgb[1] > 255
		|| rgb[2] < 0 || rgb[2] > 255)
		throw_error(MAP_ERROR, heap);
}
