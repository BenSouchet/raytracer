/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_outliner_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:28:52 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/08 19:39:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static size_t	fsdl_clr_to_size_t(SDL_Color clr)
{
	size_t	new;

	new = 0;
	if (clr.r == 44)
		new = 0xFF2c3540;
	else if (clr.r == 48)
		new = 0xFF303a45;
	else if (clr.r == 40)
		new = 0xFF283039;
	return (new);
}

void			draw_outliner_element(t_rt *rt, t_obj *obj, int state)
{
	int		t;
	char	*tmp;

	t = (obj->next == NULL || obj->type != obj->next->type) ? 291 : 262;
	t += (state > 0) ? 58 : 0;
	t += (state > 1) ? 58 : 0;
	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){13, t, obj->r_ol.w, 29},
	rt->s_back, &(SDL_Rect){13, obj->r_ol.y, obj->r_ol.w, 29});
	tmp = ft_strunc((char *)obj->n, 17);
	if (obj->visibility == 1)
		fsdl_fill_rect(rt->s_back, (SDL_Rect){173, obj->r_ol.y + 8, 15, 13},
		fsdl_clr_to_size_t(rt->ui->c_clr[state]));
	rt->ui->s_tmp = TTF_RenderText_Shaded(rt->ui->font[1], tmp,
	(SDL_Color){162, 162, 162, 255}, rt->ui->c_clr[state]);
	free(tmp);
	SDL_LowerBlit(rt->ui->s_tmp, &(SDL_Rect){0, 0, rt->ui->s_tmp->w,
	rt->ui->s_tmp->h}, rt->s_back, &(SDL_Rect){45, obj->r_ol.y + 7,
	rt->ui->s_tmp->w, rt->ui->s_tmp->h});
	SDL_FreeSurface(rt->ui->s_tmp);
	if (state == 0)
		rt->ui->c_hover = -1;
}

void			draw_outliner_title(t_rt *rt, int i)
{
	char	*name;

	if (i == -1)
		name = (rt->scn->n_cams > 1) ? "Cameras" : "Camera";
	else if (i == -2)
		name = (rt->scn->n_lgts > 1) ? "Lights" : "Light";
	else
		name = (rt->scn->n_objs > 1) ? "Objects" : "Object";
	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){13, 233, rt->ui->area[12].w, 29},
	rt->s_back, &(SDL_Rect){13, rt->ui->area[12].y, rt->ui->area[12].w, 29});
	rt->ui->s_tmp = TTF_RenderText_Shaded(rt->ui->font[1], name,
	(SDL_Color){162, 162, 162, 255}, (SDL_Color){40, 45, 52, 255});
	SDL_LowerBlit(rt->ui->s_tmp, &(SDL_Rect){0, 0, rt->ui->s_tmp->w,
	rt->ui->s_tmp->h}, rt->s_back, &(SDL_Rect){32, rt->ui->area[12].y + 7,
	rt->ui->s_tmp->w, rt->ui->s_tmp->h});
	SDL_FreeSurface(rt->ui->s_tmp);
}
