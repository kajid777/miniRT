/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thashimo <thashimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 13:16:24 by thashimo          #+#    #+#             */
/*   Updated: 2025/07/12 13:16:27 by thashimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_vec3	vec_mul_scalar(t_vec3 v, double scalar)
{
	return (vec_new(v.x * scalar, v.y * scalar, v.z * scalar));
}

t_vec3	vec_div_scalar(t_vec3 v, double scalar)
{
	if (scalar == 0)
		return (vec_new(0, 0, 0));
	return (vec_new(v.x / scalar, v.y / scalar, v.z / scalar));
}
