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

	check_duplicate_ambient(world, ctx);
	ambient_light = malloc(sizeof(*ambient_light));
	if (!(ambient_light))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	ctx->tmp_object = ambient_light;
	ratio = ft_atod_safe(ctx->data[1], world, ctx);
	val_ambient_ratio(ratio, ambient_light, world, ctx);
	ambient_light->color = str_to_rgb(ctx->data[2], world, ctx);
	ambient_light->lighting_ratio = ratio;
	world->ambient = ambient_light;
}

void	set_camera(t_world *world, t_parse_ctx *ctx)
{
	t_camera	*camera;
	t_vec3		direction;
	double		fov;

	check_duplicate_camera(world, ctx);
	camera = malloc(sizeof(*camera));
	if (!(camera))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	camera->position = str_to_vect(ctx->data[1], world, ctx);
	direction = str_to_vect(ctx->data[2], world, ctx);
	fov = ft_atod_safe(ctx->data[3], world, ctx);
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

	check_duplicate_light(world, ctx);
	light = malloc(sizeof(*light));
	if (!(light))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	ctx->tmp_object = light;
	light->position = str_to_vect(ctx->data[1], world, ctx);
	brightness = ft_atod_safe(ctx->data[2], world, ctx);
	val_light_brightness(brightness, light, world, ctx);
	light->intensity = brightness;
	light->color = str_to_rgb(ctx->data[3], world, ctx);
	world->light = light;
}
