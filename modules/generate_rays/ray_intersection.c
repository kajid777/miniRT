/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:07:48 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 18:19:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

static t_hit	check_sphere_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit		current_hit;
	t_hit		closest_sphere_hit;
	t_sphere	*current_sphere;
	double		closest_sphere_t;

	closest_sphere_hit.is_hit = 0;
	closest_sphere_t = closest_t;
	current_sphere = world->sphere;
	while (current_sphere)
	{
		current_hit = intersect_sphere(ray_dir, ray_origin,
				current_sphere, world->light->position);
		if (current_hit.is_hit && current_hit.t > 0.001
			&& current_hit.t < closest_sphere_t)
		{
			closest_sphere_t = current_hit.t;
			closest_sphere_hit = current_hit;
		}
		current_sphere = current_sphere->next;
	}
	return (closest_sphere_hit);
}

static t_hit	check_plane_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;
	t_hit	closest_plane_hit;
	t_plane	*current_plane;
	double	closest_plane_t;

	closest_plane_hit.is_hit = 0;
	closest_plane_t = closest_t;
	current_plane = world->plane;
	while (current_plane)
	{
		current_hit = intersect_plane(ray_dir, ray_origin,
				current_plane, world->light->position);
		if (current_hit.is_hit && current_hit.t > 0.001
			&& current_hit.t < closest_plane_t)
		{
			closest_plane_t = current_hit.t;
			closest_plane_hit = current_hit;
		}
		current_plane = current_plane->next;
	}
	return (closest_plane_hit);
}

static t_hit	check_cylinder_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit		current_hit;
	t_hit		closest_cylinder_hit;
	t_cylinder	*current_cylinder;
	double		closest_cylinder_t;

	closest_cylinder_hit.is_hit = 0;
	closest_cylinder_t = closest_t;
	current_cylinder = world->cylinder;
	while (current_cylinder)
	{
		current_hit = intersect_cylinder(ray_dir, ray_origin,
				current_cylinder, world->light->position);
		if (current_hit.is_hit && current_hit.t > 0.001
			&& current_hit.t < closest_cylinder_t)
		{
			closest_cylinder_t = current_hit.t;
			closest_cylinder_hit = current_hit;
		}
		current_cylinder = current_cylinder->next;
	}
	return (closest_cylinder_hit);
}

static void	update_closest_hit(t_hit current_hit, t_hit *closest_hit,
					double *closest_t)
{
	if (current_hit.is_hit)
	{
		*closest_t = current_hit.t;
		*closest_hit = current_hit;
	}
}

t_hit	find_closest_intersection(t_vec3 ray_origin,
		t_vec3 ray_dir, t_world *world)
{
	t_hit	closest_hit;
	t_hit	current_hit;
	double	closest_t;

	closest_hit.is_hit = 0;
	closest_t = DBL_MAX;
	if (world->sphere)
	{
		current_hit = check_sphere_intersection(ray_origin, ray_dir,
				world, closest_t);
		update_closest_hit(current_hit, &closest_hit, &closest_t);
	}
	if (world->plane)
	{
		current_hit = check_plane_intersection(ray_origin, ray_dir,
				world, closest_t);
		update_closest_hit(current_hit, &closest_hit, &closest_t);
	}
	if (world->cylinder)
	{
		current_hit = check_cylinder_intersection(ray_origin, ray_dir,
				world, closest_t);
		update_closest_hit(current_hit, &closest_hit, &closest_t);
	}
	return (closest_hit);
}
