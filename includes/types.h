#ifndef TYPES_H
# define TYPES_H

# include <stdbool.h>

// Represents a 3D vector (x, y, z coordinates)
typedef struct s_vec3 {
    double     x;
    double     y;
    double     z;
} t_vec3;

// Represents a floating-point RGB color
typedef struct s_fcolor {
    double     red;
    double     green;
    double     blue;
} t_fcolor;

// Represents a camera with position, direction, and field of view
typedef struct s_camera {
    t_vec3    position;
    t_vec3    direction;
    t_vec3    up;
    t_vec3    right;
    double    fov;
} t_camera;

typedef struct s_screen {
    t_vec3    center;
    t_vec3    top_left;
    double    from_camera_distance;
    double    pixel_step_size;
    t_vec3    pixel_horizontal;
    t_vec3    pixel_vertical;
} t_screen;

typedef struct s_ray {
    double    t;
    t_vec3    pos;
    t_vec3    dir;
} t_ray;

// Represents a point light source with position, intensity, and color
typedef struct s_light {
    t_vec3      position;
    double      intensity;
    t_fcolor    color;
} t_light;

typedef struct s_ambient_lighting {
    double      lighting_ratio;
    t_fcolor    color;
} t_ambient_lighting;

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
} t_obj_type;

// Linked list node for objects (sphere, plane, cylinder, etc.)
typedef struct s_obj_list {
    t_obj_type           type;   // Object type
    void                *obj;    // Pointer to the object (t_sphere*, t_plane*, t_cylinder*)
    struct s_obj_list   *next;   // Next object in the list
} t_obj_list;

// Represents the main world state, including window and screen info
typedef struct s_world {
    void       *mlx;  // minilibx instance pointer
    void       *win;  // minilibx window pointer
    t_camera *camera;  // List of cameras
    t_light      *light;  // List of lights
    t_ambient_lighting    *ambient;  // Ambient light
    t_obj_list      *objects;  // List of objects
    
    // 新しく追加するメンバー
    t_sphere    *spheres;    // List of spheres
    t_plane     *planes;     // List of planes
    t_cylinder  *cylinders;  // List of cylinders
} t_world;

#endif