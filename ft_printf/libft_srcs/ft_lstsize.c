/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 19:40:34 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/06 21:07:31 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
