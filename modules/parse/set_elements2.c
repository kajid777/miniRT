/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:53:11 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/06 14:10:41 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// 正規化ベクトルが有効かチェックする関数
static void	validate_normalized_vector(t_vec3 vector, void *object,
		t_world *world)
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

static void	validate_sphere_diameter(double diameter, t_sphere *sphere,
		t_world *world)
{
	if (diameter <= 0)
	{
		free(sphere);
		free_world(world);
		print_err_and_exit("Error: Sphere diameter must be greater than 0", 1);
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

void	set_sphere(t_world *world, char **strs)
{
	t_sphere	*sphere;
	double		diameter;
	t_sphere	*current;

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

void	set_plane(t_world *world, char **strs)
{
	t_plane	*plane;
	t_vec3	normal;
	t_plane	*current;

	if (!(plane = malloc(sizeof(*plane))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	plane->point = str_to_vect(strs[1]);
	normal = str_to_vect(strs[2]);
	validate_normalized_vector(normal, plane, world);
	plane->normal_vector = vec_norm(normal);
	plane->color = str_to_rgb(strs[3], world);
	plane->next = NULL;
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

void	set_cylinder(t_world *world, char **strs)
{
	t_cylinder	*cy;
	t_vec3		direction;
	t_cylinder	*current;

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
	if (world->cylinder == NULL)
	{
		world->cylinder = cy;
	}
	else
	{
		current = world->cylinder;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = cy;
	}
}
