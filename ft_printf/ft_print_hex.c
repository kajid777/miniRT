/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 16:19:58 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/08/25 19:37:41 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hex_len(unsigned	int num)
{
	int	len;

	len = 0;
	while (num != 0)
	{
		len++;
		num = num / 16;
	}
	return (len);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10 + 'a'), 1);
			if (format == 'X')
				ft_putchar_fd((num - 10 + 'A'), 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
		return (write(1, "0", 1));
	else
		ft_put_hex(num, format);
	return (ft_hex_len(num));
}

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }

// void	ft_put_hex(unsigned int num, const char format)
// {
// 	if (num >= 16)
// 	{
// 		ft_put_hex(num / 16, format);
// 		ft_put_hex(num % 16, format);
// 	}
// 	else
// 	{
// 		if (num <= 9)
// 			ft_putchar_fd((num + '0'), 1);
// 		else
// 		{
// 			if (format == 'x')
// 				ft_putchar_fd((num - 10 +'a'), 1);
// 			if (format == 'X')
// 				ft_putchar_fd((num - 10 + 'A'), 1);
// 		}
// 	}
// }
// int ft_print_hex(unsigned int num, const char format)
// {
// 	if (num == 0)
// 		return (write(1, "0", 1));
// 	else
// 		ft_put_hex(num, format);
// 	return (ft_hex_len(num));
// }
// int main(void)
// {
//     ft_print_hex(15, 'X');

//     return 0;
// }