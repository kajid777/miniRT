/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 14:10:20 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 14:10:20 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"


void	*init_world(t_world *world)
{
	world->ambient = NULL;
	world->camera = NULL;
	world->light = NULL;
	world->sphere = NULL;
	world->plane = NULL;
	world->cylinder = NULL;
	world->mlx = NULL;
	world->win = NULL;
	return (world);
}

bool	check_line(const char *line, char **data, const char *type,
		const int nb_elements)
{
	if (!line)
		return (false);
	if (!data)
		return (false);
	if (!ft_strcmp(data[0], type))
	{
		if (ft_tab_size(data) == nb_elements)
			return (true);
	}
	return (0);
}

static void	process_line(t_world *world, char *line, char **data)
{
	if (check_line(line, data, "A", NB_ELEM_AL))
		set_ambient_light(world, data);
	else if (check_line(line, data, "C", NB_ELEM_CAMERA))
		set_camera(world, data);
	else if (check_line(line, data, "L", NB_ELEM_LIGHT))
		set_light(world, data);
	else if (check_line(line, data, "sp", NB_ELEM_SPHERE))
		set_sphere(world, data);
	else if (check_line(line, data, "pl", NB_ELEM_PLANE))
		set_plane(world, data);
	else if (check_line(line, data, "cy", NB_ELEM_CYLINDER))
		set_cylinder(world, data);
	else if (!ft_is_from_charset(line, WHITE_SPACES))
	{
		free(line);
		ft_free_tab(data);
		print_err_and_exit("Parse error", PARSE_ERROR);
	}
}

t_world	*parse(int fd)
{
	t_world *world;
	char *line;
	char **data;

	if (!(world = malloc(sizeof(*world))))
		print_err_and_exit("malloc failed in parse", 1);
	init_world(world);
	line = get_next_line(fd);
	while (line != NULL)
	{
		data = ft_split_set(line, WHITE_SPACES);
		if (!data)
		{
			free(line);
			free_world(world);
			print_err_and_exit("Malloc failed", 1);
		}
		process_line(world, line, data);
		free(line);
		ft_free_tab(data);
		line = get_next_line(fd);
	}
	return (world);
}

t_world	*get_world(const int argc, char *argv[])
{
	int fd;
	t_world *world;

	if (argc < 2)
		print_err_and_exit("expecting a '.rt'file", 1);
	if (argc > 3)
		print_err_and_exit("expecting a 2 arguments maximum", 1);
	if (argc == 2 && ft_strncmp_rev(argv[1], ".rt", 3))
		print_err_and_exit("First argument must be a '.rt' file", 1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		print_err_and_exit("open failed", 1);
	if (!(world = parse(fd)))
		print_err_and_exit("Parsing error", 1);
	if (close(fd) == -1)
	{
		free_world(world);
		print_err_and_exit("close failed", 1);
	}
	return (world);
}
