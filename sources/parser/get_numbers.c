/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:29:13 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/09 16:54:26 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Function to get a double (float) value from a position in my buffer (v->buf)
*/

int			get_d(t_rt *rt, int b_end, char *st, char *e)
{
	int		start;
	int		end;

	rt->prs->t_i = 0;
	while (rt->prs->i < b_end &&
	(rt->prs->buf[rt->prs->i] == 32 || rt->prs->buf[rt->prs->i] == 9))
		rt->prs->i++;
	start = rt->prs->i;
	(rt->prs->i < b_end && (rt->prs->buf[rt->prs->i] == 43 ||
	rt->prs->buf[rt->prs->i] == 45)) ? rt->prs->i++ : 1;
	while (rt->prs->i < b_end && (rt->prs->buf[rt->prs->i] == '.' ||
	(rt->prs->buf[rt->prs->i] >= 48 && rt->prs->buf[rt->prs->i] <= 57)))
		(rt->prs->i++ > 0 && rt->prs->buf[rt->prs->i] == '.') ?
		rt->prs->t_i++ : 1;
	end = rt->prs->i;
	while (rt->prs->i < b_end &&
	(rt->prs->buf[rt->prs->i] == 32 || rt->prs->buf[rt->prs->i] == 9))
		rt->prs->i++;
	if ((start == end || rt->prs->i != b_end || rt->prs->t_i > 1) &&
	(rt->prs->b_o = st) && s(&rt->prs->b_c, e))
		return (error(rt, 14) + 1);
	rt->prs->t_d = ft_atof(rt->prs->buf, start);
	rt->prs->i = b_end + ft_strlen(e);
	return (1);
}

/*
** Function to get a integer value from a position in my buffer (v->buf)
*/

int			get_i(t_rt *rt, int b_end, char *st, char *e)
{
	int		start;
	int		end;

	while (rt->prs->i < b_end && (rt->prs->buf[rt->prs->i] == 32 ||
	rt->prs->buf[rt->prs->i] == 9))
		rt->prs->i++;
	start = rt->prs->i;
	if (rt->prs->i < b_end &&
	(rt->prs->buf[rt->prs->i] == 43 || rt->prs->buf[rt->prs->i] == 45))
		rt->prs->i++;
	while (rt->prs->i < b_end && rt->prs->buf[rt->prs->i] >= 48 &&
	rt->prs->buf[rt->prs->i] <= 57)
		rt->prs->i++;
	end = rt->prs->i;
	while (rt->prs->i < b_end &&
	(rt->prs->buf[rt->prs->i] == 32 || rt->prs->buf[rt->prs->i] == 9))
		rt->prs->i++;
	if ((start == end || rt->prs->i != b_end) && s(&rt->prs->b_o, st) &&
	s(&rt->prs->b_c, e))
		return (error(rt, 14) + 1);
	rt->prs->t_i = ft_atoi(rt->prs->buf, start);
	rt->prs->i = b_end + ft_strlen(e);
	return (1);
}

/*
** Function to get a vector (XYZ) from a position in my buffer (v->buf)
*/

static void	lol(t_rt *rt, int *b_e, int *end, int *z)
{
	while (rt->prs->i < *b_e &&
	(rt->prs->buf[rt->prs->i] == 32 || rt->prs->buf[rt->prs->i] == 9))
		rt->prs->i++;
	*z = rt->prs->i;
	(rt->prs->i < *b_e &&
	(rt->prs->buf[rt->prs->i] == 43 || rt->prs->buf[rt->prs->i] == 45)) ?
	rt->prs->i++ : 1;
	while (rt->prs->i < *b_e && (rt->prs->buf[rt->prs->i] == '.' ||
	(rt->prs->buf[rt->prs->i] >= 48 && rt->prs->buf[rt->prs->i] <= 57)))
		(rt->prs->i++ > 0 && rt->prs->buf[rt->prs->i] == '.') ?
		rt->prs->t_i++ : 1;
	*end = rt->prs->i;
	while (rt->prs->i < *b_e &&
	(rt->prs->buf[rt->prs->i] == 32 || rt->prs->buf[rt->prs->i] == 9))
		rt->prs->i++;
}

int			get_v(t_rt *rt, int b_e, char *st, char *e)
{
	int		z;
	int		end;
	int		p;

	p = 0;
	while (rt->prs->i < b_e && p < 3 && (rt->prs->t_i = 0) != 1)
	{
		lol(rt, &b_e, &end, &z);
		if ((z == end || rt->prs->t_i > 1) && s(&rt->prs->b_o, st) &&
		s(&rt->prs->b_c, e))
			return (error(rt, 14) + 1);
		if (p == 0)
			rt->prs->vec.x = ft_atof(rt->prs->buf, z);
		else if (p == 1)
			rt->prs->vec.y = ft_atof(rt->prs->buf, z);
		else
			rt->prs->vec.z = ft_atof(rt->prs->buf, z);
		p++;
	}
	if ((rt->prs->i != b_e || p != 3) && s(&rt->prs->b_o, st) &&
	s(&rt->prs->b_c, e))
		return (error(rt, 14) + 1);
	rt->prs->i = b_e + ft_strlen(e);
	return (1);
}

/*
** Function to get a hexadecimal value from a position in my buffer (v->buf)
*/

int			get_h(t_rt *rt, int b_end, char *st, char *e)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	i = 0;
	j = 0;
	k = 0;
	str = ft_getstr(rt->prs->buf, rt->prs->i, b_end);
	if (str[i] == '#')
		i++;
	else if (str[i] == '0' && (str[i + 1] == 'x' || str[i + 1] == 'X'))
		i += 2;
	j = i;
	while (str[i] != 0 && ((str[i] >= '0' && str[i] <= '9') ||
	(str[i] >= 'A' && str[i] <= 'F') ||
	(str[i] >= 'a' && str[i] <= 'f')) && ++k != 0)
		i++;
	if ((str[i] != 0 || k != 6) && s(&rt->prs->b_o, st) &&
	s(&rt->prs->b_c, e))
		return (error(rt, 14) + 1);
	rt->prs->t_u = ft_shtoi(str + j);
	free(str);
	rt->prs->i = b_end + ft_strlen(e);
	return (1);
}
