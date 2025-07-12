/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:18:31 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:19:14 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

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

bool	is_empty_or_whitespace_only(const char *line)
{
	int	i;

	if (!line)
		return (true);
	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
			&& line[i] != '\r')
			return (false);
		i++;
	}
	return (true);
}
