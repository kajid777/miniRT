/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_shadow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:38:02 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/06 19:09:14 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

int	is_in_shadow(t_vec3 point, t_vec3 light_pos, t_world *world)
{
	t_vec3	shadow_ray_dir;
	t_vec3	shadow_ray_origin;
	t_hit	shadow_hit;
	double	light_distance;
	double	epsilon;

	epsilon = 0.001;
	light_distance = vec_length(vec_sub(light_pos, point));
	shadow_ray_dir = vec_norm(vec_sub(light_pos, point));
	shadow_ray_origin = vec_add(point, vec_mul_scalar(shadow_ray_dir, epsilon));
	shadow_hit = find_closest_intersection(shadow_ray_origin, shadow_ray_dir,
			world);
	if (shadow_hit.is_hit && shadow_hit.t > 0 && shadow_hit.t < light_distance)
		return (1);
	return (0);
}
