/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_read_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 12:34:37 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:57 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "libgnl.h"

#define OPT(a) (!!(opts & a))

/*
** reads whole fd till EOL
** stores result from succ calls to gnl in buf
** ignores lines starting with any char in ignore
** (used for ignoring comments)
*/

size_t		gnl_read_all(int fd, t_vect *buf, int opts, size_t *calls)
{
	int		ret;
	int		size_set;
	size_t	size;
	t_vect	line;
	t_vect	v;

	vect_init(&v);
	vect_init(&line);
	size_set = 0;
	while ((ret = get_next_line(fd, &v, &line, opts)) == 1)
	{
		if (!line.used
			|| ((MEMCHR(GNL_IGNORE, *(char *)line.data)) && !(line.used = 0)))
			continue ;
		if (size_set && size != line.used)
			return (0);
		if (OPT(GNL_CHECK_SIZE) && !size_set && (size_set = 1))
			size = line.used;
		vect_add(buf, line.data, line.used);
		line.used = 0;
		(*calls)++;
	}
	free(line.data);
	free(v.data);
	return (size_set ? size : !ret);
}
