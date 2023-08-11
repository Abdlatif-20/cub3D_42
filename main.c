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

void	ft_initializer(t_data *data)
{
	data->mlx.mlx = mlx_init();
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			SCREEN_WIDTH, SCREEN_HEIGHT, "Hello world!");
	data->mlx.img = mlx_new_image(data->mlx.mlx, 1200, 1200);
	data->mlx.addr = mlx_get_data_addr(data->mlx.img, &data->mlx.bits_per_pixel,
			&data->mlx.line_length, &data->mlx.endian);
	data->flags.flag_down = 0;
	data->flags.flag_up = 0;
	data->flags.flag_left = 0;
	data->flags.flag_right = 0;
	data->flags.rotate_left = 0;
	data->flags.rotate_right = 0;
	data->player.rotation_angle = 0;
	data->more_speed = 1;
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

	heap = NULL;
	if (ac != 2)
		return (printf("Wrong Argument\n"), 0);
	check_map_extension(av[1]);
	full_map = get_full_map(av[1], &heap);
	init_data(&data, full_map, &heap);
	ft_initializer(&data);
	mini_map(&data);
	get_position_of_player(&data);
	color_player(&data);
	drawing_line(&data.player, &p, &data);
	mlx_put_image_to_window(data.mlx.mlx, data.mlx.win, data.mlx.img, 0, 0);
	mlx_hook(data.mlx.win, 2, 0, key_hook, &data);
	mlx_hook(data.mlx.win, 3, 0, key_hook2, &data);
	mlx_hook(data.mlx.win, 17, 0, ft_close, &data);
	mlx_loop_hook(data.mlx.mlx, key_hook3, &data);
	mlx_loop(data.mlx.mlx);
	empty_trash(&heap);
	return (0);
}
