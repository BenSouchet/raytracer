/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hsv_editon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 22:11:01 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 17:25:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

cl_float3		ft_hsv_to_vec(t_hsv hsv)
{
	double		c;
	double		h_prime;
	double		x;
	double		m;
	cl_float3	v;

	c = hsv.v * hsv.s;
	h_prime = fmod(hsv.h / 60.0f, 6);
	x = c * (1 - fabs(fmod(h_prime, 2) - 1));
	m = hsv.v - c;
	v = (cl_float3){{0, 0, 0}};
	if (0 <= h_prime && h_prime < 1)
		v = (cl_float3){{c, x, 0}};
	else if (1 <= h_prime && h_prime < 2)
		v = (cl_float3){{x, c, 0}};
	else if (2 <= h_prime && h_prime < 3)
		v = (cl_float3){{0, c, x}};
	else if (3 <= h_prime && h_prime < 4)
		v = (cl_float3){{0, x, c}};
	else if (4 <= h_prime && h_prime < 5)
		v = (cl_float3){{x, 0, c}};
	else if (5 <= h_prime && h_prime < 6)
		v = (cl_float3){{c, 0, x}};
	return ((cl_float3){{(v.x + m) * 255.0f, (v.y + m) * 255.0f,
	(v.z + m) * 255.0f}});
}

t_hsv			ft_vec_to_hsv(cl_float3 c)
{
	t_hsv		out;
	double		min;
	double		max;
	double		delta;

	min = (c.x < c.y) ? c.x : c.y;
	min = (min < c.z) ? min : c.z;
	max = (c.x > c.y) ? c.x : c.y;
	max = (max > c.z) ? max : c.z;
	delta = max - min;
	out = (t_hsv){0.0f, 0.0f, max};
	if (delta > 0.00001)
	{
		if (max == c.x)
			out.h = 60 * (fmod(((c.y - c.z) / delta), 6));
		else if (max == c.y)
			out.h = 60 * (((c.z - c.x) / delta) + 2);
		else if (max == c.z)
			out.h = 60 * (((c.x - c.y) / delta) + 4);
		out.s = (max > 0.00001) ? delta / max : 0.0f;
	}
	if (out.h < 0.0f)
		out.h += 360.0f;
	return (out);
}
