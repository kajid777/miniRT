/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:16:42 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 22:37:11 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		s++;
		count++;
	}
	return (count);
}

// #include <stdio.h>
// int main() {
// 	char *x;
//     printf("文を入力してください: ");
//     scanf("%s", x);
// 	printf("%s\n", x);
// 	int result;
// 	result = ft_strlen(x);
// 	printf("%d\n", result);
//     return 0;
// }
// #include <stdio.h>
// int main() {

// 	int result;
// 	result = ft_strlen(NULL);
// 	printf("%d\n", result);
//     return 0;
// }