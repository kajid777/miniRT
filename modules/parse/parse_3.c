/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 20:15:00 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 20:15:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	validate_required_elements(t_world *world)
{
	if (!world->ambient)
	{
		free_world(world);
		print_err_and_exit("Error: Missing ambient light (A)", 1);
	}
	if (!world->camera)
	{
		free_world(world);
		print_err_and_exit("Error: Missing camera (C)", 1);
	}
	if (!world->light)
	{
		free_world(world);
		print_err_and_exit("Error: Missing light (L)", 1);
	}
}

t_world	*get_world(const int argc, char *argv[])
{
	int		fd;
	t_world	*world;

	if (argc < 2)
		print_err_and_exit("expecting a '.rt'file", 1);
	if (argc > 3)
		print_err_and_exit("expecting a 2 arguments maximum", 1);
	if (argc == 2 && ft_strncmp_rev(argv[1], ".rt", 3))
		print_err_and_exit("First argument must be a '.rt' file", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_err_and_exit("open failed", 1);
	world = parse(fd);
	if (!(world))
		print_err_and_exit("Parsing error", 1);
	if (close(fd) == -1)
	{
		free_world(world);
		print_err_and_exit("close failed", 1);
	}
	return (world);
}
