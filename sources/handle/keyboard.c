/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:08:04 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:18:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	hide_object_scene(t_rt *rt, t_cl *cl)
{
	rt->n_info = -2;
	if (rt->scn->s_elem->visibility == 0)
	{
		rt->scn->s_elem->visibility = 1;
		rt->ui->tmp = ft_strf(INF35, rt->ui->c_elem->n);
	}
	else if ((rt->scn->s_elem->visibility = 0) != -1)
		rt->ui->tmp = ft_strf(INF34, rt->scn->s_elem->n);
	draw_outliner_element(rt, rt->scn->s_elem, 1);
	cl_main_krl_update_buffers(cl, rt->scn);
	rt->scn->redraw = 1;
	draw_info_bar(rt);
	free(rt->ui->tmp);
}

static void	handle_keyboard_keypress(t_rt *rt, t_cl *cl)
{
	if (rt->ui->case_active > 0 || rt->scn->s_elem)
	{
		if (CK_DOWN == SDLK_DELETE || CK_DOWN == SDLK_BACKSPACE)
		{
			delete_current_element(rt, cl, NULL, NULL);
			rt->ui->b_se_down = -1;
			rt->ui->b_se_hover = -1;
			rt->ui->case_active = -1;
			rt->ui->case_rect = NULL;
			rt->ui->k_edit = 0;
		}
		else if (rt->event.type == 0x301 && CK_DOWN == SDLK_h &&
		rt->scn->s_elem && rt->ui->case_active == -1)
			hide_object_scene(rt, cl);
		else if (CK_DOWN == SDLK_EQUALS || CK_DOWN == SDLK_KP_PLUS ||
		CK_DOWN == SDLK_UP || CK_DOWN == SDLK_RIGHT || CK_DOWN == SDLK_d ||
		CK_DOWN == SDLK_w || CK_DOWN == SDLK_e)
			update_se_box_plus(rt, cl);
		else if (CK_DOWN == SDLK_MINUS || CK_DOWN == SDLK_KP_MINUS ||
		CK_DOWN == SDLK_LEFT || CK_DOWN == SDLK_DOWN || CK_DOWN == SDLK_a ||
		CK_DOWN == SDLK_s || CK_DOWN == SDLK_q)
			update_se_box_minus(rt, cl);
	}
}

void		handle_keyboard(t_rt *rt, t_cl *cl)
{
	if (rt->ui->case_active > 0)
	{
		if (CK_DOWN == SDLK_KP_ENTER || CK_DOWN == SDLK_RETURN ||
		CK_DOWN == SDLK_RETURN2 || CK_DOWN == SDLK_END)
		{
			if (fsdl_pt_in_rect(&rt->m_pos, *rt->ui->case_rect))
				draw_se_button(rt, rt->ui->case_active, S_ELEM->type, 1);
			else
				draw_se_button(rt, rt->ui->case_active, S_ELEM->type, 4);
			rt->ui->case_active = -1;
			rt->ui->case_rect = NULL;
			return ;
		}
	}
	handle_keyboard_keypress(rt, cl);
}
