/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/01 17:40:57 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <stdio.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>

typedef struct s_garbage
{
	void				*data;
	struct s_garbage	*next;
	struct s_garbage	*last;
}				t_garbage;

void	check_name_of_map(char *str, char *find);
void	fill_map(char *av, char **map, t_garbage **heap);
char	*get_next_line(int fd);
size_t	length_of_map(char *av);
void	check_map_is_valid(char **map);
void	add_to_garbage(t_garbage **garbage, void *ptr);
void	check_texture(char *av);
void	free_garbage(t_garbage **garbage);
#endif