/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkajiwar <dkajiwar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:28:26 by dkajiwar          #+#    #+#             */
/*   Updated: 2025/06/15 16:03:14 by dkajiwar         ###   ########.fr       */
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

// Vector3D
typedef struct    s_vec3 {
    double     x;
    double     y;
    double     z;
} t_vec3;

typedef struct s_fcolor {
    double     red;
    double     green;
    double     blue;
}               t_fcolor;

typedef struct s_world {
    void       *mlx;  // minilibx特有のやつ
    void       *win;  // minilibxのウィンドウを指すポインタ
    int        screen_width;
    int        screen_height;
    // t_dlist *cameras;  // カメラのリスト
    // t_list      *objects;  // 物体のリスト
    // t_fcolor    ambient;  // 環境光の強度
    // t_list      *lights;  // 光源のリスト
}               t_world;
int		ft_printf(const char *str, ...);

//end_exit.c
void	end_with_error(void);
int		exit_point(t_world *game);
void	when_mlx_ptr_failed(t_world *game);
int		exit_with_cross(t_world *game);

#endif