/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_duplicate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:11:15 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:11:15 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	check_duplicate_ambient(t_world *world, t_parse_ctx *ctx)
{
	if (world->ambient != NULL)
	{
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Error: Duplicate ambient light", 1);
	}
}

void	check_duplicate_camera(t_world *world, t_parse_ctx *ctx)
{
	if (world->camera != NULL)
	{
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Error: Duplicate camera", 1);
	}
}

void	check_duplicate_light(t_world *world, t_parse_ctx *ctx)
{
	if (world->light != NULL)
	{
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
		free_world(world);
		print_err_and_exit("Error: Duplicate light", 1);
	}
}
