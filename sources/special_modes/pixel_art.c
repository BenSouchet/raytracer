/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_art.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:05:31 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 11:00:14 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static size_t	get_average_clr(t_rt *rt, short x, short y)
{
	rt->ui->t_v = (cl_float3){{0, 0, 0, 0}};
	while (++y < rt->ui->t_rect.y + PX_SIZE)
	{
		x = rt->ui->t_rect.x;
		while (++x < rt->ui->t_rect.x + PX_SIZE)
		{
			rt->ui->t_v2 =
			fsdl_get_pt_clr(rt->s_rend, x, y);
			rt->ui->t_v.x += rt->ui->t_v2.x;
			rt->ui->t_v.y += rt->ui->t_v2.y;
			rt->ui->t_v.z += rt->ui->t_v2.z;
		}
	}
	return (((((int)(rt->ui->t_v.x / PX_SIZE_SQRD) & 0xFF) << 24) +
	(((int)(rt->ui->t_v.y / PX_SIZE_SQRD) & 0xFF) << 16) +
	(((int)(rt->ui->t_v.z / PX_SIZE_SQRD) & 0xFF) << 8) + ((int)255 & 0xff)));
}

void			add_pixel_art_effect(t_rt *rt)
{
	size_t clr;

	rt->ui->t_rect.y = -1;
	while (rt->ui->t_rect.y < rt->s_rend->h)
	{
		rt->ui->t_rect.x = -1;
		while (rt->ui->t_rect.x < rt->s_rend->w)
		{
			clr = get_average_clr(rt, rt->ui->t_rect.x, rt->ui->t_rect.y);
			fsdl_fill_rect(rt->s_effct, (SDL_Rect){rt->ui->t_rect.x + 1,
			rt->ui->t_rect.y + 1, PX_SIZE, PX_SIZE}, clr);
			rt->ui->t_rect.x += PX_SIZE;
		}
		rt->ui->t_rect.y += PX_SIZE;
	}
}
