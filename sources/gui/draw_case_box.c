/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_case_box.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/28 17:29:24 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:27:30 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	redraw_case_box_camera(t_rt *rt, t_obj *obj, int m)
{
	if (rt->ui->case_active == 1)
		D_C(rt, ft_itoa(obj->focal), rt->ui->cam_b_rect[1], m);
	else if (rt->ui->case_active == 2)
		D_C(rt, ft_dtoa(obj->pos.x, 0, 1), rt->ui->cam_b_rect[2], m);
	else if (rt->ui->case_active == 3)
		D_C(rt, ft_dtoa(obj->pos.y, 0, 1), rt->ui->cam_b_rect[3], m);
	else if (rt->ui->case_active == 4)
		D_C(rt, ft_dtoa(obj->pos.z, 0, 1), rt->ui->cam_b_rect[4], m);
	else if (rt->ui->case_active == 5)
		D_C(rt, ft_dtoa(obj->rot.x, 0, 1), rt->ui->cam_b_rect[5], m);
	else if (rt->ui->case_active == 6)
		D_C(rt, ft_dtoa(obj->rot.y, 0, 1), rt->ui->cam_b_rect[6], m);
	else if (rt->ui->case_active == 7)
		D_C(rt, ft_dtoa(obj->rot.z, 0, 1), rt->ui->cam_b_rect[7], m);
}

static void	redraw_case_box_light(t_rt *rt, t_obj *obj, int m)
{
	if (rt->ui->case_active == 1)
		D_C(rt, ft_itoa(obj->intensity), rt->ui->lgt_b_rect[1], m);
	else if (rt->ui->case_active == 2)
		D_C(rt, ft_strf("YES"), rt->ui->lgt_b_rect[2], m);
	else if (rt->ui->case_active == 3)
		D_C(rt, DTOA(R(obj->clr.x * 255.0f), 0, 1), rt->ui->lgt_b_rect[3], m);
	else if (rt->ui->case_active == 4)
		D_C(rt, DTOA(R(obj->clr.y * 255.0f), 0, 1), rt->ui->lgt_b_rect[4], m);
	else if (rt->ui->case_active == 5)
		D_C(rt, DTOA(R(obj->clr.z * 255.0f), 0, 1), rt->ui->lgt_b_rect[5], m);
	else if (rt->ui->case_active == 6)
		D_C(rt, ft_dtoa(obj->pos.x, 0, 1), rt->ui->lgt_b_rect[6], m);
	else if (rt->ui->case_active == 7)
		D_C(rt, ft_dtoa(obj->pos.y, 0, 1), rt->ui->lgt_b_rect[7], m);
	else if (rt->ui->case_active == 8)
		D_C(rt, ft_dtoa(obj->pos.z, 0, 1), rt->ui->lgt_b_rect[8], m);
	else if (rt->ui->case_active == 9)
		D_C(rt, ft_dtoa(obj->rot.x, 0, 1), rt->ui->lgt_b_rect[9], m);
	else if (rt->ui->case_active == 10)
		D_C(rt, ft_dtoa(obj->rot.y, 0, 1), rt->ui->lgt_b_rect[10], m);
	else if (rt->ui->case_active == 11)
		D_C(rt, ft_dtoa(obj->rot.z, 0, 1), rt->ui->lgt_b_rect[11], m);
}

static void	redraw_case_box_object_part2(t_rt *rt, t_obj *obj, int m)
{
	if (rt->ui->case_active == 3)
		D_C(rt, ft_dtoa(obj->reflex, 0, 1), rt->ui->obj_b_rect[3], m);
	else if (rt->ui->case_active == 4)
		D_C(rt, (obj->refrac == 0) ? ft_strf("NO") : ft_strf("YES"),
		rt->ui->obj_b_rect[4], m);
	else if (rt->ui->case_active == 5)
		D_C(rt, ft_dtoa(obj->radius, 0, 1), rt->ui->obj_b_rect[5], m);
	else if (rt->ui->case_active == 6)
		D_C(rt, ft_dtoa(obj->width, 0, 1), rt->ui->obj_b_rect[6], m);
	else if (rt->ui->case_active == 7)
		D_C(rt, ft_dtoa(obj->height, 0, 1), rt->ui->obj_b_rect[7], m);
	else if (rt->ui->case_active == 8)
		D_C(rt, ft_dtoa(obj->lenght, 0, 1), rt->ui->obj_b_rect[8], m);
	else if (rt->ui->case_active == 9)
		D_C(rt, DTOA(R(obj->clr.x * 255.0f), 0, 1), rt->ui->obj_b_rect[9], m);
	else if (rt->ui->case_active == 10)
		D_C(rt, DTOA(R(obj->clr.y * 255.0f), 0, 1), rt->ui->obj_b_rect[10], m);
	else if (rt->ui->case_active == 11)
		D_C(rt, DTOA(R(obj->clr.z * 255.0f), 0, 1), rt->ui->obj_b_rect[11], m);
}

static void	redraw_case_box_object(t_rt *rt, t_obj *obj, int m)
{
	if (rt->ui->case_active == 1)
		D_C(rt, ft_dtoa(obj->opacity, 0, 1), rt->ui->obj_b_rect[1], m);
	else if (rt->ui->case_active == 2)
		D_C(rt, (obj->specular == 0) ? ft_strf("NO") : ft_strf("YES"),
		rt->ui->obj_b_rect[2], m);
	else if (rt->ui->case_active > 2 && rt->ui->case_active < 12)
		redraw_case_box_object_part2(rt, obj, m);
	else if (rt->ui->case_active == 12)
		D_C(rt, ft_dtoa(obj->pos.x, 0, 1), rt->ui->obj_b_rect[12], m);
	else if (rt->ui->case_active == 13)
		D_C(rt, ft_dtoa(obj->pos.y, 0, 1), rt->ui->obj_b_rect[13], m);
	else if (rt->ui->case_active == 14)
		D_C(rt, ft_dtoa(obj->pos.z, 0, 1), rt->ui->obj_b_rect[14], m);
	else if (rt->ui->case_active == 15)
		D_C(rt, ft_dtoa(obj->rot.x, 0, 1), rt->ui->obj_b_rect[15], m);
	else if (rt->ui->case_active == 16)
		D_C(rt, ft_dtoa(obj->rot.y, 0, 1), rt->ui->obj_b_rect[16], m);
	else if (rt->ui->case_active == 17)
		D_C(rt, ft_dtoa(obj->rot.z, 0, 1), rt->ui->obj_b_rect[17], m);
	else if (rt->ui->case_active == 18)
		D_C(rt, get_shader_name(obj), rt->ui->obj_b_rect[18], m);
}

void		redraw_case_active(t_rt *rt, int mode)
{
	if (rt->ui->k_edit)
		mode = 0;
	if (rt->scn->s_elem->type == 'C')
		redraw_case_box_camera(rt, rt->scn->s_elem, mode);
	else if (rt->scn->s_elem->type == 'L')
		redraw_case_box_light(rt, rt->scn->s_elem, mode);
	else
		redraw_case_box_object(rt, rt->scn->s_elem, mode);
	if (rt->ui->k_edit)
	{
		rt->ui->case_active = -1;
		rt->ui->case_rect = NULL;
		rt->ui->k_edit = 0;
	}
}
