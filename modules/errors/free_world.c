/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 00:00:00 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/01/01 00:00:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	free_world(t_world *world)
{
	if (!world)
		return;
	
	// Free camera
	if (world->camera)
	{
		free(world->camera);
		world->camera = NULL;
	}
	
	// Free light
	if (world->light)
	{
		free(world->light);
		world->light = NULL;
	}
	
	// Free ambient lighting
	if (world->ambient)
	{
		free(world->ambient);
		world->ambient = NULL;
	}
	
	// Free sphere
	if (world->sphere)
	{
		free(world->sphere);
		world->sphere = NULL;
	}
	
	// Free plane
	if (world->plane)
	{
		free(world->plane);
		world->plane = NULL;
	}
	
	// Free cylinder
	if (world->cylinder)
	{
		free(world->cylinder);
		world->cylinder = NULL;
	}
	
	// Free MLX resources
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
	
	// Finally free the world structure itself
	free(world);
} 