/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:16:52 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:02:14 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//past ft_strlcpy
// int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	unsigned int	i;
// 	unsigned int	j;

// 	i = 0;
// 	j = 0;
// 	while (src[i] != '\0' && i + 1 < dstsize)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	if (dstsize != 0)
// 		dst[i] = '\0';
// 	while (src[j] != '\0')
// 	{
// 		j++;
// 	}
// 	return (j);
// }
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (src[i] != '\0' && i + 1 < dstsize)
	{
		dst[i] = src[i];
		i++;
	}
	if (dstsize != 0)
		dst[i] = '\0';
	while (src[j] != '\0')
	{
		j++;
	}
	return (j);
}
// #include<stdio.h>
// int	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	int		src_count;

// 	i = 0;
// 	printf("%zu\n", dstsize);
// 	while (i + 1 < dstsize)
// 	{
// 		dst[i] = src[i];
// 		i++;
// 		printf("test1\n");
// 	}
// 	if (dstsize > 0)
// 	{
// 		printf("test2\n");
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

// int main(){
// 	char *dst1 = calloc(10, sizeof(char));
// 	char *dst2 = calloc(10, sizeof(char));
// 	char *src1 = calloc(10, sizeof(char));
// 	char *src2 = calloc(10, sizeof(char));
// 	memset(src1, 'z', 9);
// 	memset(src2, 'z', 9);
// 	ft_strlcpy(dst1, src1, 0);//dstsize includes null character
// 	strlcpy(dst2, src2, 0);
// 	printf("destination1: %s\n", dst1);
// 	printf("destination2: %s\n", dst2);
// }
// int main() {
//     // テストケース1: 基本的なケース
//     printf("テストケース1: 基本的なケース\n");
//     char src1[] = "Hello";
//     char dst1[10];
//     size_t result1 = ft_strlcpy(dst1, src1, sizeof(dst1));
//     printf("結果: %zu\n", result1);
//     printf("コピー後の文字列: %s\n", dst1);

//     // テストケース2: dstsize が 0 の場合
//     printf("\nテストケース2: dstsize が 0 の場合\n");
//     char src2[] = "World";
//     char dst2[10];
//     size_t result2 = ft_strlcpy(dst2, src2, 0);
//     printf("結果: %zu\n", result2);
//     printf("コピー後の文字列: %s\n", dst2);

//     // テストケース3: dstsize よりも長いソース文字列の場合
//     printf("\nテストケース3: dstsize よりも長いソース文字列の場合\n");
//     char src3[] = "This is a long string";
//     char dst3[10];
//     size_t result3 = ft_strlcpy(dst3, src3, sizeof(dst3));
//     printf("結果: %zu\n", result3);
//     printf("コピー後の文字列: %s\n", dst3);

//     // テストケース4: dst が NULL の場合
//     printf("\nテストケース4: dst が NULL の場合\n");
//     char src4[] = "Hello";
// 	strlcpy(NULL, src4, 10);
//     // size_t result4 = ft_strlcpy(NULL, src4, 10);
//     // printf("結果: %zu\n", result4);

//     // テストケース5: src が NULL の場合
//     printf("\nテストケース5: src が NULL の場合\n");
//     char dst5[10];
// 	// strlcpy(dst5, NULL, sizeof(dst5));
// 	printf("本家結果: %s\n", dst5);
//     // size_t result5 = ft_strlcpy(dst5, NULL, sizeof(dst5));
//     printf("自作結果: %s\n", dst5);

//     printf("コピー後の文字列: %s\n", dst5);

//     return 0;
// }

// libftTester
// int main(void)
// {
// 	char src[] = "coucou";
// 	// char dest1[10];
// 	// memset(dest1, 'A', 9);

// 	// int ft_result = ft_strlcpy(dest1, src, -1);
// 	// printf("fake%d\n", ft_result);
// 	// if(dest1[0] == 0)
// 	// {
// 	// 	printf("tess");
// 	// }

// 	// printf("%s\n", dest1);

// //以下本物
// 	char dest2[10];
// 	memset(dest2, 'A', 9);

// 	int real_result = strlcpy(dest2, src, -1);
// 	// if(dest2[0] == 0)
// 	// {
// 	// 	printf("tess");
// 	// }
// 	printf("real%d\n", real_result);
// 	int i = 0;
// 	while(1)
// 	{
// 		write(1, &dest2[i], 1);
// 		if (dest2[i] == '\0')
// 		{
// 			// printf("%s\n", "null char");
// 			break;
// 		}
// 		i++;
// 	}
// 	// printf("real%s\n", dest2);

// 	write(1, "\n", 1);
// 	return (0);
// }