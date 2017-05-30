/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_element.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 16:41:53 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/11 14:23:47 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	edit_begin_outliner(t_rt *rt, t_obj *nav)
{
	nav = rt->scn->o;
	while (nav->next && nav->next->id != rt->scn->b_outliner->id)
		nav = nav->next;
	rt->scn->b_outliner = nav;
	rt->ui->nav_state = (rt->scn->n_elms >= 12) ? 1 : 0;
	if (rt->scn->n_elms <= 12)
		rt->scn->b_outliner = rt->scn->o;
}

void		delete_current_element(t_rt *rt, t_cl *cl,
			t_obj *nav, t_obj *tmp)
{
	char		*str;

	if ((rt->scn->s_elem->type == 'C' && rt->scn->n_cams == 1) ||
		(rt->scn->s_elem->type == 'L' && rt->scn->n_lgts == 1) ||
		(rt->scn->s_elem->type == 'O' && rt->scn->n_objs == 1))
	{
		set_default_element(rt, cl, rt->scn->s_elem->type);
		return ;
	}
	if (rt->scn->s_elem->type == 'C')
		--rt->scn->n_cams;
	else
		(rt->scn->s_elem->type == 'L') ? --rt->scn->n_lgts : --rt->scn->n_objs;
	--rt->scn->n_elms;
	if (rt->scn->s_elem->type != 'C')
		(rt->scn->s_elem->type == 'L') ? --rt->scn->lt[rt->scn->s_elem->forme] :
		--rt->scn->ot[rt->scn->s_elem->forme];
	nav = rt->scn->o;
	while (nav->next && nav->next->id != rt->scn->s_elem->id)
		nav = nav->next;
	tmp = nav->next;
	nav->next = nav->next->next;
	str = (char *)tmp->n;
	edit_begin_outliner(rt, NULL);
	redraw_current_element(rt, cl, str);
}
