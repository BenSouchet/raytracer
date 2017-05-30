/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_current_camera_name.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:09:27 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/22 19:09:38 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_current_camera_name(t_rt *rt, short type)
{
	fsdl_fill_rect(rt->s_back, (SDL_Rect){1078, 32, 190, 16}, PAN_BG);
	if (type == 2)
		free(rt->ui->r_dim);
	if (type != 0)
		free(rt->ui->c_name);
	if (type != 1)
		rt->ui->r_dim = ft_strjoin(ft_strjoin(ft_strjoin(" (",
		ft_itoa(rt->r_view.w), 'R'), ft_strjoin(" x ",
		ft_itoa(rt->r_view.h), 'R'), 'B'), ")", 'L');
	rt->ui->c_name = ft_strunc((char *)rt->scn->c_cam->n,
	(24 - ft_strlen(rt->ui->r_dim)));
	rt->ui->tmp = ft_strjoin(rt->ui->c_name, rt->ui->r_dim, 'N');
	rt->ui->s_tmp = TTF_RenderText_Shaded(rt->ui->font[0], rt->ui->tmp,
	(SDL_Color){162, 162, 162, 255}, (SDL_Color){52, 62, 77, 255});
	rt->ui->t_c = ((192 - rt->ui->s_tmp->w) / 2);
	SDL_LowerBlit(rt->ui->s_tmp, &(SDL_Rect){0, 0, rt->ui->s_tmp->w,
	rt->ui->s_tmp->h}, rt->s_back, &(SDL_Rect){1078 + rt->ui->t_c, 32,
	rt->ui->s_tmp->w, rt->ui->s_tmp->h});
	SDL_FreeSurface(rt->ui->s_tmp);
	free(rt->ui->tmp);
}
