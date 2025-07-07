/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 19:23:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	add_cylinder_to_list(t_world *world, t_cylinder *cylinder)
{
	t_cylinder	*current;

	if (world->cylinder == NULL)
	{
		world->cylinder = cylinder;
	}
	else
	{
		current = world->cylinder;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = cylinder;
	}
}

static void	val_cylinder_diameter(double diameter, t_cylinder *cylinder,
		t_world *world, t_parse_ctx *ctx)
{
	if (diameter <= 0)
	{
		free(cylinder);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Error: Cylinder diameter must be greater than 0",
			1);
	}
}

static void	val_cylinder_height(double height, t_cylinder *cylinder,
		t_world *world, t_parse_ctx *ctx)
{
	if (height <= 0)
	{
		free(cylinder);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Error: Cylinder height must be greater than 0", 1);
	}
}

void	set_cylinder(t_world *world, t_parse_ctx *ctx)
{
	t_cylinder	*cy;
	t_vec3		direction;

	cy = malloc(sizeof(*cy));
	if (!(cy))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	cy->center = str_to_vect(ctx->data[1], world);
	direction = str_to_vect(ctx->data[2], world);
	val_normalized_vector(direction, cy, world, ctx);
	cy->direction = vec_norm(direction);
	cy->diameter = ft_atod(ctx->data[3]);
	cy->height = ft_atod(ctx->data[4]);
	val_cylinder_diameter(cy->diameter, cy, world, ctx);
	val_cylinder_height(cy->height, cy, world, ctx);
	cy->color = str_to_rgb(ctx->data[5], world, ctx, cy);
	cy->next = NULL;
	add_cylinder_to_list(world, cy);
}
