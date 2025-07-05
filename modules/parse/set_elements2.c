/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:53:11 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/27 11:17:53 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// シーンに球体（sphere）を追加する関数
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
	sphere->diameter = diameter;
	sphere->color = str_to_rgb(strs[3], world);
	world->sphere = sphere;
}

// シーンに平面（plane）を追加する関数
void	set_plane(t_world *world, char **strs)
{
	t_plane		*plane;

	if (!(plane = malloc(sizeof(*plane))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	plane->point = str_to_vect(strs[1]);
	plane->normal_vector = vec_norm(str_to_vect(strs[2]));
	plane->color = str_to_rgb(strs[3], world);
	world->plane = plane;
}

// シーンに円柱（cylinder）を追加する関数
void	set_cylinder(t_world *world, char **strs)
{
	t_cylinder	*cy;

	if (!(cy = malloc(sizeof(*cy))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	cy->center = str_to_vect(strs[1]);
	cy->direction = vec_norm(str_to_vect(strs[2]));
	cy->diameter = ft_atod(strs[3]);
	cy->height = ft_atod(strs[4]);
	cy->color = str_to_rgb(strs[5], world);
	world->cylinder = cy;
}

