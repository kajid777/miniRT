#include "vector_caluculation.h"

t_vec3  vec_new(double x, double y, double z) 
{
    t_vec3 new_vec;
    new_vec.x = x;
    new_vec.y = y;
    new_vec.z = z;
    return (new_vec);
}

t_vec3  vec_add(t_vec3 v1, t_vec3 v2) 
{
	double x;
	double y;
	double z;

	x = v1.x + v2.x;
	y = v1.y + v2.y;
	z = v1.z + v2.z;
	return vec_new(x, y, z);
}

t_vec3  vec_sub(t_vec3 v1, t_vec3 v2) 
{
	double x;
	double y;
	double z;

	x = v1.x - v2.x;
	y = v1.y - v2.y;
	z = v1.z - v2.z;
	return vec_new(x, y, z);
}

t_vec3  vec_scalar_mul(t_vec3 v, double scalar) 
{
	double x;
	double y;
	double z;

	x = v.x * scalar;
	y = v.y * scalar;
	z = v.z * scalar;
	return vec_new(x, y, z);
}

t_vec3  vec_scalar_div(t_vec3 v, double scalar) 
{
	double x;
	double y;
	double z;

	x = v.x / scalar;
	y = v.y / scalar;
	z = v.z / scalar;
	return vec_new(x, y, z);
}

double  vec_dot(t_vec3 v1, t_vec3 v2) 
{
	double x;
	double y;
	double z;

	x = v1.x * v2.x;
	y = v1.y * v2.y;
	z = v1.z * v2.z;
	return (x + y + z);
}

t_vec3  vec_cross(t_vec3 v1, t_vec3 v2) 
{
	//保留
}

double  vec_length(t_vec3 v) 
{
	double n;
	n = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));

	return (n);
}

t_vec3  vec_normalize(t_vec3 v) 
{
	//ノルムを計算
	double n;
	n = sqrt(pow(v.x, 2) + pow(v.y, 2) + pow(v.z, 2));
	
	if (n == 0)
		return vec_new(0, 0, 0);
	//各成分をノルムで割る
	return vec_new(v.x / n, v.y / n, v.z / n);
}
