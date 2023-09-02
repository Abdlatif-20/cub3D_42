/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   angle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:54:10 by mel-yous          #+#    #+#             */
/*   Updated: 2023/08/16 13:54:11 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	rotate_left(t_data *data)
{
	if (data->rotate_left)
		data->angle -= (ROT_SPEED * (M_PI / 180));
}

void	rotate_right(t_data *data)
{
	if (data->rotate_right)
		data->angle += (ROT_SPEED * (M_PI / 180));
}
