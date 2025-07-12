/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:15:11 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:15:13 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	init_split_segment(t_split_segment *seg,
	char **result, int *seg_idx, const char *str)
{
	seg->result = result;
	seg->seg_idx = seg_idx;
	seg->str = str;
}

void	set_segment_range(t_split_segment *seg, int seg_start, int seg_len)
{
	seg->seg_start = seg_start;
	seg->seg_len = seg_len;
}

int	handle_delimiter(t_split_segment *seg, int *seg_start, int i)
{
	set_segment_range(seg, *seg_start, i - *seg_start);
	if (!process_segment(seg))
		return (0);
	*seg_start = i + 1;
	return (1);
}

int	process_segment(t_split_segment *seg)
{
	if (seg->seg_len > 0)
	{
		if (!create_segment(seg))
			return (0);
		(*(seg->seg_idx))++;
	}
	return (1);
}

int	create_segment(t_split_segment *seg)
{
	seg->result[*(seg->seg_idx)]
		= (char *)malloc((seg->seg_len + 1) * sizeof(char));
	if (seg->result[*(seg->seg_idx)] == 0)
		return (0);
	ft_strlcpy(seg->result[*(seg->seg_idx)],
		seg->str + seg->seg_start, seg->seg_len + 1);
	return (1);
}
