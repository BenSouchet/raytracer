/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_outliner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 18:43:06 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 10:49:31 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_outliner(t_rt *rt, int i, int max)
{
	t_obj	*lst;

	lst = rt->scn->b_outliner;
	rt->ui->area[12].y = 233;
	fsdl_fill_rect(rt->s_back, (SDL_Rect){13, 233, 188, 409}, INFO_BG);
	(rt->scn->n_elms >= 12) ? (rt->ui->nav_state = 1) : 1;
	if (rt->ui->nav_state == 1)
		draw_top_nav_button(rt, (lst->id == rt->scn->o->id) ? -1 : 0);
	max = (rt->ui->nav_state == 1) ? 12 : 13;
	while (i < max && lst)
	{
		if (lst->title != 0)
			draw_outliner_title(rt, lst->title);
		else
		{
			lst->r_ol = rt->ui->area[12];
			lst->r_ol.h = 29;
			draw_outliner_element(rt, lst, 0);
		}
		rt->ui->area[12].y += 29;
		(i < max - 1) ? (lst = lst->next) : 0;
		i++;
	}
	if (rt->ui->nav_state == 1)
		draw_bottom_nav_button(rt, (lst == NULL || lst->next == NULL) ? -1 : 0);
}
