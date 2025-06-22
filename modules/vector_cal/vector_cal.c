#include <math.h>
#include "../../miniRT.h"

t_vec3 vec_new(double x, double y, double z)
{
	t_vec3 new;

	new.x = x;
	new.y = y;
	new.z = z;
	return (new);
}

t_vec3 vec_add(t_vec3 a, t_vec3 b)
{
	return (vec_new(a.x + b.x, a.y + b.y, a.z + b.z));
}

t_vec3 vec_sub(t_vec3 a, t_vec3 b)
{
	return (vec_new(a.x - b.x, a.y - b.y, a.z - b.z));
}

double vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);	
}

t_vec3 vec_cross(t_vec3 a, t_vec3 b) 
{
	double f;
	double s;
	double t;

	f = a.y * b.z - a.z * b.y;
	s = a.z * b.x - a.x * b.z;
	t = a.x * b.y - a.y * b.x;
	return (vec_new(f, s, t));
}

t_vec3 vec_norm(t_vec3 v)
{
	double norm;

	norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (norm == 0)
		return (vec_new(0, 0, 0));
	return (vec_new(v.x / norm, v.y / norm, v.z / norm));
}

t_vec3 vec_mul_scalar(t_vec3 v, double scalar)
{
	return (vec_new(v.x * scalar, v.y * scalar, v.z * scalar));
}
