/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sepia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:01:30 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 10:57:40 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	add_sepia_effect(t_rt *rt, short r, short g, short b)
{
	rt->ui->t_rect.y = -1;
	while (++rt->ui->t_rect.y < rt->s_rend->h)
	{
		rt->ui->t_rect.x = -1;
		while (++rt->ui->t_rect.x < rt->s_rend->w)
		{
			rt->ui->t_v =
			fsdl_get_pt_clr(rt->s_rend, rt->ui->t_rect.x, rt->ui->t_rect.y);
			r = (unsigned)((rt->ui->t_v.z * 0.393) + (rt->ui->t_v.y * 0.769) +
			(rt->ui->t_v.x * 0.189));
			g = (unsigned)((rt->ui->t_v.z * 0.349) + (rt->ui->t_v.y * 0.686) +
			(rt->ui->t_v.x * 0.168));
			b = (unsigned)((rt->ui->t_v.z * 0.272) + (rt->ui->t_v.y * 0.534) +
			(rt->ui->t_v.x * 0.131));
			fsdl_draw_pt(rt->s_effct,
			(((((r > 255) ? 255 : r) & 0xFF) << 24) +
			((((g > 255) ? 255 : g) & 0xFF) << 16) +
			((((b > 255) ? 255 : b) & 0xFF) << 8) +
			((unsigned)255 & 0xff)), rt->ui->t_rect.x, rt->ui->t_rect.y);
		}
	}
}
