/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:03:46 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/30 12:54:04 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	rgb2int_converter(int *rgb)
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
