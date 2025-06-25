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
	// mlx_destroy_image(game->mlx_ptr, game->floor);

	if (world->win)
		mlx_destroy_window(world->mlx, world->win);
	mlx_destroy_display(world->mlx);
	exit_point(world);
	exit(0);
}

void	end_with_error(void)
{
	ft_printf("Error\n");
	exit(1);
}
