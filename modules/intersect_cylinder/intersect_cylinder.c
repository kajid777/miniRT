#include "../../includes/miniRT.h"

t_vec3	get_norm_cylinder(t_vec3 hitpoint, t_cylinder cylinder)
{
	t_vec3	from_center;
	double	axis_projection;
	t_vec3	axis_point;
	t_vec3	norm;

	from_center = vec_sub(hitpoint, cylinder.center);
	axis_projection = vec_dot(from_center, cylinder.direction);
	axis_point = vec_add(cylinder.center,
			vec_mul_scalar(cylinder.direction, axis_projection));
	norm = vec_sub(hitpoint, axis_point);
	norm = vec_norm(norm);
	return (norm);
}

static t_hit	check_cylinder_cap(t_vec3 dir, t_vec3 origin,
		t_cylinder cylinder, t_vec3 cap_center)
{
	double	t;
	t_vec3	hp;
	t_vec3	to_center;
	double	distance_sq;
	double	radius_sq;

	radius_sq = (cylinder.diameter / 2) * (cylinder.diameter / 2);
	t = vec_dot(vec_sub(cap_center, origin), cylinder.direction)
		/ vec_dot(dir, cylinder.direction);
	if (t <= 0)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0),
				vec_new(0, 0, 0), INFINITY, 0));
	hp = get_hitpoint(t, dir, origin);
	to_center = vec_sub(hp, cap_center);
	distance_sq = vec_dot(to_center, to_center);
	if (distance_sq <= radius_sq)
		return (new_hit(hp, cylinder.direction,
				get_light_dir(hp, vec_new(0, 0, 0)), t, 1));
	return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0),
			vec_new(0, 0, 0), INFINITY, 0));
}

t_hit	intersect_cylinder_caps(t_vec3 dir, t_vec3 origin,
		t_cylinder cylinder, t_vec3 light_pos)
{
	t_vec3	cap_center_bottom;
	t_vec3	cap_center_top;
	t_hit	bottom_hit;
	t_hit	top_hit;

	if (vec_dot(dir, cylinder.direction) == 0)
		return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0),
				vec_new(0, 0, 0), INFINITY, 0));
	cap_center_bottom = vec_add(cylinder.center,
			vec_mul_scalar(cylinder.direction, -cylinder.height / 2));
	cap_center_top = vec_add(cylinder.center,
			vec_mul_scalar(cylinder.direction, cylinder.height / 2));
	bottom_hit = check_cylinder_cap(dir, origin, cylinder, cap_center_bottom);
	if (bottom_hit.is_hit)
		bottom_hit.norm = vec_mul_scalar(cylinder.direction, -1);
	top_hit = check_cylinder_cap(dir, origin, cylinder, cap_center_top);
	if (bottom_hit.is_hit && top_hit.is_hit)
	{
		if (bottom_hit.t < top_hit.t)
			return (bottom_hit);
		return (top_hit);
	}
	if (bottom_hit.is_hit)
		return (bottom_hit);
	return (top_hit);
}

t_hit	intersect_cylinder(t_vec3 dir, t_vec3 origin,
		t_cylinder cylinder, t_vec3 light_pos)
{
	t_hit	side_hit;
	t_hit	cap_hit;

	side_hit = get_cylinder_side_hit(dir, origin, cylinder, light_pos);
	cap_hit = intersect_cylinder_caps(dir, origin, cylinder, light_pos);
	if (side_hit.is_hit && cap_hit.is_hit)
	{
		if (side_hit.t < cap_hit.t)
			return (side_hit);
		return (cap_hit);
	}
	if (side_hit.is_hit)
		return (side_hit);
	if (cap_hit.is_hit)
		return (cap_hit);
	return (new_hit(vec_new(0, 0, 0), vec_new(0, 0, 0),
			vec_new(0, 0, 0), -1, 0));
}
