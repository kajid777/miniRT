#include "../../miniRT.h"

int judge(double a, double b, double c)
{
	//Δ = B^2 - 4AC
	double result;
	
	result = pow(b, 2) - 4 * a * c;
	if (result < 0)
		return (-1);
	else if (result > 0)
		return (2);
	else
		return (1);
}

double solve_quadratic(double a, double b, double c)
{
	// t = (-B ± √(B^2 - 4AC)) / (2A)
	double t = - b + sqrt(pow(b, 2) - 4 * a * c) / (2 * a);
	return (t);
}

t_vec3 get_hitpoint(double t, t_vec3 d, t_vec3 origin)
{
	t_vec3 p;

	p = vec_add(origin, vec_mul_scalar(d, t));
	return (p);
}

t_vec3 intersect_sphere(t_vec3 dir, t_vec3 origin, t_vec3 center, double radius)
{
	t_vec3 d;
	t_vec3 o;
	t_vec3 c;
	double r;

	d = dir;
	o = origin;
	c = center;
	r = radius;

	//rayの方程式
	//P = O + td
	//球の方程式
	//|P - C|^2	= r^2
	
	//t^2(D ・D) + t(2(D ・(O - C))) + ((O - C)(O - C) - r^2) = 0 
	//判別式 At^2 + Bt + C = 0
	//A = (D ・D) B = (2(D ・(O - C))) C = ((O - C)(O - C) - r^2)
	//vec_dot(vec_dot(D, vec_sub(O, C)));
	//vec_sub(vec_dot(vec_sub(O, C), vec_sub(O, C)), pow(r, 2))
	
	//judge(vec_dot(D, D), vec_dot(vec_dot(D, vec_sub(O, C)), vec_sub(vec_dot(vec_sub(O, C), vec_sub(O, C)), pow(r, 2))));
	double j_a = vec_dot(d, d);
	double j_b = 2 * (vec_dot(d, vec_sub(o, c)));
	double j_c = vec_dot(vec_sub(o, c), vec_sub(o, c)) - pow(r, 2);
	int result = judge(j_a, j_b, j_c);

	//これはカメラの後ろ
	if (result == -1)
		return vec_new(0, 0, 0);

	double t = solve_quadratic(j_a, j_b, j_c);
	return (get_hitpoint(t, d, o));
} 
