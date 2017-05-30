/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fsdl_get_pt_clr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/02 17:55:07 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/02 18:28:47 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fsdl.h"

cl_float3	fsdl_get_pt_clr(SDL_Surface *dst, int x, int y)
{
	size_t		tmp;
	cl_float3	clr;

	tmp = (*((unsigned *)(dst->pixels + y * dst->pitch + x *
	dst->format->BytesPerPixel)));
	clr.x = (((tmp >> 24) & 0xFF));
	clr.y = (((tmp >> 16) & 0xFF));
	clr.z = (((tmp >> 8) & 0xFF));
	return (clr);
}
