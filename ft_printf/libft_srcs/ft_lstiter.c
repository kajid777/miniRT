/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:44:12 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/06 21:11:58 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*current_node;

	if (!lst || !f)
		return ;
	current_node = lst;
	while (current_node != 0)
	{
		f(current_node->content);
		current_node = current_node->next;
	}
}
//I am not sure about if i need line27.
