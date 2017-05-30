/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_selected_panel.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:09:43 by bsouchet          #+#    #+#             */
/*   Updated: 2017/03/03 22:49:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_no_selected_element(t_rt *rt)
{
	fsdl_fill_rect(rt->s_back, rt->ui->area[8], PAN_BG);
	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){851, 206, 214, 143},
	rt->s_back, &(SDL_Rect){1066, 67, 214, 143});
}

void		draw_case_active(t_rt *rt, char *tmp, SDL_Rect rect, int type)
{
	SDL_Color	font_clr;

	font_clr = (type == 1) ?
	(SDL_Color){113, 149, 164, 255} : (SDL_Color){109, 125, 145, 255};
	fsdl_fill_rect(rt->s_back,
	(SDL_Rect){rect.x + 1, rect.y + 1, rect.w - 2, rect.h - 2}, BOX_BG);
	rt->ui->s_tmp = TTF_RenderText_Shaded(rt->ui->font[1], tmp,
	font_clr, (SDL_Color){42, 52, 64, 255});
	SDL_LowerBlit(rt->ui->s_tmp,
	&(SDL_Rect){0, 0, rt->ui->s_tmp->w, rt->ui->s_tmp->h},
	rt->s_back, &(SDL_Rect){(rect.x + ((rect.w - rt->ui->s_tmp->w) / 2.)),
	(rect.y + ((rect.h - rt->ui->s_tmp->h) / 2.) + 1),
	rt->ui->s_tmp->w, rt->ui->s_tmp->h});
	SDL_FreeSurface(rt->ui->s_tmp);
	free(tmp);
}

void		draw_parameter(t_rt *rt, char *tmp, SDL_Rect rect, int type)
{
	unsigned	bg_clr2;
	SDL_Color	bg_clr;
	SDL_Color	font_clr;

	bg_clr = (type == 2) ?
	(SDL_Color){42, 52, 64, 255} : (SDL_Color){45, 56, 69, 255};
	font_clr = (type == 2) ?
	(SDL_Color){109, 125, 145, 255} : (SDL_Color){135, 136, 137, 255};
	bg_clr2 = (type == 2) ? 0xFF2a3440 : 0xFF2d3845;
	fsdl_fill_rect(rt->s_back, rect, bg_clr2);
	rt->ui->s_tmp = TTF_RenderText_Shaded(rt->ui->font[1], tmp,
	font_clr, bg_clr);
	SDL_LowerBlit(rt->ui->s_tmp,
	&(SDL_Rect){0, 0, rt->ui->s_tmp->w, rt->ui->s_tmp->h},
	rt->s_back, &(SDL_Rect){(rect.x + ((rect.w - rt->ui->s_tmp->w) / 2.)),
	(rect.y + ((rect.h - rt->ui->s_tmp->h) / 2.) + 1),
	rt->ui->s_tmp->w, rt->ui->s_tmp->h});
	SDL_FreeSurface(rt->ui->s_tmp);
	free(tmp);
}

void		draw_selected_element(t_rt *rt)
{
	fsdl_fill_rect(rt->s_back, rt->ui->area[8], PAN_BG);
	if (!rt->scn->s_elem)
		draw_no_selected_element(rt);
	else if (rt->scn->s_elem->type == 'C')
		draw_selected_camera(rt, rt->scn->s_elem);
	else if (rt->scn->s_elem->type == 'L')
		draw_selected_light(rt, rt->scn->s_elem);
	else if (rt->scn->s_elem->type == 'O')
		draw_selected_object(rt, rt->scn->s_elem);
}
