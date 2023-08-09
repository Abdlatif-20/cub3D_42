/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/09 18:45:13 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_close(void)
{
	exit(0);
}

void	ft_initializeer(t_data *data, char **map)
{
	map = NULL;
	map = (char **)malloc((data->width + 1) * sizeof(char *));
	if (!map)
		exit(0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1200, 1200, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->flag_down = 0;
	data->flag_up = 0;
	data->flag_left = 0;
	data->flag_right = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->player.rotation_angle = 0;
}

static void	check_map_extension(char *path)
{
	char	*str;

	str = ft_strchr(path, '.');
	if (!str)
		throw_error("Map extension is not valid", NULL);
	if (!(str[1] == 'c' && str[2] == 'u' && str[3] == 'b' && !str[4]))
		throw_error("Map extension is not valid", NULL);
}

int	main(int ac, char **av)
{
	char		**full_map;
	t_point		p;
	t_garbage	*heap;
	t_data		data;
	char		**map;

	heap = NULL;
	if (ac != 2)
		return (printf("Wrong Argument\n"), 0);
	check_name_of_map(av[1], ".cub");
	length_of_map(av[1], &data);
	map = (char **)malloc((data.width + 1) * sizeof(char *));
	if (!map)
		return (0);
	check_map_extension(av[1]);
//	full_map = get_full_map(av[1], &heap);
//	init_data(&data, full_map, &heap);
	fill_map(av[1], map);
	ft_initializeer(&data, map);
	mini_map(&data, map);
	get_position_of_player(map, &data);
	color_player(&data);
	data.map = map;
	drawing_line(&data.player, &p, &data);
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 3, 0, key_hook2, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop_hook(data.mlx, key_hook3, &data);
	mlx_loop(data.mlx);
	empty_trash(&heap);
	return (0);
}
