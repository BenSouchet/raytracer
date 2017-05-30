/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgatibel <lgatibel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:37:37 by lgatibel          #+#    #+#             */
/*   Updated: 2017/05/11 15:31:08 by erodrigu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CALC_H
# define CALC_H
# include "./obj_def.h"

typedef struct			s_data
{
	global t_obj		*objs;
	global t_obj		*obj;
	global t_lgt		*lights;
	global unsigned int	*pixel;
	short				n_objs;
	short				n_lgts;
	float3				ray_pos;
	float3				ray_dir;
	float3				intersect;
	float3				save_pos;
	float3				save_dir;
	float3				save_inter;
	float3				save_clr;
	short				save_id;
	short				save_t;
	short				through;
	short				test;
	float				light_pow;
	float				light_refract_pow;
	float				light_reflex_pow;
	short				id;
	short				reflex;
	short				opacity;
	short				skytype;
	short				type;
	float3				rd_light;
	float3				pos;
	float3				inter;
	float3				clr;
	float3				offset;
	float3				normale;
	short				is_light;
	short				nl;
	float				t;
	float				t0;
	float				t1;
}						t_data;

void			save(t_data *data);
void			load(t_data *data);
void			touch_object(t_data *data);
void			touch_object2(t_data *data);
void			calc_intersect(t_data *data);
void			set_offset(t_data *data, short *index);
void			calc_picture(global unsigned int *pixel,
	global t_obj *objs, global t_lgt *lgts, short nobjs, short nlgts,
	float3 ray_pos, float3 ray_dir, global t_cam *cam, short x, short y);
float			calc_delta(float3 *disc, t_data *data);
short			cone_intersection(t_data *data, short *index);
short			plane_intersection(t_data *data, short *index);
short			sphere_intersection(t_data *data, short *index);
short			cylinder_intersection(t_data *data, short *index);
short			cone_caps(t_data *data, float3 *rot, short *index, float m);
short			cylinder_caps(t_data *data, float3 *rot, short *index,
	float m);
float3			rotate_cam(float3 rot);
float3			calcul_normale(t_data *data);
float3			rotate_ray(t_data *data, short *index);
#endif
