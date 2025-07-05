#include "../../includes/miniRT.h"
#include <math.h>

static t_hit	check_sphere_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;

	current_hit = intersect_sphere(ray_dir, ray_origin,
		*world->sphere, world->light->position);
	if (current_hit.is_hit && current_hit.t > 0.001
		&& current_hit.t < closest_t)
		return (current_hit);
	current_hit.is_hit = 0;
	return (current_hit);
}

static t_hit	check_plane_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;

	current_hit = intersect_plane(ray_dir, ray_origin,
		*world->plane, world->light->position);
	if (current_hit.is_hit && current_hit.t > 0.001
		&& current_hit.t < closest_t)
		return (current_hit);
	current_hit.is_hit = 0;
	return (current_hit);
}

static t_hit	check_cylinder_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
							t_world *world, double closest_t)
{
	t_hit	current_hit;

	current_hit = intersect_cylinder(ray_dir, ray_origin,
		*world->cylinder, world->light->position);
	if (current_hit.is_hit && current_hit.t > 0.001
		&& current_hit.t < closest_t)
		return (current_hit);
	current_hit.is_hit = 0;
	return (current_hit);
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