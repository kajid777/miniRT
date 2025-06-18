/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 22:51:20 by dkajiwar          #+#    #+#             */
/*   Updated: 2024/05/06 18:11:01 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(char x)
{
	if (x == '\t')
		return (1);
	if (x == '\n')
		return (1);
	if (x == '\v')
		return (1);
	if (x == '\f')
		return (1);
	if (x == '\r')
		return (1);
	if (x == ' ')
		return (1);
	return (0);
}

static int	overflowl(int sign, long l, char next)
{
	if (sign == 1)
		if (LONG_MAX / 10 < l
			|| (LONG_MAX / 10 == l && LONG_MAX % 10 <= next - '0'))
			return (1);
	if (sign == -1)
		if (LONG_MIN / -10 < l
			|| (LONG_MIN / -10 == l && LONG_MIN % -10 * -1 <= next - '0'))
			return (-1);
	return (0);
}

// int	judge_minus_plus(char str, int *signature)
// {
// 	if (str == '-')
// 	{
// 		*signature = -1 * (*signature);
// 	}
// 	if (str == '-' || str == '+')
// 	{
// 		return (1);
// 	}
// 	else
// 	{
// 		return (0);
// 	}
// }

// // int	ft_atoi(const char *str)
// // {
// // 	int	signature;
// // 	int	result;

// // 	signature = 1;
// // 	result = 0;
// // 	while (*str != '\0')
// // 	{
// // 		while (ft_isspace(*str))
// // 			str++;
// // 		while (judge_minus_plus(*str, &signature))
// // 			str++;
// // 		while ('0' <= *str && *str <= '9')
// // 		{
// // 			result = (int)(*str++ - '0') + result * 10;
// // 		}
// // 		if (!('0' <= *str && *str <= '9'))
// // 			return (result * signature);
// // 	}
// // 	return (0);
// // }
// //ver00

int	ft_atoi(const char *str)
{
	long	ret;
	int		sign;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	while (*str)
	{
		if ('0' <= *str && *str <= '9')
		{
			if (overflowl(sign, ret, *str) == 1)
				return ((int)LONG_MAX);
			if (overflowl(sign, ret, *str) == -1)
				return ((int)LONG_MIN);
			ret = ret * 10 + (long)(*str - '0');
			str++;
		}
		else
			break ;
	}
	return ((int)(ret * sign));
}

// //ver01

// // #include <stdio.h>
// // int main(void)
// // {
// // 	int number;
// // 	char test[] = " ab---+--+0124567";
// // 	number = ft_atoi(test);
// // 	printf("Converted integer: %d\n", number);
// // 	//Test Case 1: Positive number
// //     char test_case_1[] = "123";
// //     int result_1 = ft_atoi(test_case_1);
// //     printf("Test Case 1 Result: %d\n", result_1); // Expected Output: 123

// //     // Test Case 2: Negative number
// //     char test_case_2[] = "---456";
// //     int result_2 = ft_atoi(test_case_2);
// //     printf("Test Case 2 Result: %d\n", result_2); // Expected Output: -456

// //     // Test Case 3: Leading whitespace and sign
// //     char test_case_3[] = "   +789";
// //     int result_3 = ft_atoi(test_case_3);
// //     printf("Test Case 3 Result: %d\n", result_3); // Expected Output: 789

// //     // Test Case 4: Trailing characters after valid number
// //     char test_case_4[] = "987abc";
// //     int result_4 = ft_atoi(test_case_4);
// //     printf("Test Case 4 Result: %d\n", result_4); // Expected Output: 987

// //     // Test Case 5: Empty string
// //     char test_case_5[] = "";
// //     int result_5 = ft_atoi(test_case_5);
// //     printf("Test Case 5 Result: %d\n", result_5); // Expected Output: 0
// // 	return 0;
// // }

// #include<stdio.h>
// int	main(void)
// {
// 	/* 20. LONG_MAX */
// 	// int a = atoi("9223372036854775807");
// 	// int b = ft_atoi("9223372036854775807");
// 	// printf("%d\n",a);
// 	// printf("%d\n",b);
// 	/* 27. LONG_MAX + 1 */ 
// 	// long a = atoi("9223372036854775808");
// 	// long b = ft_atoi("9223372036854775808");
// 	// printf("%ld\n",a);
// 	// printf("%ld\n",b);
// 	// /* 28. LONG_MIN - 1 */
// 	// long a = atoi("-9223372036854775809");
// 	// long b = ft_atoi("-9223372036854775809");
// 	// printf("%ld\n",a);
// 	// printf("%ld\n",b);
// 	// printf("%d\n",-1112% -10);
// 	return (0);
// }