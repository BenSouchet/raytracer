/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   se_box_minus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 16:41:58 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 15:49:30 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	update_se_camera_box(t_rt *rt)
{
	if (AC == 1 && S_ELEM->focal > 18)
		S_ELEM->focal -= 1;
	else if ((AC == 2 || (AC == -1 && CK_DOWN == SDLK_LEFT && (AC = 2) &&
	(rt->ui->k_edit = 1))) && S_ELEM->pos.x >= -999.50f)
		S_ELEM->pos.x = R((S_ELEM->pos.x - 0.50f) * 100) / 100;
	else if ((AC == 3 || (AC == -1 && CK_DOWN == SDLK_DOWN && (AC = 3) &&
	(rt->ui->k_edit = 1))) && S_ELEM->pos.y >= -999.50f)
		S_ELEM->pos.y = R((S_ELEM->pos.y - 0.50f) * 100) / 100;
	else if (AC == 4 && S_ELEM->pos.z >= -999.50f)
		S_ELEM->pos.z = R((S_ELEM->pos.z - 0.50f) * 100) / 100;
	else if ((AC == 5 || (AC == -1 && CK_DOWN == SDLK_s && (AC = 5) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.x >= -719.50f)
		S_ELEM->rot.x = R((S_ELEM->rot.x - 0.50f) * 100) / 100;
	else if ((AC == 6 || (AC == -1 && CK_DOWN == SDLK_a && (AC = 6) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.y >= -719.50f)
		S_ELEM->rot.y = R((S_ELEM->rot.y - 0.50f) * 100) / 100;
	else if ((AC == 7 || (AC == -1 && CK_DOWN == SDLK_q && (AC = 7) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.z >= -719.50f)
		S_ELEM->rot.z = R((S_ELEM->rot.z - 0.50f) * 100) / 100;
	redraw_case_active(rt, 1);
}

static void	update_se_light_box(t_rt *rt)
{
	if (AC == 1 && S_ELEM->intensity > 0)
		S_ELEM->intensity -= 1;
	else if (AC == 3 && S_ELEM->clr.x >= 0.0020f)
		S_ELEM->clr.x = R((S_ELEM->clr.x - 0.0020f) * 1000) / 1000;
	else if (AC == 4 && S_ELEM->clr.y >= 0.0020f)
		S_ELEM->clr.y = R((S_ELEM->clr.y - 0.0020f) * 1000) / 1000;
	else if (AC == 5 && S_ELEM->clr.z >= 0.0020f)
		S_ELEM->clr.z = R((S_ELEM->clr.z - 0.0020f) * 1000) / 1000;
	else if ((AC == 6 || (AC == -1 && CK_DOWN == SDLK_LEFT && (AC = 6) &&
	(rt->ui->k_edit = 1))) && S_ELEM->pos.x >= -999.50f)
		S_ELEM->pos.x = R((S_ELEM->pos.x - 0.50f) * 100) / 100;
	else if ((AC == 7 || (AC == -1 && CK_DOWN == SDLK_DOWN && (AC = 7) &&
	(rt->ui->k_edit = 1))) && S_ELEM->pos.y >= -999.50f)
		S_ELEM->pos.y = R((S_ELEM->pos.y - 0.50f) * 100) / 100;
	else if (AC == 8 && S_ELEM->pos.z >= -999.50f)
		S_ELEM->pos.z = R((S_ELEM->pos.z - 0.50f) * 100) / 100;
	else if (AC > 8)
		update_se_light_box_minus_part2(rt);
	redraw_case_active(rt, 1);
}

static void	update_se_object_box_part2(t_rt *rt)
{
	if (AC == 3 && S_ELEM->reflex >= 0.050f)
		S_ELEM->reflex = R((S_ELEM->reflex - 0.050f) * 100) / 100;
	else if (AC == 4 && S_ELEM->refrac != 0)
		S_ELEM->refrac = 0;
	else if (AC == 5 && S_ELEM->radius >= 1.0f)
		S_ELEM->radius -= 1.0f;
	else if (AC == 6 && S_ELEM->width >= -999.50f)
		S_ELEM->width = R((S_ELEM->width - 0.50f) * 100) / 100;
	else if (AC == 7 && S_ELEM->height >= -999.50f)
		S_ELEM->height = R((S_ELEM->height - 0.50f) * 100) / 100;
	else if (AC == 8 && S_ELEM->lenght >= -999.50f)
		S_ELEM->lenght = R((S_ELEM->lenght - 0.50f) * 100) / 100;
	else if (AC == 9 && S_ELEM->clr.x >= 0.0020f)
		S_ELEM->clr.x = R((S_ELEM->clr.x - 0.0020f) * 1000) / 1000;
	else if (AC == 10 && S_ELEM->clr.y >= 0.0020f)
		S_ELEM->clr.y = R((S_ELEM->clr.y - 0.0020f) * 1000) / 1000;
	else if (AC == 11 && S_ELEM->clr.z >= 0.0020f)
		S_ELEM->clr.z = R((S_ELEM->clr.z - 0.0020f) * 1000) / 1000;
	else if ((AC == 12 || (AC == -1 && CK_DOWN == SDLK_LEFT && (AC = 12) &&
	(rt->ui->k_edit = 1))) && S_ELEM->pos.x >= -999.50f)
		S_ELEM->pos.x = R((S_ELEM->pos.x - 0.50f) * 100) / 100;
}

static void	update_se_object_box(t_rt *rt)
{
	if (AC == 1 && S_ELEM->opacity >= 0.050f)
		S_ELEM->opacity = R((S_ELEM->opacity - 0.050f) * 100) / 100;
	else if (AC == 2 && S_ELEM->specular != 0)
		S_ELEM->specular = 0;
	else if (AC > 2 && AC < 13)
		update_se_object_box_part2(rt);
	else if ((AC == 13 || (AC == -1 && CK_DOWN == SDLK_DOWN && (AC = 13) &&
	(rt->ui->k_edit = 1))) && S_ELEM->pos.y >= -999.50f)
		S_ELEM->pos.y = R((S_ELEM->pos.y - 0.50f) * 100) / 100;
	else if (AC == 14 && S_ELEM->pos.z >= -999.50f)
		S_ELEM->pos.z = R((S_ELEM->pos.z - 0.50f) * 100) / 100;
	else if ((AC == 15 || (AC == -1 && CK_DOWN == SDLK_s && (AC = 15) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.x >= -719.50f)
		S_ELEM->rot.x = R((S_ELEM->rot.x - 0.50f) * 100) / 100;
	else if ((AC == 16 || (AC == -1 && CK_DOWN == SDLK_a && (AC = 16) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.y >= -719.50f)
		S_ELEM->rot.y = R((S_ELEM->rot.y - 0.50f) * 100) / 100;
	else if ((AC == 17 || (AC == -1 && CK_DOWN == SDLK_q && (AC = 17) &&
	(rt->ui->k_edit = 1))) && S_ELEM->rot.z >= -719.50f)
		S_ELEM->rot.z = R((S_ELEM->rot.z - 0.50f) * 100) / 100;
	else if ((AC == 18 && S_ELEM->shader >= 1))
		--S_ELEM->shader;
	redraw_case_active(rt, 1);
}

void		update_se_box_minus(t_rt *rt, t_cl *cl)
{
	if (S_ELEM->type == 'C')
		update_se_camera_box(rt);
	else if (S_ELEM->type == 'L')
		update_se_light_box(rt);
	else
		update_se_object_box(rt);
	if (S_ELEM == rt->scn->c_cam)
		cl_main_krl_update_camera(cl, rt->scn->c_cam);
	else
		cl_main_krl_update_buffers(cl, rt->scn);
}
