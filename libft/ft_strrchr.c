/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 11:34:58 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/23 15:42:58 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;
	int		len;

	ptr = (char *)str;
	len = ft_strlen(ptr) + 1;
	while (--len >= 0)
		if (ptr[len] == (unsigned char)c)
			return (ptr + len);
	return (0);
}
