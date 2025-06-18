/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:36:10 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 21:54:14 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	change_into_char(int c)
// {
// 	while (c < -128 || 127 < c)
// 	{
// 		if (c < -128)
// 			c += 256;
// 		if (127 < c)
// 			c -= 256;
// 	}
// 	return (c);
// }
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if ((s1[i] != s2[i]) || (!s1[i]) || (!s2[i]))
		{
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		}
		i++;
	}
	return (0);
}

// int main()
// {
// 	char *s1 = "";
// 	char *s2 = "AAAAAA";

// 	printf("my ans = %d\n", ft_strncmp(s1, s2, 6));
// 	printf("ans = %d\n", strncmp(s1, s2, 6));
// }
//updated1

// int ft_strncmp(const char *s1, const char *s2, size_t n)
// {
//     // nが0以下の場合、何も比較できないので0を返す
//     if (n == 0) {
//         return 0;
//     }

//     // s1とs2のどちらかがNUL文字に達するか、nバイトを比較するまでループ
//     while (*s1 != '\0' && *s2 != '\0' && n > 1) {
//         // 文字が異なる場合、その差を返す
//         if (*s1 != *s2) {
//             return (*s1 - *s2);
//         }
//         // 次の文字に進む
//         s1++;
//         s2++;
//         n--;
//     }

//     // nバイトを比較し、それでも等しい場合は0を返す
//     if (n > 0) {
//         return (*s1 - *s2);
//     }

//     // nバイト分比較し終わっても等しい場合も0を返す
//     return 0;
// }
//updated2

// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (s1[i] != s2[i])
// 		{
// 			return (s1[i] - s2[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// #include<stdio.h>
// int main(){
// 	char s1[] = "hello world!";
// 	char s2[] = "hdllo world!";
// 	int dif;
// 	dif = ft_strncmp(s1,s2,3);
// 	printf("difference: %d\n", dif);
// 	return 0;
// }

// #include "string.h"
// #include<stdio.h>

// int	main(void)
// {
// 	char *str = "libft-test-tokyo";
// 	char *cmp = "libft-test-tokyo";
// 	int	len = strlen(str);

// 	char *cmp2 = calloc(10, 1);
// 	strlcpy(cmp2, "libft", 10);
// 	printf("%s\n", str);
// 	printf("%s\n", cmp2);

// 	cmp2[5] = -42;
// 	int a = ft_strncmp(str, cmp2, len);
// 	int b = strncmp(str, cmp2, len);
// 	printf("fake_%d\n", a);
// 	printf("real_%d\n", b);
// }