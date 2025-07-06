#include "../../includes/miniRT.h"

void calculate_camera_right(t_camera *camera)
{
	t_vec3 camera_right;
	t_vec3 normalized_camera_right;
	t_vec3 world_up;

	world_up = vec_new(0, 1, 0);
	camera_right = vec_cross(camera->direction, world_up);
	if (vec_length(camera_right) == 0)
	{
		camera_right = vec_new(1, 0, 0);
	}
	normalized_camera_right = vec_norm(camera_right);
	camera->right = normalized_camera_right;
}

void calculate_camera_up(t_camera *camera)
{
	t_vec3 camera_up;
	t_vec3 normalized_camera_up;

	camera_up = vec_cross(camera->right, camera->direction);
	normalized_camera_up = vec_norm(camera_up);
	camera->up = normalized_camera_up;
}

void camera_prepare(t_camera *camera)
{
    calculate_camera_right(camera);
    calculate_camera_up(camera);
}
