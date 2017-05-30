/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_interface.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 07:55:11 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:45 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CL_INTERFACE_H
# define CL_INTERFACE_H

# include "rt.h"

typedef struct		s_cl_obj
{
	cl_short		type;
	cl_float3		pos;
	cl_float3		rot;
	cl_float3		clr;
	cl_float		opacity;
	cl_float		width;
	cl_float		height;
	cl_float		radius;
	cl_float		specular;
	cl_float		reflex;
	cl_float		refrac;
	cl_short		shader;
	cl_float		shiness;
	cl_float		mshiness;
	cl_float3		offset;
}					t_cl_obj;

typedef struct		s_cl_lgt
{
	cl_float3		pos;
	cl_float3		rot;
	cl_float3		clr;
	cl_float		intensity;
}					t_cl_lgt;

typedef struct		s_cl_cam
{
	cl_float3		pos;
	cl_float3		rot;
	cl_short		focal;
	cl_short		skytype;
}					t_cl_cam;

/*
** implementation of these three functions needs to be reviewed
** each time data structures are modified
*/

void				cpy_cam(t_cl_cam *dest, t_obj *src);
void				cpy_lgt(t_cl_lgt *dest, t_obj *src);
void				cpy_obj(t_cl_obj *dest, t_obj *src);

#endif
