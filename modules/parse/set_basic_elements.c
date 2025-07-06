/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_basic_elements.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:50:00 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/06 17:50:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	set_ambient_light(t_world *world, char **data)
{
	t_ambient_lighting	*ambient_light;
	double				ratio;

	ambient_light = malloc(sizeof(*ambient_light));
	if (!(ambient_light))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	ratio = ft_atod(data[1]);
	val_ambient_ratio(ratio, ambient_light, world);
	ambient_light->color = str_to_rgb(data[2], world);
	ambient_light->lighting_ratio = ratio;
	world->ambient = ambient_light;
}

void	set_camera(t_world *world, char **data)
{
	t_camera	*camera;
	t_vec3		direction;
	double		fov;

	camera = malloc(sizeof(*camera));
	if (!(camera))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	camera->position = str_to_vect(data[1], world);
	direction = str_to_vect(data[2], world);
	fov = ft_atod(data[3]);
	val_camera_direction(direction, camera, world);
	val_normalized_vector(direction, camera, world);
	val_camera_fov(fov, camera, world);
	camera->direction = vec_norm(direction);
	camera->fov = fov;
	world->camera = camera;
}

void	set_light(t_world *world, char **data)
{
	t_light	*light;
	double	brightness;

	light = malloc(sizeof(*light));
	if (!(light))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	light->position = str_to_vect(data[1], world);
	brightness = ft_atod(data[2]);
	val_light_brightness(brightness, light, world);
	light->intensity = brightness;
	light->color = str_to_rgb(data[3], world);
	world->light = light;
} 