/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:40:34 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:58:48 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int		size_count;
	t_list	*temp;

	if (lst == '\0')
		return (0);
	size_count = 0;
	temp = lst;
	while (temp->next != '\0')
	{
		temp = temp->next;
		size_count++;
	}
	if (temp->next == NULL)
		size_count++;
	return (size_count);
}
