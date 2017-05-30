/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 13:49:49 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:47:57 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_client.h"

static void
	update_camera
	(t_vect *data
	, t_cl *cl)
{
	int		ret;

	if ((ret = cl_write(&cl->info, cl->main_krl.args[1]
		, sizeof(t_cl_cam), data->data)) != CL_SUCCESS)
		ERR("cannot update camera, cl err %a", 0, ret);
}

static void
	update_buffer
	(t_vect *data
	, cl_mem *mem
	, short n
	, t_cl *cl)
{
	int		ret;

	clReleaseMemObject(*mem);
	if (n == 0)
		return ;
	*mem = clCreateBuffer(cl->info.ctxt, 0, data->used, NULL, &ret);
	if (ret != CL_SUCCESS)
		ERR("clCreateBuffer error %a", 0, ret);
	else if ((ret = cl_write(&cl->info, *mem, data->used, data->data)
		!= CL_SUCCESS))
		ERR("cl_write error %a", 0, ret);
}

static void
	process_command
	(char cmd
	, t_vect *data
	, t_cl *cl
	, int sockfd)
{
	if (cmd == 'c')
		update_camera(data, cl);
	if (cmd == 'l')
	{
		update_buffer(data, &cl->lgts, data->used / sizeof(t_cl_lgt), cl);
		cl->n_lgts = data->used / sizeof(t_cl_lgt);
	}
	if (cmd == 'o')
	{
		update_buffer(data, &cl->objs, data->used / sizeof(t_cl_obj), cl);
		cl->n_objs = data->used / sizeof(t_cl_obj);
	}
	if (cmd == 'r')
	{
		cl_main_krl_exec(cl);
		data->used = 0;
		vect_req(data, 4 * REND_W * REND_H);
		cl_read(&cl->info, cl->main_krl.args[0]
			, cl->main_krl.sizes[0], data->data);
		data->used = cl->main_krl.sizes[0];
		send(sockfd, data->data, data->used, 0);
	}
	if (cmd == 's')
		ft_memcpy(&cl->offs, data->data, data->used);
	send(sockfd, &cmd, 1, 0);
}

void
	client_loop
	(int sockfd
	, t_vect *data
	, t_cl *cl)
{
	char	cmd;
	int		ret;
	size_t	data_size;

	if ((ret = recv(sockfd, &cmd, 1, 0)) != 1)
		return ;
	data->used = 0;
	if ((ret = recv(sockfd, &data_size, 8, 0)) <= 0)
		return ;
	if (data_size)
	{
		vect_req(data, data_size);
		recv(sockfd, data->data, data_size, 0);
		data->used = data_size;
	}
	process_command(cmd, data, cl, sockfd);
	client_loop(sockfd, data, cl);
}
