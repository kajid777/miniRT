/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:43:16 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:59:35 by dkajiwar         ###   ########.fr       */
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

// int	ft_memcmp(const void *s_1, const void *s_2, size_t n)
// {
// 	size_t		i;
// 	const char	*s1;
// 	const char	*s2;

// 	i = 0;
// 	s1 = s_1;
// 	s2 = s_2;
// 	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
// 	{
// 		if (s1[i] != s2[i])
// 		{
// 			return (s1[i] - s2[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

//updated

// int	ft_memcmp(const void *s_1, const void *s_2, size_t n)
// {
// 	size_t		i;
// 	const char	*s1;
// 	const char	*s2;

// 	i = 0;
// 	s1 = s_1;
// 	s2 = s_2;
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
int	ft_memcmp(const void *s_1, const void *s_2, size_t n)
{
	size_t		i;
	const char	*s1;
	const char	*s2;

	i = 0;
	s1 = s_1;
	s2 = s_2;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
		{
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		}
		i++;
	}
	return (0);
}
// #include<string.h>
// #include<stdio.h>
// int main(){
// 	char s[] = {-128, 0, 127, 0};
// 	char sCpy[] = {-128, 0, 127, 0};
// 	char s2[] = {0, 0, 127, 0};
// 	char s3[] = {0, 0, 42, 0};
// 	int a = ft_memcmp(s,s2,1);
// 	int b = memcmp(s,s2,1);
// 	printf("fake: %d\n", a);
// 	printf("real: %d\n", b);
// 	return 0;
// }