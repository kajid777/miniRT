/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/07/06 14:09:40 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 14:09:40 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"


void	ft_free_tab(char **tab)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	is_in_charset(char c, const char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_segments_set(const char *str, const char *charset)
{
	int count;
	int inside_segment;

	count = 0;
	inside_segment = 0;
	while (*str)
	{
		if (is_in_charset(*str, charset))
		{
			inside_segment = 0;
		}
		else
		{
			if (!inside_segment)
			{
				count++;
				inside_segment = 1;
			}
		}
		str++;
	}
	return (count);
}