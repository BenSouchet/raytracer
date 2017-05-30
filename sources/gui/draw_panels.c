/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_panels.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:43:50 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:18:25 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	draw_left_panel(t_rt *rt)
{
	fsdl_fill_rect(rt->s_back, (SDL_Rect){214, 84, 18, 588}, WIN_BG);
	fsdl_fill_rect(rt->s_back, (SDL_Rect){214, 690, 1, 30}, WIN_BG);
	draw_scene_parameters(rt);
	draw_renderer_info(rt);
	draw_outliner(rt, -1, 0);
}

static void	draw_right_panel(t_rt *rt)
{
	fsdl_fill_rect(rt->s_back, (SDL_Rect){1048, 84, 18, 588}, WIN_BG);
	fsdl_fill_rect(rt->s_back, (SDL_Rect){1065, 690, 1, 30}, WIN_BG);
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->ra_rect[2], rt->s_back,
	&rt->ui->ra_rect[rt->scn->sp_mode + 3]);
	draw_selected_element(rt);
}

void		draw_panel(t_rt *rt, int p, int type)
{
	p = (p == 15) ? 2 : 7;
	if (type == 0)
		fsdl_fill_rect(rt->s_back, rt->ui->area[p], WIN_BG);
	else
	{
		SDL_LowerBlit(rt->ui->s_ui, &rt->ui->area[p], rt->s_back,
		&rt->ui->area[p]);
		if (p == 2)
			draw_left_panel(rt);
		else
			draw_right_panel(rt);
	}
	if (type == 0 && (rt->r_info.w += 215) > 0)
		(p == 2) ? (rt->r_info.x = 0) : 1;
	else if ((rt->r_info.w -= 215) > 0)
		(p == 2) ? (rt->r_info.x = 215) : 1;
	if (type == 0 && (rt->r_view.w += 214) > 0)
		(p == 2) ? (rt->r_view.x = 18) : 1;
	else if ((rt->r_view.w -= 214) > 0)
		(p == 2) ? (rt->r_view.x = 232) : 1;
	draw_current_camera_name(rt, 2);
	draw_info_bar(rt);
	if (type == 0)
		rt->scn->redraw = 1;
}
