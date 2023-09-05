/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/09/05 22:10:00 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_map_extension(char *path)
{
	char	*str;

	str = ft_strchr(path, '.');
	if (!str)
		throw_error("Map extension is not valid", NULL);
	if (!(str[1] == 'c' && str[2] == 'u' && str[3] == 'b' && !str[4]))
		throw_error("Map extension is not valid", NULL);
}

static int	ft_close(void)
{
	exit(0);
}

static int	mouse_rotation(int x, int y, t_data *data)
{
	int diff_x;
	int diff_y;

	(void)y;
	(void)diff_y;
	if (data->hide_mouse)
	{
		mlx_mouse_move(data->win_ptr, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);
		diff_x = x - data->mouse_x;
		// diff_y =y - data->mouse_y;
		data->angle += diff_x * MOUSE_ROTSPEED;
		// data->angle += diff_y * MOUSE_ROTSPEED;
	}
	return (0);
}

int	main(int ac, char **av)
{
	char		**full_map;
	t_garbage	*heap;
	t_data		data;
	t_dda		dda_vars;
	t_vars		vars;

	if (ac != 2)
		throw_error("Number of args is not valid", NULL);
	heap = NULL;
	check_map_extension(av[1]);
	full_map = get_full_map(av[1], &heap);
	init_data(&data, full_map, &heap);
	data.dda_vars = &dda_vars;
	data.vars = &vars;
	mlx_hook(data.win_ptr, 17, 0, ft_close, NULL);
	mlx_hook(data.win_ptr, 2, 0, key_press, &data);
	mlx_hook(data.win_ptr, 3, 0, key_release, &data);
	mlx_hook(data.win_ptr, 6, 0, mouse_rotation, &data);
	mlx_loop_hook(data.mlx_ptr, render_frame, &data);
	mlx_loop(data.mlx_ptr);
	empty_trash(&heap);
	return (0);
}
