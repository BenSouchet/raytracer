/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_int_sign_64.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:25:49 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:27 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

void
	fmt_int_sign_64
	(t_vect *a
	, int base
	, long x)
{
	bool	neg;
	char	s[20];
	size_t	i;

	i = 19;
	neg = (x < 0);
	if (!x)
		return ((void)vect_mset_end(a, '0', 1));
	while ((x > 0 || x <= base) && ((x < 0) || (x >= base)))
	{
		s[i] = x % base;
		s[i] = ABS(s[i]);
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	if (x)
		s[i--] = ABS(x) + (x <= 9 ? '0' : 'a' - 10);
	if (neg)
		s[i--] = '-';
	i++;
	vect_add(a, s + i, 20 - i);
}
