/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-yous <mel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 18:28:53 by mel-yous          #+#    #+#             */
/*   Updated: 2022/10/31 18:03:14 by mel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ptr;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		ptr = (char *)malloc(ft_strlen(s) + 1);
		if (ptr == NULL)
			return (NULL);
		while (s[i] != '\0')
		{
			ptr[i] = (*f)(i, s[i]);
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	return (NULL);
}
