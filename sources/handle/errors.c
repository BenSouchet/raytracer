/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/06 17:58:11 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/10 10:52:49 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Function to init the tab that contain all errors
*/

void		init_errors(t_rt *r, int i)
{
	r->err = (char **)malloc(sizeof(char *) * 50);
	i = (
	s(&r->err[0], MSG0) && s(&r->err[1], MSG1) && s(&r->err[2], MSG2) &&
	s(&r->err[4], MSG4) && s(&r->err[5], MSG5) && s(&r->err[6], MSG6) &&
	s(&r->err[8], MSG8) && s(&r->err[11], MSG11) && s(&r->err[12], MSG12) &&
	s(&r->err[13], MSG13) && s(&r->err[16], MSG16) && s(&r->err[17], MSG17) &&
	s(&r->err[18], MSG18) && s(&r->err[19], MSG19) && s(&r->err[20], MSG20) &&
	s(&r->err[21], MSG21) && s(&r->err[22], MSG22) && s(&r->err[23], MSG23) &&
	s(&r->err[24], MSG24) && s(&r->err[25], MSG25) && s(&r->err[26], MSG26) &&
	s(&r->err[27], MSG27) && s(&r->err[28], MSG28) && s(&r->err[29], MSG29) &&
	s(&r->err[30], MSG30) && s(&r->err[31], MSG31) && s(&r->err[32], MSG32) &&
	s(&r->err[33], MSG33) && s(&r->err[34], MSG34) && s(&r->err[35], MSG35) &&
	s(&r->err[36], MSG36) && s(&r->err[37], MSG37) && s(&r->err[38], MSG38) &&
	s(&r->err[39], MSG39) && s(&r->err[40], MSG40) && s(&r->err[41], MSG41) &&
	s(&r->err[42], MSG42) && s(&r->err[43], MSG43) && s(&r->err[44], MSG44) &&
	s(&r->err[46], MSG46) && s(&r->err[47], MSG47))
	? 1 : 1;
}

/*
** Function to call and print the error associated with the number (int)t
*/

int			error(t_rt *rt, int t)
{
	char	*s;

	s = NULL;
	if (t == 3 && write(2, "error : ", 8) &&
	write(2, strerror(errno), ft_strlen(strerror(errno))))
		write(2, ".\n", 2);
	else if (t == 7)
		s = ft_strjoin(ft_strjoin("error : ", rt->prs->b_c, 'N'), MSG7, 'L');
	else if (t == 9)
		s = ft_strjoin(ft_strjoin(MSG9, rt->prs->b_o, 'N'),
		ft_strjoin(" and ", rt->prs->b_c, 'N'), 'B');
	else if (t == 10)
		s = ft_strjoin(ft_strjoin(MSG10, rt->prs->b_o, 'N'),
		ft_strjoin(" and ", rt->prs->b_c, 'N'), 'B');
	else if (t == 14)
		s = ft_strjoin(ft_strjoin(MSG14, rt->prs->b_o, 'N'),
		ft_strjoin(" and ", rt->prs->b_c, 'N'), 'B');
	else if (t == 15)
		s = ft_strjoin(ft_strjoin(ft_strjoin("error : ", rt->prs->b_o, 'N'),
		ft_strjoin(MSG15A, rt->prs->b_c, 'N'), 'B'), MSG15B, 'L');
	(!s && t != 3) ? write(2, rt->err[t], ft_strlen(rt->err[t])) : 1;
	(s) ? (write(2, s, ft_strlen(s)) && write(2, ".\n", 2)) : 1;
	exit(1);
	return (1);
}
