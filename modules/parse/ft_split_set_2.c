/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 00:00:00 by user              #+#    #+#             */
/*   Updated: 2024/01/01 00:00:00 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// セグメントを作成してresult配列に格納する関数
static int	create_segment(char **result, int seg_idx, const char *str, int seg_start, int seg_len)
{
	result[seg_idx] = (char *)malloc((seg_len + 1) * sizeof(char));
	if (result[seg_idx] == 0)
		return (0);
	ft_strlcpy(result[seg_idx], str + seg_start, seg_len + 1);
	return (1);
}

// 区切り文字を処理する関数
static void	process_delimiter(int *seg_start, int i)
{
	*seg_start = i + 1;
}

// セグメントを処理する関数
static int	process_segment(char **result, int *seg_idx, const char *str, int seg_start, int seg_len)
{
	if (seg_len > 0)
	{
		if (!create_segment(result, *seg_idx, str, seg_start, seg_len))
			return (0);
		(*seg_idx)++;
	}
	return (1);
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
			if (!process_segment(result, &seg_idx, str, seg_start, seg_len))
				return (0);
			process_delimiter(&seg_start, i);
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
