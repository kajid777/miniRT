/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_generation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:13:30 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:13:35 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

t_vec3	generate_one_ray(t_camera camera, t_screen screen, int x, int y)
{
	t_vec3	obj_on_screen;
	t_vec3	ray;
	t_vec3	normalized_ray;

	obj_on_screen = vec_add(screen.top_left,
			vec_mul_scalar(screen.pixel_horizontal, x));
	obj_on_screen = vec_add(obj_on_screen,
			vec_mul_scalar(screen.pixel_vertical, y));
	ray = vec_sub(obj_on_screen, camera.position);
	normalized_ray = vec_norm(ray);
	return (normalized_ray);
}

t_fcolor	trace_ray(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world)
{
	t_hit		hit;
	t_fcolor	color;
	t_fcolor	object_color;

	if (is_camera_inside_object(world))
	{
		color.red = 0.0;
		color.green = 0.0;
		color.blue = 0.0;
		return (color);
	}
	hit = find_closest_intersection(ray_origin, ray_dir, world);
	if (!hit.is_hit)
	{
		color.red = 0.0;
		color.green = 0.0;
		color.blue = 0.0;
		return (color);
	}
	object_color = get_object_color(hit);
	color = calculate_lighting(hit, world);
	color.red *= object_color.red;
	color.green *= object_color.green;
	color.blue *= object_color.blue;
	return (color);
}
