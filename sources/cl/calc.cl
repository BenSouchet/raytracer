/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.cl                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:50:51 by lgatibel          #+#    #+#             */
/*   Updated: 2017/05/10 10:45:03 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "obj_def.h"
#include "calc.h"
#include "light.h"
#include "caps.cl"
#include "calc_intersect.cl"
#include "rotate.cl"
#include "calc_normal.cl"
#include "init.cl"
#include "save.cl"
#include "noise.h"
#include "shaders.cl"
#include "light.cl"
#include "reflex.cl"
#include "refract.cl"
#include "shiness.cl"
#include "light.h"
#include "color.cl"
#include "get_color.cl"

float			calc_delta(float3 *disc, t_data *data)
{
	float	tmp;

	tmp = (disc->y * disc->y) - (disc->x * disc->z);
	if(tmp < 0.0f)
		return (-1);
	else if (tmp == 0.0f)
	{
		if ((data->t = -disc->y / (disc->x)) < 0.0f)
			return (-1);
		return (0);
	}
	tmp = sqrt(tmp);
	data->t0 = ((-disc->y + tmp) / disc->x);
	data->t1 = ((-disc->y - tmp) / disc->x);
	if ((data->t = (data->t0 >= 0.0f && data->t0 < data->t1)
	 ? data->t0 : data->t1) < 0.0f)
		return (-1);
	return (1);
}

static short	ray_intersection(t_data *data, short *index)
{
	if (data->objs[(int)*index].type == T_PLANE)
		return (plane_intersection(data, index));
	else if (data->objs[(int)*index].type == T_CONE)
		return (cone_intersection(data, index));
	else if (data->objs[(int)*index].type == T_CYLINDER)
		return (cylinder_intersection(data, index));
	else if (data->objs[(int)*index].type == T_SPHERE)
		return (sphere_intersection(data, index));
	return (0);
}

void			touch_object(t_data *data)
{
	short			index;
	float			smallest_norm;
	float			norm;
	float3			closest_intersect;
	float			t;
	float			type;

	t = -1;
	index = -1;
	data->id = -1;
	smallest_norm = -1;
	while(++index < data->n_objs)
	{
		if (ray_intersection(data, &index))
			if ((norm = fast_distance(data->intersect, data->ray_pos)) >
			 0.0f && (norm + PREC < smallest_norm || smallest_norm == -1))
			{
				closest_intersect = data->intersect;
				smallest_norm = norm;
				data->id = index;
				t = data->t;
				type = data->type;
			}
	}
	data->intersect = closest_intersect;
	data->t = t;
	data->type = type;
	if (!data->is_light)
	{
		data->inter = data->intersect;
		data->is_light = 1;
	}
}



void			calc_picture(global unsigned int *pixel, global t_obj *objs,
	global t_lgt *lgts, short n_objs, short n_lgts, float3 ray_pos,
	float3 ray_dir, global t_cam *cam, short x, short y)
{
	t_data	data;
	init_data(&data, objs, lgts, n_objs, n_lgts, ray_pos, ray_dir, pixel,
	 cam->skytype);
	touch_object(&data);
	if (data.id > -1)
	{
		*pixel = get_lighting(&data);
		return ;
	}
	data.rd_light = get_font_color(&data, &data.light_pow);
	*pixel = calcul_rendu_light(&data);
}
