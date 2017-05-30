/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_clicks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 21:44:36 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:18:19 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		handle_double_click_down(t_rt *rt, t_cl *cl)
{
	if (!rt->ui->c_elem || rt->ui->c_elem->type != 'C')
		return ;
	if (rt->ui->c_down != -1 || rt->ui->c_elem->type != 'C' ||
	rt->ui->c_hover == -1 || rt->ui->c_elem == rt->scn->c_cam)
		return ;
	rt->n_info = -2;
	rt->scn->c_cam = rt->ui->c_elem;
	draw_current_camera_name(rt, 1);
	rt->ui->tmp = ft_strf(INF33, rt->scn->c_cam->n);
	cl_main_krl_update_camera(cl, rt->scn->c_cam);
	rt->scn->redraw = 1;
	draw_info_bar(rt);
	free(rt->ui->tmp);
}

void		handle_left_click_up(t_rt *rt)
{
	if (rt->ui->b_down == -1 && rt->ui->c_down == -1 && rt->ui->ra_down == -1 &&
	rt->ui->b_se_down == -1)
		return ;
	if (rt->ui->b_down != -1 && rt->ui->b_state[(int)rt->ui->b_down] < 2 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->b_rect[(int)rt->ui->b_down]))
		draw_button(rt, rt->ui->b_down, 1);
	if (rt->ui->c_down > -1 && rt->ui->c_elem &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->c_elem->r_ol))
		draw_outliner_element(rt, rt->ui->c_elem, 1);
	if (rt->ui->ra_down != -1 &&
	fsdl_pt_in_rect(&rt->m_pos, rt->ui->ra_rect[(int)rt->ui->ra_down + 3]))
		draw_special_mode(rt, rt->ui->ra_down, 1);
	rt->ui->b_down = -1;
	rt->ui->c_down = -1;
	rt->ui->ra_down = -1;
	rt->ui->b_se_down = -1;
}

static void	handle_left_click_down_part2(t_rt *rt, t_cl *cl)
{
	rt->ui->t_c = rt->ui->b_state[(int)rt->ui->b_hover];
	if (rt->ui->b_se_down == -1 && rt->ui->b_se_hover != -1)
		handle_selected_element_down(rt, cl);
	else if (rt->ui->b_down == -1 && rt->ui->b_hover != -1 && rt->ui->t_c < 3)
		handle_buttons_down(rt, cl);
	else if (rt->ui->c_down == -1 && rt->ui->c_hover != -1)
		handle_outliner_down(rt);
	else if (rt->ui->ra_down == -1 && rt->ui->ra_hover != -1)
		handle_special_modes_down(rt);
}

void		handle_left_click_down(t_rt *rt, t_cl *cl)
{
	rt->n_info = -1;
	draw_info_bar(rt);
	if (fsdl_pt_in_rect(&rt->m_pos, (SDL_Rect){1078, 28, 190, 28}))
	{
		rt->scn->s_elem = rt->scn->c_cam;
		(rt->ui->b_state[16] == 2) ? draw_selected_element(rt) : 1;
		return ;
	}
	if (rt->ui->b_se_hover > 0 &&
	!fsdl_pt_in_rect(&rt->m_pos, rt->ui->area[13]))
		draw_se_button(rt, rt->ui->b_se_hover, rt->scn->s_elem->type, 0);
	if (rt->ui->case_active != -1 &&
	fsdl_pt_in_rect(&rt->m_pos, *rt->ui->case_rect))
		return ;
	else if (rt->ui->case_active != -1 && !(rt->ui->case_rect = NULL))
	{
		draw_se_button(rt, rt->ui->case_active, rt->scn->s_elem->type, 4);
		redraw_case_active(rt, 0);
		rt->ui->case_active = -1;
	}
	handle_left_click_down_part2(rt, cl);
}

void		handle_right_click_down(t_rt *rt, t_cl *cl)
{
	if (rt->ui->c_down != -1 || rt->ui->c_hover < 0 ||
	rt->ui->c_elem->type == 'C')
		return ;
	rt->n_info = -2;
	if (rt->ui->c_elem->visibility == 0)
	{
		rt->ui->c_elem->visibility = 1;
		rt->ui->tmp = ft_strf(INF35, rt->ui->c_elem->n);
	}
	else if ((rt->ui->c_elem->visibility = 0) != -1)
		rt->ui->tmp = ft_strf(INF34, rt->ui->c_elem->n);
	draw_outliner_element(rt, rt->ui->c_elem, 1);
	cl_main_krl_update_buffers(cl, rt->scn);
	rt->scn->redraw = 1;
	draw_info_bar(rt);
	free(rt->ui->tmp);
}
