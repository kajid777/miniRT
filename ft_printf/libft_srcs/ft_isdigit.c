/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:01:23 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:54:19 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}
// #include <stdio.h>
// #include <ctype.h>
// int main(void){
// 	if (ft_isdigit('a')){
// 		printf("succcess\n");
// 	} else {
// 		printf("failed");
// 	}
// 	return (0);
// }