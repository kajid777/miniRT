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
	top_left_corner = vec_sub(top_left_corner, b);
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

t_hit	find_closest_intersection(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world)
{
	t_hit	closest_hit;
	t_hit	current_hit;
	double	closest_t;

	closest_hit.is_hit = 0;
	closest_t = DBL_MAX;
	
	if (world->sphere)
	{
		current_hit = intersect_sphere(ray_dir, ray_origin, 
			world->sphere->center, world->sphere->diameter / 2.0);
		if (current_hit.is_hit && current_hit.t > 0.001 && current_hit.t < closest_t)
		{
			closest_t = current_hit.t;
			closest_hit = current_hit;
		}
	}
	
	if (world->plane)
	{
		current_hit = intersect_plane(ray_dir, ray_origin, 
			world->plane->point, world->plane->normal_vector);
		if (current_hit.is_hit && current_hit.t > 0.001 && current_hit.t < closest_t)
		{
			closest_t = current_hit.t;
			closest_hit = current_hit;
		}
	}
	
	if (world->cylinder)
	{
		current_hit = intersect_cylinder(ray_dir, ray_origin, 
			*world->cylinder, world->light->position);
		if (current_hit.is_hit && current_hit.t > 0.001 && current_hit.t < closest_t)
		{
			closest_t = current_hit.t;
			closest_hit = current_hit;
		}
	}
	
	return (closest_hit);
}

t_fcolor	calculate_lighting(t_hit hit, t_world *world)
{
	t_fcolor	result;
	t_fcolor	ambient;
	t_fcolor	diffuse;
	double		light_intensity;
	
	ambient.red = world->ambient->color.red * world->ambient->lighting_ratio;
	ambient.green = world->ambient->color.green * world->ambient->lighting_ratio;
	ambient.blue = world->ambient->color.blue * world->ambient->lighting_ratio;
	
	light_intensity = vec_dot(hit.norm, hit.light_dir);
	if (light_intensity < 0)
		light_intensity = 0;
	
	diffuse.red = world->light->color.red * world->light->intensity * light_intensity;
	diffuse.green = world->light->color.green * world->light->intensity * light_intensity;
	diffuse.blue = world->light->color.blue * world->light->intensity * light_intensity;
	
	result.red = ambient.red + diffuse.red;
	result.green = ambient.green + diffuse.green;
	result.blue = ambient.blue + diffuse.blue;
	
	if (result.red > 1.0) result.red = 1.0;
	if (result.green > 1.0) result.green = 1.0;
	if (result.blue > 1.0) result.blue = 1.0;
	
	return (result);
}

int	color_to_int(t_fcolor color)
{
	int	r, g, b;
	
	r = (int)(color.red * 255);
	g = (int)(color.green * 255);
	b = (int)(color.blue * 255);
	
	if (r > 255) r = 255;
	if (g > 255) g = 255;
	if (b > 255) b = 255;
	if (r < 0) r = 0;
	if (g < 0) g = 0;
	if (b < 0) b = 0;
	
	return ((r << 16) | (g << 8) | b);
}

t_fcolor	get_object_color(t_hit hit, t_world *world)
{
	t_fcolor	object_color;
	
	if (world->sphere && hit.t > 0)
		object_color = world->sphere->color;
	else if (world->plane && hit.t > 0)
		object_color = world->plane->color;
	else if (world->cylinder && hit.t > 0)
		object_color = world->cylinder->color;
	else
	{
		object_color.red = 1.0;
		object_color.green = 1.0;
		object_color.blue = 1.0;
	}
	return (object_color);
}

t_fcolor	trace_ray(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world)
{
	t_hit		hit;
	t_fcolor	color;
	t_fcolor	object_color;
	
	hit = find_closest_intersection(ray_origin, ray_dir, world);
	
	if (!hit.is_hit)
	{
		color.red = 0.0;
		color.green = 0.0;
		color.blue = 0.0;
		return (color);
	}
	
	object_color = get_object_color(hit, world);
	color = calculate_lighting(hit, world);
	
	color.red *= object_color.red;
	color.green *= object_color.green;
	color.blue *= object_color.blue;
	
	return (color);
}

void	render_scene(t_world *world)
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			x, y;
	t_vec3		ray_dir;
	t_fcolor	pixel_color;
	int			color_int;
	t_screen	*screen;
	
	img = mlx_new_image(world->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!img)
		return;
	
	addr = mlx_get_data_addr(img, &bits_per_pixel, &line_length, &endian);
	
	camera_prepare(world->camera);
	
	screen = malloc(sizeof(t_screen));
	if (!screen)
	{
		mlx_destroy_image(world->mlx, img);
		return;
	}
	
	calculate_viewplane_distance(*world->camera, screen);
	screen->center = calculate_viewplane_center(*world->camera, screen->from_camera_distance);
	calculate_pixel_step_size(*world->camera, screen);
	calculate_step_vec(*world->camera, screen);
	calculate_top_left_corner(screen);
	
	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ray_dir = generate_one_ray(*world->camera, *screen, x, y);
			pixel_color = trace_ray(world->camera->position, ray_dir, world);
			color_int = color_to_int(pixel_color);
			
			*(int*)(addr + (y * line_length + x * (bits_per_pixel / 8))) = color_int;
			
			x++;
		}
		y++;
	}
	
	mlx_put_image_to_window(world->mlx, world->win, img, 0, 0);
	mlx_destroy_image(world->mlx, img);
	free(screen);
}
