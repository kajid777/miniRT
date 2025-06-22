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

#include "miniRT.h"

//スクリーンの中心位置が決まる。
//スクリーンの左上はしから右上はしまでfor文を回す。
//スクリーンの左から１マス右、一マス下がどのくらいのベクトルの移動なのかを確定させる。
//スクリーンの一マスの座標とカメラを通るレイを求める。
double calculate_viewplane_distance(int fov)
{
	double ratio;
	double viewplane_distance;
	
	ratio = 1.0 / tan((M_PI * fov /180) / 2);
	viewplane_distance = SCREEN_WIDTH * ratio;
	return (viewplane_distance);
}

t_vec3 calculate_viewplane_center(t_camera camera, double viewplane_distance)
{
	t_vec3	viewplane_center;
	t_vec3	normalized_direction;
	t_vec3	cam_to_viewplane_vec;

	normalized_direction = vec_norm(camera.direction);
	cam_to_viewplane_vec = vec_mul_scalar(normalized_direction, viewplane_distance);
	viewplane_center = vec_add(camera.position + cam_to_viewplane_vec);
}

void calculate_camera_right(t_camera camera)
{
	t_vec camera_right;
	t_vec normalized_camera_right;
	t_vec world_up;

	world_up = vec_new(0, 1, 0);
	camera_right = vec_cross(camera.direction, world_up);
	normalized_camera_right = vec_norm(camera_right);
	camera.right = normalized_camera_right;
	//カメラの向きが天を仰いでいた時の例外処理をする
}

void calculate_camera_up(t_vec viewplane_center, t_camera camera)
{
	t_vec camera_up;
	t_vec normalized_camera_up;

	camera_up = vec_cross(camera.right, camera.direction);
	normalized_camera_up = vec_norm(camera_up);
	camera.up = normalized_camera_up;
}

void generate_one_ray(t_camera camera, int x, int y)
{
	
}

void generate_rays(t_camera camera)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		while (x < SCREEN_WIDTH)
		{

			//スクリーンの中心位置からのベクトルを求める
			//スクリーンの中心位置からのベクトルとカメラの向きからなる平面との交点を求める
		}
	}
}