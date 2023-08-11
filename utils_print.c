/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 18:18:00 by aben-nei          #+#    #+#             */
/*   Updated: 2023/08/08 18:18:05 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_list(t_garbage *garbage)
{
	while (garbage)
	{
		printf("%s\n", (char *)garbage->data);
		garbage = garbage->next;
	}
}
//
//void	print(char **map)
//{
//	int	i;
//
//	for (i = 0;map[i];i++)
//		 printf("%s", map[i]);
//}
