/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthomas <hthomas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 17:51:22 by hthomas           #+#    #+#             */
/*   Updated: 2022/01/26 14:27:29 by hthomas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

// 3つの文字列（x, y, z）からベクトル構造体を生成する関数
t_vec3	set_vect(const char *x, const char *y, const char *z)
{
	t_vec3	vect;

	vect.x = ft_atod(x);
	vect.y = ft_atod(y);
	vect.z = ft_atod(z);
	return (vect);
}

// カンマ区切りの文字列からベクトル構造体を生成する関数
t_vec3	str_to_vect(const char *str)
{
	char	**tab;

	tab = ft_split(str, ',');
	return (set_vect(tab[0], tab[1], tab[2]));
}

// RGB値の範囲をチェックする関数
static void	validate_rgb_value(double value, t_world *world)
{
	if (value < 0 || value > 255)
	{
		free_world(world);
		print_err_and_exit("Error: RGB values must be between 0 and 255", 1);
	}
}

// 3つの文字列（r, g, b）からRGB構造体を生成する関数
t_fcolor	char_to_rgb(const char *r, const char *g, const char *b, t_world *world)
{
	t_fcolor	color;

	color.red = ft_atod(r);
	color.green = ft_atod(g);
	color.blue = ft_atod(b);
	
	validate_rgb_value(color.red, "Red", world);
	validate_rgb_value(color.green, "Green", world);
	validate_rgb_value(color.blue, "Blue", world);
	
	return (color);
}

// カンマ区切りの文字列からRGB構造体を生成する関数
t_fcolor	str_to_rgb(const char *str, t_world *world)
{
	char	**tab;
	t_fcolor	color;

	tab = ft_split(str, ',');
	if (!tab)
	{
		free_world(world);
		print_err_and_exit("Malloc failed", MALLOC_ERROR);
	}
	color = char_to_rgb(tab[0], tab[1], tab[2], world);
	ft_free_tab(tab);
	return (color);
}

// 角度をラジアンに変換する関数
// double	to_rad(const double angle)
// {
// 	return (angle * M_PI * 0.5);
// }いらない


// 指定した位置と方向からレイ構造体を生成する関数
t_ray	new_ray(const t_vec3 position, const t_vec3 direction)
{
	t_ray	ray;

	ray.pos = position;
	ray.dir = direction;
	return (ray);
}

