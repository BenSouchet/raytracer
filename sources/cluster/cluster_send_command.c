/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_send_command.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/13 08:29:54 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:38 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cluster.h"
#include "../cl_build/cl_interface.h"

int
	cluster_send_command
	(t_client *client
	, char command
	, void *arg
	, size_t arg_size)
{
	char	ack;

	if (!send(client->fd, &command, 1, 0))
		return (0);
	if (!send(client->fd, &arg_size, 8, 0))
		return (0);
	if (arg_size)
	{
		if (!send(client->fd, arg, arg_size, 0))
			return (0);
	}
	if (command == 'r' && client->buffer == NULL)
		client->buffer = malloc(4 * REND_W * REND_H);
	if (command == 'r' && (!client->buffer || recv(client->fd
			, client->buffer, 4 * REND_W * REND_H, MSG_WAITALL) == 0))
		return (0);
	if (recv(client->fd, &ack, 1, 0) == 0)
		return (0);
	if (ack == 'c')
		client->status |= CLIENT_CAM_OK;
	if (ack == 'l')
		client->status |= CLIENT_LGT_OK;
	if (ack == 'o')
		client->status |= CLIENT_OBJ_OK;
	return (1);
}

static void
	remove_client
	(t_cl *cl
	, t_client **cli
	, t_client **tmp)
{
	free((*cli)->buffer);
	if (*tmp == NULL)
	{
		cl->cli_list = (*cli)->next;
		close((*cli)->fd);
		free(*cli);
		*cli = cl->cli_list;
	}
	else
	{
		(*tmp)->next = (*cli)->next;
		free(*cli);
		*cli = (*tmp)->next;
	}
}

void
	*dup_kernel_data
	(t_cl *cl
	, char cmd)
{
	void	*ret;
	size_t	size;

	ret = NULL;
	if (cmd == 'c')
	{
		ret = malloc(sizeof(t_cl_cam));
		if (ret != NULL)
			cl_read(&cl->info, cl->main_krl.args[1], sizeof(t_cl_cam), ret);
	}
	if (cmd == 'l')
	{
		size = sizeof(t_cl_lgt) * cl->n_lgts;
		ret = malloc(size);
		if (ret != NULL)
			cl_read(&cl->info, cl->lgts, size, ret);
	}
	if (cmd == 'o')
	{
		size = sizeof(t_cl_obj) * cl->n_objs;
		ret = malloc(size);
		if (ret != NULL)
			cl_read(&cl->info, cl->objs, size, ret);
	}
	return (ret);
}

static int
	fill_client_buffers
	(t_cl *cl
	, t_client *cli)
{
	void	*buffer;

	buffer = NULL;
	if ((cli->status & CLIENT_CAM_OK) == 0)
	{
		if (!(buffer = dup_kernel_data(cl, 'c')))
			return (0);
		cluster_send_command(cli, 'c', buffer, sizeof(t_cl_cam));
	}
	if ((cli->status & CLIENT_OBJ_OK) == 0)
	{
		if (!(buffer = dup_kernel_data(cl, 'o')))
			return (0);
		cluster_send_command(cli, 'o', buffer
			, cl->n_objs * sizeof(t_cl_obj));
	}
	if ((cli->status & CLIENT_LGT_OK) == 0)
	{
		if (!(buffer = dup_kernel_data(cl, 'l')))
			return (0);
		cluster_send_command(cli, 'l', buffer
			, cl->n_lgts * sizeof(t_cl_lgt));
	}
	free(buffer);
	return (1);
}

int
	cluster_send_command_all
	(t_cl *cl
	, char command
	, void *arg
	, size_t arg_size)
{
	t_client	*cli;
	t_client	*tmp;
	int			nclients;
	int			alive;

	tmp = NULL;
	nclients = 0;
	cli = cl->cli_list;
	while (cli != NULL)
	{
		if (command == 'r')
			alive = fill_client_buffers(cl, cli);
		if (alive)
			alive = cluster_send_command(cli, command, arg, arg_size);
		if (!alive)
			remove_client(cl, &cli, &tmp);
		else
		{
			tmp = cli;
			cli = cli->next;
			nclients++;
		}
	}
	return (nclients + 1);
}
