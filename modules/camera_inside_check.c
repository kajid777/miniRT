/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_inside_check.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claude <noreply@anthropic.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 00:00:00 by claude            #+#    #+#             */
/*   Updated: 2025/07/12 00:00:00 by claude           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

static int	is_inside_sphere(t_vec3 point, t_sphere *sphere)
{
	t_vec3	diff;
	double	distance_squared;
	double	radius_squared;

	diff = vec_sub(point, sphere->center);
	distance_squared = vec_dot(diff, diff);
	radius_squared = pow(sphere->diameter / 2, 2);
	return (distance_squared < radius_squared);
}

static int	check_cylinder_height(t_vec3 point_vec, t_vec3 axis_vec,
	t_cylinder *cylinder)
{
	double	projection;

	projection = vec_dot(point_vec, axis_vec);
	if (projection < 0 || projection > cylinder->height)
		return (0);
	return (1);
}

static int	check_cylinder_radius(t_vec3 point_vec, t_vec3 axis_vec,
	t_cylinder *cylinder)
{
	t_vec3	closest_on_axis;
	t_vec3	radial_vec;
	double	radial_distance_squared;
	double	radius_squared;
	double	projection;

	projection = vec_dot(point_vec, axis_vec);
	closest_on_axis = vec_mul_scalar(axis_vec, projection);
	radial_vec = vec_sub(point_vec, closest_on_axis);
	radial_distance_squared = vec_dot(radial_vec, radial_vec);
	radius_squared = pow(cylinder->diameter / 2, 2);
	return (radial_distance_squared < radius_squared);
}

static int	is_inside_cylinder(t_vec3 point, t_cylinder *cylinder)
{
	t_vec3	axis_vec;
	t_vec3	point_vec;

	axis_vec = vec_norm(cylinder->direction);
	point_vec = vec_sub(point, cylinder->center);
	if (!check_cylinder_height(point_vec, axis_vec, cylinder))
		return (0);
	return (check_cylinder_radius(point_vec, axis_vec, cylinder));
}

int	is_camera_inside_object(t_world *world)
{
	t_sphere	*current_sphere;
	t_cylinder	*current_cylinder;

	current_sphere = world->sphere;
	while (current_sphere)
	{
		if (is_inside_sphere(world->camera->position, current_sphere))
			return (1);
		current_sphere = current_sphere->next;
	}
	current_cylinder = world->cylinder;
	while (current_cylinder)
	{
		if (is_inside_cylinder(world->camera->position, current_cylinder))
			return (1);
		current_cylinder = current_cylinder->next;
	}
	return (0);
}
