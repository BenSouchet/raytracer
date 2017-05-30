/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_copy_image_buffer.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:35:42 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:42 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libfmt.h"
#include <sys/socket.h>

static bool
	buffer_average_samples
	(t_cl *cl
	, unsigned int *buffer
	, int n)
{
	unsigned int	tmp[3];
	size_t			i;
	t_client		*cli;

	i = 0;
	while (i < REND_W * REND_H)
	{
		*(long *)tmp = 0;
		tmp[2] = 0;
		cli = cl->cli_list;
		while (cli)
		{
			tmp[0] += (cli->buffer[i] >> 8) & 0xFF;
			tmp[1] += (cli->buffer[i] >> 16) & 0xFF;
			tmp[2] += (cli->buffer[i] >> 24) & 0xFF;
			cli = cli->next;
		}
		tmp[0] = (tmp[0] + (buffer[i] >> 8 & 0xFF)) / n;
		tmp[1] = (tmp[1] + (buffer[i] >> 16 & 0xFF)) / n;
		tmp[2] = (tmp[2] + (buffer[i] >> 24 & 0xFF)) / n;
		buffer[i++] = 0xFF
			| (tmp[0] << 8) | (tmp[1] << 16) | (tmp[2] << 24);
	}
	return (true);
}

bool
	cl_copy_image_buffer
	(t_cl *cl
	, void *buffer)
{
	int			n;
	int			ret;
	t_client	*cli;

	ret = 0;
	n = 1;
	cli = cl->cli_list;
	while (cli)
	{
		n++;
		cli = cli->next;
	}
	if ((ret = clEnqueueReadBuffer(cl->info.cmd_queue
		, cl->main_krl.args[0], CL_TRUE, 0
		, cl->main_krl.sizes[0], buffer, 0, NULL, NULL)) != CL_SUCCESS)
		return (ERR("cannot read image buffer, err %a", false, ret));
	return (buffer_average_samples(cl, buffer, n));
}
