/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_utils_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:38:02 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/06 19:09:21 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static void	set_hit_basic(t_hit *hit, t_vec3 hp, t_vec3 norm, t_vec3 light_dir)
{
	hit->hit_point = hp;
	hit->norm = norm;
	hit->light_dir = light_dir;
}

static void	set_hit_extra(t_hit *hit, double t, int is_hit, t_obj_type obj_type)
{
	hit->t = t;
	hit->is_hit = is_hit;
	hit->obj_type = obj_type;
}

static void	set_hit_object(t_hit *hit, void *hit_object)
{
	hit->hit_object = hit_object;
}

t_hit	new_hit(t_hit_params params)
{
	t_hit	new;

	set_hit_basic(&new, params.hp, params.norm, params.light_dir);
	set_hit_extra(&new, params.t, params.is_hit, params.obj_type);
	set_hit_object(&new, params.hit_object);
	return (new);
}

t_vec3	get_hitpoint(double t, t_vec3 d, t_vec3 origin)
{
	t_vec3	p;

	p = vec_add(origin, vec_mul_scalar(d, t));
	return (p);
}
