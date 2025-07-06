/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:54:10 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/06 17:25:48 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_fcolor	*int_to_rgb(const int r, const int g, const int b, t_world *world)
{
	t_fcolor	*rgb;

	rgb = malloc(sizeof(*rgb));
	if (!(rgb))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
	return (rgb);
}

t_fcolor	*mult_rgb_double(const t_fcolor rgb, const double mult,
		t_world *world)
{
	return (int_to_rgb(rgb.red * mult, rgb.green * mult, rgb.blue * mult,
			world));
}

static void	val_camera_direction(t_vec3 direction, t_camera *camera,
		t_world *world)
{
	if (direction.x == 0 && direction.y == 0 && direction.z == 0)
	{
		free(camera);
		free_world(world);
		print_err_and_exit("Error: Camera direction cannot be (0,0,0)", 1);
	}
}

static void	val_camera_fov(double fov, t_camera *camera, t_world *world)
{
	if (fov <= 0 || fov >= 180)
	{
		free(camera);
		free_world(world);
		print_err_and_exit("Error: FOV must be between 0 and 180 degrees", 1);
	}
}

static void	val_ambient_ratio(double ratio, t_ambient_lighting *ambient,
		t_world *world)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		free(ambient);
		free_world(world);
		print_err_and_exit("Ambient lighting ratio must be in range [0.0,1.0]",
			1);
	}
}

static void	val_normalized_vector(t_vec3 vector, void *object, t_world *world)
{
	if (vector.x < -1.0 || vector.x > 1.0 || vector.y < -1.0 || vector.y > 1.0
		|| vector.z < -1.0 || vector.z > 1.0)
	{
		free(object);
		free_world(world);
		print_err_and_exit("Normalized vector must be in range [-1,1]",
			1);
	}
}

static void	val_light_brightness(double brightness, t_light *light,
		t_world *world)
{
	if (brightness < 0.0 || brightness > 1.0)
	{
		free(light);
		free_world(world);
		print_err_and_exit("Light brightness ratio must be in range [0.0,1.0]",
			1);
	}
}

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
