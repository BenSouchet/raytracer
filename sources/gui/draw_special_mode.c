/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_special_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:07:05 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/22 19:07:33 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_special_mode(t_rt *rt, int r_num, int type)
{
	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->ra_rect[type], rt->s_back,
	&rt->ui->ra_rect[r_num]);
	(type == 0) ? (rt->ui->ra_hover = -1) : 1;
}
