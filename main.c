/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:06:22 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/15 16:02:03 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include <X11/X.h>
// #include <X11/keysym.h>
// #include "mlx.h"
#include "includes/miniRT.h"

// main
// parse
// makefile
// test
int	main(int argc, char **argv)
{
	t_world *world;

	world = get_world(argc, argv);
	camera_prepare(world->camera);
	generate_rays(*(world->camera));

	world->mlx = mlx_init();
	// if (mlx_ptr)
	// 	when_mlx_ptr_failed(mlx_ptr);
	world->win = mlx_new_window(world->mlx, 1000, 1000, "so_long");//ここ治す
	if (!world->win)
		return (free(world->mlx), 1);

	mlx_hook(world->win, 17, 0, exit_with_cross, &world);
	// mlx_key_hook(game.win_ptr, handle_command, &game);
	(void)world->win;
	mlx_loop(world->mlx);
	return (0);
}
