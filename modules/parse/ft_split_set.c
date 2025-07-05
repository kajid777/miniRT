/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// 文字列配列の全要素をfreeする関数
void	ft_free_tab(char **tab)
{
	int	i;

	if (!tab)
		return;
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

// 文字が指定されたセットに含まれるかチェックする関数
int	is_in_charset(char c, const char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

// セグメント数をカウントする関数
int	count_segments_set(const char *str, const char *charset)
{
	int	count;
	int	inside_segment;

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