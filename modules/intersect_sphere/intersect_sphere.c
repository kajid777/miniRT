/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_sphere.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:08:45 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 18:17:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static double	calc_sphere_quadratic(t_vec3 dir, t_vec3 origin,
		t_sphere sphere)
{
	t_vec3	oc;
	double	r;
	double	j_a;
	double	j_b;
	double	j_c;

	oc = vec_sub(origin, sphere.center);
	r = sphere.diameter / 2;
	j_a = vec_dot(dir, dir);
	j_b = 2 * vec_dot(dir, oc);
	j_c = vec_dot(oc, oc) - pow(r, 2);
	return (solve_quadratic(j_a, j_b, j_c));
}

static t_hit	sphere_intersection_calc(t_vec3 dir, t_vec3 origin,
		t_sphere *sphere, t_vec3 light_pos)
{
	double	t;
	t_vec3	hp;
	t_vec3	light_dir;

	t = calc_sphere_quadratic(dir, origin, *sphere);
	if (t == -1)
		return (new_hit((t_hit_params){vec_new(0, 0, 0),
				vec_new(0, 0, 0), vec_new(0, 0, 0), -1, 0, NONE, NULL}));
	hp = get_hitpoint(t, dir, origin);
	light_dir = get_light_dir(hp, light_pos);
	return (new_hit((t_hit_params){hp, get_norm_sphere(hp, sphere->center),
			light_dir, t, 1, SPHERE, sphere}));
}

t_vec3	get_norm_sphere(t_vec3 hit_point, t_vec3 center)
{
	return (vec_norm(vec_sub(hit_point, center)));
}

t_hit	intersect_sphere(t_vec3 dir, t_vec3 origin, t_sphere *sphere,
		t_vec3 light_pos)
{
	return (sphere_intersection_calc(dir, origin, sphere, light_pos));
}
