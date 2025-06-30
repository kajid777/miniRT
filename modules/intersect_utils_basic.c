#include "../miniRT.h"

static void	set_hit_values(t_hit *hit, t_vec3 hp, t_vec3 norm, 
		t_vec3 light_dir, double t, int is_hit)
{
	hit->hit_point = hp;
	hit->norm = norm;
	hit->light_dir = light_dir;
	hit->t = t;
	hit->is_hit = is_hit;
}

t_hit	new_hit(t_vec3 hp, t_vec3 norm, t_vec3 light_dir, double t)
{
	t_hit	new;

	set_hit_values(&new, hp, norm, light_dir, t, 1);
	return (new);
}

t_vec3	get_hitpoint(double t, t_vec3 d, t_vec3 origin)
{
	t_vec3	p;

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