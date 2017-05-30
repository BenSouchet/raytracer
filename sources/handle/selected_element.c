/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selected_element.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/23 21:18:20 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 19:33:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void			handle_selected_element_down(t_rt *rt, t_cl *cl)
{
	if (rt->ui->b_se_hover == 0)
	{
		delete_current_element(rt, cl, NULL, NULL);
		rt->ui->b_se_down = -1;
		rt->ui->b_se_hover = -1;
		return ;
	}
	rt->ui->b_se_down = rt->ui->b_se_hover;
	rt->ui->case_active = rt->ui->b_se_hover;
	draw_se_button(rt, rt->ui->b_se_hover, rt->scn->s_elem->type, 2);
	redraw_case_active(rt, 1);
	rt->ui->case_rect = rt->ui->b_se_rect;
}

static void		handle_selected_camera(t_rt *rt)
{
	rt->ui->t_c = 0;
	while (rt->ui->t_c < 8 &&
	!fsdl_pt_in_rect(&rt->m_pos, rt->ui->cam_b_rect[(int)rt->ui->t_c]))
		rt->ui->t_c++;
	if ((rt->ui->t_c == 8 || rt->ui->t_c == rt->ui->case_active) &&
	(rt->ui->b_se_hover = -1) != 0)
		return ;
	rt->ui->b_se_hover = rt->ui->t_c;
	draw_se_button(rt, rt->ui->b_se_hover, 'C', 1);
}

static void		handle_selected_light(t_rt *rt)
{
	rt->ui->t_c = 0;
	while (rt->ui->t_c < 12 &&
	!fsdl_pt_in_rect(&rt->m_pos, rt->ui->lgt_b_rect[(int)rt->ui->t_c]))
		rt->ui->t_c++;
	if ((rt->ui->t_c == 12 || rt->ui->t_c == rt->ui->case_active) &&
	(rt->ui->b_se_hover = -1) != 0)
		return ;
	rt->ui->b_se_hover = rt->ui->t_c;
	draw_se_button(rt, rt->ui->b_se_hover, 'L', 1);
}

static void		handle_selected_object(t_rt *rt, t_obj *o)
{
	rt->ui->t_c = 0;
	while (rt->ui->t_c < 19 &&
	!fsdl_pt_in_rect(&rt->m_pos, rt->ui->obj_b_rect[(int)rt->ui->t_c]))
		rt->ui->t_c++;
	if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->obj_b_rect[5]) &&
	(o->forme == T_PLANE || o->forme == T_CUBE))
		return ;
	if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->obj_b_rect[6]) &&
	(o->forme == T_SPHERE || o->forme == T_CONE || o->forme == T_CYLINDER ||
	o->forme == T_TORUS))
		return ;
	if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->obj_b_rect[7]) &&
	(o->forme == T_PLANE || o->forme == T_SPHERE || o->forme == T_TORUS))
		return ;
	if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->obj_b_rect[8]) &&
	(o->forme == T_SPHERE || o->forme == T_CONE || o->forme == T_CYLINDER ||
	o->forme == T_TORUS))
		return ;
	if ((rt->ui->t_c == 19 || rt->ui->t_c == rt->ui->case_active) &&
	(rt->ui->b_se_hover = -1) != 0)
		return ;
	rt->ui->b_se_hover = rt->ui->t_c;
	draw_se_button(rt, rt->ui->b_se_hover, 'O', 1);
}

void			handle_selected_element(t_rt *rt)
{
	if (rt->scn->s_elem->type == 'C' &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[14]))
		handle_selected_camera(rt);
	else if (rt->scn->s_elem->type == 'L' &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[15]))
		handle_selected_light(rt);
	else if (rt->scn->s_elem->type == 'O')
		handle_selected_object(rt, rt->scn->s_elem);
}
