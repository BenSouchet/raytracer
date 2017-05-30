/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_box.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/09 15:55:45 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 15:57:55 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	update_se_light_box_minus_part2(t_rt *rt)
{
	if ((AC == 9 || (AC == -1 && CK_DOWN == SDLK_s && (AC = 9) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.x >= -719.50f)
		S_ELEM->rot.x = R((S_ELEM->rot.x - 0.50f) * 100) / 100;
	else if ((AC == 10 || (AC == -1 && CK_DOWN == SDLK_a && (AC = 10) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.y >= -719.50f)
		S_ELEM->rot.y = R((S_ELEM->rot.y - 0.50f) * 100) / 100;
	else if ((AC == 11 || (AC == -1 && CK_DOWN == SDLK_q && (AC = 11) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.z >= -719.50f)
		S_ELEM->rot.z = R((S_ELEM->rot.z - 0.50f) * 100) / 100;
}

void	update_se_light_box_plus_part2(t_rt *rt)
{
	if ((AC == 9 || (AC == -1 && CK_DOWN == SDLK_w && (AC = 9) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.x <= 719.50f)
		S_ELEM->rot.x = R((S_ELEM->rot.x + 0.50f) * 100) / 100;
	else if ((AC == 10 || (AC == -1 && CK_DOWN == SDLK_d && (AC = 10) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.y <= 719.50f)
		S_ELEM->rot.y = R((S_ELEM->rot.y + 0.50f) * 100) / 100;
	else if ((AC == 11 || (AC == -1 && CK_DOWN == SDLK_e && (AC = 11) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.z <= 719.50f)
		S_ELEM->rot.z = R((S_ELEM->rot.z + 0.50f) * 100) / 100;
}
