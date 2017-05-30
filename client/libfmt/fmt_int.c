/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fmt_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsouchet <bsouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:20:51 by bsouchet          #+#    #+#             */
/*   Updated: 2017/05/30 16:48:21 by bsouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libfmt.h"

void
	fmt_int
	(t_vect *a
	, char **d
	, size_t *n
	, va_list l)
{
	char			*s;
	int				sign;
	unsigned long	base;
	unsigned long	bytes;

	sign = 0;
	base = 0;
	bytes = 0;
	if (**d == '-')
	{
		(*d)++;
		(*n)--;
		sign = 1;
	}
	s = STRTOB10(*d, base);
	if (*s == '/')
		s = STRTOB10(++s, bytes);
	*n -= s - *d;
	*d = s;
	if (sign)
		bytes == 4 ? fmt_int_sign_32(a, base, va_arg(l, int))
			: fmt_int_sign_64(a, base, va_arg(l, long));
	else
		fmt_int_unsign(a, base, va_arg(l, unsigned long));
}
