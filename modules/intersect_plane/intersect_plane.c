#include "../../includes/miniRT.h"

static t_hit	plane_intersection_calc(t_vec3 dir, t_vec3 origin, 
		t_plane plane, t_vec3 light_pos)
{
	double	t;
	t_vec3	hp;
	double	denominator;
	double	numerator;
	t_vec3	norm;
	t_vec3	light_dir;

	norm = vec_norm(plane.normal_vector);
	denominator = vec_dot(dir, norm);
	if (fabs(denominator) < DBL_EPSILON)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0, NONE));
	numerator = vec_dot(vec_sub(plane.point, origin), norm);
	t = numerator / denominator;
	if (t <= 0)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0, NONE));
	hp = get_hitpoint(t, dir, origin);
	light_dir = get_light_dir(hp, light_pos);
	if (denominator < 0)
		return (new_hit(hp, norm, light_dir, t, 1, PLANE));
	else
		return (new_hit(hp, vec_mul_scalar(norm, -1), light_dir, t, 1, PLANE));
}

t_hit	intersect_plane(t_vec3 dir, t_vec3 origin, t_vec3 point, 
		t_vec3 normal, t_vec3 light_pos)
{
	t_plane	plane;

	plane.point = point;
	plane.normal_vector = normal;
	return (plane_intersection_calc(dir, origin, plane, light_pos));
}
