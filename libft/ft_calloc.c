/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:35:48 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/30 17:58:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*p;

	if (n != 0 && (n * size) / n != size)
		return (NULL);
	p = (void *)malloc(n * size);
	if (!p)
		return (NULL);
	ft_bzero (p, n * size);
	return (p);
}
