/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pistol_animation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 16:20:29 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/22 12:03:48 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	render_0to8_frames(t_data *data, int i)
{
	if (i >= 0 && i < 1)
		load_put_image(data, PISTOL_DIR, "0.xpm");
	else if (i >= 1 && i < 2)
		load_put_image(data, PISTOL_DIR, "1.xpm");
	else if (i >= 2 && i < 3)
		load_put_image(data, PISTOL_DIR, "2.xpm");
	else if (i >= 3 && i < 4)
		load_put_image(data, PISTOL_DIR, "3.xpm");
	else if (i >= 4 && i < 5)
		load_put_image(data, PISTOL_DIR, "4.xpm");
	else if (i >= 5 && i < 6)
		load_put_image(data, PISTOL_DIR, "5.xpm");
	else if (i >= 6 && i < 7)
		load_put_image(data, PISTOL_DIR, "6.xpm");
	else if (i >= 7 && i < 8)
		load_put_image(data, PISTOL_DIR, "7.xpm");
	else if (i >= 8 && i < 9)
		load_put_image(data, PISTOL_DIR, "8.xpm");
}

void	pistol_animation(t_data *data)
{
	static int	i;

	if (data->flags->pistol_shoot == false)
	{
		load_put_image(data, PISTOL_DIR, "0.xpm");
		return ;
	}
	if (i >= 9)
	{
		play_sound("sound/gunshoot.wav");
		i = 0;
		data->flags->pistol_shoot = false;
	}
	render_0to8_frames(data, i);
	i++;
}
