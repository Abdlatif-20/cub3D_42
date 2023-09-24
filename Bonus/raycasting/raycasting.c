/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 10:33:34 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/24 23:07:38 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	cast_one_ray(t_data *data, float ray_angle)
{
	t_ray	*ray;
	int	h, v, flag_door = 0;

	ray = data->ray;
	ray_angle = adjust_angle(ray_angle);
	ray->ray_looking_down = ray_angle > 0 && ray_angle < M_PI;
	ray->ray_looking_right = ray_angle < 0.5 * M_PI
		|| ray_angle > 1.5 * M_PI;
	check_horz_intersection(data, ray_angle, &flag_door);
	h = flag_door;
	flag_door = 0;
	check_vert_intersection(data, ray_angle, &flag_door);
	v = flag_door;
	if (ray->horz_dist < ray->vert_dist)
	{
		ray->distance = ray->horz_dist * cos(ray_angle - data->player->angle);
		ray->wall_hit_x = ray->x_horz_int;
		ray->wall_hit_y = ray->y_horz_int;
		ray->ray_angle = ray_angle;
		ray->hit_vert_horz = 0;
		ray->hit_door = h;
	}
	else
	{
		ray->distance = ray->vert_dist * cos(ray_angle - data->player->angle);
		ray->wall_hit_x = ray->x_vert_int;
		ray->wall_hit_y = ray->y_vert_int;
		ray->ray_angle = ray_angle;
		ray->hit_vert_horz = 1;
		ray->hit_door = v;
	}
}

void	cast_all_rays(t_data *data)
{
	int		i;
	float	angle_incr;
	t_ray	ray;
	float	wall_height;
	float	ray_angle;

	i = 0;
	ray_angle = data->player->angle - (data->player->fov / 2);
	angle_incr = data->player->fov / SCREEN_WIDTH;
	data->ray = &ray;
	while (i < SCREEN_WIDTH)
	{
		cast_one_ray(data, ray_angle);
		wall_height = (SCALE_SIZE * data->player->dis_proj_player)
			/ (data->ray->distance);
		wall_drawing(i, wall_height, data);
		if (data->ray->hit_door == 1)
			door_drawing(i, wall_height, data);
		ray_angle += angle_incr;
		i++;
	}
}
