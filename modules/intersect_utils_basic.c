#include "../includes/miniRT.h"

static void	set_hit_values(t_hit *hit, t_vec3 hp, t_vec3 norm, 
		t_vec3 light_dir, double t, int is_hit, t_obj_type obj_type, void *hit_object)
{
	hit->hit_point = hp;
	hit->norm = norm;
	hit->light_dir = light_dir;
	hit->t = t;
	hit->is_hit = is_hit;
	hit->obj_type = obj_type;
	hit->hit_object = hit_object;
}

t_hit	new_hit(t_vec3 hp, t_vec3 norm, t_vec3 light_dir, double t, int is_hit, t_obj_type obj_type, void *hit_object)
{
	t_hit	new;

	set_hit_values(&new, hp, norm, light_dir, t, is_hit, obj_type, hit_object);
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

	light_dir = vec_sub(light_pos, hitpoint);
	light_dir = vec_norm(light_dir);
	return (light_dir);
}

int	is_in_shadow(t_vec3 point, t_vec3 light_pos, t_world *world)
{
	t_vec3	shadow_ray_dir;
	t_vec3	shadow_ray_origin;
	t_hit	shadow_hit;
	double	light_distance;
	double	epsilon;

	epsilon = 0.001;
	light_distance = vec_length(vec_sub(light_pos, point));
	shadow_ray_dir = vec_norm(vec_sub(light_pos, point));
	shadow_ray_origin = vec_add(point, vec_mul_scalar(shadow_ray_dir, epsilon));
	
	shadow_hit = find_closest_intersection(shadow_ray_origin, shadow_ray_dir, world);
	
	if (shadow_hit.is_hit && shadow_hit.t > 0 && shadow_hit.t < light_distance)
		return (1);
	return (0);
}
