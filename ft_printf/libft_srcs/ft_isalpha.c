/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:01:09 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:49:03 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int ch)
{
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main() {
//     char ch;
//     printf("一文字を入力してください: ");
//     scanf("%c", &ch);

//     if (ft_isalpha(ch)) {
//         printf("%c はアルファベットです。\n", ch);
//     } else {
//         printf("%c はアルファベットではありません。\n", ch);
//     }
//     return 0;
// }