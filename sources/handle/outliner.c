/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outliner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/17 21:00:30 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/22 13:26:39 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			handle_click_nav(t_rt *rt)
{
	t_obj	*list;
	int		c_hover_tmp;

	list = rt->scn->o;
	rt->ui->c_down = rt->ui->c_hover;
	c_hover_tmp = rt->ui->c_hover;
	if (rt->ui->c_hover == -2)
	{
		list = rt->scn->o;
		while (list && list->next->id != rt->scn->b_outliner->id)
			list = list->next;
		rt->scn->b_outliner = list;
	}
	else
		rt->scn->b_outliner = rt->scn->b_outliner->next;
	draw_outliner(rt, -1, 0);
	handle_outliner(rt, 0, 0, 0);
	return (1);
}

void		handle_outliner_down(t_rt *rt)
{
	if (rt->ui->c_hover < -1 && handle_click_nav(rt))
		return ;
	rt->n_info = -2;
	rt->ui->tmp = ft_strf(INF32, rt->ui->c_elem->n);
	draw_outliner_element(rt, rt->ui->c_elem, 2);
	rt->ui->c_down = rt->ui->c_hover;
	rt->scn->s_elem = rt->ui->c_elem;
	(rt->ui->b_state[16] == 2) ? draw_selected_element(rt) : 1;
	if (rt->ui->c_elem->type == 'O')
		(!rt->ui->m_visible) ? draw_materials(rt, 'E') : 1;
	else if (rt->ui->m_visible)
		draw_materials(rt, 'D');
	draw_info_bar(rt);
	free(rt->ui->tmp);
}

int			handle_top_nav_button(t_rt *rt)
{
	rt->ui->c_hover = -1;
	if (rt->scn->b_outliner->n == NULL && rt->scn->b_outliner->type == 'C')
		return (1);
	rt->ui->c_hover = -2;
	rt->ui->r_hover = (SDL_Rect){13, 232, 188, 16};
	draw_top_nav_button(rt, 1);
	return (1);
}

int			handle_bottom_nav_button(t_rt *rt, t_obj *list, int pos)
{
	pos--;
	while (--pos && list->next)
		list = list->next;
	rt->ui->c_hover = -1;
	if (list->next == NULL)
		return (1);
	rt->ui->c_hover = -3;
	rt->ui->r_hover = (SDL_Rect){13, 625, 188, 16};
	draw_bottom_nav_button(rt, 1);
	return (1);
}

void		handle_outliner(t_rt *rt, int pos, int tmp, int type)
{
	t_obj	*list;

	(void)tmp;
	(void)type;
	rt->ui->c_hover = -1;
	list = rt->scn->b_outliner;
	pos = ((int)((float)(rt->m_pos.y - 233.) / 29.) + 1);
	if (rt->ui->nav_state == 1)
	{
		pos = ((int)((float)(rt->m_pos.y - 249.) / 29.) + 1);
		if (rt->m_pos.y < 249 && handle_top_nav_button(rt))
			return ;
		else if (rt->m_pos.y > 625 && handle_bottom_nav_button(rt, list, pos))
			return ;
	}
	while (--pos && list->next != NULL)
		list = list->next;
	if (list->n == NULL && (rt->ui->c_hover = -1) != 0)
		return ;
	rt->ui->c_hover = list->id;
	rt->ui->c_elem = list;
	draw_outliner_element(rt, list, 1);
}
