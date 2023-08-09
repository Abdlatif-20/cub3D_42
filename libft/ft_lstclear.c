/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 19:02:02 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/02 14:36:15 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (lst != NULL && del != NULL)
	{
		tmp = *lst;
		while (*lst != NULL)
		{
			*lst = (*lst)->next;
			ft_lstdelone(tmp, del);
			tmp = *lst;
		}
		lst = NULL;
	}
}
