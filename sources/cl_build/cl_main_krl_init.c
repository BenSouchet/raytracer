/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_main_krl_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 15:08:54 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:58 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libvect.h"
#include "libfmt.h"
#include "parameters.h"
#include "cl_interface.h"

#define FILENAME	"sources/cl/main.cl"
#define KRLNAME		"kernel_entry"

static void
	cl_build_line
	(t_vect *build_line)
{
	vect_init(build_line);
	VECT_STRADD(build_line, KRLNAME ":");
	VECT_STRADD(build_line, "-I sources/cl ");
	FMT_VECT(build_line, "-D WIDTH=%a ", REND_W);
	FMT_VECT(build_line, "-D HEIGHT=%a ", REND_H);
	FMT_VECT(build_line, "-D AREA=%a ", REND_W * REND_H);
	FMT_VECT(build_line, "-D XCENTER=%a ", REND_W / 2);
	FMT_VECT(build_line, "-D YCENTER=%a ", REND_H / 2);
	FMT_VECT(build_line, "-Werror", 0);
}

bool
	cl_main_krl_init
	(t_cl *cl)
{
	int		fd;
	int		ret;
	t_vect	build_line;

	ft_bzero(cl, sizeof(*cl));
	if ((fd = open(FILENAME, O_RDONLY)) < 0)
		return (ERR("cannot open " FILENAME, false, 0));
	cl_init(&cl->info);
	cl_krl_init(&cl->main_krl, 2);
	cl->main_krl.sizes[0] = REND_W * REND_H * 4;
	cl->main_krl.sizes[1] = sizeof(t_cl_cam);
	cl_build_line(&build_line);
	if ((ret = cl_krl_build(&cl->info
		, &cl->main_krl, fd, &build_line)) != CL_SUCCESS)
		return (ERR("cannot build kernel, err %a", false, ret));
	close(fd);
	free(build_line.data);
	return (true);
}
