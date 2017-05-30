/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greyscale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:01:52 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:51:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_black_n_white_effect(t_rt *rt)
{
	rt->ui->t_rect.y = -1;
	while (++rt->ui->t_rect.y < rt->s_rend->h)
	{
		rt->ui->t_rect.x = -1;
		while (++rt->ui->t_rect.x < rt->s_rend->w)
		{
			rt->ui->t_v =
			fsdl_get_pt_clr(rt->s_rend, rt->ui->t_rect.x, rt->ui->t_rect.y);
			fsdl_draw_pt(rt->s_effct, ((((unsigned)((rt->ui->t_v.z * 0.1140) +
			(rt->ui->t_v.y * 0.5870) + (rt->ui->t_v.x * 0.2989)) & 0xFF)
			<< 24) + (((unsigned)((rt->ui->t_v.z * 0.1140) +
			(rt->ui->t_v.y * 0.5870) + (rt->ui->t_v.x * 0.2989)) & 0xFF)
			<< 16) + (((unsigned)((rt->ui->t_v.z * 0.1140) +
			(rt->ui->t_v.y * 0.5870) + (rt->ui->t_v.x * 0.2989)) & 0xFF)
			<< 8) + ((unsigned)255 & 0xff)),
			rt->ui->t_rect.x, rt->ui->t_rect.y);
		}
	}
}
