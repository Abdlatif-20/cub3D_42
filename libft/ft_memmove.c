/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 15:56:11 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/02 18:00:04 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*ptrd;
	char	*ptrs;
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
	ptrd = (char *)dst;
	ptrs = (char *)src;
	i = len;
	if (ptrd > ptrs)
	{
		while (i > 0)
		{
			ptrd[i - 1] = ptrs[i - 1];
			i--;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, len));
}
