/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/30 17:35:48 by aben-nei         ###   ########.fr       */
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

// static void	leaks_detector(void)
// {
// 	system("leaks cub3D");
// }

// static int	handle_key_release(int keycode, t_data *data)
// {
// 	(void)keycode;
// 	data->keycode = -1;
// 	return (1);
// }

// static int	handle_key_press(int keycode, t_data *data)
// {
// 	data->keycode = keycode;
// 	return (1);
// }

int	ft_close(void)
{
	exit(0);
}

int	main(int ac, char **av)
{
	char		**full_map;
	t_garbage	*heap;
	t_data		data;
	t_dda		dda_vars;
	t_vars		vars;

	// atexit(leaks_detector);
	if (ac != 2)
		throw_error("Number of args is not valid", NULL);
	heap = NULL;
	check_map_extension(av[1]);
	full_map = get_full_map(av[1], &heap);
	init_data(&data, full_map, &heap);
	data.dda_vars = &dda_vars;
	data.vars = &vars;
	// cast_all_rays(&data);
	draw_map(&data);
	// draw_walls(&data);
	mlx_hook(data.win_ptr, 17, 0, ft_close, NULL);
	mlx_hook(data.win_ptr, 2, 0, key_hook, &data);
	mlx_hook(data.win_ptr, 3, 0, key_hook2, &data);
	// mlx_hook(data.win_ptr, 2, 1L << 0, key_hook, &data);
	// mlx_hook(data.win_ptr, 3, 1L << 1, key_hook2, &data);
	mlx_loop_hook(data.mlx_ptr, key_hook3, &data);
	mlx_loop(data.mlx_ptr);
	empty_trash(&heap);
	return (0);
}
