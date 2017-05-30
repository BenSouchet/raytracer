/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_main_krl_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 12:07:51 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:47 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libfmt.h"

#define N_BENCH 2000

static void
	cpy_kernel_args
	(t_cl *cl)
{
	CL_KRL_ARG(cl->main_krl.krl, 2, cl->objs);
	CL_KRL_ARG(cl->main_krl.krl, 3, cl->lgts);
	CL_KRL_ARG(cl->main_krl.krl, 4, cl->n_objs);
	CL_KRL_ARG(cl->main_krl.krl, 5, cl->n_lgts);
	CL_KRL_ARG(cl->main_krl.krl, 6, cl->offs);
}

static double
	main_krl_exec_benchmark
	(t_cl *cl
	, size_t *work_size)
{
	cl_event	ev;
	cl_ulong	end;
	cl_ulong	start;
	int			ret;

	ret = clEnqueueNDRangeKernel(cl->info.cmd_queue
		, cl->main_krl.krl, 2, NULL, work_size, NULL, 0, NULL, &ev);
	clWaitForEvents(1, &ev);
	clFinish(cl->info.cmd_queue);
	clGetEventProfilingInfo(ev, CL_PROFILING_COMMAND_START
		, sizeof(start), &start, NULL);
	clGetEventProfilingInfo(ev, CL_PROFILING_COMMAND_END
		, sizeof(end), &end, NULL);
	return ((end - start) / 1000000000.0);
}

bool
	cl_main_krl_exec
	(t_cl *cl
	, short *n_aa)
{
	double			total;
	int				ret;
	size_t			i;
	static size_t	work_size[2] = {REND_W, REND_H};

	cluster_strategy(cl);
	cpy_kernel_args(cl);
	*n_aa = cluster_send_command_all(cl, 'r', NULL, 0);
	if (BENCHMARK_KRL == 1)
	{
		i = -1;
		total = 0;
		while (++i < N_BENCH)
			total += main_krl_exec_benchmark(cl, work_size);
		total /= N_BENCH;
	}
	else
	{
		if ((ret = cl_krl_exec(&cl->info, cl->main_krl.krl, 2, work_size))
			!= CL_SUCCESS)
			return (ERR("cannot exec kernel, err %a\n", false, ret));
	}
	return (true);
}
