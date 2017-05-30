/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parameters.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 13:02:07 by bsouchet          #+#    #+#             */
/*   Updated: 2017/04/30 19:25:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		handle_scene_parameters(t_rt *rt)
{
	if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->param_b_rect[0]))
		rt->ui->b_sp_hover = 0;
	else if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->param_b_rect[1]))
		rt->ui->b_sp_hover = 1;
	else if (fsdl_pt_in_rect(&rt->m_pos, rt->ui->param_b_rect[2]))
		rt->ui->b_sp_hover = 2;
	if (rt->ui->b_sp_hover > -1)
		draw_sp_element(rt, rt->ui->b_sp_hover, 1);
}
