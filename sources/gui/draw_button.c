/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_button.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:05:57 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/02 16:31:22 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_button(t_rt *rt, int b_num, int type)
{
	rt->ui->t_rect = rt->ui->b_rect[b_num];
	(type == 1) ? rt->ui->t_rect.y += 51 : 1;
	(type == 2) ? rt->ui->t_rect.y += 94 : 1;
	(type == 3) ? rt->ui->t_rect.y += 137 : 1;
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->t_rect, rt->s_back,
	&rt->ui->b_rect[b_num]);
	(type == 0) ? (rt->ui->b_hover = -1) : 1;
}

static int	draw_delete_button(t_rt *rt, char etype, int type)
{
	SDL_Rect	*rect;
	SDL_Rect	*rect_origin;

	rect_origin = (type == 0) ? &rt->ui->obj_b_rect[0] : DELETE_RECT;
	if (etype == 'C')
		rect = &rt->ui->cam_b_rect[0];
	else if (etype == 'L')
		rect = &rt->ui->lgt_b_rect[0];
	else
		rect = &rt->ui->obj_b_rect[0];
	SDL_LowerBlit(rt->ui->s_ui, rect_origin, rt->s_back, rect);
	rt->ui->b_se_rect = rect;
	(type == 0) ? (rt->ui->b_se_hover = -1) : 1;
	return (1);
}

void		draw_se_button(t_rt *rt, int b_num, char etype, int type)
{
	SDL_Rect	*rect;
	size_t		clr;

	clr = 0xFF29323e;
	if (b_num == 0 && draw_delete_button(rt, etype, type))
		return ;
	if (etype == 'C')
		rect = &rt->ui->cam_b_rect[b_num];
	else if (etype == 'L')
		rect = &rt->ui->lgt_b_rect[b_num];
	else
		rect = &rt->ui->obj_b_rect[b_num];
	if (type == 1)
		clr = HOVER_SE;
	else if (type == 2)
		clr = FOCUS_SE;
	fsdl_draw_rect(rt->s_back, *rect, clr);
	if (type == 4 && rt->ui->case_active > 0)
		redraw_case_active(rt, 0);
	rt->ui->b_se_rect = rect;
	(type == 0) ? (rt->ui->b_se_hover = -1) : 1;
}
