/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ctx_and_world.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 20:43:28 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/15 20:43:28 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	free_ctx_and_world(t_world *world, t_parse_ctx *ctx)
{
	if (ctx)
	{
		if (ctx->tmp_object)
			free(ctx->tmp_object);
		if (ctx->line)
			free(ctx->line);
		if (ctx->data)
			ft_free_tab(ctx->data);
	}
	free_world(world);
}
