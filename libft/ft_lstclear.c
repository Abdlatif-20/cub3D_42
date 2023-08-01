/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:44:58 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/26 15:39:28 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*swap;

	if (lst && del)
	{
		if (*lst)
		{
			while (*lst)
			{
				swap = (*lst)->next;
				ft_lstdelone(*lst, del);
				(*lst) = swap;
			}
		}
	}
}
