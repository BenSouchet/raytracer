/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_main_krl_update_buffers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 08:51:33 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:51:01 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "cl_interface.h"
#include "libvect.h"
#include "libcl.h"
#include "libfmt.h"

/*
** updates GPU memory
** needs to be called each time the scene is changed
*/

#define OBJSIZE sizes[0]
#define NOBJS sizes[1]

static void
	krl_cpy_lst
	(void (*cpy_f) (void *, void *)
	, t_obj *obj
	, size_t *sizes
	, t_vect *buf)
{
	size_t	i;

	i = 0;
	while (i < NOBJS)
	{
		if (obj->visibility)
		{
			vect_req(buf, OBJSIZE);
			cpy_f(buf->data + buf->used, obj);
			buf->used += OBJSIZE;
		}
		obj = obj->next;
		i++;
	}
}

static cl_mem
	krl_get_mem
	(void (*cpy_f) (void *, void *)
	, t_cl *cl
	, t_obj *objs
	, size_t *sizes)
{
	cl_mem	mem;
	int		ret;
	t_vect	buf;

	vect_init(&buf);
	krl_cpy_lst(cpy_f, objs, sizes, &buf);
	NOBJS = buf.used / OBJSIZE;
	if (buf.used == 0)
		return (NULL);
	mem = clCreateBuffer(cl->info.ctxt, 0, buf.used, NULL, &ret);
	if (ret != CL_SUCCESS)
	{
		ERR("clCreateBuffer error %a", 0, ret);
		return (NULL);
	}
	if ((ret = cl_write(&cl->info, mem, buf.used, buf.data)) != CL_SUCCESS)
	{
		ERR("cl_write error %a", 0, ret);
		return (NULL);
	}
	cluster_send_command_all(cl, OBJSIZE == sizeof(t_cl_lgt) ? 'l' : 'o'
		, buf.data, buf.used);
	free(buf.data);
	return (mem);
}

bool
	cl_main_krl_update_buffers
	(t_cl *cl
	, t_scene *scn)
{
	size_t	sizes[2];

	OBJSIZE = sizeof(t_cl_lgt);
	NOBJS = scn->n_lgts;
	if (cl->n_lgts)
		clReleaseMemObject(cl->lgts);
	cl->lgts = krl_get_mem((void (*)(void *, void *))&cpy_lgt
		, cl, scn->b_lgts->next, sizes);
	cl->n_lgts = NOBJS;
	OBJSIZE = sizeof(t_cl_obj);
	NOBJS = scn->n_objs;
	if (cl->n_objs)
		clReleaseMemObject(cl->objs);
	cl->objs = krl_get_mem((void (*)(void *, void *))&cpy_obj
		, cl, scn->b_objs->next, sizes);
	cl->n_objs = NOBJS;
	return (true);
}
