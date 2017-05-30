/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:06:16 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/12 18:03:44 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Fonctions to get & assign values to elements of the scene
*/

int			set_scene(t_rt *rt, int b_end, int e)
{
	while (e != -1 && rt->prs->i < b_end)
	{
		if ((e = check_tags(rt, BO_N, BC_N)) > 1)
			rt->scn->name = (cl_char *)get_s(rt->prs, e, 7);
		else if (e > -1 && (e = check_tags(rt, BO_A, BC_A)) > 1)
			(get_d(rt, e, BO_A, BC_A)) ?
			cf(&rt->scn->ambient, rt->prs->t_d) : (e = -1);
		else if (e > -1 && (e = check_tags(rt, BO_MR, BC_MR)) > 1)
			(get_i(rt, e, BO_MR, BC_MR)) ?
			ci(&rt->scn->m_ref, rt->prs->t_i) : (e = -1);
		else if (e > -1 && (rt->prs->b_o = BO_S) &&
		(rt->prs->b_c = BC_S))
			return (error(rt, 10));
	}
	return ((e != -1) ? check_scene(rt) : e);
}

int			add_camera(t_rt *rt, int b_end)
{
	if (rt->scn->n_cams == N_CAMS)
		return (error(rt, 20));
	set_default_parameters(rt->prs->obj_tmp, 'C', 0);
	if (add_camera_parameters(rt, rt->prs->obj_tmp, b_end, 0) != -1)
		return (check_camera(rt, rt->prs->obj_tmp, 0));
	return (-1);
}

int			add_light(t_rt *rt, int b_end)
{
	if (rt->scn->n_lgts == N_LGTS)
		return (error(rt, 21));
	set_default_parameters(rt->prs->obj_tmp, 'L', 0);
	if (add_light_parameters(rt, rt->prs->obj_tmp, b_end, 0) != -1)
		return (check_light(rt, rt->prs->obj_tmp, 0));
	return (-1);
}

int			add_object(t_rt *rt, int b_end)
{
	if (rt->scn->n_objs == N_OBJS)
		return (error(rt, 22));
	set_default_parameters(rt->prs->obj_tmp, 'O', 0);
	if (add_object_parameters(rt, rt->prs->obj_tmp, b_end, 0) != -1)
		return (check_object(rt, rt->prs->obj_tmp, 0));
	return (-1);
}
