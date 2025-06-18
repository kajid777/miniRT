/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:42:17 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 20:11:26 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

// void ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*current_node;
// 	t_list	*next_node;

// 	if (!del || !lst || !*lst)
// 		return ;
// 	current_node = lst[0];
// 	while (current_node->next != '\0')
// 	{
// 		del(current_node->content);
// 		next_node = current_node->next;
// 		free(current_node);
// 		current_node = next_node;
// 	}
// 	del(current_node->content);
// 	free(current_node);
// 	free(lst);
// }
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!del || !lst || !*lst)
		return ;
	while (lst && *lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
}
//Finally, the pointer to the list must be set to NULL.