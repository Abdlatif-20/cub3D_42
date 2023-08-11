/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 17:38:31 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/06 16:45:22 by mel-yous         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"

typedef struct s_garbage	t_garbage;
typedef struct s_data		t_data;
typedef struct s_dict		t_dict;

# define MAP_ERROR "Error: something is wrong in the map"

struct s_garbage
{
	void		*address;
	t_garbage	*next;
	t_garbage	*last;
};

struct s_dict
{
	char	*key;
	char	*value;
	t_dict	*next;
	t_dict	*last;
};

struct s_data
{
	t_dict	*textures;
	int		ceiling[3];
	int		floor[3];
	char	**map;
};

/*-----------------------------cub_utils.c-----------------------------*/
void	throw_error(char *msg, t_garbage **heap);
char	*free_s1_join(char *s1, char *s2);
int		tab_size(char **tab);
int		ft_strcmp(char *s1, char *s2);
bool	is_number(char *str);

/*-----------------------------parsing.c-----------------------------*/
void	check_textures(t_dict *textures, t_garbage **heap);
void	check_rgb_code(int *rgb, t_garbage **heap);
void	check_map_components(char **map, t_garbage **heap);
void	map_is_closed(char **map, t_garbage **heap);
void	space_checker(char **map, t_garbage **heap);

/*-----------------------------map_reader.c-----------------------------*/
char	**get_full_map(char *path, t_garbage **heap);

/*-----------------------------g_collector.c-----------------------------*/
void	add_to_garbage(t_garbage **heap, void *address);
void	empty_trash(t_garbage **heap);

/*-----------------------------dict_utils.c-----------------------------*/
char	*get_key_value(char *str, short option, t_garbage **heap);

/*-----------------------------initializer.c-----------------------------*/
void	init_data(t_data *data, char **full_map, t_garbage **heap);

/*-----------------------------parsing_utils.c-----------------------------*/
bool	is_valid_component(char c);
void	skip_spaces(char *line, int *i);

#endif