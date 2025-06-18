/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:52:49 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/05 15:53:40 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*dest;
	int		i;
	int		s1_len;
	int		first_index;
	int		last_index;

	if (s1 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	i = 0;
	while (ft_strchr(set, s1[i]))
		i++;
	first_index = i;
	i = 0;
	while (ft_strrchr(set, s1[s1_len - i - 1]))
		i++;
	last_index = s1_len - i - 1;
	dest = ft_substr(s1, first_index, last_index - first_index + 1);
	return (dest);
}

// dest = (char *)malloc((last_index - first_index) + 2);
// #include<stdio.h>
// int main() {
//     // テスト用の文字列とセットを定義
//     char *s1 = "hello world";
//     char *set = "world";

//     // ft_strtrim関数を使用して文字列をトリム
//     char *trimmed_str = ft_strtrim(s1, set);

//     // トリムされた文字列を出力
//     printf("Trimmed string: \"%s\"\n", trimmed_str);

//     // トリムされた文字列のメモリを解放
//     free(trimmed_str);

//     return 0;
// }