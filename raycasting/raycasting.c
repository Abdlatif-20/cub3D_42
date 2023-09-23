/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:12:25 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/23 14:49:10 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	adjust_angle(double ray_angle)
{
	double	new_angle;

	new_angle = remainder(ray_angle, 2 * M_PI);
	if (new_angle < 0)
		new_angle += (2 * M_PI);
	return (new_angle);
}

int	match_door(t_door *door, int x1, int y1)
{
	int	i;

	i = 0;
	while (i < 20)
	{
		if (door[i].x_door == x1 && door[i].y_door == y1)
			return (i);
		i++;
	}
	return (0);
}

static void	check_horz_int(t_data *data, double ray_angle, int *flag_door)
{
	t_vars	*vars;
	vars = data->vars;
	vars->y_horz_int = floor(data->py / WALL_SIZE) * WALL_SIZE;
	vars->j = 0;
	if (!vars->ray_looking_down)
		vars->j = 1;
	else
		vars->y_horz_int += WALL_SIZE;
	vars->x_horz_int = data->px + (vars->y_horz_int - data->py) / tan(ray_angle);
	vars->x_step = WALL_SIZE / tan(ray_angle);
	while (vars->x_horz_int > 0 && vars->x_horz_int < data->width * WALL_SIZE
		&& vars->y_horz_int > 0 && vars->y_horz_int < data->height * WALL_SIZE
		&& data->map[(int)(vars->y_horz_int - vars->j) / WALL_SIZE][(int)vars->x_horz_int / WALL_SIZE] != '1')
	{
		if (data->map[(int)((vars->y_horz_int) - vars->j) / WALL_SIZE][(int)vars->x_horz_int / WALL_SIZE] == 'D')
		{
			// Calculate the horizontal distance to the door
			data->door_dist = sqrt(pow(data->px - vars->x_horz_int, 2) + pow(data->py - vars->y_horz_int, 2));
			int i = match_door(data->door, (int)vars->x_horz_int / WALL_SIZE, (int)((vars->y_horz_int) - vars->j) / WALL_SIZE);
			data->index_door = i;
			if (data->door[i].open_door)
			{
				*flag_door = 1;
				break;
			}
		}
		vars->y_step = WALL_SIZE;
		if (!vars->ray_looking_down)
			vars->y_step *= -1;
		vars->y_horz_int += vars->y_step;
		if (vars->ray_looking_right && vars->x_step < 0)
			vars->x_step *= -1;
		else if (!vars->ray_looking_right && vars->x_step > 0)
			vars->x_step *= -1;
		vars->x_horz_int += vars->x_step;
	}
	vars->horz_dist = sqrt(pow(data->px - vars->x_horz_int, 2) + pow(data->py - vars->y_horz_int, 2));
}

static void	check_vert_int(t_data *data, double ray_angle, int *flag_door)
{
	t_vars	*vars;
	vars = data->vars;

	vars->x_vert_int = floor(data->px / WALL_SIZE) * WALL_SIZE;
	vars->j = 0;
	if (!vars->ray_looking_right)
		vars->j = 1;
	else
		vars->x_vert_int += WALL_SIZE;
	vars->y_vert_int = data->py + (vars->x_vert_int - data->px) * tan(ray_angle);
	vars->y_step = WALL_SIZE * tan(ray_angle);
	while (vars->x_vert_int > 0 && vars->x_vert_int < data->width * WALL_SIZE
		&& vars->y_vert_int > 0 && vars->y_vert_int < data->height * WALL_SIZE
		&& data->map[(int)vars->y_vert_int / WALL_SIZE][(int)(vars->x_vert_int - vars->j) / WALL_SIZE] != '1')
	{
		if (data->map[(int)vars->y_vert_int / WALL_SIZE][(int)((vars->x_vert_int) - vars->j) / WALL_SIZE] == 'D')
		{
			// Calculate the vertical distance to the door
			data->door_dist = sqrt(pow(data->px - vars->x_vert_int, 2) + pow(data->py - vars->y_vert_int, 2));
			int i = match_door(data->door, (int)((vars->x_vert_int) - vars->j) / WALL_SIZE, (int)vars->y_vert_int / WALL_SIZE);
			data->index_door = i;
			if (data->door[i].open_door)
			{
				*flag_door = 1;
				break;
			}
		}
		vars->x_step = WALL_SIZE;
		if (!vars->ray_looking_right)
			vars->x_step *= -1;
		vars->x_vert_int += vars->x_step;
		if (vars->ray_looking_down && vars->y_step < 0)
			vars->y_step *= -1;
		else if (!vars->ray_looking_down && vars->y_step > 0)
			vars->y_step *= -1;
			vars->y_vert_int += vars->y_step;
	}
	vars->vert_dist = sqrt(pow(data->px - vars->x_vert_int, 2) + pow(data->py - vars->y_vert_int, 2));
}

static void	cast_ray(t_data *data, t_ray *rays, double ray_angle)
{
	int v;
	int h;
	int flag_door;

	flag_door = 0;
	ray_angle = adjust_angle(ray_angle);
	data->vars->ray_looking_down = ray_angle > 0 && ray_angle < M_PI;
	data->vars->ray_looking_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	check_horz_int(data, ray_angle, &flag_door);
	h = flag_door;
	flag_door = 0;
	check_vert_int(data, ray_angle, &flag_door);
	v = flag_door;
	if (data->vars->horz_dist < data->vars->vert_dist)
	{
		rays->distance = data->vars->horz_dist;
		rays->ray_angle = ray_angle;
		rays->wall_hit_x = data->vars->x_horz_int;
		rays->wall_hit_y = data->vars->y_horz_int;
		rays->flag_color = 0;
		rays->is_door = h;
	}
	else
	{
		rays->distance = data->vars->vert_dist;
		rays->ray_angle = ray_angle;
		rays->wall_hit_x = data->vars->x_vert_int;
		rays->wall_hit_y = data->vars->y_vert_int;
		rays->flag_color = 1;
		rays->is_door = v;
	}
}

void	cast_all_rays(t_data *data)
{
	t_ray	*rays;
	int		i;
	double	ray_angle;
	double	angle_inc;
	
	i = 0;
	ray_angle = data->angle - (FOV / 2);
	angle_inc = FOV / SCREEN_WIDTH;
	rays = malloc(sizeof(t_ray) * SCREEN_WIDTH);
	if (!rays)
		throw_error("Error: Malloc failed", NULL);
	while (i < SCREEN_WIDTH)
	{
		cast_ray(data, &rays[i], ray_angle);
		ray_angle += angle_inc;
		i++;
	}
	data->rays = rays;
}
