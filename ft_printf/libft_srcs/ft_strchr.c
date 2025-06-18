/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:30:28 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 22:21:38 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// static int	change_into_char(int c)
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

// char	*ft_strchr(const char *s, int c)
// {
// 	int	i;
// 	int	char_size;

// 	i = 0;
// 	char_size = ft_strlen(s);
// 	c = change_into_char(c);
// 	while (i <= char_size)
// 	{
// 		if (s[i] == c)
// 		{
// 			return ((char *)&s[i]);
// 		}
// 		i++;
// 	}
// 	return ((char *)(0));
// }

// static int	change_into_char(int c)
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

char	*ft_strchr(const char *s, int c)
{
	int	i;
	int	char_size;

	i = 0;
	char_size = ft_strlen(s);
	while (i <= char_size)
	{
		if ((unsigned char)s[i] == (unsigned char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	return ((char *)(0));
}
//ver01

// /* 18 */ ASSERT_EQ_STR(ft_strchr(s, 'l' + 256), strchr(s, 'l' + 256));
// 	/* 19 */ ASSERT_EQ_STR(ft_strchr(s, 'i' + 256), strchr(s, 'i' + 256));
// 	/* 20 */ ASSERT_EQ_STR(ft_strchr(s, 'l' - 256), strchr(s, 'l' - 256));
// 	/* 21 */ ASSERT_EQ_STR(ft_strchr(s, 'i' - 256), strchr(s, 'i' - 256));
// #include<string.h>
// #include<stdio.h>
// int main(){
// 	char *s = "libft-test-tokyo";
// 	// int test;
// 	// test = 101;
// 	// // char *fakeresult_location;
// 	// // char *realresult_location;
// 	// // fakeresult_location = ft_strchr(s, 'l' + 256);
// 	// realresult_location = strchr(s, 'l' + 256);
// 	// printf("found_place: %p\n", fakeresult_location);
// 	// realresult_location = strchr(s, 'l');
// 	// printf("found_place: %p\n", fakeresult_location);
// 	// printf("found_place: %p\n", realresult_location);
// 	//int i = 0;
// 	// while (s[i] != '\0')
// 	// {
// 	// 	printf("%d", i);
// 	// 	printf("found_place: %p\n", &s[i]);
// 	// 	i++;
// 	// }
// 	// printf("found_place: %p\n", &s[i]);
// 	// char c = 'l' + 256;
// 	// printf("%c\n", c);
// 	char *result_location;

// 	result_location = ft_strchr(s, 'l' - 256);
// 	printf("found_place: %p\n", result_location);
// 	result_location = ft_strchr(s, 'l');
// 	printf("found_place: %p\n", result_location);
// 	return 0;
// }