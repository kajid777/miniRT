/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:28:26 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/18 16:58:42 by dkajiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <stdlib.h>
# include <math.h>
# include <float.h>
# include "../minilibx-linux/mlx.h"
# include "../ft_printf/libft_srcs/libft.h"
# include "get_next_line.h"
# include "types.h"
# include "parse.h"

#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#define MALLOC_ERROR 1
#define PARSE_ERROR 1
//cylinder structures
typedef struct s_cylinder_calc
{
	t_vec3	d_perp;
	t_vec3	w_perp;
}	t_cylinder_calc;

typedef struct s_cylinder_params
{
	t_vec3		d;
	t_vec3		o;
	t_cylinder	cylinder;
	t_vec3		light_pos;
}	t_cylinder_params;

// Function declarations

void camera_prepare(t_camera *camera);
t_vec3 calculate_viewplane_center(t_camera camera, double viewplane_distance);
t_vec3 generate_one_ray(t_camera camera, t_screen screen, int x, int y);
t_fcolor get_object_color(t_hit hit, t_world *world);

// 関数プロトタイプ
int		ft_printf(const char *str, ...);

//vector_cal.c
t_vec3	vec_new(double x, double y, double z);
t_vec3	vec_add(t_vec3 a, t_vec3 b);
t_vec3	vec_sub(t_vec3 a, t_vec3 b);
double	vec_dot(t_vec3 a, t_vec3 b);
t_vec3	vec_cross(t_vec3 a, t_vec3 b);
double	vec_length(t_vec3 v);
t_vec3	vec_norm(t_vec3 v);
t_vec3	vec_mul_scalar(t_vec3 v, double scalar);
t_vec3	vec_div_scalar(t_vec3 v, double scalar);

//errors/end_exit.c
void print_err_and_exit(char *message, int exit_code);
int ft_strncmp_rev(const char *s1, const char *s2, size_t n);
void	when_mlx_ptr_failed(t_world *game);
int		exit_with_cross(t_world *game);

//errors/free_world.c
void	free_world(t_world *world);

//intersect_utils_basic.c
t_hit	new_hit(t_vec3 hp, t_vec3 norm, t_vec3 light_dir, double t, int is_hit, t_obj_type obj_type);
t_vec3	get_hitpoint(double t, t_vec3 d, t_vec3 origin);
t_vec3	get_light_dir(t_vec3 hitpoint, t_vec3 light_pos);

//intersect_sphere.c
t_hit	intersect_sphere(t_vec3 dir, t_vec3 origin, t_vec3 center, double radius, t_vec3 light_pos);

//intersect_utils.c (assuming this exists)
double	solve_quadratic(double a, double b, double c);
t_vec3	get_norm_sphere(t_vec3 hit_point, t_vec3 center);

//intersect_cylinder.c
t_vec3	get_norm_cylinder(t_vec3 hitpoint, t_cylinder cylinder);
t_hit	intersect_cylinder_caps(t_vec3 dir, t_vec3 origin,
		t_cylinder cylinder, t_vec3 light_pos);
t_hit	intersect_cylinder(t_vec3 dir, t_vec3 origin,
		t_cylinder cylinder, t_vec3 light_pos);

//cylinder_calc.c
void	calc_cylinder_vectors(t_vec3 d, t_vec3 o,
		t_cylinder cylinder, t_cylinder_calc *calc);
int		solve_cylinder_quadratic(t_cylinder_calc calc, t_cylinder cylinder,
		double results[2]);

//cylinder_utils.c
t_hit	select_best_cylinder_hit(double t1, double t2, int num_solutions,
		t_cylinder_params params);
t_hit	get_cylinder_side_hit(t_vec3 d, t_vec3 o,
		t_cylinder cylinder, t_vec3 light_pos);

//intersect_plane.c
t_hit	intersect_plane(t_vec3 dir, t_vec3 origin, t_vec3 point, t_vec3 normal);

//render.c
t_hit	find_closest_intersection(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world);
t_fcolor	calculate_lighting(t_hit hit, t_world *world);
int	color_to_int(t_fcolor color);
t_fcolor	trace_ray(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world);
void	render_scene(t_world *world);

#endif
