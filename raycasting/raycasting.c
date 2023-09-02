/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 12:12:25 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/01 22:25:56 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static double	adjust_angle(double ray_angle)
{
	double	new_angle;

	new_angle = remainder(ray_angle, 2 * M_PI);
	if (new_angle < 0)
		new_angle += (2 * M_PI);
	return (new_angle);
}

static void	check_horz_int(t_data *data, double ray_angle)
{
	t_vars	*vars;
	int		j;

	vars = data->vars;
	vars->y_horz_int = floor(data->py / WALL_SIZE) * WALL_SIZE;
	j = 0;
	if (!vars->ray_looking_down)
		j = 1;
	else
		vars->y_horz_int += WALL_SIZE;
	vars->x_horz_int = data->px + (vars->y_horz_int - data->py) / tan(ray_angle);
	while (vars->x_horz_int > 0 && vars->x_horz_int < data->width * WALL_SIZE
		&& vars->y_horz_int > 0 && vars->y_horz_int < data->height * WALL_SIZE
		&& data->map[(int)(vars->y_horz_int - j) / WALL_SIZE][(int)vars->x_horz_int / WALL_SIZE] != '1')
	{
		vars->y_step = WALL_SIZE;
		if (!vars->ray_looking_down)
			vars->y_step *= -1;
		vars->y_horz_int += vars->y_step;
		vars->x_step = WALL_SIZE / tan(ray_angle);
		if (vars->ray_looking_right && vars->x_step < 0)
			vars->x_step *= -1;
		else if (!vars->ray_looking_right && vars->x_step > 0)
			vars->x_step *= -1;
		vars->x_horz_int += vars->x_step;
	}
	vars->horz_dist = sqrt(pow(data->px - vars->x_horz_int, 2) + pow(data->py - vars->y_horz_int, 2));
}

static void	check_vert_int(t_data *data, double ray_angle)
{
	t_vars	*vars;
	int		j;

	vars = data->vars;
	vars->x_vert_int = floor(data->px / WALL_SIZE) * WALL_SIZE;
	j  = 0;
	if (!vars->ray_looking_right)
		j = 1;
	else
		vars->x_vert_int += WALL_SIZE;
	vars->y_vert_int = data->py + (vars->x_vert_int - data->px) * tan(ray_angle);
	while (vars->x_vert_int > 0 && vars->x_vert_int < data->width * WALL_SIZE
		&& vars->y_vert_int > 0 && vars->y_vert_int < data->height * WALL_SIZE
		&& data->map[(int)vars->y_vert_int / WALL_SIZE][(int)(vars->x_vert_int - j) / WALL_SIZE] != '1')
	{
		vars->x_step = WALL_SIZE;
		if (!vars->ray_looking_right)
			vars->x_step *= -1;
		vars->x_vert_int += vars->x_step;
		vars->y_step = WALL_SIZE * tan(ray_angle);
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
	ray_angle = adjust_angle(ray_angle);
	data->vars->ray_looking_down = ray_angle > 0 && ray_angle < M_PI;
	data->vars->ray_looking_right = ray_angle < 0.5 * M_PI || ray_angle > 1.5 * M_PI;
	check_horz_int(data, ray_angle);
	check_vert_int(data, ray_angle);
	if (data->vars->horz_dist < data->vars->vert_dist)
	{
		rays->distance = data->vars->horz_dist;
		rays->ray_angle = ray_angle;
		rays->wall_hit_x = data->vars->x_horz_int;
		rays->wall_hit_y = data->vars->y_horz_int;
		rays->flag_color = 0;
	}
	else
	{
		rays->distance = data->vars->vert_dist;
		rays->ray_angle = ray_angle;
		rays->wall_hit_x = data->vars->x_vert_int;
		rays->wall_hit_y = data->vars->y_vert_int;
		rays->flag_color = 1;
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
		throw_error("Error: Malloc failed", NULL) ;
	while (i < SCREEN_WIDTH)
	{
		cast_ray(data, &rays[i], ray_angle);
		ray_angle += angle_inc;
		i++;
	}
	data->rays = rays;
	i = 0;
	while (i < SCREEN_WIDTH)
	{
		dda(data, rays[i].wall_hit_x, rays[i].wall_hit_y);
		i++;
	}
}
