/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:01:45 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:51:54 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int ch)
{
	if (ch >= 32 && ch <= 126)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// #include <ctype.h>
// int main() {
// 	char x;
//     printf("一文字を入力してください: ");
//     scanf("%c", &x);

//     if (ft_isprint(x)) {
//         printf("%c は表示される文字です。\n", x);
//     } else {
//         printf("%c は表示されない文字です。\n", x);
//     }

//     return 0;
// }
