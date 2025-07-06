/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:51:22 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/06 17:21:49 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec3	set_vect(char **tab)
{
	t_vec3	vect;

	vect.x = ft_atod(tab[0]);
	vect.y = ft_atod(tab[1]);
	vect.z = ft_atod(tab[2]);
	ft_free_tab(tab);
	return (vect);
}

t_vec3	str_to_vect(const char *str, t_world *world)
{
	char	**tab;

	tab = ft_split(str, ',');
	if (!tab)
	{
		free_world(world);
		print_err_and_exit("malloc failed", 1);
	}
	return (set_vect(tab));
}

static void	val_rgb_value(double value, t_world *world)
{
	if (value < 0 || value > 255)
	{
		free_world(world);
		print_err_and_exit("RGB values must be between 0 and 255", 1);
	}
}

t_fcolor	char_to_rgb(const char *r, const char *g, const char *b,
		t_world *world)
{
	t_fcolor	color;

	color.red = ft_atod(r) / 255;
	color.green = ft_atod(g) / 255;
	color.blue = ft_atod(b) / 255;
	val_rgb_value(color.red, world);
	val_rgb_value(color.green, world);
	val_rgb_value(color.blue, world);
	return (color);
}

t_fcolor	str_to_rgb(const char *str, t_world *world)
{
	char		**tab;
	t_fcolor	color;

	tab = ft_split(str, ',');
	if (!tab)
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	color = char_to_rgb(tab[0], tab[1], tab[2], world);
	ft_free_tab(tab);
	return (color);
}

t_ray	new_ray(const t_vec3 position, const t_vec3 direction)
{
	t_ray	ray;

	ray.pos = position;
	ray.dir = direction;
	return (ray);
}
