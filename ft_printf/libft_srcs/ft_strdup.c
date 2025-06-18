/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 23:00:13 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/01 21:44:09 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

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

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*dest;
	int		i;

	len = ft_strlen(s1);
	dest = (char *)malloc(len * sizeof(char) + 1);
	if (dest == 0)
	{
		return (0);
	}
	i = 0;
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>

// int main() {
// 	char *x;
//     printf("文を入力してください: ");
//     scanf("%s", x);
// 	printf("%s\n", x);

// 	char* result;
// 	result = ft_strdup(x);
// 	printf("%s\n", result);
//     return 0;
// }
