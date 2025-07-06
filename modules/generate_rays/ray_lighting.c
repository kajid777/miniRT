/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_lighting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:07:53 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 18:23:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

static t_fcolor	calculate_ambient(t_world *world)
{
	t_fcolor	ambient;

	ambient.red = world->ambient->color.red * world->ambient->lighting_ratio;
	ambient.green = world->ambient->color.green
		* world->ambient->lighting_ratio;
	ambient.blue = world->ambient->color.blue * world->ambient->lighting_ratio;
	return (ambient);
}

static t_fcolor	calculate_diffuse(t_hit hit, t_world *world,
					double light_intensity)
{
	t_fcolor	diffuse;
	int			in_shadow;

	in_shadow = is_in_shadow(hit.hit_point, world->light->position, world);
	if (in_shadow)
	{
		diffuse.red = 0;
		diffuse.green = 0;
		diffuse.blue = 0;
	}
	else
	{
		diffuse.red = world->light->color.red
			* world->light->intensity * light_intensity;
		diffuse.green = world->light->color.green
			* world->light->intensity * light_intensity;
		diffuse.blue = world->light->color.blue
			* world->light->intensity * light_intensity;
	}
	return (diffuse);
}

t_fcolor	calculate_lighting(t_hit hit, t_world *world)
{
	t_fcolor	result;
	t_fcolor	ambient;
	t_fcolor	diffuse;
	double		light_intensity;

	ambient = calculate_ambient(world);
	light_intensity = vec_dot(hit.norm, hit.light_dir);
	if (light_intensity < 0)
		light_intensity = 0;
	diffuse = calculate_diffuse(hit, world, light_intensity);
	result.red = ambient.red + diffuse.red;
	result.green = ambient.green + diffuse.green;
	result.blue = ambient.blue + diffuse.blue;
	if (result.red > 1.0)
		result.red = 1.0;
	if (result.green > 1.0)
		result.green = 1.0;
	if (result.blue > 1.0)
		result.blue = 1.0;
	return (result);
}

t_fcolor	get_object_color(t_hit hit)
{
	t_fcolor	object_color;

	if (hit.obj_type == SPHERE && hit.hit_object)
		object_color = ((t_sphere *)hit.hit_object)->color;
	else if (hit.obj_type == PLANE && hit.hit_object)
		object_color = ((t_plane *)hit.hit_object)->color;
	else if (hit.obj_type == CYLINDER && hit.hit_object)
		object_color = ((t_cylinder *)hit.hit_object)->color;
	else
	{
		object_color.red = 1.0;
		object_color.green = 1.0;
		object_color.blue = 1.0;
	}
	return (object_color);
}
