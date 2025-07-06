/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/07/06 13:47:27 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 13:47:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>

// Represents a 3D vector (x, y, z coordinates)
typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

// Represents a floating-point RGB color
typedef struct s_fcolor
{
	double	red;
	double	green;
	double	blue;
}	t_fcolor;

// Structure to store rendering data
typedef struct s_render_data
{
	int		bits_per_pixel;
	int		line_length;
	char	*addr;
}	t_render_data;

// Represents a camera with position, direction, and field of view
typedef struct s_camera
{
	t_vec3	position;
	t_vec3	direction;
	t_vec3	up;
	t_vec3	right;
	double	fov;
}	t_camera;

typedef struct s_screen
{
	t_vec3	center;
	t_vec3	top_left;
	double	from_camera_distance;
	double	pixel_step_size;
	t_vec3	pixel_horizontal;
	t_vec3	pixel_vertical;
}	t_screen;

typedef struct s_ray
{
	double	t;
	t_vec3	pos;
	t_vec3	dir;
}	t_ray;

// Represents a point light source with position, intensity, and color
typedef struct s_light
{
	t_vec3		position;
	double		intensity;
	t_fcolor	color;
}	t_light;

typedef struct s_ambient_lighting
{
	double		lighting_ratio;
	t_fcolor	color;
}	t_ambient_lighting;

// Represents a sphere with center, diameter, and color
typedef struct s_sphere
{
	t_vec3			center;
	double			diameter;
	t_fcolor		color;
	struct s_sphere	*next;
}	t_sphere;

// Represents a plane with a point, normal vector, and color
typedef struct s_plane
{
	t_vec3			point;
	t_vec3			normal_vector;
	t_fcolor		color;
	struct s_plane	*next;
}	t_plane;

// Represents a cylinder with center, direction, diameter, height, and color
typedef struct s_cylinder
{
	t_vec3				center;
	t_vec3				direction;
	double				diameter;
	double				height;
	t_fcolor			color;
	struct s_cylinder	*next;
}	t_cylinder;

// Enum for object type
typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	CYLINDER,
	NONE
}	t_obj_type;

typedef struct s_hit_params
{
	t_vec3		hp;
	t_vec3		norm;
	t_vec3		light_dir;
	double		t;
	int			is_hit;
	t_obj_type	obj_type;
}	t_hit_params;

typedef struct s_hit
{
	t_vec3		hit_point;
	t_vec3		norm;
	t_vec3		light_dir;
	double		t;
	int			is_hit;
	t_obj_type	obj_type;
}	t_hit;

typedef struct s_world
{
	void				*mlx;
	void				*win;
	t_camera			*camera;
	t_light				*light;
	t_ambient_lighting	*ambient;
	t_sphere			*sphere;
	t_plane				*plane;
	t_cylinder			*cylinder;
}	t_world;

#endif