/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:16:09 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:16:09 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	add_sphere_to_list(t_world *world, t_sphere *sphere)
{
	t_sphere	*current;

	if (world->sphere == NULL)
	{
		world->sphere = sphere;
	}
	else
	{
		current = world->sphere;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = sphere;
	}
}

static void	val_sphere_diameter(double diameter,
	t_sphere *sphere, t_world *world, t_parse_ctx *ctx)
{
	if (diameter <= 0)
	{
		free(sphere);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Error: Sphere diameter must be greater than 0", 1);
	}
}

void	set_sphere(t_world *world, t_parse_ctx *ctx)
{
	t_sphere	*sphere;
	double		diameter;

	sphere = malloc(sizeof(*sphere));
	if (!(sphere))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	sphere->center = str_to_vect(ctx->data[1], world);
	diameter = ft_atod(ctx->data[2]);
	val_sphere_diameter(diameter, sphere, world, ctx);
	sphere->diameter = diameter;
	sphere->color = str_to_rgb(ctx->data[3], world, ctx, sphere);
	sphere->next = NULL;
	add_sphere_to_list(world, sphere);
}
