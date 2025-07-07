/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:51:22 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/06 18:42:11 by thashimo         ###   ########.fr       */
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

static void	val_rgb_value(double value, t_world *world, t_parse_ctx *ctx, 
		char **tab, void *current_object)
{
	if (value < 0 || value > 255)
	{
		if (current_object)
			free(current_object);
		if (tab)
			ft_free_tab(tab);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("RGB values must be between 0 and 255", 1);
	}
}

t_fcolor	char_to_rgb(char **tab, t_world *world, t_parse_ctx *ctx, 
		void *current_object)
{
	t_fcolor	color;

	color.red = ft_atod(tab[0]) / 255;
	color.green = ft_atod(tab[1]) / 255;
	color.blue = ft_atod(tab[2]) / 255;
	val_rgb_value(color.red, world, ctx, tab, current_object);
	val_rgb_value(color.green, world, ctx, tab, current_object);
	val_rgb_value(color.blue, world, ctx, tab, current_object);
	return (color);
}

t_fcolor	str_to_rgb(const char *str, t_world *world, t_parse_ctx *ctx, 
		void *current_object)
{
	char		**tab;
	t_fcolor	color;

	tab = ft_split(str, ',');
	if (!tab)
	{
		if (current_object)
			free(current_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	color = char_to_rgb(tab, world, ctx, current_object);
	ft_free_tab(tab);
	return (color);
}
