/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinders.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 14:35:35 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	validate_normalized_vector(t_vec3 vector, void *object, t_world *world)
{
	if (vector.x < -1.0 || vector.x > 1.0 || vector.y < -1.0 || vector.y > 1.0
		|| vector.z < -1.0 || vector.z > 1.0)
	{
		free(object);
		free_world(world);
		print_err_and_exit("Error: Normalized vector must be in range [-1,1] for each axis",
			1);
	}
}

static void	add_cylinder_to_list(t_world *world, t_cylinder *cylinder)
{
	t_cylinder *current;

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

static void	validate_cylinder_diameter(double diameter, t_cylinder *cylinder,
		t_world *world)
{
	if (diameter <= 0)
	{
		free(cylinder);
		free_world(world);
		print_err_and_exit("Error: Cylinder diameter must be greater than 0",
			1);
	}
}

static void	validate_cylinder_height(double height, t_cylinder *cylinder,
		t_world *world)
{
	if (height <= 0)
	{
		free(cylinder);
		free_world(world);
		print_err_and_exit("Error: Cylinder height must be greater than 0", 1);
	}
}

void	set_cylinder(t_world *world, char **strs)
{
	t_cylinder	*cy;
	t_vec3		direction;

	if (!(cy = malloc(sizeof(*cy))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	cy->center = str_to_vect(strs[1]);
	direction = str_to_vect(strs[2]);
	validate_normalized_vector(direction, cy, world);
	cy->direction = vec_norm(direction);
	cy->diameter = ft_atod(strs[3]);
	cy->height = ft_atod(strs[4]);
	validate_cylinder_diameter(cy->diameter, cy, world);
	validate_cylinder_height(cy->height, cy, world);
	cy->color = str_to_rgb(strs[5], world);
	cy->next = NULL;
	add_cylinder_to_list(world, cy);
}
