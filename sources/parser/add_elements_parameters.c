/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements_parameters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 14:58:09 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:33:23 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			add_global_parameters(t_rt *rt, t_parser *p, t_obj *obj, int e)
{
	if ((e = check_tags(rt, BO_N, BC_N)) > 1)
		rt->prs->obj_tmp->n = (cl_char *)get_s(p, e, 7);
	else if (e > -1 && (e = check_tags(rt, BO_CR, BC_CR)) > 1 && ++p->t[0])
		(get_v(rt, e, BO_CR, BC_CR)) ? (vc(&obj->clr, p->vec)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_CH, BC_CH)) > 1 && ++p->t[1])
		(get_h(rt, e, BO_CH, BC_CH)) ? (h(&obj->clr, p->t_u)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_P, BC_P)) > 1 && ++p->t[2])
		(get_v(rt, e, BO_P, BC_P)) ? (vc(&obj->pos, p->vec)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_R, BC_R)) > 1 && ++p->t[3])
		(get_v(rt, e, BO_R, BC_R)) ? (vc(&obj->rot, p->vec)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_V, BC_V)) > 1 && ++p->t[4])
		(get_b(rt, e, BO_V, BC_V)) ? (obj->visibility = p->t_i) : i(&e, -1);
	return (e);
}

int			add_global_parameters_obj(t_rt *rt, t_parser *p, t_obj *obj, int e)
{
	if ((e = check_tags(rt, BO_N, BC_N)) > 1)
		rt->prs->obj_tmp->n = (cl_char *)get_s(p, e, 7);
	else if (e > -1 && (e = check_tags(rt, BO_CR, BC_CR)) > 1 && ++p->t[0])
		(get_v(rt, e, BO_CR, BC_CR)) ? (vc(&obj->clr, p->vec)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_CH, BC_CH)) > 1 && ++p->t[1])
		(get_h(rt, e, BO_CH, BC_CH)) ? (h(&obj->clr, p->t_u)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_P, BC_P)) > 1 && ++p->t[2])
		(get_v(rt, e, BO_P, BC_P)) ? (vc(&obj->pos, p->vec)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_R, BC_R)) > 1 && ++p->t[3])
		(get_v(rt, e, BO_R, BC_R)) ? (vc(&obj->rot, p->vec)) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_V, BC_V)) > 1 && ++p->t[4])
		(get_b(rt, e, BO_V, BC_V)) ? (obj->visibility = p->t_i) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_T, BC_T)) > 1 && ++p->t[8])
		(get_t(rt, e, BO_T, BC_T)) ? (obj->forme = p->t_i) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_OP, BC_OP)) > 1 && ++p->t[7])
		(get_d(rt, e, BO_OP, BC_OP)) ? (obj->opacity = p->t_d) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_RA, BC_RA)) > 1 && ++p->t[9])
		(get_d(rt, e, BO_RA, BC_RA)) ? (obj->radius = p->t_d) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_LT, BC_LT)) > 1 && ++p->t[14])
		(get_d(rt, e, BO_LT, BC_LT)) ? (obj->lenght = p->t_d) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_WT, BC_WT)) > 1 && ++p->t[10])
		(get_d(rt, e, BO_WT, BC_WT)) ? (obj->width = p->t_d) : i(&e, -1);
	else if (e > -1 && (e = check_tags(rt, BO_HT, BC_HT)) > 1 && ++p->t[11])
		(get_d(rt, e, BO_HT, BC_HT)) ? (obj->height = p->t_d) : i(&e, -1);
	return (e);
}

int			add_camera_parameters(t_rt *rt, t_obj *obj, int b_end, int e)
{
	int			e_tmp;
	t_parser	*p;

	p = rt->prs;
	while (e != -1 && rt->prs->i < b_end)
	{
		e_tmp = e;
		e = add_global_parameters(rt, rt->prs, rt->prs->obj_tmp, e);
		if (e != e_tmp)
			;
		else if (e > -1 && (e = check_tags(rt, BO_FL, BC_FL)) > 1 && ++p->t[5])
			(get_i(rt, e, BO_FL, BC_FL)) ? (obj->focal = p->t_i) : i(&e, -1);
		else if (e > -1 && s(&rt->prs->b_o, BO_C) && (rt->prs->b_c = BC_C))
			return (error(rt, 10));
	}
	return (e);
}

int			add_light_parameters(t_rt *rt, t_obj *obj, int b_end, int e)
{
	int			e_tmp;
	t_parser	*p;

	p = rt->prs;
	while (e != -1 && rt->prs->i < b_end)
	{
		e_tmp = e;
		e = add_global_parameters(rt, rt->prs, rt->prs->obj_tmp, e);
		if (e != e_tmp)
			;
		else if (e > -1 && (e = check_tags(rt, BO_T, BC_T)) > 1 && ++p->t[8])
			(get_lt(rt, e, BO_T, BC_T)) ? (obj->forme = p->t_d) : i(&e, -1);
		else if (e > -1 && (e = check_tags(rt, BO_I, BC_I)) > 1 && ++p->t[6])
			(get_d(rt, e, BO_I, BC_I)) ? (obj->intensity = p->t_d) : i(&e, -1);
		else if (e > -1 && (e = check_tags(rt, BO_F, BC_F)) > 1 && ++p->t[13])
			(get_b(rt, e, BO_F, BC_F)) ? 1 : i(&e, -1);
		else if (e > -1 && s(&rt->prs->b_o, BO_L) && (rt->prs->b_c = BC_L))
			return (error(rt, 10));
	}
	return (e);
}

int			add_object_parameters(t_rt *rt, t_obj *obj, int b_end, int e)
{
	int			e_tmp;
	t_parser	*p;

	p = rt->prs;
	while (e != -1 && rt->prs->i < b_end && (e_tmp = e) != -1)
	{
		e = add_global_parameters_obj(rt, rt->prs, rt->prs->obj_tmp, e);
		if (e != e_tmp)
			;
		else if (e > -1 && (e = check_tags(rt, BO_M, BC_M)) > 1 && ++p->t[12])
			(get_m(rt, e, BO_M, BC_M)) ? (obj->preset = p->t_i) : i(&e, -1);
		else if (e > -1 && (e = check_tags(rt, BO_RE, BC_RE)) > 1 && ++p->t[15])
			(get_d(rt, e, BO_RE, BC_RE)) ? (obj->reflex = p->t_d) : i(&e, -1);
		else if (e > -1 && (e = check_tags(rt, BO_RI, BC_RI)) > 1 && ++p->t[16])
			(get_d(rt, e, BO_RI, BC_RI)) ? (obj->refrac = p->t_d) : i(&e, -1);
		else if (e > -1 && (e = check_tags(rt, BO_SP, BC_SP)) > 1 && ++p->t[18])
			(get_i(rt, e, BO_SP, BC_SP)) ? (obj->specular = p->t_i) : i(&e, -1);
		else if (e > -1 && (e = check_tags(rt, BO_SH, BC_SH)) > 1 && ++p->t[19])
			(get_i(rt, e, BO_SH, BC_SH)) ?
			(obj->shader = p->t_i * 2) : i(&e, -1);
		else if (e > -1 && s(&rt->prs->b_o, BO_O) && (rt->prs->b_c = BC_O))
			return (error(rt, 10));
	}
	return (e);
}
