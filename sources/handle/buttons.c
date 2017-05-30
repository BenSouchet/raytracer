/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:56:06 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 16:03:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		handle_buttons_down(t_rt *rt, t_cl *cl)
{
	if (rt->ui->t_c < 2)
		draw_button(rt, rt->ui->b_hover, 2);
	if (rt->ui->t_c == 0)
		execute_button(rt, rt->ui->b_hover, cl);
	if (rt->ui->t_c == 1 && (rt->ui->b_state[(int)rt->ui->b_hover] += 1) != 0)
		draw_panel(rt, rt->ui->b_hover, 1);
	else if (rt->ui->t_c == 2 &&
	(rt->ui->b_state[(int)rt->ui->b_hover] -= 1) != 0)
		draw_panel(rt, rt->ui->b_hover, 0);
	rt->ui->b_down = rt->ui->b_hover;
}

void		execute_button(t_rt *rt, int button, t_cl *cl)
{
	if (button == 0 && (rt->n_info = -1) != 0)
		export_config_file(rt);
	else if (button == 1 && (rt->n_info = 1) != 0)
		add_new_camera(rt, rt->prs->obj_tmp);
	else if (button == 2 && (rt->n_info = 2) != 0)
		add_new_light(rt, rt->prs->obj_tmp, T_DIFFUSE);
	else if (button == 3 && (rt->n_info = 3) != 0)
		add_new_light(rt, rt->prs->obj_tmp, T_DIRECTIONAL);
	else if (button == 4 && (rt->n_info = 4) != 0)
		add_new_light(rt, rt->prs->obj_tmp, T_SPOT);
	else if (button >= 5 && button <= 10 && (rt->n_info = (button)) != 0)
		add_new_object(rt, rt->prs->obj_tmp, (button - 4));
	else if (button >= 11 && button <= 14 && (rt->n_info = (button + 2)) != 0)
		add_new_shader(rt->scn->s_elem, (button - 11));
	else if (button == 17 && (rt->n_info = 21) != 0)
		save_to_png(rt);
	if (button > 0 && button < 15)
	{
		cl_main_krl_update_buffers(cl, rt->scn);
		rt->scn->redraw = 1;
	}
	(button == 15 || button == 16) ? (rt->scn->redraw = 1) : 1;
	draw_info_bar(rt);
}

static int	check_buttons(t_rt *rt)
{
	rt->ui->t_c = 0;
	while (rt->ui->t_c < 18 &&
	!fsdl_pt_in_rect(&rt->m_pos, rt->ui->b_rect[(int)rt->ui->t_c]))
		rt->ui->t_c++;
	if (rt->ui->t_c == 6 || rt->ui->t_c == 10)
		return (-1);
	rt->ui->b_hover = (rt->ui->t_c == 18) ? -1 : rt->ui->t_c;
	return (rt->ui->b_hover);
}

void		handle_buttons(t_rt *rt)
{
	if (check_buttons(rt) == -1)
		return ;
	if (rt->ui->b_state[(int)rt->ui->b_hover] < 2)
		draw_button(rt, rt->ui->b_hover, 1);
}
