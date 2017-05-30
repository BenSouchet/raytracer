/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_mode.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 12:55:32 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:18:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		handle_special_modes_down(t_rt *rt)
{
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->ra_rect[0], rt->s_back,
	&rt->ui->ra_rect[(int)rt->scn->sp_mode + 3]);
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->ra_rect[2], rt->s_back,
	&rt->ui->ra_rect[(int)rt->ui->ra_hover]);
	rt->ui->ra_down = rt->ui->ra_hover;
	rt->scn->sp_mode = rt->ui->ra_down - 3;
	rt->ui->ra_hover = -1;
	rt->n_info = 24 + rt->scn->sp_mode;
	rt->scn->redraw = 1;
	draw_info_bar(rt);
}

void		handle_special_mode(t_rt *rt, int i)
{
	rt->ui->ra_hover = -1;
	while (i < 11 && !fsdl_pt_in_rect(&rt->m_pos, rt->ui->ra_rect[i]))
		i++;
	if (i == 11 || (i - 3) == rt->scn->sp_mode)
		return ;
	rt->ui->ra_hover = i;
	draw_special_mode(rt, rt->ui->ra_hover, 1);
}
