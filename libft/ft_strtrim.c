/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:28:20 by mel-yous          #+#    #+#             */
/*   Updated: 2022/11/02 18:19:45 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	begin;
	size_t	end;
	char	*trim;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	begin = 0;
	end = ft_strlen(s1);
	while (s1[begin] != '\0' && ft_strchr(set, s1[begin]))
		begin++;
	while (end >= begin && ft_strchr(set, s1[end]))
		end--;
	trim = ft_substr(s1, begin, (end - begin) + 1);
	return (trim);
}
