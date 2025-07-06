/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:54:45 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 12:54:46 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static t_hit	plane_intersection_calc(t_vec3 dir, t_vec3 origin, 
		t_plane plane, t_vec3 light_pos, t_plane *plane_ptr)
{
	double	t;
	t_vec3	hp;
	t_vec3	norm;
	double	denominator;

	norm = vec_norm(plane.normal_vector);
	denominator = vec_dot(dir, norm);
	if (fabs(denominator) < DBL_EPSILON)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0, NONE, NULL));
	t = vec_dot(vec_sub(plane.point, origin), norm) / denominator;
	if (t <= 0)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0, NONE, NULL));
	hp = get_hitpoint(t, dir, origin);
	if (denominator < 0)
		return (new_hit(hp, norm, get_light_dir(hp, light_pos), t, 1, PLANE, plane_ptr));
	else
		return (new_hit(hp, vec_mul_scalar(norm, -1), 
				get_light_dir(hp, light_pos), t, 1, PLANE, plane_ptr));
}

t_hit	intersect_plane(t_vec3 dir, t_vec3 origin, t_plane plane, 
		t_vec3 light_pos, t_plane *plane_ptr)
{
	return (plane_intersection_calc(dir, origin, plane, light_pos, plane_ptr));
}
