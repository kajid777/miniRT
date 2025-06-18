/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 21:18:45 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 22:32:20 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include<stdio.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	copy_limit;
	size_t	original_dst_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (dstsize + src_len);
	original_dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (original_dst_len >= dstsize)
		return (dstsize + src_len);
	i = 0;
	copy_limit = dstsize - original_dst_len - 1;
	j = 0;
	while (src[j] != '\0' && j < copy_limit)
	{
		dst[original_dst_len + j] = src[j];
		j++;
	}
	dst[original_dst_len + j] = '\0';
	return (original_dst_len + src_len);
}
// by me
// if (!(dstsize == 0 || (size_t)ft_strlen(dst) > dstsize))
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aestevam <aestevam@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 00:01:08 by aestevam          #+#    #+#             */
/*   Updated: 2021/10/05 08:06:54 by aestevam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	j;

// 	i = 0;
// 	j = 0;
// 	while (i < dstsize && dst[i])
// 	{
// 		i++;
// 	}
// 	while ((i + j + 1) < dstsize && src[j])
// 	{
// 		dst[i + j] = src[j];
// 		j++;
// 	}
// 	if (i != dstsize)
// 	{
// 		dst[i + j] = '\0';
// 	}
// 	return (i + ft_strlen(src));
// }
//i found it on web.

// #include<stdio.h>
// #include<string.h>
// int main(void)
// {
// 	char fakedest[30];
// 	memset(fakedest, 0, 30);
// 	char realdest[30];
// 	memset(realdest, 0, 30);
// 	char * src = (char *)"AAAAAAAAA";

// 	memset(fakedest, 'C', 5);
// 	memset(realdest, 'C', 5);
// 	/* 5 */ 
// 	if (ft_strlcat(fakedest, src, -1) == 14)
// 		printf("passed\n");
// 	printf("fakedest:%s", fakedest);
// 	// strlcat(realdest, src, -1);
// 	// printf("realdest:%s", realdest);

// }

// #include<string.h>
// int	main(void)
// {
// 	char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));

// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}

// 	/* 19 */
// 	ft_strlcat(NULL, src1, 0);
// 	strlcat(NULL, src2, 0);
// }

// #include<string.h>
// int	main(void)
// {
// 	char *dst1 = calloc(100, sizeof(char));
// 	char *dst2 = calloc(100, sizeof(char));
// 	/* 1 */ ft_strlcat(dst1, "", 100), strlcat(dst2, "", 100);

// 	/* 3 */ ft_strlcat(dst1, "hello", 100), strlcat(dst2, "hello", 100);

// 	/* 5 */ ft_strlcat(dst1, "world", 100), strlcat(dst2, "world", 100);

// 	char *src1 = calloc(100, sizeof(char));
// 	char *src2 = calloc(100, sizeof(char));
// 	for (int i = 0; i < 99; i++)
// 	{
// 		src1[i] = i + 1;
// 		src2[i] = i + 1;
// 	}
// 	/* 7 */ ft_strlcat(dst1, src1, 0);
// 	strlcat(dst2, src2, 0);
// 	/* 9 */ft_strlcat(dst1, src1, 10);
// 	strlcat(dst2, src2, 10);

// 	/* 11 */ ft_strlcat(dst1, src1, 50);
// 	strlcat(dst2, src2, 50);

// 	/* 13 */ ft_strlcat(dst1, src1, 100);
// 	strlcat(dst2, src2, 100);

// 	/* 15 */ ft_strlcat(dst1, src1, 10);
// 	strlcat(dst2, src2, 10);

// 	/* 17 */ ft_strlcat(dst1, src1, 100);
// 	strlcat(dst2, src2, 100);
// 	printf("fakedest:%s\n", dst1);
// 	printf("realdest:%s\n", dst2);

// 	/* 19 */ int fakeretur = ft_strlcat(NULL, src1, 0);
// 	int realretur =strlcat(NULL, src2, 0);

// 	printf("fake-return :%d\n", fakeretur);
// 	printf("real-return :%d\n", realretur);

// 	printf("fakedest:%s\n", dst1);
// 	printf("realdest:%s\n", dst2);
// }