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
