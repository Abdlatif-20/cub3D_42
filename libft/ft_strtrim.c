/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:25:14 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/31 02:25:25 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	str_start(char const *str, char const *set)
{
	int	i;
	int	start;

	i = 0;
	start = 0;
	while (set[i])
	{
		while (str[start] == set[i])
		{
			start++;
			i = 0;
		}
		i++;
	}
	return (start);
}

static int	str_end(char const *str, char const *set)
{
	int	i;
	int	end;

	i = 0;
	end = ft_strlen(str) - 1;
	while (set[i])
	{
		while (end >= 0 && str[end] == set[i] && str_start(str, set) < end)
		{
			end--;
			i = 0;
		}
		i++;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	else if (!set)
		return ((char *)s1);
	start = str_start(s1, set);
	end = str_end(s1, set);
	str = ft_substr(s1, start, (end - start) + 1);
	return (str);
}
