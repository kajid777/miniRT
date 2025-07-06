/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_cal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tac <tac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 12:56:08 by tac               #+#    #+#             */
/*   Updated: 2025/07/06 12:56:09 by tac              ###   ########.fr       */
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
