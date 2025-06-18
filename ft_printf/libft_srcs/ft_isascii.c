/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:01:17 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:50:06 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int ch)
{
	if (ch >= 0 && ch <= 127)
		return (1);
	else
		return (0);
}

// #include <stdio.h>
// int main(void){
// 	if (ft_isascii('a')){
// 		printf("succcess\n");
// 	} else {
// 		printf("failed");
// 	}
// 	return (0);
// }