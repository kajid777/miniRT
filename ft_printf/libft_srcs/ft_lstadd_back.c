/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:57:07 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/06 21:11:50 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// t_list ft_lstlast(t_list *lst)
// {
// 	int	size_count;
// 	t_list *next_node;

// 	if (!new)
// 		return ;

// 	if (lst == '\0')
// 		return (lst);
// 	size_count = 1;
// 	next_node = lst;
// 	while (next_node->next != '\0')
// 	{
// 		next_node = next_node->next;
// 	}
// 	return (next_node);
// }

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*dest;

	if (!new)
		return ;
	if (!lst[0])
		lst[0] = new;
	else
	{
		dest = ft_lstlast(lst[0]);
		dest->next = new;
	}
}
//Is lst[0] same as *lst?
