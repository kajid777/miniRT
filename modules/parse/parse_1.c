/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 12:21:27 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/27 10:41:13 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// ft_strcmp関数 - 2つの文字列を比較する
int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

// ft_tab_size関数 - 文字列配列のサイズを返す
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

// 文字が文字セット内にあるかをチェックする関数
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

// 文字列が指定された文字セットの文字のみで構成されているかを判定する関数
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
