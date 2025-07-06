/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:11:29 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 18:37:19 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

double	solve_quadratic(double a, double b, double c)
{
	double	discriminant;
	double	t1;
	double	t2;
	double	sqrt_disc;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (-1);
	sqrt_disc = sqrt(discriminant);
	t1 = (-b - sqrt_disc) / (2 * a);
	t2 = (-b + sqrt_disc) / (2 * a);
	if (t1 > 0.001)
		return (t1);
	else if (t2 > 0.001)
		return (t2);
	return (-1);
}

static void	swap_if_needed(double *t1, double *t2)
{
	double	temp;

	if (*t1 > *t2)
	{
		temp = *t1;
		*t1 = *t2;
		*t2 = temp;
	}
}

static void	set_quadratic_results(double sqrt_disc, double a, double b,
		double *results)
{
	results[0] = (-b - sqrt_disc) / (2 * a);
	results[1] = (-b + sqrt_disc) / (2 * a);
	swap_if_needed(&results[0], &results[1]);
}

int	solve_quadratic_both(double a, double b, double c, double *results)
{
	double	discriminant;
	double	sqrt_disc;

	discriminant = pow(b, 2) - 4 * a * c;
	if (discriminant < 0)
		return (0);
	if (discriminant == 0)
	{
		results[0] = -b / (2 * a);
		results[1] = results[0];
		return (1);
	}
	sqrt_disc = sqrt(discriminant);
	set_quadratic_results(sqrt_disc, a, b, results);
	return (2);
}

t_vec3	get_light_dir(t_vec3 hitpoint, t_vec3 light_pos)
{
	t_vec3	light_dir;

	light_dir = vec_sub(light_pos, hitpoint);
	light_dir = vec_norm(light_dir);
	return (light_dir);
}
