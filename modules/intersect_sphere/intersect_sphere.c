#include "../../includes/miniRT.h"

static double	calc_sphere_quadratic(t_vec3 dir, t_vec3 origin, t_sphere sphere)
{
	t_vec3	oc;
	double	r;
	double	j_a;
	double	j_b;
	double	j_c;

	oc = vec_sub(origin, sphere.center);
	r = sphere.diameter / 2;
	j_a = vec_dot(dir, dir);
	j_b = 2 * vec_dot(dir, oc);
	j_c = vec_dot(oc, oc) - pow(r, 2);
	return (solve_quadratic(j_a, j_b, j_c));
}

static t_hit	sphere_intersection_calc(t_vec3 dir, t_vec3 origin, 
		t_sphere sphere)
{
	double	t;
	t_vec3	hp;

	t = calc_sphere_quadratic(dir, origin, sphere);
	if (t == -1)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0), 
				vec_new(0, 0, 0), -1, 0));
	hp = get_hitpoint(t, dir, origin);
	return (new_hit(hp, get_norm_sphere(hp, sphere.center), 
			vec_new(0, 0, 0), t, 1));
}

t_hit	intersect_sphere(t_vec3 dir, t_vec3 origin, t_vec3 center, 
		double radius)
{
	t_sphere	sphere;

	sphere.center = center;
	sphere.diameter = radius * 2;
	return (sphere_intersection_calc(dir, origin, sphere));
}
