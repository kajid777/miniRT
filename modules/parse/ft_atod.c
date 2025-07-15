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

static bool	is_valid_number_format(const char *str)
{
	int	i;
	int	has_digit;
	int	dot_count;
	int	number_end;

	if (!str)
		return (false);
	i = 0;
	has_digit = 0;
	dot_count = 0;
	number_end = 0;
	skip_whitespace(str, &i);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			has_digit = 1;
			number_end = 0;
		}
		else if (str[i] == '.')
		{
			dot_count++;
			if (dot_count > 1)
				return (false);
			number_end = 0;
		}
		else if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		{
			number_end = 1;
		}
		else if (number_end)
		{
			return (false);
		}
		else
		{
			return (false);
		}
		i++;
	}
	return (has_digit);
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

double	ft_atod_safe(const char *str, t_world *world, t_parse_ctx *ctx)
{
	if (!is_valid_number_format(str))
	{
		if (ctx->tmp_object)
			free(ctx->tmp_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Invalid number format", 1);
	}
	return (ft_atod(str));
}
