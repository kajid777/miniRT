#include "../../miniRT.h"

static t_hit	plane_intersection_calc(t_vec3 dir, t_vec3 origin, 
		t_plane plane)
{
	double	t;
	t_vec3	hp;
	double	denominator;
	double	numerator;
	t_vec3	norm;

	norm = vec_norm(plane.normal_vector);
	denominator = vec_dot(dir, norm);
	if (fabs(denominator) < EPSILON)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0));
	numerator = vec_dot(vec_sub(plane.point, origin), norm);
	t = numerator / denominator;
	if (t < EPSILON)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0));
	hp = get_hitpoint(t, dir, origin);
	if (denominator < 0)
		return (new_hit(hp, norm, vec_new(0, 0, 0), t, 1));
	else
		return (new_hit(hp, vec_mul_scalar(norm, -1), vec_new(0, 0, 0), t, 1));
}

t_hit	intersect_plane(t_vec3 dir, t_vec3 origin, t_vec3 point, 
		t_vec3 normal)
{
	t_plane	plane;

	plane.point = point;
	plane.normal_vector = normal;
	return (plane_intersection_calc(dir, origin, plane));
}