/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 23:21:52 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/01 18:36:14 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (haystack == NULL && len == 0)
		return (NULL);
	if (len > ft_strlen(haystack))
		len = ft_strlen(haystack);
	if (*needle == 0)
		return ((char *)haystack);
	i = 0;
	j = 0;
	while (i < len && haystack[i] != '\0')
	{
		while ((haystack[i + j] == needle[j]) && (i + j < len))
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		j = 0;
		i++;
	}
	return (NULL);
}
