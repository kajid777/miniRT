/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:15:00 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:15:00 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	make_lists_set(char **result, const char *str, const char *charset,
		int str_len)
{
	int				seg_idx;
	int				seg_start;
	int				i;
	t_split_segment	seg;

	seg_idx = 0;
	seg_start = 0;
	i = 0;
	init_split_segment(&seg, result, &seg_idx, str);
	while (i <= str_len)
	{
		if (is_in_charset(str[i], charset) || str[i] == '\0')
		{
			if (!handle_delimiter(&seg, &seg_start, i))
				return (0);
		}
		i++;
	}
	return (1);
}

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
