/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_ops.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 13:48:58 by marvin            #+#    #+#             */
/*   Updated: 2025/07/06 13:48:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

double	vec_dot(t_vec3 a, t_vec3 b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec3	vec_cross(t_vec3 a, t_vec3 b)
{
	double	f;
	double	s;
	double	t;

	f = a.y * b.z - a.z * b.y;
	s = a.z * b.x - a.x * b.z;
	t = a.x * b.y - a.y * b.x;
	return (vec_new(f, s, t));
}

double	vec_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vec3	vec_norm(t_vec3 v)
{
	double	norm;

	norm = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	if (norm == 0)
		return (vec_new(0, 0, 0));
	return (vec_new(v.x / norm, v.y / norm, v.z / norm));
}
