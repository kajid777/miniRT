/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 00:31:51 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 22:05:28 by dkajiwar         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		s1_len;
	int		s2_len;
	char	*dest;

	if (s1 == 0 || s2 == 0)
		return (0);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	dest = (char *)malloc(s1_len + s2_len + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, s1_len + 1);
	ft_strlcpy(&dest[s1_len], s2, s1_len + s2_len + 1);
	return (dest);
}

// int main()
// {
// 	char *s1 = "where is my ";
// 	char *s2 = "malloc ???";

// 	printf("my ans = %s\n", ft_strjoin(s2, s1));
// 	printf("ans = %s\n", strjoin(s2, s1));

// }

// #include<stdio.h>
// int	main(void)
// {
// 	/* 1 */
// 	char *a = ft_strjoin("hello", "world");
// 	// char *b = strjoin("hello", "world");
// 	printf("%s\n",a);
// 	// printf("%s\n",b);

// 	// /* 2 */ ASSERT_EQ_STR(ft_strjoin("", "world"), "world");
// 	// /* 3 */ ASSERT_EQ_STR(ft_strjoin("hello", ""), "hello");
// 	// /* 4 */ ASSERT_EQ_STR(ft_strjoin("", ""), "");
// }