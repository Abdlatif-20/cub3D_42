/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aben-nei <aben-nei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 21:01:02 by aben-nei          #+#    #+#             */
/*   Updated: 2022/10/26 15:29:10 by aben-nei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}
// #include<stdio.h>
// int main()
// {
// 	t_list *N1 = ft_lstnew("Hello");
// 	t_list *N2 = ft_lstnew("World");
// 	t_list *N3 = ft_lstnew("1337");
// 	N1->next = N2;
// 	N2->next = N3;
// 	t_list *m = ft_lstlast(N1);
// 	printf("%s\n", m->content);
// }