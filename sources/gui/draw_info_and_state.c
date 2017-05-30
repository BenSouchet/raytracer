/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_info_and_state.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:44:46 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 10:41:31 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_renderer_info(t_rt *rt)
{
	SDL_LowerBlit(rt->ui->s_ver,
	&(SDL_Rect){0, 0, rt->ui->s_ver->w, rt->ui->s_ver->h},
	rt->s_back, &(SDL_Rect){18, 687, rt->ui->s_ver->w, rt->ui->s_ver->h});
}

int			draw_info_bar(t_rt *rt)
{
	fsdl_fill_rect(rt->s_back, rt->r_info, INFO_BG);
	if (rt->n_info == -1)
		return (0);
	rt->ui->s_tmp = TTF_RenderText_Shaded(rt->ui->font[1],
	(rt->n_info != -2) ? rt->inf[(int)rt->n_info] : rt->ui->tmp,
	(SDL_Color){178, 147, 41, 255}, (SDL_Color){44, 53, 64, 255});
	SDL_LowerBlit(rt->ui->s_tmp, &(SDL_Rect){0, 0, rt->ui->s_tmp->w,
	rt->ui->s_tmp->h}, rt->s_back, &(SDL_Rect){(rt->r_info.x + 18), 697,
	rt->ui->s_tmp->w, rt->ui->s_tmp->h});
	SDL_FreeSurface(rt->ui->s_tmp);
	return (0);
}
