/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.ma>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:15:50 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/01 13:52:42 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*get_key_value(char *str, short option, t_garbage **heap)
{
	int		i;
	char	*sub;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	if (option == 0)
	{
		sub = ft_substr(str, 0, i);
		return (add_to_garbage(heap, sub), sub);
	}
	else
	{
		while (str[i] && str[i] == ' ')
			i++;
		sub = ft_substr(str, i, ft_strlen(str));
		return (add_to_garbage(heap, sub), sub);
	}
}

void	add_to_texture(t_texture **texture, char *key,
							char *value, t_garbage **heap)
{
	t_texture	*new;

	new = malloc(sizeof(t_texture));
	if (!new)
		throw_error("Error: malloc failed", heap);
	new->key = key;
	new->value = value;
	new->next = NULL;
	new->last = NULL;
	add_to_garbage(heap, new);
	if (!*texture)
	{
		*texture = new;
		(*texture)->next = NULL;
		(*texture)->last = new;
	}
	else
	{
		(*texture)->last->next = new;
		(*texture)->last = new;
	}
}
