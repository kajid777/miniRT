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
	t_parse_ctx	ctx;

	ctx.line = line;
	ctx.data = data;
	if (check_line(line, data, "A", NB_ELEM_AL))
		set_ambient_light(world, &ctx);
	else if (check_line(line, data, "C", NB_ELEM_CAMERA))
		set_camera(world, &ctx);
	else if (check_line(line, data, "L", NB_ELEM_LIGHT))
		set_light(world, &ctx);
	else if (check_line(line, data, "sp", NB_ELEM_SPHERE))
		set_sphere(world, &ctx);
	else if (check_line(line, data, "pl", NB_ELEM_PLANE))
		set_plane(world, &ctx);
	else if (check_line(line, data, "cy", NB_ELEM_CYLINDER))
		set_cylinder(world, &ctx);
	else if (!ft_is_from_charset(line, WHITE_SPACES))
	{
		free(line);
		ft_free_tab(data);
		print_err_and_exit("Parse error", PARSE_ERROR);
	}
}

static void	parse_file_content(t_world *world, int fd)
{
	char	*line;
	char	**data;

	line = get_next_line(fd);
	if (line == NULL)
	{
		free_world(world);
		print_err_and_exit("Error: Empty file", 1);
	}
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
}

t_world	*parse(int fd)
{
	t_world	*world;

	world = malloc(sizeof(*world));
	if (!(world))
		print_err_and_exit("malloc failed in parse", 1);
	init_world(world);
	parse_file_content(world, fd);
	validate_required_elements(world);
	return (world);
}
