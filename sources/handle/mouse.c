/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:42:55 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 11:46:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	check_mouse_areas(t_rt *rt)
{
	if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[1]))
		handle_buttons(rt);
	else if (rt->ui->b_state[15] == 2 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[3]))
		handle_scene_parameters(rt);
	else if (rt->ui->b_state[15] == 2 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[4]))
		handle_outliner(rt, 0, 0, 0);
	else if (rt->ui->b_state[16] == 2 && rt->scn->s_elem &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[13]))
		handle_selected_element(rt);
	else if (rt->ui->b_state[16] == 2 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[9]))
		handle_special_mode(rt, 3);
}

static int	handle_motion_mouse_part2(t_rt *rt)
{
	if (rt->ui->c_hover < -1 && fsdl_pt_in_rect(&rt->m_pos, rt->ui->r_hover))
		return (1);
	else if (rt->ui->c_hover < -1)
		draw_nav_element(rt, 0);
	if (rt->ui->b_hover != -1 &&
		fsdl_pt_in_rect(&rt->m_pos, rt->ui->b_rect[(int)rt->ui->b_hover]))
		return (1);
	else if (rt->ui->b_hover != -1 && rt->ui->b_state[(int)rt->ui->b_hover] < 2)
		draw_button(rt, rt->ui->b_hover, 0);
	else if (rt->ui->b_hover != -1 && rt->ui->b_state[(int)rt->ui->b_hover] == 2
	&& !fsdl_pt_in_rect(&rt->m_pos, rt->ui->b_rect[(int)rt->ui->b_hover]))
		rt->ui->b_hover = -1;
	return (0);
}

void		handle_motion_mouse(t_rt *rt)
{
	rt->m_pos.x = rt->event.motion.x;
	rt->m_pos.y = rt->event.motion.y;
	if (rt->ui->b_sp_hover != -1 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->param_b_rect[(int)rt->ui->b_sp_hover]))
		return ;
	else if (rt->ui->b_sp_hover > -1)
		draw_sp_element(rt, rt->ui->b_sp_hover, 0);
	if (rt->ui->b_se_hover != -1 &&
	fsdl_pt_in_rect(&rt->m_pos, *rt->ui->b_se_rect))
		return ;
	else if (rt->ui->b_se_hover != -1 &&
	rt->ui->b_se_hover != rt->ui->case_active)
		draw_se_button(rt, rt->ui->b_se_hover, rt->scn->s_elem->type, 0);
	if (rt->ui->ra_hover != -1 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->ra_rect[(int)rt->ui->ra_hover]))
		return ;
	else if (rt->ui->ra_hover != -1)
		draw_special_mode(rt, rt->ui->ra_hover, 0);
	if (rt->ui->c_hover > -1 && fsdl_pt_in_rect(&rt->m_pos, RECT_OUTLINER))
		return ;
	else if (rt->ui->c_hover > -1)
		draw_outliner_element(rt, rt->ui->c_elem, 0);
	if (handle_motion_mouse_part2(rt))
		return ;
	check_mouse_areas(rt);
}
