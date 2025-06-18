/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 20:30:30 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 21:26:29 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	d = dst;
	s = src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
// #include <stdio.h>
// int main() {
//     char src[] = "Hello, World!";
//     char dest[50];

//     // srcからdestにデータをコピーする
//     ft_memcpy(dest, src, sizeof(src));

//     // コピー後のdestを出力
//     printf("dest: %s\n", dest);

//     return 0;
// }