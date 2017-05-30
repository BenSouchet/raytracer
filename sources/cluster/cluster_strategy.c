/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cluster_strategy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/10 11:32:49 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:50:43 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "libfmt.h"

void
	cluster_strategy
	(t_cl *cl)
{
	int			nclients;
	cl_float2	offs;
	float		theta;
	t_client	*cli;

	nclients = 1;
	cli = cl->cli_list;
	while (cli && (nclients++ | 42))
		cli = cli->next;
	theta = 2 * M_PI / nclients;
	cli = cl->cli_list;
	while (nclients--)
	{
		offs.x = cos(theta * nclients);
		offs.y = sin(theta * nclients);
		if (cli)
		{
			cluster_send_command(cli, 's', &offs, sizeof(offs));
			cli = cli->next;
		}
		else
			ft_memcpy(&cl->offs, &offs, sizeof(offs));
	}
}
