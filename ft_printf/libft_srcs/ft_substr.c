/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:50:01 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:59:24 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char *s)
// {
// 	int	count;

// 	count = 0;
// 	while (*s != '\0')
// 	{
// 		s++;
// 		count++;
// 	}
// 	return (count);
// }

// int	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
// {
// 	size_t	i;
// 	int		src_count;

// 	i = 0;
// 	while (i < dstsize - 1)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	if (!dstsize)
// 	{
// 		dst[i] = '\0';
// 	}
// 	src_count = 0;
// 	while (*src != '\0')
// 	{
// 		src++;
// 		src_count++;
// 	}
// 	return (src_count);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int		src_len;
// 	char				*dest;

// 	if (s == 0)
// 		return (0);
// 	src_len = ft_strlen(s);
// 	if (src_len - 1< start)
// 		return (0);
// 	if (start + len > src_len)
// 	{
// 		dest = (char *)malloc((src_len - start + 1) * sizeof(char));
// 		if (dest == 0)
// 			return (0);
// 		ft_strlcpy(dest, &s[start], src_len - start + 1);
// 	}
// 	else
// 	{
// 		dest = (char *)malloc((len + 1) * sizeof(char));
// 		if (dest == 0)
// 			return (0);
// 		ft_strlcpy(dest, &s[start], len + 1);
// 	}
// 	return (dest);
// }

// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	unsigned int		src_len;
// 	char				*dest;

// 	if (s == 0)
// 		return (0);
// 	src_len = ft_strlen(s);
// 	if (src_len <= start)
// 	{
// 		dest = (char *)malloc(sizeof(char) * 1);
// 		dest[0] = 0;
// 		return (dest);
// 	}
// 	if (start + len > src_len)
// 	{
// 		dest = (char *)malloc((src_len - start + 1) * sizeof(char));
// 		if (dest == 0)
// 			return (0);
// 		ft_strlcpy(dest, &s[start], src_len - start + 1);
// 	}
// 	else
// 	{
// 		dest = (char *)malloc((len + 1) * sizeof(char));
// 		if (dest == 0)
// 			return (0);
// 		ft_strlcpy(dest, &s[start], len + 1);
// 	}
// 	return (dest);
// }
//ver01

static char	*dest_zero(char *dest)
{
	dest = (char *)malloc(sizeof(char) * 1);
		dest[0] = 0;
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int		src_len;
	char				*dest;

	dest = NULL;
	if (s == 0)
		return (0);
	src_len = ft_strlen(s);
	if (src_len <= start)
		return (dest_zero(dest));
	if (start + len > src_len)
	{
		dest = (char *)malloc((src_len - start + 1) * sizeof(char));
		if (dest == 0)
			return (0);
		ft_strlcpy(dest, &s[start], src_len - start + 1);
	}
	else
	{
		dest = (char *)malloc((len + 1) * sizeof(char));
		if (dest == 0)
			return (0);
		ft_strlcpy(dest, &s[start], len + 1);
	}
	return (dest);
}
//ver02

// #include <stdio.h>
// #include <stdlib.h>
// int main() {
//     // テスト用の文字列とパラメータを定義
//     char *s = "Hello, world!";
//     unsigned int start = 7;
//     size_t len = 5;

//     // ft_substr関数を使用して部分文字列を取得
//     char *substr = ft_substr(s, start, len);

//     // 部分文字列を出力
//     if (substr != NULL) {
//         printf("Subtring: %s\n", substr);
//         // メモリを解放
//         free(substr);
//     } else {
//         printf("Failed to allocate memory for substring.\n");
//     }

//     return 0;
// }

// #include<stdio.h>
// int	main(void)
// {
// 	char *s = "libft-test-tokyo";

// 	printf("s %p\n", s);

// 	char *a = ft_substr(s, 20, 5);

// 	printf("fake %p\n", a);

// 	// /* 5 */ ASSERT_EQ_STR(ft_substr(s, 20, 100), "");
// 	// /* 10 */ ASSERT_EQ_STR(ft_substr(s, 20, 5), "");

// 	// /* 15 */ ASSERT_EQ_STR(ft_substr(s, 20, 0), "");
// }