/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:14:37 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/15 16:05:29 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

// ... existing code ...

void print_err_and_exit(char *message, int exit_code)
{
    ft_printf("Error: %s\n", message);
    exit(exit_code);
}

int ft_strncmp_rev(const char *s1, const char *s2, size_t n)
{
    size_t len1 = strlen(s1);
    size_t len2 = strlen(s2);
    
    if (len1 < n || len2 < n)
        return (1);
    
    return (strncmp(s1 + len1 - n, s2, n));
}

// ... existing code ...
int	exit_point(t_world *world)
{
	(void)world;
	// free(game->mlx_ptr);
	// free_all_2darray(game->map, game->map_height);
	exit(0);
}

void	when_mlx_ptr_failed(t_world *world)
{
	(void)world;
	ft_printf("Error\nmalloc failed.");
	// free_all_2darray(game->map, game->map_height);
	exit(0);
}

int	exit_with_cross(t_world *world)
{
	if (world && world->mlx)
		mlx_loop_end(world->mlx);
	free_world(world);
	exit(0);
}

void	end_with_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

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
