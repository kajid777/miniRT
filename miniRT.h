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
# include "./minilibx-linux/mlx.h"

define SCREEN_WIDTH 1200
define SCREEN_HEIGHT 800
define M_PI 3.14159265358979323846

// Represents a 3D vector (x, y, z coordinates)
typedef struct    s_vec3 {
    double     x;
    double     y;
    double     z;
} t_vec3;

// Represents a floating-point RGB color
typedef struct s_fcolor {
    double     red;
    double     green;
    double     blue;
}               t_fcolor;

// Represents a camera with position, direction, and field of view
typedef struct s_camera {
    t_vec3    position;
    t_vec3    direction;
    double    fov;
} t_camera;

// Represents a point light source with position, intensity, and color
typedef struct s_light {
    t_vec3      position;
    double      intensity;
    t_fcolor    color;
} t_light;

// Represents a sphere with center, diameter, and color
typedef struct s_sphere {
    t_vec3      center;
    double      diameter;
    t_fcolor    color;
} t_sphere;

// Represents a plane with a point, normal vector, and color
typedef struct s_plane {
    t_vec3      point;
    t_vec3      normal_vector;
    t_fcolor    color;
} t_plane;

// Represents a cylinder with center, direction, diameter, height, and color
typedef struct s_cylinder {
    t_vec3      center;
    t_vec3      direction;
    double      diameter;
    double      height;
    t_fcolor    color;
} t_cylinder;

// Enum for object type
typedef enum e_obj_type {
    SPHERE,
    PLANE,
    CYLINDER
}   t_obj_type;

// Linked list node for objects (sphere, plane, cylinder, etc.)
typedef struct s_obj_list {
    t_obj_type           type;   // Object type
    void                *obj;    // Pointer to the object (t_sphere*, t_plane*, t_cylinder*)
    struct s_obj_list   *next;   // Next object in the list
}   t_obj_list;

// Represents the main world state, including window and screen info
// (camera, objects, ambient, and lights are commented out for now)
typedef struct s_world {
    void       *mlx;  // minilibx instance pointer
    void       *win;  // minilibx window pointer
    int        screen_width;
    int        screen_height;
    t_camera *camera;  // List of cameras
    t_light      *light;  // List of lights
    t_fcolor    ambient;  // Ambient light
    t_obj_list      *objects;  // List of objects
}               t_world;



int		ft_printf(const char *str, ...);

//end_exit.c
void	end_with_error(void);
int		exit_point(t_world *game);
void	when_mlx_ptr_failed(t_world *game);
int		exit_with_cross(t_world *game);

#endif