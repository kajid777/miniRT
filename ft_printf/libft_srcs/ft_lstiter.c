/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 18:44:12 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 13:27:27 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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
