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

void	print_list(t_garbage *garbage)
{
	while (garbage)
	{
		printf("%s\n", (char *)garbage->data);
		garbage = garbage->next;
	}
}

int	main(int ac, char **av)
{
	char		**map;
	t_garbage	*heap;

	map = NULL;
	heap = NULL;
	map = (char **)malloc((length_of_map(av[1]) + 1) * sizeof(char *));
	if (!map)
		return (0);
	if (ac == 2)
	{
		check_name_of_map(av[1], ".cub");
		fill_map(av[1], map, &heap);
		check_texture(av[1]);
		check_map_is_valid(map);
	}
	else
		printf("Wrong Argument\n");
	return (0);
}
