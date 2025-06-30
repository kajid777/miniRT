/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_rays.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 18:35:03 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/22 15:36:05 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

//スクリーンの中心位置が決まる。
//スクリーンの左上はしから右上はしまでfor文を回す。
//スクリーンの左から１マス右、一マス下がどのくらいのベクトルの移動なのかを確定させる。
//スクリーンの一マスの座標とカメラを通るレイを求める。
void calculate_viewplane_distance(t_camera camera, t_screen *screen)
{
	double ratio;
	double viewplane_distance;
	
	ratio = 1.0 / tan((M_PI * camera.fov /180) / 2);
	viewplane_distance = SCREEN_WIDTH * ratio;
	screen->from_camera_distance = viewplane_distance;
}

t_vec3 calculate_viewplane_center(t_camera camera, double viewplane_distance)
{
	t_vec3	viewplane_center;
	t_vec3	normalized_direction;
	t_vec3	cam_to_viewplane_vec;

	normalized_direction = vec_norm(camera.direction);
	cam_to_viewplane_vec = vec_mul_scalar(normalized_direction, viewplane_distance);
	viewplane_center = vec_add(camera.position, cam_to_viewplane_vec);
	return (viewplane_center);
}



void calculate_pixel_step_size(t_camera camera, t_screen *screen)
{
	double	ratio;
	double	horizontal_half_width;
	// double	vertical_half_width;

	// vertical_half_width = SCREEN_HEIGHT / 2;
	ratio = tan((M_PI * (camera.fov) / 180) / 2);
	horizontal_half_width = (screen->from_camera_distance) * ratio;
	screen->pixel_step_size =  horizontal_half_width / (SCREEN_WIDTH / 2);
}

void	calculate_step_vec(t_camera camera, t_screen *screen)
{
	t_vec3	horizontal_step_vec;
	t_vec3	vertical_step_vec;

	horizontal_step_vec = vec_div_scalar(camera.right, screen->pixel_step_size);
	vertical_step_vec = vec_div_scalar(camera.up, screen->pixel_step_size);
	screen->pixel_horizontal = horizontal_step_vec;
	screen->pixel_vertical = vertical_step_vec;
}

void calculate_top_left_corner(t_screen *screen)
{
	t_vec3	top_left_corner;
	t_vec3	a;
	t_vec3	b;

	a = vec_mul_scalar(screen->pixel_horizontal, SCREEN_WIDTH/2);
	b = vec_mul_scalar(screen->pixel_vertical, SCREEN_HEIGHT/2);

	top_left_corner = vec_sub(screen->center, a);
	top_left_corner = vec_sub(screen->center, b);
	screen->top_left = top_left_corner;
}

t_vec3 generate_one_ray(t_camera camera, t_screen screen, int x, int y)
{
	t_vec3	obj_on_screen;
	t_vec3	ray;
	t_vec3	normalized_ray;

	obj_on_screen = vec_add(screen.top_left, vec_mul_scalar(screen.pixel_horizontal, x));
	obj_on_screen = vec_sub(obj_on_screen, vec_mul_scalar(screen.pixel_vertical, y));
	ray = vec_sub(obj_on_screen, camera.position);
	normalized_ray = vec_norm(ray);
	return (normalized_ray);
}
void generate_rays(t_camera camera)
{
	int x;
	int y;
	t_screen *screen;
	screen = malloc(sizeof(t_screen));
	if (!screen)
		exit(1);

    calculate_viewplane_distance(camera, screen);
	calculate_pixel_step_size(camera, screen);
	calculate_step_vec(camera, screen);
	calculate_top_left_corner(screen);
	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		while (x < SCREEN_WIDTH)
		{
			generate_one_ray(camera, *screen, x, y);

			//スクリーンの中心位置からのベクトルを求める
			//スクリーンの中心位置からのベクトルとカメラの向きからなる平面との交点を求める
			x++;
		}
		y++;
	}
}