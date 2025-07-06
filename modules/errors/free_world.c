/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/01 00:00:00 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/01/01 00:00:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"


// Free all object lists (spheres, planes, cylinders)
void	free_obj_lists(t_world *world)
{
	while (world->sphere)
	{
		t_sphere *temp = world->sphere;
		world->sphere = world->sphere->next;
		free(temp);
	}
	while (world->plane)
	{
		t_plane *temp = world->plane;
		world->plane = world->plane->next;
		free(temp);
	}
	while (world->cylinder)
	{
		t_cylinder *temp = world->cylinder;
		world->cylinder = world->cylinder->next;
		free(temp);
	}
}

void	free_world(t_world *world)
{
	if (!world)
		return ;

	if (world->camera)
	{
		free(world->camera);
		world->camera = NULL;
	}

	if (world->light)
	{
		free(world->light);
		world->light = NULL;
	}

	if (world->ambient)
	{
		free(world->ambient);
		world->ambient = NULL;
	}

	free_obj_lists(world);

	if (world->mlx)
	{
		if (world->win)
		{
			mlx_destroy_window(world->mlx, world->win);
			world->win = NULL;
		}
		mlx_destroy_display(world->mlx);
		free(world->mlx);
		world->mlx = NULL;
	}

	free(world);
}