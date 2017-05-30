/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 19:05:12 by bsouchet          #+#    #+#             */
/*   Updated: 2017/02/10 19:05:20 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			check_tags(t_rt *rt, char *b_o, char *b_c)
{
	int		end;
	int		tmp;

	if (!ft_strcmp(rt->prs->buf, b_o, rt->prs->i))
		return (0);
	rt->prs->i += ft_strlen(b_o);
	end = rt->prs->i;
	tmp = end;
	while (rt->prs->buf[end] != 0 && !ft_strcmp(rt->prs->buf, b_c, end))
		end++;
	while (rt->prs->buf[tmp] != 0 &&
	(rt->prs->buf[tmp] == 32 || rt->prs->buf[tmp] == 9))
		tmp++;
	if (rt->prs->buf[end] == 0 && (rt->prs->b_c = b_c))
		return (error(rt, 7));
	if ((rt->prs->i == end || end == tmp) && s(&rt->prs->b_o, b_o) &&
	(rt->prs->b_c = b_c))
		return (error(rt, 9));
	return (end);
}
