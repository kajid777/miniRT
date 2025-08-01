/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_planes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:16:04 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:16:04 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	add_plane_to_list(t_world *world, t_plane *plane)
{
	t_plane	*current;

	if (world->plane == NULL)
	{
		world->plane = plane;
	}
	else
	{
		current = world->plane;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = plane;
	}
}

void	set_plane(t_world *world, t_parse_ctx *ctx)
{
	t_plane		*plane;
	t_vec3		normal;

	plane = malloc(sizeof(*plane));
	if (!(plane))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	ctx->tmp_object = plane;
	plane->point = str_to_vect(ctx->data[1], world, ctx);
	normal = str_to_vect(ctx->data[2], world, ctx);
	val_normalized_vector(normal, plane, world, ctx);
	plane->normal_vector = vec_norm(normal);
	plane->color = str_to_rgb(ctx->data[3], world, ctx);
	plane->next = NULL;
	add_plane_to_list(world, plane);
}
