/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:08:26 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 18:18:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static int	check_cylinder_height(t_vec3 hp, t_cylinder cylinder)
{
	t_vec3	from_center;
	double	height_axis;

	from_center = vec_sub(hp, cylinder.center);
	height_axis = vec_dot(from_center, cylinder.direction);
	return (height_axis >= -cylinder.height / 2
		&& height_axis <= cylinder.height / 2);
}

static t_hit	process_cylinder_intersect(double t, t_cylinder_params params)
{
	t_vec3	hp;

	if (t <= 0)
		return (new_hit((t_hit_params){vec_new(0, 0, 0),
				vec_new(0, 0, 0), vec_new(0, 0, 0),
				INFINITY, 0, NONE, NULL}));
	hp = get_hitpoint(t, params.d, params.o);
	if (!check_cylinder_height(hp, params.cylinder))
		return (new_hit((t_hit_params){vec_new(0, 0, 0),
				vec_new(0, 0, 0), vec_new(0, 0, 0),
				INFINITY, 0, NONE, NULL}));
	return (new_hit((t_hit_params){hp, get_norm_cylinder(hp, params.cylinder),
			get_light_dir(hp, params.light_pos), t, 1, CYLINDER, NULL}));
}

t_hit	select_best_cylinder_hit(double t1, double t2, int num_solutions,
		t_cylinder_params params)
{
	t_hit	hit1;
	t_hit	hit2;

	hit1 = process_cylinder_intersect(t1, params);
	if (num_solutions == 1)
		return (hit1);
	hit2 = process_cylinder_intersect(t2, params);
	if (hit1.is_hit && hit2.is_hit)
	{
		if (hit1.t < hit2.t)
			return (hit1);
		return (hit2);
	}
	if (hit1.is_hit)
		return (hit1);
	return (hit2);
}

t_hit	get_cylinder_side_hit(t_vec3 d, t_vec3 o, t_cylinder cylinder,
		t_vec3 light_pos)
{
	t_cylinder_calc		calc;
	double				results[2];
	int					num_solutions;
	t_cylinder_params	params;

	params.d = d;
	params.o = o;
	params.cylinder = cylinder;
	params.light_pos = light_pos;
	calc_cylinder_vectors(d, o, cylinder, &calc);
	num_solutions = solve_cylinder_quadratic(calc, cylinder, results);
	if (num_solutions == 0)
		return (new_hit((t_hit_params){vec_new(0, 0, 0), vec_new(0, 0, 0),
				vec_new(0, 0, 0), INFINITY, 0, NONE, NULL}));
	if (num_solutions == -1)
		return (process_cylinder_intersect(0, params));
	return (select_best_cylinder_hit(results[0], results[1], num_solutions,
			params));
}
