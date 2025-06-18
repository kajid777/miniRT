/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:47:41 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 22:42:03 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	int		j;

// 	i = 0;
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		j = 0;
// 		while (haystack[i + j] == needle[j])
// 		{
// 			j++;
// 			if (needle[j] == '\0')
// 			{
// 				return ((char *)&haystack[i]);
// 			}
// 		}
// 		i++;
// 	}
// 	return (0);
// }
//updated0

// static int	ft_memcmp(const void *s_1, const void *s_2, size_t n)
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

// static int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < n)
// 	{
// 		if (s1[i] != s2[i])
// 		{
// 			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// 		}
// 		i++;
// 	}
// 	return (0);
// }
//update1

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	// int		j;
// 	int		needle_len;

// 	i = 0;
// 	needle_len = ft_strlen(needle);
// 	if (ft_strlen(needle) == 0)
// 		return ((char *)haystack);
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		if(!(ft_strncmp(&haystack[i], needle, needle_len)))
// 		{
// 			return (char *)&haystack[i];
// 		}
// 		i++;
// 	}
// 	return (0);
// }
//update2 using strncmp
// char *str = "libft-test-tokyo";
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	needle_len;

	if (haystack == 0 && len == 0)
		return (0);
	i = 0;
	needle_len = ft_strlen(needle);
	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i < len && i + needle_len <= len)
	{
		if (!(ft_strncmp(&haystack[i], needle, needle_len)))
		{
			return ((char *)&haystack[i]);
		}
		i++;
	}
	return (0);
}
//update3 using strncmp

// char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
// {
// 	size_t	i;
// 	// int		j;
// 	int		needle_len;

// 	i = 0;
// 	needle_len = ft_strlen(needle);
// 	if (ft_strlen(needle) == 0)
// 		return ((char *)haystack);
// 	while (haystack[i] != '\0' && i < len)
// 	{
// 		if(!(ft_memcmp(&haystack[i], needle, needle_len)))
// 		{
// 			return (char *)&haystack[i];
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// #include<string.h>
// #include<stdio.h>
// int main(){
// 	char *str = "libft-test-tokyo";
// 	int	len = strlen(str);
// 	char *fakeresult_location;
// 	char *realresult_location;
// 	// printf("str:%p\n", str);

// 	// fakeresult_location = ft_strnstr(NULL, "1", 0);
// 	realresult_location = strnstr(NULL, "1", 0);
// 	// printf("fake-found_place: %p\n", fakeresult_location);
// 	printf("real-found_place: %p\n", realresult_location);

// 	// for (int i = 0; i < len; i++)
// 	// {
// 	// 	fakeresult_location = ft_strnstr(str, "libft", i);
// 	// 	realresult_location = strnstr(str, "libft", i);
// 	// 	printf("%d\n", i);
// 	// 	printf("fake-found_place: %p\n", fakeresult_location);
// 	// 	printf("real-found_place: %p\n", realresult_location);
// 	// }

// // // 	//int i = 0;
// // // 	// while (s[i] != '\0')
// // // 	// {
// // // 	// 	printf("%d", i);
// // // 	// 	printf("found_place: %p\n", &s[i]);
// // // 	// 	i++;
// // // 	// }
// // // 	// printf("found_place: %p\n", &s[i]);
// // // 	// char c = 'l' + 256;
// // // 	// printf("%c\n", c)

// // // 	char *result_location;

// // // 	result_location = ft_strchr(s, 'l' - 256);
// // // 	printf("found_place: %p\n", result_location);
// // // 	result_location = ft_strchr(s, 'l');
// // // 	printf("found_place: %p\n", result_location);
// // // 	return 0;
// }