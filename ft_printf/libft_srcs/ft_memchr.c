/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:39:02 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 22:31:55 by dkajiwar         ###   ########.fr       */
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

// void	*ft_memchr(const void *s, int c, size_t n)
// {
// 	size_t		i;
// 	size_t		char_size;
// 	const unsigned char	*str;

// 	str = s;
// 	char_size = ft_strlen(s);
// 	i = 0;
// 	c = change_into_char(c);
// 	while (i <= char_size && i < n)
// 	{
// 		if (str[i] == c)
// 		{
// 			return ((void *)&s[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

//updated
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const char			*str;

	str = (const char *)s;
	i = 0;
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((void *)&str[i]);
		i++;
	}
	return (0);
}
// #include<string.h>
// #include<stdio.h>
// int main(){
// 	// s = "libft-test-tokyo\0\0\0acdfg\0\0\0\0\0"
// 	char *s = calloc(30, sizeof(char));
// 	memcpy(s, "libft-test-tokyo", 17);
// 	memcpy(s + 20, "acdfg", 5);

// 	char *result_location;
// 	result_location = memchr(s, 'a', 30);
// 	printf("real-found_place: %p\n", result_location);
// 	result_location = ft_memchr(s, 'a', 30);
// 	printf("fake-found_place: %p\n", result_location);
// 	return 0;
// }