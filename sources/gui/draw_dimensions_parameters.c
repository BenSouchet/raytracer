/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_dimensions_parameters.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 15:02:08 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 13:12:41 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		draw_dimensions_parameter(t_rt *rt, t_obj *o)
{
	if (o->forme == T_PLANE || o->forme == T_CUBE)
		D_P(rt, ft_dtoa(o->width, 0, 1), rt->ui->obj_b_rect[6], 2);
	else
		D_P(rt, ft_strf("-----"), rt->ui->obj_b_rect[6], 1);
	if (o->forme == T_CUBE || o->forme == T_CYLINDER || o->forme == T_CONE)
		D_P(rt, ft_dtoa(o->height, 0, 1), rt->ui->obj_b_rect[7], 2);
	else
		D_P(rt, ft_strf("-----"), rt->ui->obj_b_rect[7], 1);
	if (o->forme == T_PLANE || o->forme == T_CUBE)
		D_P(rt, ft_dtoa(o->lenght, 0, 1), rt->ui->obj_b_rect[8], 2);
	else
		D_P(rt, ft_strf("-----"), rt->ui->obj_b_rect[8], 1);
}
