/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_calc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:14:13 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:14:16 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	solve_quadratic_both(double a, double b, double c,
		double results[2])
{
	double	discriminant;
	double	sqrt_discriminant;

	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	if (discriminant == 0)
	{
		results[0] = -b / (2 * a);
		return (1);
	}
	sqrt_discriminant = sqrt(discriminant);
	results[0] = (-b - sqrt_discriminant) / (2 * a);
	results[1] = (-b + sqrt_discriminant) / (2 * a);
	return (2);
}

void	calc_cylinder_vectors(t_vec3 d, t_vec3 o, t_cylinder cylinder,
		t_cylinder_calc *calc)
{
	t_vec3	w;
	double	d_parallel;
	double	w_parallel;

	w = vec_sub(o, cylinder.center);
	d_parallel = vec_dot(d, cylinder.direction);
	w_parallel = vec_dot(w, cylinder.direction);
	calc->d_perp = vec_sub(d, vec_mul_scalar(cylinder.direction, d_parallel));
	calc->w_perp = vec_sub(w, vec_mul_scalar(cylinder.direction, w_parallel));
}

int	check_cylinder_height(t_vec3 hp, t_cylinder cylinder)
{
	t_vec3	from_center;
	double	height_axis;

	from_center = vec_sub(hp, cylinder.center);
	height_axis = vec_dot(from_center, cylinder.direction);
	return (height_axis >= -cylinder.height / 2
		&& height_axis <= cylinder.height / 2);
}

int	solve_cylinder_quadratic(t_cylinder_calc calc, t_cylinder cylinder,
		double results[2])
{
	double	quad[3];

	quad[0] = vec_dot(calc.d_perp, calc.d_perp);
	quad[1] = 2.0 * vec_dot(calc.w_perp, calc.d_perp);
	quad[2] = vec_dot(calc.w_perp, calc.w_perp) - (cylinder.diameter / 2)
		* (cylinder.diameter / 2);
	if (quad[0] == 0)
	{
		if (quad[2] <= 0)
			return (-1);
		return (0);
	}
	return (solve_quadratic_both(quad[0], quad[1], quad[2], results));
}
