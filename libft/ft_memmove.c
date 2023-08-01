/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 20:11:21 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/30 17:57:15 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*s;

	s = (const char *)src;
	dst = (char *)dest;
	i = 0;
	if (dst == s)
		return (dst);
	if (dst < s)
		ft_memcpy(dst, s, n);
	else
		while (n--)
			dst[n] = s[n];
	return (dest);
}
