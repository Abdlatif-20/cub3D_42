/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:03:46 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/15 22:49:41 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb2int_converter(unsigned int *rgb)
{
	int		color;
	int		i;

	color = 0;
	i = 2;
	while (i >= 0)
	{
		ft_memset(((char *)&color) + abs(i - 2), rgb[i], sizeof(char));
		i--;
	}
	return (color);
}
