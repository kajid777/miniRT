/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_intersection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:55:37 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 12:55:38 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

static t_hit	check_sphere_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;
	t_hit	best_hit;
	t_sphere	*sphere;

	best_hit.is_hit = 0;
	sphere = world->sphere;
	while (sphere)
	{
		current_hit = intersect_sphere(ray_dir, ray_origin,
			*sphere, world->light->position, sphere);
		if (current_hit.is_hit && current_hit.t > 0.001
			&& current_hit.t < closest_t)
		{
			if (!best_hit.is_hit || current_hit.t < best_hit.t)
				best_hit = current_hit;
		}
		sphere = sphere->next;
	}
	return (best_hit);
}

static t_hit	check_plane_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;
	t_hit	best_hit;
	t_plane	*plane;

	best_hit.is_hit = 0;
	plane = world->plane;
	while (plane)
	{
		current_hit = intersect_plane(ray_dir, ray_origin,
			*plane, world->light->position, plane);
		if (current_hit.is_hit && current_hit.t > 0.001
			&& current_hit.t < closest_t)
		{
			if (!best_hit.is_hit || current_hit.t < best_hit.t)
				best_hit = current_hit;
		}
		plane = plane->next;
	}
	return (best_hit);
}

static t_hit	check_cylinder_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;
	t_hit	best_hit;
	t_cylinder	*cylinder;

	best_hit.is_hit = 0;
	cylinder = world->cylinder;
	while (cylinder)
	{
		current_hit = intersect_cylinder(ray_dir, ray_origin,
			*cylinder, world->light->position, cylinder);
		if (current_hit.is_hit && current_hit.t > 0.001
			&& current_hit.t < closest_t)
		{
			if (!best_hit.is_hit || current_hit.t < best_hit.t)
				best_hit = current_hit;
		}
		cylinder = cylinder->next;
	}
	return (best_hit);
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

t_hit	find_closest_intersection(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world)
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