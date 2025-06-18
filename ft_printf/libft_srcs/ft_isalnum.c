/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:01:00 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:47:54 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_isdigit(int ch)
// {
// 	if (ch >= '0' && ch <= '9')
// 		return (1);
// 	else
// 		return (0);
// }

// int	ft_isalpha(int ch)
// {
// 	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
// 		return (1);
// 	else
// 		return (0);
// }

int	ft_isalnum(int ch)
{
	if (ft_isalpha(ch) || ft_isdigit(ch))
		return (1);
	else
		return (0);
}

//test
// #include <stdio.h>
// int main() {
//     // int x;
//     // printf("一文字を入力してください: ");
//     // scanf("%d", &x);
// 	// printf("%d¥n", x);

// 	char x;
//     printf("一文字を入力してください: ");
//     scanf("%c", &x);

//     if (ft_isalnum(x)) {
//         printf("%c はアルファベットか数字です。\n", x);
//     } else {
//         printf("%c はアルファベットでも数字でもありません。\n", x);
//     }

//     return 0;
// }