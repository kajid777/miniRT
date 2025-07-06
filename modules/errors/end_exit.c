/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_exit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024/12/19 19:14:37 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/15 16:05:29 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	print_err_and_exit(char *message, int exit_code)
{
	ft_printf("Error: %s\n", message);
	exit(exit_code);
}

int	ft_strncmp_rev(const char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	len2;

	len1 = strlen(s1);
	len2 = strlen(s2);
	if (len1 < n || len2 < n)
		return (1);
	return (strncmp(s1 + len1 - n, s2, n));
}

void	when_mlx_ptr_failed(t_world *world)
{
	(void)world;
	ft_printf("Error\nmalloc failed.");
	exit(0);
}

int	exit_with_cross(t_world *world)
{
	if (world && world->mlx)
		mlx_loop_end(world->mlx);
	free_world(world);
	exit(0);
}

int	handle_key_press(int keycode, t_world *world)
{
	if (keycode == 65307)
	{
		if (world && world->mlx)
			mlx_loop_end(world->mlx);
		free_world(world);
		exit(0);
	}
	return (0);
}
