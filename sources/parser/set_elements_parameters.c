/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_elements_parameters.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 15:13:44 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/13 12:32:49 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_default_parameters_part2(t_obj *obj)
{
	obj->reflex = 0.0;
	obj->refrac = 0;
	obj->shader = 0;
	obj->specular = 0;
	obj->r_ol = (SDL_Rect){0, 0, 0, 0};
}

t_obj		*set_default_parameters(t_obj *obj, char type, int title)
{
	obj->n = NULL;
	obj->title = title;
	obj->type = type;
	obj->forme = -1;
	obj->pos = (cl_float3){{0., 0., 0., 0.}};
	obj->rot = (cl_float3){{0., 0., 0., 0.}};
	obj->clr = (cl_float3){{.5, .5, .5, .5}};
	obj->opacity = 1.;
	obj->focal = 55;
	obj->radius = 25.0;
	obj->lenght = 50.0;
	obj->width = 50.0;
	obj->height = 50.0;
	obj->preset = -1;
	obj->visibility = 1;
	obj->intensity = 10.;
	set_default_parameters_part2(obj);
	return (obj);
}

static void	set_element_parameters_part2(t_obj *obj, t_obj *tmp)
{
	obj->preset = tmp->preset;
	obj->reflex = tmp->reflex;
	obj->refrac = tmp->refrac;
	obj->specular = tmp->specular;
	obj->shader = tmp->shader;
}

t_obj		*set_element_parameters(t_obj *obj, t_obj *tmp, char t, int title)
{
	if (title != 0)
		return (set_default_parameters(obj, t, title));
	obj->n = (tmp->n) ? tmp->n : NULL;
	obj->type = tmp->type;
	obj->title = tmp->title;
	obj->forme = tmp->forme;
	obj->pos = tmp->pos;
	obj->rot = tmp->rot;
	obj->clr = tmp->clr;
	obj->opacity = tmp->opacity;
	obj->focal = tmp->focal;
	obj->radius = tmp->radius;
	obj->lenght = tmp->lenght;
	obj->width = tmp->width;
	obj->height = tmp->height;
	obj->visibility = tmp->visibility;
	obj->intensity = tmp->intensity;
	set_element_parameters_part2(obj, tmp);
	return (obj);
}
