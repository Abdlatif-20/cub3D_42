/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 15:17:13 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/22 13:29:09 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// static void	draw_square(t_data *data, int x, int y, int color, int square_size)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < square_size)
// 	{
// 		j = 0;
// 		while (j < square_size)
// 		{
// 			my_mlx_pixel_put(data, x + j, y + i, color);
// 			j++;
// 		}
// 		i++;
// 	}
// }

static void	draw_player(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < PLAYER_SIZE)
	{
		j = 0;
		while (j < PLAYER_SIZE)
		{
			my_mlx_pixel_put(data, j + 100, i + 100, color);
			j++;
		}
		i++;
	}
	
}
//function to draw a filed of view of 60 degrees
// void	cast_rays(t_data *data)
// {
// 	int i;

// 	i = 0;
// }

//Grey square for the minimap = 0x808080

// void	draw_map(t_data *data)
// {
// 	int	i;
// 	int	j;
// 	int px;
// 	int py;
	
// 	i = 0;
// 	py = (int)data->py - 100;
// 	while (py < (int)data->py + 100)
// 	{
// 		px = (int)data->px - 100;
// 		j = 0;
// 		while (px < data->px + 100)
// 		{
// 			if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == '1')
// 				my_mlx_pixel_put(data, j, i, 0x000000);
// 			else if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == 'D')
// 				my_mlx_pixel_put(data, j, i, 0x808080);
// 			else
// 				my_mlx_pixel_put(data, j, i, 0xffffff);
// 			px++;
// 			j++;
// 		}
// 		py++;
// 		i++;
// 	}
// 	draw_player(data, 0xff3f34);
// 	dda(data, (data->px / WALL_SIZE) - 16, (data->py / WALL_SIZE) - 16, (data->px / WALL_SIZE) - 16 + 50 , (data->py / WALL_SIZE) - 16 + 50);
// }

// void DrawCircle(t_data *data)
// {
//       static const double PI = 3.1415926535;
//       double i, angle, x1, y1;

//       for(i = 0; i < 360; i += 0.1)
//       {
//             angle = i;
//             x1 = data->angle * cos(angle * PI / 180);
//             y1 = data->angle * sin(angle * PI / 180);
//             my_mlx_pixel_put(data, data->px + x1, data->py + y1, 0x000000);
//       }
// }

// color blue = 0x0000FF;

// void	draw_map(t_data *data)
// {
// 	int i;
// 	int j;
// 	int px;
// 	int py;
// 	int radius = 100; // Radius of the circle

// 	i = 0;
// 	py = (int)data->py - radius;
// 	while (py < (int)data->py + radius)
// 	{
// 		px = (int)data->px - radius;
// 		j = 0;
// 		while (px < data->px + radius)
// 		{
// 			// Calculate the distance from the current pixel to the center of the circle
// 			int distance = (px - (int)data->px) * (px - (int)data->px) + (py - (int)data->py) * (py - (int)data->py);

// 			if (distance <= radius * radius)
// 			{
// 				if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == '1')
// 					my_mlx_pixel_put(data, j, i, 0x000000);
// 				else if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == 'D')
// 					my_mlx_pixel_put(data, j, i, 0x808080);
// 				else
// 					my_mlx_pixel_put(data, j, i, 0xffffff);
// 			}

// 			px++;
// 			j++;
// 		}
// 		py++;
// 		i++;
// 	}
// 	draw_player(data, 0xff3f34);
// }


// Define a function for alpha blending
int alpha_blend(int old_color, int new_color, float alpha)
{
	int r1 = (old_color >> 16) & 0xFF;
	int g1 = (old_color >> 8) & 0xFF;
	int b1 = old_color & 0xFF;

	int r2 = (new_color >> 16) & 0xFF;
	int g2 = (new_color >> 8) & 0xFF;
	int b2 = new_color & 0xFF;

	int r = (int)(r2 * alpha + r1 * (1 - alpha));
	int g = (int)(g2 * alpha + g1 * (1 - alpha));
	int b = (int)(b2 * alpha + b1 * (1 - alpha));

	return ((r << 16) | (g << 8) | b);
}

void	draw_map(t_data *data)
{
	int i;
	int j;
	int px;
	int py;
	int radius = 100; // Radius of the circle

	i = 0;
	py = (int)data->py - radius;
	while (py < (int)data->py + radius)
	{
		px = (int)data->px - radius;
		j = 0;
		while (px < data->px + radius)
		{
			// Calculate the distance from the current pixel to the center of the circle
			int distance = (px - (int)data->px) * (px - (int)data->px) + (py - (int)data->py) * (py - (int)data->py);

			if (distance <= radius * radius)
			{
				if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == '1')
					my_mlx_pixel_put(data, j, i, 0x000000);
				else if ((int)py / WALL_SIZE >= 0 && (int)py / WALL_SIZE < tab_size(data->map) && data->map[(int)py / WALL_SIZE] && data->map[(int)py / WALL_SIZE][(int)px / WALL_SIZE] == 'D')
					my_mlx_pixel_put(data, j, i, 0x808080);
				else
					my_mlx_pixel_put(data, j, i, 0xffffff);
			}

			px++;
			j++;
		}
		py++;
		i++;
	}
	draw_player(data, 0xff3f34);
}