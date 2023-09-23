/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 13:11:32 by mel-yous          #+#    #+#             */
/*   Updated: 2023/09/22 14:59:03 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	throw_error(char *msg, t_garbage **heap)
{
	if (heap)
		empty_trash(heap);
	ft_putendl_fd(msg, 2);
	exit(1);
}

char	*free_s1_join(char *s1, char *s2)
{
	char	*joined;

	if (!s1)
		s1 = ft_strdup("");
	joined = ft_strjoin(s1, s2);
	free(s1);
	return (joined);
}

int	tab_size(char **tab)
{
	int	i;

	if (!tab || !*tab)
		return (0);
	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

bool	is_number(char *str)
{
	int	i;

	if (!str)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (false);
		i++;
	}
	return (true);
}
