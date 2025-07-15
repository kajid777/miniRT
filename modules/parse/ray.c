/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:15:45 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 18:27:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec3	set_vect(char **tab, t_world *world, t_parse_ctx *ctx)
{
	t_vec3	vect;

	vect.x = ft_atod_safe(tab[0], world, ctx);
	vect.y = ft_atod_safe(tab[1], world, ctx);
	vect.z = ft_atod_safe(tab[2], world, ctx);
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
	return (set_vect(tab, world, ctx));
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
	double				red_val;
	double				green_val;
	double				blue_val;

	val_ctx.world = world;
	val_ctx.ctx = ctx;
	val_ctx.tab = tab;
	val_ctx.current_object = ctx->tmp_object;
	red_val = ft_atod_safe(tab[0], world, ctx);
	green_val = ft_atod_safe(tab[1], world, ctx);
	blue_val = ft_atod_safe(tab[2], world, ctx);
	val_rgb_value(red_val, &val_ctx);
	val_rgb_value(green_val, &val_ctx);
	val_rgb_value(blue_val, &val_ctx);
	color.red = red_val / 255;
	color.green = green_val / 255;
	color.blue = blue_val / 255;
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
