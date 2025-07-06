/* ************************************************************************** */
/*                                                                            */ /*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:06:22 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/15 16:02:03 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/miniRT.h"
int	main(int argc, char **argv)
{
	t_world *world;

	world = get_world(argc, argv);
	world->mlx = mlx_init();
	if (!world->mlx)
	{
		free_world(world);
		print_err_and_exit("mlx_init failed", 1);
	}
	world->win = mlx_new_window(world->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "miniRT");
	if (!world->win)
	{
		free_world(world);
		print_err_and_exit("mlx_new_window failed", 1);
	}
	render_scene(world);
	mlx_hook(world->win, 17, 0, exit_with_cross, world);
	mlx_loop(world->mlx);
	return (0);
}
