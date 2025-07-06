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

void	set_ambient_light(t_world *world, t_parse_ctx *ctx)
{
	t_ambient_lighting	*ambient_light;
	double				ratio;

	ambient_light = malloc(sizeof(*ambient_light));
	if (!(ambient_light))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	ratio = ft_atod(ctx->data[1]);
	val_ambient_ratio(ratio, ambient_light, world, ctx);
	ambient_light->color = str_to_rgb(ctx->data[2], world);
	ambient_light->lighting_ratio = ratio;
	world->ambient = ambient_light;
}

void	set_camera(t_world *world, t_parse_ctx *ctx)
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
	camera->position = str_to_vect(ctx->data[1], world);
	direction = str_to_vect(ctx->data[2], world);
	fov = ft_atod(ctx->data[3]);
	val_camera_direction(direction, camera, world, ctx);
	val_normalized_vector(direction, camera, world, ctx);
	val_camera_fov(fov, camera, world, ctx);
	camera->direction = vec_norm(direction);
	camera->fov = fov;
	world->camera = camera;
}

void	set_light(t_world *world, t_parse_ctx *ctx)
{
	t_light	*light;
	double	brightness;

	light = malloc(sizeof(*light));
	if (!(light))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	light->position = str_to_vect(ctx->data[1], world);
	brightness = ft_atod(ctx->data[2]);
	val_light_brightness(brightness, light, world, ctx);
	light->intensity = brightness;
	light->color = str_to_rgb(ctx->data[3], world);
	world->light = light;
}
