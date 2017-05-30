/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 09:18:16 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:47:56 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt_client.h"

#define DIGIT "0123456789"

static int
	usage
	(int ret)
{
	static char	usage[] = "usage: rt-client IP\n";

	fmt_print(1, 0, usage, sizeof(usage) - 1);
	return (ret);
}

int
	main
	(int argc
	, char **argv)
{
	int		sockfd;
	t_vect	data;
	t_cl	cl;

	if (argc != 2)
		return (usage(1));
	sockfd = client_init(argv[1]);
	if (sockfd <= 0)
		return (0);
	vect_init(&data);
	cl_main_krl_init(&cl);
	client_loop(sockfd, &data, &cl);
	return (0);
}
