/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:21:27 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/06 14:10:33 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_tab_size(char **tab)
{
	int	size;

	size = 0;
	if (!tab)
		return (0);
	while (tab[size])
		size++;
	return (size);
}

static bool	is_char_in_charset(char c, const char *charset)
{
	int	j;

	j = 0;
	while (charset[j])
	{
		if (c == charset[j])
		{
			return (true);
		}
		j++;
	}
	return (false);
}

bool	ft_is_from_charset(const char *str, const char *charset)
{
	int	i;

	if (!str || !charset)
		return (false);
	i = 0;
	while (str[i])
	{
		if (!is_char_in_charset(str[i], charset))
			return (false);
		i++;
	}
	return (true);
}
