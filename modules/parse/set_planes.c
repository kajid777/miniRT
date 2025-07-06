/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_planes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 14:10:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	val_normalized_vector(t_vec3 vector, void *object, t_world *world)
{
	if (vector.x < -1.0 || vector.x > 1.0
		|| vector.y < -1.0 || vector.y > 1.0
		|| vector.z < -1.0 || vector.z > 1.0)
	{
		free(object);
		free_world(world);
		print_err_and_exit("Normalized vector isnt in range [-1,1] for axis",
			1);
	}
}

static void	add_plane_to_list(t_world *world, t_plane *plane)
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

void	set_plane(t_world *world, char **strs)
{
	t_plane		*plane;
	t_vec3		normal;

	plane = malloc(sizeof(*plane));
	if (!(plane))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	plane->point = str_to_vect(strs[1], world);
	normal = str_to_vect(strs[2], world);
	val_normalized_vector(normal, plane, world);
	plane->normal_vector = vec_norm(normal);
	plane->color = str_to_rgb(strs[3], world);
	plane->next = NULL;
	add_plane_to_list(world, plane);
}
