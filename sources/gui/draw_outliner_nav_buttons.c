/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_outliner_nav_buttons.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:27:52 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/08 19:39:16 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_top_nav_button(t_rt *rt, int state)
{
	if (state == -1)
		state = 545;
	else if (state == 0)
		state = 561;
	else if (state == 1)
		state = 577;
	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){13, state, 188, 16},
	rt->s_back, &(SDL_Rect){13, 232, 188, 16});
	rt->ui->area[12].y += 15;
}

void		draw_bottom_nav_button(t_rt *rt, int state)
{
	if (state == -1)
		state = 593;
	else if (state == 0)
		state = 609;
	else if (state == 1)
		state = 625;
	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){13, state, 188, 16},
	rt->s_back, &(SDL_Rect){13, 625, 188, 16});
}

void		draw_nav_element(t_rt *rt, int state)
{
	int		pos;
	t_obj	*list;

	list = rt->scn->b_outliner;
	if (rt->ui->c_hover == -2)
	{
		if (rt->scn->b_outliner->n == NULL && rt->scn->b_outliner->type == 'C')
			state = -1;
		draw_top_nav_button(rt, state);
	}
	else
	{
		pos = 13;
		while (--pos)
			list = list->next;
		if (list->next == NULL)
			state = -1;
		draw_bottom_nav_button(rt, state);
	}
	rt->ui->c_hover = -1;
	rt->ui->c_elem = NULL;
	rt->ui->r_hover = (SDL_Rect){0, 0, 0, 0};
}
