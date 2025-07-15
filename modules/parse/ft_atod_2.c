/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:30:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/15 20:30:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static bool	is_whitespace_char(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r');
}

static bool	process_number_char(char c, int *has_digit, int *dot_count, int *number_end)
{
	if (c >= '0' && c <= '9')
	{
		*has_digit = 1;
		*number_end = 0;
		return (true);
	}
	else if (c == '.')
	{
		(*dot_count)++;
		if (*dot_count > 1)
			return (false);
		*number_end = 0;
		return (true);
	}
	else if (is_whitespace_char(c))
	{
		*number_end = 1;
		return (true);
	}
	else if (*number_end)
		return (false);
	else
		return (false);
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
		if (!process_number_char(str[i], &has_digit, &dot_count, &number_end))
			return (false);
		i++;
	}
	return (has_digit);
}

double	ft_atod_safe(const char *str, t_world *world, t_parse_ctx *ctx)
{
	if (!is_valid_number_format(str))
	{
		free_ctx_and_world(world, ctx);
		print_err_and_exit("Invalid number format", 1);
	}
	return (ft_atod(str));
}
