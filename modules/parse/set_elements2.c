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

#include "../includes/miniRT.h"

// シーンに球体（sphere）を追加する関数
void	set_sphere(t_world *world, char **strs)
{
	t_sphere	*sphere;
	double		radius;

	if (!(sphere = malloc(sizeof(*sphere))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	sphere->pos = str_to_vect(strs[1]);
	radius = ft_atod(strs[2]);
	sphere->radius2 = radius * radius;
	sphere->color = str_to_rgb(strs[3]);
	sphere->reflec = 0;
	if (strs[4])
		sphere->reflec = ft_atod(strs[4]);
	ft_lstadd_front(&(world->spheres), ft_lstnew(sphere));
}

// シーンに平面（plane）を追加する関数
void	set_plane(t_world *world, char **strs)
{
	t_plane		*plane;

	if (!(plane = malloc(sizeof(*plane))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	plane->pos = str_to_vect(strs[1]);
	plane->normal = normalize(str_to_vect(strs[2]));
	plane->color = str_to_rgb(strs[3]);
	ft_lstadd_front(&(world->planes), ft_lstnew(plane));
}

// シーンに円柱（cylinder）を追加する関数
void	set_cylinder(t_world *world, char **strs)
{
	t_cylinder	*cy;
	double		radius;

	if (!(cy = malloc(sizeof(*cy))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	cy->pos = str_to_vect(strs[1]);
	cy->dir = normalize(str_to_vect(strs[2]));
	radius = ft_atod(strs[3]) / 2;
	cy->radius2 = radius * radius;
	cy->height = ft_atod(strs[4]);
	cy->pos2 = add_vect(cy->pos, multi_vect(cy->dir, cy->height));
	cy->color = str_to_rgb(strs[5]);
	if (strs[6])
		cy->is_closed = ft_atoi_strict(strs[6]);
	else
		cy->is_closed = 1;
	ft_lstadd_front(&(world->cylinders), ft_lstnew(cy));
}

