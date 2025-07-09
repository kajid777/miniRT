/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:51:22 by hthomas           #+#    #+#             */
/*   Updated: 2025/07/09 21:04:51 by marvin           ###   ########.fr       */
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

t_vec3	str_to_vect(const char *str, t_world *world, t_parse_ctx *ctx)
{
	char	**tab;
	int		tab_size;

	tab = ft_split(str, ',');
	if (!tab)
	{
		if (ctx->tmp_object)
			free(ctx->tmp_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("malloc failed", 1);
	}
	tab_size = 0;
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 3)
	{
		ft_free_tab(tab);
		if (ctx->tmp_object)
			free(ctx->tmp_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("vectors are not valid not 3 numbers", 1);
	}
	return (set_vect(tab));
}

static void	val_rgb_value(double value, t_validation_ctx *val_ctx)
{
	if (value < 0 || value > 255)
	{
		if (val_ctx->current_object)
			free(val_ctx->current_object);
		if (val_ctx->tab)
			ft_free_tab(val_ctx->tab);
		if (val_ctx->ctx->line)
			free(val_ctx->ctx->line);
		if (val_ctx->ctx->data)
			ft_free_tab(val_ctx->ctx->data);
		free_world(val_ctx->world);
		print_err_and_exit("RGB values must be between 0 and 255", 1);
	}
}

t_fcolor	char_to_rgb(char **tab, t_world *world, t_parse_ctx *ctx)
{
	t_fcolor			color;
	t_validation_ctx	val_ctx;

	val_ctx.world = world;
	val_ctx.ctx = ctx;
	val_ctx.tab = tab;
	val_ctx.current_object = ctx->tmp_object;
	color.red = ft_atod(tab[0]) / 255;
	color.green = ft_atod(tab[1]) / 255;
	color.blue = ft_atod(tab[2]) / 255;
	val_rgb_value(color.red, &val_ctx);
	val_rgb_value(color.green, &val_ctx);
	val_rgb_value(color.blue, &val_ctx);
	return (color);
}

t_fcolor	str_to_rgb(const char *str, t_world *world, t_parse_ctx *ctx)
{
	char		**tab;
	t_fcolor	color;
	int			tab_size;

	tab = ft_split(str, ',');
	tab_size = 0;
	
	if (!tab)
	{
		if (ctx->tmp_object)
			free(ctx->tmp_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	while (tab[tab_size])
		tab_size++;
	if (tab_size != 3)
	{
		ft_free_tab(tab);
		if (ctx->tmp_object)
			free(ctx->tmp_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("RGB are not valid", 1);
	}
	color = char_to_rgb(tab, world, ctx);
	ft_free_tab(tab);
	return (color);
}
