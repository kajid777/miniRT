/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 18:59:41 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/04 22:06:08 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	digit;

	if (n == -2147483648)
	{
		write(fd, "-", 1);
		write(fd, "2147483648", 10);
	}
	else
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		digit = '0' + (n % 10);
		write(fd, &digit, 1);
	}
}

// #include<stdio.h>
// int main() {
//     int num = 7483648; // Test with different numbers here

//     printf("Original number: %d\n", num);
//     ft_putnbr_fd(num, 1);
//     printf("\n");

//     return 0;
// }