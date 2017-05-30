/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cartoon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/06 21:03:58 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 11:01:11 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static size_t	limit_clr(size_t col)
{
	if (col <= 0)
		return (0);
	else if (col > 0 && col <= 50)
		return (25);
	else if (col > 50 && col <= 100)
		return (75);
	else if (col > 100 && col <= 200)
		return (150);
	else if (col > 200 && col < 250)
		return (225);
	else if (col >= 255)
		return (255);
	return (col);
}

static size_t	x_g(t_rt *rt, short res, short j, char type)
{
	short	i;
	short	sum;
	short	tab[3][3];

	tab[0][0] = -1;
	tab[0][1] = (type == 'X') ? 0 : -2;
	tab[0][2] = (type == 'X') ? 1 : -1;
	tab[1][0] = (type == 'X') ? -2 : 0;
	tab[1][1] = 0;
	tab[1][2] = (type == 'X') ? 2 : 0;
	tab[2][0] = (type == 'X') ? -1 : 1;
	tab[2][1] = (type == 'X') ? 0 : 2;
	tab[2][2] = 1;
	while (++j < 2)
	{
		i = -2;
		while (++i < 2)
		{
			rt->ui->t_v2 = fsdl_get_pt_clr(rt->s_rend,
			rt->ui->t_rect.x + i, rt->ui->t_rect.y + j);
			sum = (rt->ui->t_v2.x + rt->ui->t_v2.y + rt->ui->t_v2.z) / 3.;
			res += tab[j + 1][i + 1] * sum;
		}
	}
	return (res);
}

void			add_cartoon_effect(t_rt *rt, short sum, short x, short y)
{
	rt->ui->t_rect.y = -1;
	while (++rt->ui->t_rect.y < rt->s_rend->h)
	{
		rt->ui->t_rect.x = -1;
		while (++rt->ui->t_rect.x < rt->s_rend->w)
		{
			rt->ui->t_v =
			fsdl_get_pt_clr(rt->s_rend, rt->ui->t_rect.x, rt->ui->t_rect.y);
			x = x_g(rt, 0, -2, 'X');
			y = x_g(rt, 0, -2, 'Y');
			sum = 255 - sqrt((x * x) + (y * y));
			sum = sum > 255 ? 255 : sum;
			sum = sum < 0 ? 0 : sum;
			if (sum > 100)
				fsdl_draw_pt(rt->s_effct, (((limit_clr(rt->ui->t_v.x) & 0xFF)
				<< 24) + ((limit_clr(rt->ui->t_v.y) & 0xFF) << 16) +
				((limit_clr(rt->ui->t_v.z) & 0xFF) << 8) +
				((unsigned)255 & 0xff)), rt->ui->t_rect.x, rt->ui->t_rect.y);
			else
				fsdl_draw_pt(rt->s_effct, (((sum & 0xFF) << 24) + ((sum & 0xFF)
				<< 16) + ((sum & 0xFF) << 8) + ((unsigned)255 & 0xff)),
				rt->ui->t_rect.x, rt->ui->t_rect.y);
		}
	}
}
