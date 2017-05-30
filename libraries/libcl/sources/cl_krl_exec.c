/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_krl_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 02:06:54 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:51:18 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libcl.h"
#include "malloc.h"

cl_int
	cl_krl_exec
	(t_cl_info *cl
	, cl_kernel krl
	, cl_uint work_dim
	, size_t *work_size)
{
	return (clEnqueueNDRangeKernel(cl->cmd_queue
		, krl, work_dim, NULL, work_size, NULL, 0, NULL, NULL));
}
