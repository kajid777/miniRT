/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:34:18 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 22:37:34 by dkajiwar         ###   ########.fr       */
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

// char	*ft_strrchr(const char *s, int c)
// {
// 	int	i;
// 	int	char_size;

// 	i = 0;
// 	c = change_into_char(c);
// 	char_size = ft_strlen(s);
// 	while (i <= char_size)
// 	{
// 		if (s[char_size - i] == c)
// 		{
// 			return ((char *)&s[char_size - i]);
// 		}
// 		i++;
// 	}
// 	return (0);
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

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	char_size;

	i = 0;
	char_size = ft_strlen(s);
	while (i <= char_size)
	{
		if ((unsigned char)s[char_size - i] == (unsigned char)c)
		{
			return ((char *)&s[char_size - i]);
		}
		i++;
	}
	return (0);
}
// #include<stdio.h>
// int main(){
// 	char source[] = "hello world!";
// 	int test;
// 	test = 101;
// 	char *result_location;
// 	result_location = ft_strrchr(source, 100);
// 	printf("found_place: %p\n", result_location);
// 	return 0;
// }