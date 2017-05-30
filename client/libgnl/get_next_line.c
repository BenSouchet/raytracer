/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/06 15:06:08 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:51 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libgnl.h"
#include <unistd.h>

#define OPT(a) (!!(opts & a))

static int	cpy
	(t_vect *v, t_vect *line, int opts)
{
	void	*buf;

	if ((buf = ft_memchr(v->data, GNL_SEP_CHAR, v->used)))
	{
		vect_add(line, v->data, buf - v->data);
		ft_memmove(v->data, buf + 1, v->used - (buf + 1 - v->data));
		v->used -= buf + 1 - v->data;
		if (OPT(GNL_APPEND_CHAR))
			vect_mset_end(line, GNL_APPEND_CHAR, 1);
		if (OPT(GNL_STR))
			vect_mset_end(line, '\0', 1);
		return (1);
	}
	return (0);
}

int			get_next_line
	(int fd, t_vect *v, t_vect *line, int opts)
{
	int		ret;

	if (v->data && (ret = cpy(v, line, opts)))
		return (ret);
	vect_req(v, GNL_BUFF_SIZE + OPT(GNL_STR) + OPT(GNL_APPEND));
	ret = read(fd, v->data + v->used, GNL_BUFF_SIZE);
	if (ret < 0)
		return (ret);
	if (!ret)
	{
		if (!v->used)
			return (0);
		vect_add(line, v->data, v->used);
		v->used = 0;
		return (1);
	}
	v->used += ret;
	return (get_next_line(fd, v, line, opts));
}
