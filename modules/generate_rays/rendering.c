/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:55:47 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 12:55:48 by tac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"
#include <math.h>

int	color_to_int(t_fcolor color)
{
	int	r;
	int	g;
	int	b;

	r = (int)(color.red * 255);
	g = (int)(color.green * 255);
	b = (int)(color.blue * 255);
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	return ((r << 16) | (g << 8) | b);
}

static void	setup_screen_parameters(t_world *world, t_screen *screen)
{
	calculate_viewplane_distance(*world->camera, screen);
	screen->center = calculate_viewplane_center(*world->camera,
			screen->from_camera_distance);
	calculate_pixel_step_size(*world->camera, screen);
	calculate_step_vec(*world->camera, screen);
	calculate_top_left_corner(screen);
}

static void	render_pixel_loop(t_world *world, t_screen *screen,
					t_render_data *data)
{
	int			x;
	int			y;
	t_vec3		ray_dir;
	t_fcolor	pixel_color;
	int			color_int;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			ray_dir = generate_one_ray(*world->camera, *screen, x, y);
			pixel_color = trace_ray(world->camera->position, ray_dir, world);
			color_int = color_to_int(pixel_color);
			*(int *)(data->addr + (y * data->line_length
					+ x * (data->bits_per_pixel / 8))) = color_int;
			x++;
		}
		y++;
	}
}

static void	setup_mlx_data(t_world *world, void **img, t_render_data *data)
{
	int	endian;

	*img = mlx_new_image(world->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	if (!*img)
	{
		free_world(world);
		print_err_and_exit("mlx_new_image failed", 1);
	}
	data->addr = mlx_get_data_addr(*img, &data->bits_per_pixel,
			&data->line_length, &endian);
}

void	render_scene(t_world *world)
{
	void			*img;
	t_screen		*screen;
	t_render_data	data;

	setup_mlx_data(world, &img, &data);
	camera_prepare(world->camera);
	screen = malloc(sizeof(t_screen));
	if (!screen)
	{
		mlx_destroy_image(world->mlx, img);
		free_world(world);
		print_err_and_exit("Malloc failed", 1);
	}
	setup_screen_parameters(world, screen);
	render_pixel_loop(world, screen, &data);
	mlx_put_image_to_window(world->mlx, world->win, img, 0, 0);
	mlx_destroy_image(world->mlx, img);
	free(screen);
}
