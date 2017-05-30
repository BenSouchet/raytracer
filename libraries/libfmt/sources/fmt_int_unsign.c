/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_int_unsign.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:23:48 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:53:34 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

void
	fmt_int_unsign
	(t_vect *a
	, t_u32 base
	, t_u64 x)
{
	char	s[21];
	size_t	i;

	i = 20;
	if (!x)
		return ((void)vect_mset_end(a, '0', 1));
	while (x >= base)
	{
		s[i] = x % base;
		s[i] += (s[i] <= 9) ? '0' : 'a' - 10;
		x /= base;
		i--;
	}
	if (x)
		s[i--] = x + (x <= 9 ? '0' : 'a' - 10);
	i++;
	vect_add(a, s + i, 21 - i);
}
