/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                     :+:      :+:    :+:   */
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
static int	is_in_charset(char c, const char *charset)
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
static int	count_segments_set(const char *str, const char *charset)
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

// セグメントリストを作成する関数
static int	make_lists_set(char **result, const char *str, const char *charset, int str_len)
{
	int	seg_idx;
	int	seg_start;
	int	seg_len;
	int	i;

	seg_idx = 0;
	seg_start = 0;
	i = 0;
	while (i <= str_len)
	{
		if (is_in_charset(str[i], charset) || str[i] == '\0')
		{
			seg_len = i - seg_start;
			if (seg_len > 0)
			{
				result[seg_idx] = (char *)malloc((seg_len + 1) * sizeof(char));
				if (result[seg_idx] == 0)
					return (0);
				ft_strlcpy(result[seg_idx++], str + seg_start, seg_len + 1);
			}
			seg_start = i + 1;
		}
		i++;
	}
	return (1);
}

// 文字セットで文字列を分割する関数
char	**ft_split_set(const char *str, const char *charset)
{
	int		num_segments;
	char	**result;
	int		str_len;
	int		i;

	if (str == NULL)
		return (NULL);
	num_segments = count_segments_set(str, charset);
	result = (char **)malloc((num_segments + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;
	str_len = i;
	if (!(make_lists_set(result, str, charset, str_len)))
	{
		ft_free_tab(result);
		return (NULL);
	}
	result[num_segments] = NULL;
	return (result);
}