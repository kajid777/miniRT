/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:51:57 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 17:43:49 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void	bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*p;

// 	i = 0;
// 	p = s;
// 	while (i < n)
// 	{
// 		p[i] = 0;
// 		i++;
// 	}
// }

void	*ft_calloc(size_t count, size_t size)
{
	size_t		*tmp_dest;
	size_t		malloc_size;
	void		*dest;

	if (count && size && count > (4294967295 / size))
		return (NULL);
	malloc_size = count * size;
	tmp_dest = (size_t *)malloc(malloc_size);
	if (tmp_dest == 0)
		return (0);
	ft_bzero(tmp_dest, malloc_size);
	dest = (void *)tmp_dest;
	return (dest);
}

//u need to deal with overflow.
//test
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//     int* arr;
// 	arr = (int *)ft_calloc(5, sizeof(int));

// 	for (int i = 0; i < 5; i++) {
// 		printf("%d です\n", arr[i]);
// 	}
//     return 0;
// }
// //mallocの仕様が見たい
// int main(){
// 	void* p = malloc(200);
// 	int size_allocated;

// 	size_allocated = sizeof(p);

// 	printf("割り当てられたメモリのサイズは%d です\n", size_allocated);
// 	return 0;
// }

// int main(){
// 	// int arr[] = {1,2,3,4};

// 	int size_allocated = sizeof(void);

// 	printf("割り当てられたメモリのサイズは%d です\n", size_allocated);
// 	return 0;
// }