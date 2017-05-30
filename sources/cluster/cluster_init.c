/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:50:25 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:34 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cluster.h"
#include "parameters.h"
#include "libfmt.h"

void
	*accept_routine
	(void *arg)
{
	t_cl		*self;
	int			fd;
	t_client	*new;
	int			nclients;

	self = arg;
	nclients = 0;
	while (nclients < CLUSTER_MAX_CLIENTS)
	{
		fd = accept(self->sockfd, NULL, NULL);
		nclients++;
		new = malloc(sizeof(*new));
		ft_bzero(new, sizeof(*new));
		new->fd = fd;
		new->next = self->cli_list;
		self->cli_list = new;
	}
	close(self->sockfd);
	return (NULL);
}

int
	cluster_init
	(t_cl *cl)
{
	int					ret;
	int					port_offs;
	struct sockaddr_in	self_addr;

	if ((cl->sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		return (ERR("cant create socket", 0, 0));
	setsockopt(cl->sockfd, SOL_SOCKET, SO_REUSEADDR, NULL, 4);
	ft_bzero(&self_addr, sizeof(self_addr));
	self_addr.sin_family = AF_INET;
	self_addr.sin_port = CLUSTER_PORT;
	self_addr.sin_addr.s_addr = INADDR_ANY;
	port_offs = 0;
	while (port_offs <= 5 && (ret = bind(cl->sockfd
		, (void *)&self_addr, sizeof(self_addr))) == -1)
		self_addr.sin_port = CLUSTER_PORT + ++port_offs;
	if (ret == -1)
		return (ERR("bind error, all ports used", 0, 0));
	if (listen(cl->sockfd, CLUSTER_MAX_CLIENTS) == -1)
		return (ERR("listen error", 0, 0));
	pthread_create(&cl->accept_thread, NULL, &accept_routine, cl);
	return (0);
}
