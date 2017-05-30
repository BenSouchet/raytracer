/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 17:56:13 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 10:40:25 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		set_default_element(t_rt *rt, t_cl *cl, char type)
{
	char	*str;

	str = ft_strdup((char *)rt->scn->s_elem->n);
	free(rt->scn->s_elem->n);
	set_default_parameters(rt->scn->s_elem, type, 0);
	rt->scn->s_elem->id = rt->ui->id++;
	if (type == 'C')
		rt->scn->s_elem->n = (cl_char *)ft_strf("Default");
	else if (type == 'L')
		rt->scn->s_elem->n = (cl_char *)ft_strf("Default Diffuse");
	else
		rt->scn->s_elem->n = (cl_char *)ft_strf("Default Sphere");
	rt->scn->s_elem->forme = 0;
	redraw_current_element(rt, cl, str);
}

void		add_new_camera(t_rt *rt, t_obj *tmp)
{
	tmp = set_default_parameters(rt->prs->obj_tmp, 'C', 0);
	tmp->n = (cl_char *)ft_strjoin("Camera ", ft_itoa(rt->scn->n_cams), 'R');
	tmp->focal = rt->scn->c_cam->focal;
	tmp->pos.x = rt->scn->c_cam->pos.x;
	tmp->pos.y = rt->scn->c_cam->pos.y;
	tmp->pos.z = rt->scn->c_cam->pos.z;
	tmp->rot.x = rt->scn->c_cam->rot.x;
	tmp->rot.y = rt->scn->c_cam->rot.y;
	tmp->rot.z = rt->scn->c_cam->rot.z;
	rt->scn->o = lst_new_camera(rt, rt->scn->o, 0);
	rt->ui->area[4].h += (rt->ui->area[4].h <= 379) ? 29 : 0;
	(rt->scn->n_elms >= 12) ? (rt->ui->nav_state = 1) : 1;
	(rt->r_view.x != 18) ? draw_outliner(rt, -1, 0) : 1;
}

void		add_new_light(t_rt *rt, t_obj *tmp, short type)
{
	tmp = set_default_parameters(rt->prs->obj_tmp, 'L', 0);
	if (type == T_DIFFUSE && ++rt->scn->lt[0])
		tmp->n = (cl_char *)ft_strjoin("Point ",
		ft_itoa(rt->scn->lt[0]), 'R');
	else if (type == T_DIRECTIONAL && ++rt->scn->lt[1])
		tmp->n = (cl_char *)ft_strjoin("Directional ",
		ft_itoa(rt->scn->lt[1]), 'R');
	else if (++rt->scn->lt[2])
		tmp->n = (cl_char *)ft_strjoin("Spot ",
		ft_itoa(rt->scn->lt[2]), 'R');
	tmp->forme = type;
	tmp->clr = (cl_float3){{1.0f, (219. / 255.), (74. / 255.), 1.0f}};
	rt->scn->o = lst_new_light(rt, rt->scn->o, 0);
	rt->ui->area[4].h += (rt->ui->area[4].h <= 379) ? 29 : 0;
	(rt->scn->n_elms >= 12) ? (rt->ui->nav_state = 1) : 1;
	(rt->r_view.x != 18) ? draw_outliner(rt, -1, 0) : 1;
}

void		add_new_object(t_rt *rt, t_obj *tmp, short type)
{
	++rt->scn->ot[type];
	tmp = set_default_parameters(rt->prs->obj_tmp, 'O', 0);
	tmp->n = (cl_char *)ft_strjoin(shape_object(type),
	ft_itoa(rt->scn->ot[type]), 'R');
	tmp->forme = type;
	rt->scn->o = lst_new_object(rt, rt->scn->o, 0, 0);
	rt->ui->area[4].h += (rt->ui->area[4].h <= 379) ? 29 : 0;
	(rt->scn->n_elms >= 12) ? (rt->ui->nav_state = 1) : 1;
	(rt->r_view.x != 18) ? draw_outliner(rt, -1, 0) : 1;
}

void		add_new_shader(t_obj *obj, short type)
{
	obj->preset = type;
	if (type == 0)
	{
		obj->clr = (cl_float3){{0.51, 0.314, 0.098, 1.0f}};
		obj->radius = 40;
		obj->shader = 22;
	}
	else if (type == 1)
	{
		obj->clr = (cl_float3){{0.51, 0.51, 0.50, 1.0f}};
		obj->radius = 90;
		obj->shader = 2;
	}
	else if (type == 2)
	{
		obj->clr = (cl_float3){{0.992, 1.0f, 1.0f, 1.0f}};
		obj->radius = 25;
		obj->shader = 20;
	}
	else if (type == 3)
	{
		obj->clr = (cl_float3){{0.544, 0.488, 0.5058, 1.0f}};
		obj->radius = 75;
		obj->shader = 12;
	}
}
