/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:14:55 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:14:55 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	ten_to(int pow)
{
	int		i;
	double	result;

	result = 1;
	i = 0;
	while (i < pow)
	{
		result /= 10;
		i++;
	}
	return (result);
}

double	dot_part(const char *str, int *len)
{
	int		i;
	double	result;

	i = 0;
	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	result *= ten_to(i);
	*len += i;
	return (result);
}

void	skip_whitespace(const char *str, int *i)
{
	while (str[*i] == '\t' || str[*i] == '\n' || str[*i] == '\v'
		|| str[*i] == '\f' || str[*i] == '\r' || str[*i] == ' ')
		(*i)++;
}

double	parse_sign(const char *str, int *i)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		if (str[*i] == '-')
		{
			(*i)++;
			return (-1);
		}
		(*i)++;
	}
	return (1);
}

double	ft_atod(const char *str)
{
	double	nbr;
	double	sign;
	int		i;

	nbr = 0;
	sign = 1;
	i = 0;
	skip_whitespace(str, &i);
	sign = parse_sign(str, &i);
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nbr *= 10;
		nbr += str[i] - '0';
		i++;
	}
	if (str[i] == '.')
	{
		i++;
		nbr += dot_part(&str[i], &i);
	}
	return (nbr * sign);
}
