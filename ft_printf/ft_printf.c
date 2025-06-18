/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 16:15:17 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/09/08 20:59:08 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list *args, const char format)
{
	int	print_length;

	print_length = 0;
	if (format == 'c')
		print_length += ft_printchar(va_arg(*args, int));
	else if (format == 's')
		print_length += ft_printstr(va_arg(*args, char *));
	else if (format == 'p')
		print_length += ft_print_ptr(va_arg(*args, unsigned long long));
	else if (format == 'i' || format == 'd')
		print_length += ft_printnbr(va_arg(*args, int));
	else if (format == 'u')
		print_length += ft_print_unsigned(va_arg(*args, unsigned int));
	else if (format == 'x' || format == 'X')
		print_length = ft_print_hex(va_arg(*args, unsigned int), format);
	else if (format == '%')
		print_length += ft_printpercent();
	return (print_length);
}
//va_arg(*args, int);
//args++; I did not know what he said. i should ask him about it again.

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;
	int		print_length;

	i = 0;
	print_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			print_length += ft_formats(&args, str[i + 1]);
			i++;
		}
		else
			print_length += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (print_length);
}

// {
// 	unsigned long long test;
// 	test = va_arg(args, unsigned long long);
// 	printf("test:%llu", test);
// }