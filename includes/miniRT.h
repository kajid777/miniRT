/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:28:26 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/07/15 20:23:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../ft_printf/libft_srcs/libft.h"
# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "get_next_line.h"
# include "parse.h"
# include "types.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SCREEN_WIDTH 1200
# define SCREEN_HEIGHT 800
# define MALLOC_ERROR 1
# define PARSE_ERROR 1
# define DBL_MAX 1.7976931348623157e+308
# define DBL_EPSILON 2.2204460492503131e-16

// cylinder structures
typedef struct s_cylinder_calc
{
	t_vec3		d_perp;
	t_vec3		w_perp;
}				t_cylinder_calc;

typedef struct s_cylinder_params
{
	t_vec3		d;
	t_vec3		o;
	t_cylinder	cylinder;
	t_vec3		light_pos;
}				t_cylinder_params;

typedef struct s_split_segment
{
	char		**result;
	int			*seg_idx;
	const char	*str;
	int			seg_start;
	int			seg_len;
}				t_split_segment;

// Function declarations

void			camera_prepare(t_camera *camera);
void			calculate_viewplane_distance(t_camera camera, t_screen *screen);
t_vec3			calculate_viewplane_center(t_camera camera,
					double viewplane_distance);
void			calculate_pixel_step_size(t_camera camera, t_screen *screen);
void			calculate_step_vec(t_camera camera, t_screen *screen);
void			calculate_top_left_corner(t_screen *screen);
t_vec3			generate_one_ray(t_camera camera, t_screen screen, int x,
					int y);
t_hit			find_closest_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
					t_world *world);
t_fcolor		calculate_lighting(t_hit hit, t_world *world);
t_fcolor		get_object_color(t_hit hit);
t_fcolor		trace_ray(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world);
int				color_to_int(t_fcolor color);
void			render_scene(t_world *world);

int				ft_printf(const char *str, ...);

// vector_cal.c
t_vec3			vec_new(double x, double y, double z);
t_vec3			vec_add(t_vec3 a, t_vec3 b);
t_vec3			vec_sub(t_vec3 a, t_vec3 b);
double			vec_dot(t_vec3 a, t_vec3 b);
t_vec3			vec_cross(t_vec3 a, t_vec3 b);
double			vec_length(t_vec3 v);
t_vec3			vec_norm(t_vec3 v);
t_vec3			vec_mul_scalar(t_vec3 v, double scalar);
t_vec3			vec_div_scalar(t_vec3 v, double scalar);

// errors/end_exit.c
void			print_err_and_exit(char *message, int exit_code);
int				ft_strncmp_rev(const char *s1, const char *s2, size_t n);
void			when_mlx_ptr_failed(t_world *game);
int				exit_with_cross(t_world *game);
int				handle_key_press(int keycode, t_world *world);
void			disable_window_resize(t_world *world);

// errors/free_world.c
void			free_world(t_world *world);
void			free_obj_lists(t_world *world);
void			free_ctx_and_world(t_world *world, t_parse_ctx *ctx);

// intersect_utils_basic.c
t_hit			new_hit(t_hit_params params);
t_vec3			get_hitpoint(double t, t_vec3 d, t_vec3 origin);
t_vec3			get_light_dir(t_vec3 hitpoint, t_vec3 light_pos);
int				is_in_shadow(t_vec3 point, t_vec3 light_pos, t_world *world);

// intersect_sphere.c
t_hit			intersect_sphere(t_vec3 dir, t_vec3 origin, t_sphere *sphere,
					t_vec3 light_pos);

// intersect_utils.c (assuming this exists)
double			solve_quadratic(double a, double b, double c);
t_vec3			get_norm_sphere(t_vec3 hit_point, t_vec3 center);

// intersect_cylinder.c
t_vec3			get_norm_cylinder(t_vec3 hitpoint, t_cylinder cylinder);
t_hit			intersect_cylinder_caps(t_vec3 dir, t_vec3 origin,
					t_cylinder cylinder);
t_hit			intersect_cylinder(t_vec3 dir, t_vec3 origin,
					t_cylinder *cylinder, t_vec3 light_pos);

// cylinder_calc.c
void			calc_cylinder_vectors(t_vec3 d, t_vec3 o, t_cylinder cylinder,
					t_cylinder_calc *calc);
int				solve_cylinder_quadratic(t_cylinder_calc calc,
					t_cylinder cylinder, double results[2]);

// cylinder_utils.c
t_hit			select_best_cylinder_hit(double t1, double t2,
					int num_solutions, t_cylinder_params params);
t_hit			get_cylinder_side_hit(t_vec3 d, t_vec3 o, t_cylinder cylinder,
					t_vec3 light_pos);

// intersect_plane.c
t_hit			intersect_plane(t_vec3 dir, t_vec3 origin, t_plane *plane,
					t_vec3 light_pos);

// render.c
t_hit			find_closest_intersection(t_vec3 ray_origin, t_vec3 ray_dir,
					t_world *world);
t_fcolor		calculate_lighting(t_hit hit, t_world *world);
int				color_to_int(t_fcolor color);
t_fcolor		trace_ray(t_vec3 ray_origin, t_vec3 ray_dir, t_world *world);
void			render_scene(t_world *world);

// ft_split_set_3.c
void			init_split_segment(t_split_segment *seg, char **result,
					int *seg_idx, const char *str);
void			set_segment_range(t_split_segment *seg, int seg_start,
					int seg_len);
int				handle_delimiter(t_split_segment *seg, int *seg_start, int i);
int				create_segment(t_split_segment *seg);
int				process_segment(t_split_segment *seg);

// set_validation.c
void			val_camera_direction(t_vec3 direction, t_camera *camera,
					t_world *world, t_parse_ctx *ctx);
void			val_camera_fov(double fov, t_camera *camera, t_world *world,
					t_parse_ctx *ctx);
void			val_camera_fov(double fov, t_camera *camera, t_world *world,
					t_parse_ctx *ctx);
void			val_ambient_ratio(double ratio, t_ambient_lighting *ambient,
					t_world *world, t_parse_ctx *ctx);
void			val_normalized_vector(t_vec3 vector, void *object,
					t_world *world, t_parse_ctx *ctx);
void			val_light_brightness(double brightness, t_light *light,
					t_world *world, t_parse_ctx *ctx);

// set_colors.c
t_fcolor		*int_to_rgb(const int r, const int g, const int b,
					t_world *world);
t_fcolor		*mult_rgb_double(const t_fcolor rgb, const double mult,
					t_world *world);

// check_duplicate.c
void			check_duplicate_ambient(t_world *world, t_parse_ctx *ctx);
void			check_duplicate_camera(t_world *world, t_parse_ctx *ctx);
void			check_duplicate_light(t_world *world, t_parse_ctx *ctx);

// camera_inside_check.c
int				is_camera_inside_object(t_world *world);

#endif
