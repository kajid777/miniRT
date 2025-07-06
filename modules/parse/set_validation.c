/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:50:00 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/06 17:50:00 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

void	val_camera_direction(t_vec3 direction, t_camera *camera,
		t_world *world)
{
	if (direction.x == 0 && direction.y == 0 && direction.z == 0)
	{
		free(camera);
		free_world(world);
		print_err_and_exit("Error: Camera direction cannot be (0,0,0)", 1);
	}
}

void	val_camera_fov(double fov, t_camera *camera, t_world *world)
{
	if (fov <= 0 || fov >= 180)
	{
		free(camera);
		free_world(world);
		print_err_and_exit("Error: FOV must be between 0 and 180 degrees", 1);
	}
}

void	val_ambient_ratio(double ratio, t_ambient_lighting *ambient,
		t_world *world)
{
	if (ratio < 0.0 || ratio > 1.0)
	{
		free(ambient);
		free_world(world);
		print_err_and_exit("Ambient lighting ratio must be in range [0.0,1.0]",
			1);
	}
}

void	val_normalized_vector(t_vec3 vector, void *object, t_world *world)
{
	if (vector.x < -1.0 || vector.x > 1.0 || vector.y < -1.0 || vector.y > 1.0
		|| vector.z < -1.0 || vector.z > 1.0)
	{
		free(object);
		free_world(world);
		print_err_and_exit("Normalized vector must be in range [-1,1]",
			1);
	}
}

void	val_light_brightness(double brightness, t_light *light,
		t_world *world)
{
	if (brightness < 0.0 || brightness > 1.0)
	{
		free(light);
		free_world(world);
		print_err_and_exit("Light brightness ratio must be in range [0.0,1.0]",
			1);
	}
}
