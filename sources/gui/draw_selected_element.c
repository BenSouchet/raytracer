/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_selected_element.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 19:02:51 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:28:13 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		redraw_current_element(t_rt *rt, t_cl *cl, char *str)
{
	t_obj *list;

	list = rt->scn->o;
	rt->n_info = -2;
	rt->ui->tmp = ft_strf(INF36, str);
	free(str);
	if (rt->scn->s_elem->id == rt->scn->c_cam->id)
		rt->scn->c_cam = rt->scn->o->next;
	rt->scn->s_elem = NULL;
	(rt->ui->b_state[15] == 2) ? draw_outliner(rt, -1, 0) : 1;
	draw_selected_element(rt);
	cl_main_krl_update_buffers(cl, rt->scn);
	rt->scn->redraw = 1;
	draw_info_bar(rt);
	free(rt->ui->tmp);
	draw_current_camera_name(rt, 1);
}

void		draw_selected_camera(t_rt *rt, t_obj *obj)
{
	char	*tmp;

	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){421, 206, 214, 275},
	rt->s_back, &(SDL_Rect){1066, 67, 214, 275});
	tmp = ft_strunc((char *)obj->n, 14);
	D_P(rt, tmp, (SDL_Rect){1147, 106, 111, 21}, 1);
	tmp = ft_strf("Camera");
	D_P(rt, tmp, (SDL_Rect){1147, 133, 111, 21}, 1);
	D_P(rt, ft_itoa(obj->focal), rt->ui->cam_b_rect[1], 2);
	D_P(rt, ft_dtoa(obj->pos.x, 0, 1), rt->ui->cam_b_rect[2], 2);
	D_P(rt, ft_dtoa(obj->pos.y, 0, 1), rt->ui->cam_b_rect[3], 2);
	D_P(rt, ft_dtoa(obj->pos.z, 0, 1), rt->ui->cam_b_rect[4], 2);
	D_P(rt, ft_dtoa(obj->rot.x, 0, 1), rt->ui->cam_b_rect[5], 2);
	D_P(rt, ft_dtoa(obj->rot.y, 0, 1), rt->ui->cam_b_rect[6], 2);
	D_P(rt, ft_dtoa(obj->rot.z, 0, 1), rt->ui->cam_b_rect[7], 2);
}

void		draw_selected_light(t_rt *rt, t_obj *obj)
{
	char	*tmp;

	SDL_LowerBlit(rt->ui->s_ui, &(SDL_Rect){636, 206, 214, 355},
	rt->s_back, &(SDL_Rect){1066, 67, 214, 355});
	tmp = ft_strunc((char *)obj->n, 14);
	D_P(rt, tmp, (SDL_Rect){1147, 106, 111, 21}, 1);
	if (obj->forme == T_DIFFUSE)
		tmp = ft_strf("Diffuse");
	else
		tmp = (obj->forme == T_DIRECTIONAL) ?
		ft_strf("Directionnal") : ft_strf("Spot");
	D_P(rt, tmp, (SDL_Rect){1147, 133, 111, 21}, 1);
	D_P(rt, ft_itoa(obj->intensity), rt->ui->lgt_b_rect[1], 2);
	tmp = ft_strf("NO");
	D_P(rt, tmp, rt->ui->lgt_b_rect[2], 2);
	D_P(rt, ft_dtoa(obj->clr.x * 255.0f, 0, 1), rt->ui->lgt_b_rect[3], 2);
	D_P(rt, ft_dtoa(obj->clr.y * 255.0f, 0, 1), rt->ui->lgt_b_rect[4], 2);
	D_P(rt, ft_dtoa(obj->clr.z * 255.0f, 0, 1), rt->ui->lgt_b_rect[5], 2);
	D_P(rt, ft_dtoa(obj->pos.x, 0, 1), rt->ui->lgt_b_rect[6], 2);
	D_P(rt, ft_dtoa(obj->pos.y, 0, 1), rt->ui->lgt_b_rect[7], 2);
	D_P(rt, ft_dtoa(obj->pos.z, 0, 1), rt->ui->lgt_b_rect[8], 2);
	D_P(rt, ft_dtoa(obj->rot.x, 0, 1), rt->ui->lgt_b_rect[9], 2);
	D_P(rt, ft_dtoa(obj->rot.y, 0, 1), rt->ui->lgt_b_rect[10], 2);
	D_P(rt, ft_dtoa(obj->rot.z, 0, 1), rt->ui->lgt_b_rect[11], 2);
}

static void	draw_selected_object_part2(t_rt *rt, t_obj *obj)
{
	D_P(rt, ft_dtoa(obj->clr.x * 255.0f, 0, 1), rt->ui->obj_b_rect[9], 2);
	D_P(rt, ft_dtoa(obj->clr.y * 255.0f, 0, 1), rt->ui->obj_b_rect[10], 2);
	D_P(rt, ft_dtoa(obj->clr.z * 255.0f, 0, 1), rt->ui->obj_b_rect[11], 2);
	D_P(rt, ft_dtoa(obj->pos.x, 0, 1), rt->ui->obj_b_rect[12], 2);
	D_P(rt, ft_dtoa(obj->pos.y, 0, 1), rt->ui->obj_b_rect[13], 2);
	D_P(rt, ft_dtoa(obj->pos.z, 0, 1), rt->ui->obj_b_rect[14], 2);
	D_P(rt, ft_dtoa(obj->rot.x, 0, 1), rt->ui->obj_b_rect[15], 2);
	D_P(rt, ft_dtoa(obj->rot.y, 0, 1), rt->ui->obj_b_rect[16], 2);
	D_P(rt, ft_dtoa(obj->rot.z, 0, 1), rt->ui->obj_b_rect[17], 2);
}

void		draw_selected_object(t_rt *rt, t_obj *obj)
{
	char	*tmp;

	SDL_LowerBlit(rt->ui->s_ui, &rt->ui->area[8], rt->s_back, &rt->ui->area[8]);
	tmp = ft_strunc((char *)obj->n, 14);
	D_P(rt, tmp, (SDL_Rect){1147, 106, 111, 21}, 1);
	tmp = ft_strf("%s", shape_object_ws(obj->forme));
	D_P(rt, tmp, (SDL_Rect){1147, 133, 111, 21}, 1);
	D_P(rt, ft_dtoa(obj->opacity, 0, 1), rt->ui->obj_b_rect[1], 2);
	tmp = get_shader_name(obj);
	D_P(rt, tmp, (SDL_Rect){1173, 187, 85, 21}, 2);
	tmp = (obj->specular == 0) ?
	ft_strf("NO") : ft_strf("YES");
	D_P(rt, tmp, rt->ui->obj_b_rect[2], 2);
	D_P(rt, ft_dtoa(obj->reflex, 0, 1), rt->ui->obj_b_rect[3], 2);
	tmp = (obj->refrac == 0) ?
	ft_strf("NO") : ft_strf("YES");
	D_P(rt, tmp, rt->ui->obj_b_rect[4], 2);
	if (obj->forme == T_SPHERE || obj->forme == T_CYLINDER ||
	obj->forme == T_CONE || obj->forme == T_TORUS)
		D_P(rt, ft_dtoa(obj->radius, 0, 1), rt->ui->obj_b_rect[5], 2);
	else
		D_P(rt, ft_strf("---------"), rt->ui->obj_b_rect[5], 1);
	draw_dimensions_parameter(rt, obj);
	draw_selected_object_part2(rt, obj);
}
