/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_spheres.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 14:10:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

static void	add_sphere_to_list(t_world *world, t_sphere *sphere)
{
	t_sphere *current;

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

static void	validate_sphere_diameter(double diameter, t_sphere *sphere, t_world *world)
{
	if (diameter <= 0)
	{
		free(sphere);
		free_world(world);
		print_err_and_exit("Error: Sphere diameter must be greater than 0", 1);
	}
}

void	set_sphere(t_world *world, char **strs)
{
	t_sphere	*sphere;
	double		diameter;

	if (!(sphere = malloc(sizeof(*sphere))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	sphere->center = str_to_vect(strs[1]);
	diameter = ft_atod(strs[2]);
	validate_sphere_diameter(diameter, sphere, world);
	sphere->diameter = diameter;
	sphere->color = str_to_rgb(strs[3], world);
	sphere->next = NULL;
	add_sphere_to_list(world, sphere);
}
