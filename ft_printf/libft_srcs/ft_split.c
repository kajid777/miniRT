/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:06:41 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 21:53:31 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	count_segments(const char *str, char c)
// {
// 	int	count;
// 	int	inside_segment;

// 	count = 0;
// 	inside_segment = 0;
// 	while (*str)
// 	{
// 		if (is_charset(*str, c))
// 			inside_segment = 0;
// 		else
// 		{
// 			if (!inside_segment)
// 			{
// 				count++;
// 				inside_segment = 1;
// 			}
// 		}
// 		str++;
// 	}
// 	return (count);
// }

// int	make_lists(char **result, const char *str, char c, int num_segments)
// {
// 	int	seg_idx;
// 	int	seg_start;
// 	int	seg_len;
// 	int	i;
// 	char set[2];
// 	set[0] = c;
// 	set[1] = '\0';
// 	seg_idx = 0;
// 	seg_start = 0;
// 	i = 0;
// 	while (seg_idx < num_segments)
// 	{
// 		// printf("%d\n", seg_idx);
// 		while (ft_strchr(set, str[i]))
// 			i++;
// 		seg_start = i;
// 		i++;
// 		while (!(ft_strchr(set, str[i])))
// 			i++;
// 		seg_len = i - 1;
// 		result[seg_idx] = ft_substr(str, seg_start, seg_len - seg_start + 1);
// 		// printf("%s\n", result[seg_idx]);
// 		seg_idx++;
// 	}
// 	return (1);
// }

// char	**ft_split(char const *s, char c)
// {
// 	char	**dest;
// 	int		num_segments;
// 	int		i;

// 	if (s == 0)
// 		return (0);
// 	num_segments = count_segments(s, c);
// 	i = 0;
// 	dest = (char **)malloc((num_segments + 1) * sizeof(char *));
// 	if (dest == 0)
// 		return (0);
// 	if (make_lists(dest, s, c, num_segments))
// 		return (0);
// 	return (dest);
// }

// static void	free_segments(char **segments)
// {
// 	// if (segments == 0)
// 	// 	return;

// 	int i = 0;
// 	while (segments[i] != 0)
// 	{
// 		free(segments[i]);
// 		i++;
// 	}

// 	free(segments);
// }
//ver00 I remade it but failed.

static void	free_segments(char **segments)
{
	int	i;

	i = 0;
	while (segments[i] != 0)
	{
		free(segments[i]);
		i++;
	}
	free(segments);
}

static int	is_char(char a, char c)
{
	if (c == a)
	{
		return (1);
	}
	return (0);
}

static int	count_segments(const char *str, char c)
{
	int	count;
	int	inside_segment;

	count = 0;
	inside_segment = 0;
	while (*str)
	{
		if (is_char(*str, c))
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

static int	make_lists(char **result, const char *str, char c, int str_len)
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
		if (is_char(str[i], c) || str[i] == '\0')
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

char	**ft_split(const char *str, char c)
{
	int		num_segments;
	char	**result;
	int		str_len;
	int		i;

	if (str == NULL)
		return (NULL);
	num_segments = count_segments(str, c);
	result = (char **)malloc((num_segments + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
		i++;
	str_len = i;
	if (!(make_lists(result, str, c, str_len)))
	{
		free_segments(result);
		return (0);
	}
	result[num_segments] = 0;
	return (result);
}

// #include<stdio.h>
// int main() {
//     char *str = "hello,world,42,tokyo";
//     char c = ',';

//     char **segments = ft_split(str, c);

//     if (segments) {
//         for (int i = 0; segments[i] != NULL; i++) {
//             printf("%s\n", segments[i]);
//             free(segments[i]);
//         }
//         free(segments);
//     }

//     return 0;
// }
