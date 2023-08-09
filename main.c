/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:46:12 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/01 17:46:00 by aben-nei         ###   ########.fr       */
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
		return (exit(0));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 1200, 1200, "Hello world!");
	data->img = mlx_new_image(data->mlx, 1200, 1200);
	data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
	data->flag_down = 0;
	data->flag_up = 0;
	data->flag_left = 0;
	data->flag_right = 0;
	data->player.rotation_angle = 0;
}

int	main(int ac, char **av)
{
	char		**map;
	t_garbage	*heap;
	t_data		data;

	heap = NULL;
	if (ac != 2)
		return (printf("Wrong Argument\n"), 0);
	check_name_of_map(av[1], ".cub");
	length_of_map(av[1], &data);
	map = (char **)malloc((data.width + 1) * sizeof(char *));
	if (!map)
		return (0);
	fill_map(av[1], map, &heap);
	ft_initializeer(&data, map);
	mini_map(&data, map);
	get_position_of_player(map, &data);
	color_player(&data);
	data.map = map;
	mlx_put_image_to_window(data.mlx, data.win, data.img, 0, 0);
	mlx_hook(data.win, 2, 0, key_hook, &data);
	mlx_hook(data.win, 3, 0, key_hook2, &data);
	mlx_hook(data.win, 17, 0, ft_close, &data);
	mlx_loop_hook(data.mlx, key_hook3, &data);
	mlx_loop(data.mlx);
	return (free_garbage(&heap), 0);
}
