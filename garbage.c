/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 11:02:25 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/02 11:06:41 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_garbage(t_garbage **garbage)
{
	t_garbage	*tmp;

	while (*garbage)
	{
		tmp = *garbage;
		*garbage = (*garbage)->next;
		free(tmp->data);
		free(tmp);
	}
}

void	add_to_garbage(t_garbage **garbage, void *ptr)
{
	t_garbage	*new;

	new = (t_garbage *)malloc(sizeof(t_garbage));
	if (!new)
		return ;
	new->data = ptr;
	new->next = NULL;
	new->last = NULL;
	if (!*garbage)
	{
		*garbage = new;
		(*garbage)->next = NULL;
		(*garbage)->last = new;
		return ;
	}
	else
	{
		(*garbage)->last->next = new;
		(*garbage)->last = new;
	}
}
