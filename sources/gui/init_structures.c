/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 15:28:36 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/12 18:04:19 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	init_gui_areas(t_ui *ui, short lol)
{
	ui->area[0] = (SDL_Rect){0, 0, 1280, 66};
	ui->area[1] = (SDL_Rect){225, 25, 829, 34};
	ui->area[2] = (SDL_Rect){0, 67, 214, 653};
	ui->area[3] = (SDL_Rect){139, 100, 53, 75};
	ui->area[4] = (SDL_Rect){13, 233, 188, lol};
	ui->area[7] = (SDL_Rect){1066, 67, 214, 653};
	ui->area[8] = (SDL_Rect){1066, 67, 214, 527};
	ui->area[9] = (SDL_Rect){1082, 632, 106, 68};
	ui->area[10] = (SDL_Rect){0, 690, 215, 30};
	ui->area[11] = (SDL_Rect){1065, 690, 215, 30};
	ui->area[12] = (SDL_Rect){13, 233, 188, lol};
	ui->area[13] = (SDL_Rect){1088, 160, 170, 412};
	ui->area[14] = (SDL_Rect){1088, 160, 170, 171};
	ui->area[15] = (SDL_Rect){1088, 160, 170, 251};
	ui->ra_rect[0] = (SDL_Rect){1046, 632, 12, 12};
	ui->ra_rect[1] = (SDL_Rect){1046, 650, 12, 12};
	ui->ra_rect[2] = (SDL_Rect){1046, 669, 12, 12};
	ui->ra_rect[3] = (SDL_Rect){1176, 688, 12, 12};
	ui->ra_rect[4] = (SDL_Rect){1082, 688, 12, 12};
	ui->ra_rect[5] = (SDL_Rect){1176, 669, 12, 12};
	ui->ra_rect[6] = (SDL_Rect){1082, 669, 12, 12};
	ui->ra_rect[7] = (SDL_Rect){1176, 650, 12, 12};
	ui->ra_rect[8] = (SDL_Rect){1082, 650, 12, 12};
	ui->ra_rect[9] = (SDL_Rect){1176, 632, 12, 12};
	ui->ra_rect[10] = (SDL_Rect){1082, 632, 12, 12};
}

void		init_gui_structure(t_rt *rt)
{
	rt->scn->aa = 1;
	rt->ui->t_c = 0;
	rt->ui->b_down = -1;
	rt->ui->b_hover = -1;
	rt->ui->b_se_rect = NULL;
	rt->ui->b_se_hover = -1;
	rt->ui->b_se_down = -1;
	rt->ui->c_down = -1;
	rt->ui->c_hover = -1;
	rt->ui->ra_down = -1;
	rt->ui->ra_hover = -1;
	rt->ui->save_num = 1;
	rt->ui->m_visible = 0;
	rt->ui->nav_state = 0;
	init_gui_areas(rt->ui, ((((rt->scn->n_elms + 3) * 29) - 1) > 410) ?
	410 : (((rt->scn->n_elms + 3) * 29) - 1));
	init_informations(rt, 0);
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->area[0], rt->s_back, &rt->ui->area[0]);
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->area[2], rt->s_back, &rt->ui->area[2]);
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->area[7], rt->s_back, &rt->ui->area[7]);
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->ra_rect[2], rt->s_back,
	&rt->ui->ra_rect[rt->scn->sp_mode + 3]);
	init_buttons(rt);
	draw_no_selected_element(rt);
}
