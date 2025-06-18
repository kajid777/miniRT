/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:41:08 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/01 21:11:16 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (d < s)
	{
		while (i < n)
		{
			d[i] = s[i];
			i++;
		}
	}
	if (s < d)
	{
		while (i < n)
		{
			d[n - i - 1] = s[n - i - 1];
			i++;
		}
	}
	return (dst);
}

// #include<stdio.h>
// int main() {
//     char src[] = "Hello, World!";
//     char dest[50];
//     // srcからdestにデータをコピーする
//     // ft_memmove(dest, src, sizeof(src));
// 	ft_memmove(dest, src, 2);
//     // コピー後のdestを出力
//     printf("dest: %s\n", dest);
//     return 0;
// }
