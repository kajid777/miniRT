/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 16:15:22 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/07 19:14:25 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

// static void	reverse(char *str, int length)
// {
// 	int		start;
// 	int		end;
// 	char	temp;

// 	start = 0;
// 	end = length - 1;
// 	while (start < end)
// 	{
// 		temp = str[start];
// 		str[start] = str[end];
// 		str[end] = temp;
// 		start++;
// 		end--;
// 	}
// }

// static int	count_digits(int num)
// {
// 	int	count;

// 	if (num == 0)
// 		return (1);
// 	count = 0;
// 	while (num != 0)
// 	{
// 		count++;
// 		num /= 10;
// 	}
// 	return (count);
// }

// static void dealwith_negative(int *isNegative, int *num)
// {
// 	*isNegative = 1;
// 	*num = -1 * (*num);
// }
// static int	appendDigits(int num, char *dest, int index)
// {
// 	int	i;
// 	int	isNegative;
// 	int	rem;

// 	i = index;
// 	isNegative = 0;
// 	if (num == 0)
// 	{
// 		dest[i++] = '0';
// 		return (i);
// 	}
// 	if (num < 0)
// 		dealwith_negative(&isNegative, &num);
// 	while (num != 0)
// 	{
// 		rem = num % 10;
// 		dest[i++] = rem + '0';
// 		num = num / 10;
// 	}
// 	if (isNegative)
// 		dest[i++] = '-';
// 	reverse(dest + index, i - index);
// 	return (i);
// }
// // char *deal_with_intmin()
// // {
// // 	char *dest;
// // 	dest = 
// // }
// // #include<stdio.h>

// char	*ft_itoa(int num)
// {
// 	int		max_length; 
// 	int		index;
// 	char	*dest;

// 	if (num == -2147483648)
// 	{
// 		dest = malloc(12);
// 		dest[0] = '-';
// 		dest[1] = '2';
// 		dest[2] = '1';
// 		dest[3] = '4';
// 		dest[4] = '7';
// 		dest[5] = '4';
// 		dest[6] = '8';
// 		dest[7] = '3';
// 		dest[8] = '6';
// 		dest[9] = '4';
// 		dest[10] = '8';
// 		dest[11] = '\0';
// 		return dest;
// 	}
// 		// return ("-2147483648");
// 	max_length = count_digits(num) + 1;
// 	dest = (char *)malloc((max_length + 1) * sizeof(char));
// 	if (dest == NULL)
// 		return (0);
// 	index = appendDigits(num, dest, 0);
// 	dest[index] = '\0';
// 	return (dest);
// }
// Determine the maximum possible length of the string
// +1 for possible negative sign
// +1 for null terminator
// Null-terminate the string
// ver00

// static void	reverse(char *str, int length)
// {
// 	int		start;
// 	int		end;
// 	char	temp;

// 	start = 0;
// 	end = length - 1;
// 	while (start < end)
// 	{
// 		temp = str[start];
// 		str[start] = str[end];
// 		str[end] = temp;
// 		start++;
// 		end--;
// 	}
// }

// static int	count_digits(int num)
// {
// 	int	count;

// 	if (num == 0)
// 		return (1);
// 	count = 0;
// 	while (num != 0)
// 	{
// 		count++;
// 		num /= 10;
// 	}
// 	return (count);
// }

static int	count_digits(int num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	if (num < 0)
		count++;
	while (num != 0)
	{
		count++;
		num /= 10;
	}
	return (count);
}

// static void dealwith_negative(int *isNegative, int *num)
// {
// 	*isNegative = 1;
// 	*num = -1 * (*num);
// }
// static int	appendDigits(int num, char *dest, int index)
// {
// 	int	i;
// 	int	isNegative;
// 	int	rem;

// 	i = index;
// 	isNegative = 0;
// 	if (num == 0)
// 	{
// 		dest[i++] = '0';
// 		return (i);
// 	}
// 	if (num < 0)
// 		dealwith_negative(&isNegative, &num);
// 	while (num != 0)
// 	{
// 		rem = num % 10;
// 		dest[i++] = rem + '0';
// 		num = num / 10;
// 	}
// 	if (isNegative)
// 		dest[i++] = '-';
// 	reverse(dest + index, i - index);
// 	return (i);
// }
// // char *deal_with_intmin()
// // {
// // 	char *dest;
// // 	dest = 
// // }
// // #include<stdio.h>

// char	*ft_itoa(int num)
// {
// 	int		max_length; 
// 	int		index;
// 	char	*dest;

// 		// return ("-2147483648");
// 	max_length = count_digits(num) + 1;
// 	dest = (char *)malloc((max_length + 1) * sizeof(char));
// 	if (dest == NULL)
// 		return (0);
// 	if (num == -2147483648)
// 	{
// 		dest[10] = '-';
// 		dest[9] = '2';
// 		num = 147483648;
// 	}
// 	index = appendDigits(num, dest, 0);
// 	dest[index] = '\0';
// 	return (dest);
// }
// //ver01

static void	ft_itoains(long n, char *str, int *i)
{
	if (n >= 10)
	{
		ft_itoains(n / 10, str, i);
		ft_itoains(n % 10, str, i);
	}
	else
		str[(*i)++] = n + '0';
}

// static size_t	ft_itoalen(int n)
// {
// 	size_t	len;

// 	len = 0;
// 	if (n == 0)
// 		return (1);
// 	if (n < 0)
// 		len = len + 1;
// 	while (n)
// 	{
// 		n = n / 10;
// 		len ++;
// 	}
// 	return (len);
// }

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = malloc(sizeof(char) * (count_digits(n) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (n == -2147483648)
	{
		str[i++] = '-';
		str[i++] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		str[i++] = '-';
		n *= -1;
	}
	ft_itoains(n, str, &i);
	str[i] = '\0';
	return (str);
}

// Determine the maximum possible length of the string
// +1 for possible negative sign
// +1 for null terminator
// Null-terminate the string
// ver01

// int main() {
//     int num = -2147483648;
//     char* str = ft_itoa(num);
//     printf("String representation of %d: %s\n", num, str);
//     free(str); // Free the allocated memory
// 	system("leaks a.out");
//     return 0;
// }
