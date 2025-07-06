/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:50:00 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/06 17:50:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_fcolor	*int_to_rgb(const int r, const int g, const int b, t_world *world)
{
	t_fcolor	*rgb;

	rgb = malloc(sizeof(*rgb));
	if (!(rgb))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
	return (rgb);
}

t_fcolor	*mult_rgb_double(const t_fcolor rgb, const double mult,
		t_world *world)
{
	return (int_to_rgb(rgb.red * mult, rgb.green * mult, rgb.blue * mult,
			world));
} 