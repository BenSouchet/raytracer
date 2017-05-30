/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_materials.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:04:41 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/22 19:04:59 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_materials(t_rt *rt, char type)
{
	if (type == 'E')
	{
		rt->ui->b_state[11] = 0;
		rt->ui->b_state[12] = 0;
		rt->ui->b_state[13] = 0;
		rt->ui->b_state[14] = 0;
		draw_button(rt, 11, 0);
		draw_button(rt, 12, 0);
		draw_button(rt, 13, 0);
		draw_button(rt, 14, 0);
	}
	else
	{
		rt->ui->b_state[11] = 4;
		rt->ui->b_state[12] = 4;
		rt->ui->b_state[13] = 4;
		rt->ui->b_state[14] = 4;
		draw_button(rt, 11, 3);
		draw_button(rt, 12, 3);
		draw_button(rt, 13, 3);
		draw_button(rt, 14, 3);
	}
	rt->ui->m_visible = (type == 'E') ? 1 : 0;
}
