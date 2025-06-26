#include "../miniRT.h"

t_hit	new_hit(t_vec3 hp, t_vec3 norm, t_vec3 light_dir, double t, int is_hit)
{
	t_hit new;

	new.hit_point = hp;
	new.norm = norm;
	new.light_dir = light_dir;
	new.t = t;
	new.is_hit = is_hit;
	return (new);
}

double judge(double a, double b, double c)
{
	//Δ = B^2 - 4AC
	double result;
	
	result = pow(b, 2) - 4 * a * c;
	return (result);

}

double solve_quadratic(double a, double b, double c)
{
	// t = (-B ± √(B^2 - 4AC)) / (2A)
	double judgement = judge(a, b, c);
	double f_t = (-b + sqrt(judgement)) / (2 * a);
	double s_t = (-b - sqrt(judgement)) / (2 * a);

	if (f_t < s_t && f_t >= 0)
		return (f_t);
	else if (f_t > s_t && s_t >= 0)
		return (s_t);
	return (-1);
}

t_vec3 get_hitpoint(double t, t_vec3 d, t_vec3 origin)
{
	t_vec3 p;

	p = vec_add(origin, vec_mul_scalar(d, t));
	return (p);
}

t_vec3	get_light_dir(t_vec3 hitpoint, t_vec3 light_pos)
{
	t_vec3	light_dir;

	light_dir = vec_sub(hitpoint, light_pos);
	light_dir = vec_norm(light_dir);
	return (light_dir);
}

