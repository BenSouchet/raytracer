/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cl                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:50:15 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:51:10 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_def.h"
#include "calc.cl"

constant float2	size2	= (float2){WIDTH, HEIGHT};
constant float2	size2_2	= (float2){XCENTER, YCENTER};
constant float3	size3	= (float3){WIDTH, HEIGHT, 0};
constant float3	size3_2	= (float3){XCENTER, YCENTER, 0};

kernel void
	kernel_entry
	(global unsigned int *img_buffer
	, global t_cam *cam
	, global t_obj *objs
	, global t_lgt *lgts
	, short nobjs
	, short nlgts
	, float2 offs)
{
	float2	basis;
	float2	indent;
	float3	direction;
	float3	origin;
	float3	rot;
	size_t	x;
	size_t	y;

	x = get_global_id(0);
	y = get_global_id(1);
	basis.x = WIDTH / HEIGHT;
	basis.y = 1.0f;
	indent.x = basis.x / WIDTH;
	indent.y = basis.y / HEIGHT;

	rot = rotate_cam(cam->rot);
	origin.x = cam->pos.x + (cam->focal / 27.5f * rot.y) - basis.x / 2.0f;
	origin.y = cam->pos.y + (cam->focal / 27.5f * rot.x) - basis.y / 2.0f;
	origin.z = cam->pos.z + (cam->focal / 27.5f * 1.0f);
	direction.x = origin.x + (((float)x - offs.x) * indent.x) - cam->pos.x;
	direction.y = origin.y + (((float)y - offs.y) * indent.y) - cam->pos.y;
	direction.z = origin.z - cam->pos.z;
	*(img_buffer + WIDTH * y + x) = -1;
	calc_picture(img_buffer + WIDTH * y + x
		, objs
		, lgts
		, nobjs
		, nlgts
		, cam->pos
		, fast_normalize(direction)
		, cam, x, y);
}
