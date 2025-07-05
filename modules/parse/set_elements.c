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

#include "../../includes/miniRT.h"

t_fcolor	*int_to_rgb(const int r, const int g, const int b, t_world *world)
{
	t_fcolor	*rgb;

	if(!(rgb = malloc(sizeof(*rgb))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	rgb->red = r;
	rgb->green = g;
	rgb->blue = b;
	return (rgb);
}

t_fcolor	*mult_rgb_double(const t_fcolor rgb, const double mult, t_world *world)
{
	return (int_to_rgb(rgb.red * mult, rgb.green * mult, rgb.blue * mult, world));
}

// カメラの方向ベクトルが有効かチェックする関数
static void	validate_camera_direction(t_vec3 direction, t_camera *camera, t_world *world)
{
	if (direction.x == 0 && direction.y == 0 && direction.z == 0)
	{
		free(camera);
		free_world(world);
		print_err_and_exit("Error: Camera direction cannot be (0,0,0)", 1);
	}
}

// カメラのFOVが有効かチェックする関数
static void	validate_camera_fov(double fov, t_camera *camera, t_world *world)
{
	if (fov <= 0 || fov >= 180)
	{
		free(camera);
		free_world(world);
		print_err_and_exit("Error: FOV must be between 0 and 180 degrees", 1);
	}
}
// シーンの環境光（アンビエントライト）を設定する関数
void	set_ambient_light(t_world *world, char **data)
{
	t_ambient_lighting	*ambient_light;
	double			ratio;

	if (!(ambient_light = malloc(sizeof(*ambient_light))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	ratio = ft_atod(data[1]);
	ambient_light->color = *mult_rgb_double(str_to_rgb(data[2], world), ratio, world);
	ambient_light->lighting_ratio = ratio;
	world->ambient = ambient_light;
}

// シーンにカメラを追加する関数
void	set_camera(t_world *world, char **data)
{
	t_camera	*camera;
	t_vec3		direction;
	double		fov;

	if (!(camera = malloc(sizeof(*camera))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	camera->position = str_to_vect(data[1]);
	direction = str_to_vect(data[2]);
	fov = ft_atod(data[3]);
	
	validate_camera_direction(direction, camera, world);
	validate_camera_fov(fov, camera, world);
	
	camera->direction = vec_norm(direction);
	camera->fov = fov;
	world->camera = camera;
}

// シーンにライトを追加する関数
void	set_light(t_world *world, char **data)
{
	t_light		*light;
	int			ratio;

	if (!(light = malloc(sizeof(*light))))
	{
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	light->position = str_to_vect(data[1]);
	ratio = ft_atod(data[2]) * 255;
	light->color = *mult_rgb_double(str_to_rgb(data[3], world), ratio, world);
	world->light = light;
}
