/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:54:10 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/25 20:37:03 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_fcolor	*int_to_rgb(const int r, const int g, const int b)
{
	t_fcolor	*rgb;

	if(!(rgb = malloc(sizeof(*rgb))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
	return (rgb);
}

t_fcolor	*mult_rgb_double(const t_fcolor rgb, const double mult)
{
	return (int_to_rgb(rgb.red * mult, rgb.green * mult, rgb.blue * mult));
}
// シーンの環境光（アンビエントライト）を設定する関数
void	set_ambient_light(t_world *world, char **data)
{
	t_ambient_lighting	*ambient_light;
	double			ratio;

	if (!(ambient_light = malloc(sizeof(*ambient_light))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	ratio = ft_atod(data[1]);
	ambient_light->color = *mult_rgb_double(str_to_rgb(data[2]), ratio);
	ambient_light->lighting_ratio = ratio;
	world->ambient = ambient_light;
}

// シーンにカメラを追加する関数
void	set_camera(t_world *world, char **data)
{
	t_camera	*camera;

	if (!(camera = malloc(sizeof(*camera))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	camera->position = str_to_vect(data[1]);
	camera->direction = vec_norm(str_to_vect(data[2]));
	// camera->up = new_vect(0, 1, 0);
	camera->fov = ft_atod(data[3]);
	// world->camerasではなくworld->cameraに直接代入
	world->camera = camera;
}

// シーンにライトを追加する関数
void	set_light(t_world *world, char **data)
{
	t_light		*light;
	int			ratio;

	if (!(light = malloc(sizeof(*light))))
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	light->position = str_to_vect(data[1]);
	ratio = ft_atod(data[2]) * 255;
	light->color = *mult_rgb_double(str_to_rgb(data[3]), ratio);
	// world->lightsではなくworld->lightに直接代入
	world->light = light;
}
