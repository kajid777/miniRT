#include "../../includes/miniRT.h"

t_vec3	vec_mul_scalar(t_vec3 v, double scalar)
{
	return (vec_new(v.x * scalar, v.y * scalar, v.z * scalar));
}

t_vec3	vec_div_scalar(t_vec3 v, double scalar)
{
	if (scalar == 0)
		return (vec_new(0, 0, 0));
	return (vec_new(v.x / scalar, v.y / scalar, v.z / scalar));
}
